#include "global.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "field_specials.h"
#include "field_effect.h"
#include "metatile_behavior.h"
#include "pokemon.h"
#include "pokeride.h"
#include "sound.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/layouts.h"
#include "constants/songs.h"

enum
{
    POKERIDE_SPRITE_UP,
    POKERIDE_SPRITE_DOWN,
    POKERIDE_SPRITE_SIDE,
    POKERIDE_SPRITE_COUNT
};

enum
{
    POKERIDE_MOVEMENT_SLOW,
    POKERIDE_MOVEMENT_ACCELERATE_AVERAGE,
    POKERIDE_MOVEMENT_AVERAGE,
    POKERIDE_MOVEMENT_ACCELERATE_FAST,
    POKERIDE_MOVEMENT_FAST,
    POKERIDE_MOVEMENT_ACCELERATE_VERY_FAST,
    POKERIDE_MOVEMENT_VERY_FAST,
};

#define POKERIDE_FLAG_NONE          (0)
#define POKERIDE_FLAG_CAN_RIDE      (1 << 0)
#define POKERIDE_FLAG_CAN_SWIM      (1 << 1)
#define POKERIDE_FLAG_CAN_CLIMB     (1 << 2)
#define POKERIDE_FLAG_CAN_FLY       (1 << 3)

#define POKERIDE_FLY_HEIGHT 12

struct PokeRideSpriteInfo
{
    // Y has larger ranges than X
    s8 playerY;
    s8 monY;
    s8 playerX;
    s8 monX:7;
    u8 playerRendersInFront:1;
};

struct PokeRideInfo
{
    struct PokeRideSpriteInfo spriteInfo[POKERIDE_SPRITE_COUNT];
    u8 flags;
    u8 rideSpeed;
};

struct PokeRideObjectEvent
{
    struct PokeRide state;
    u8 riderObjectEventId;
    u8 riderSpriteId;
    u8 monSpriteId;
    u8 isActive:1;
};

struct PokeRideData
{
    struct PokeRideObjectEvent rideObject;
    u8 rideFrameCounter;
    u8 recentRideIndex;
    bool8 isReady;
};

static EWRAM_DATA struct PokeRideData sPokeRideData = {0};

static void UpdatePlayerRideState();
static inline bool8 TestRideFlags(u16 species, u8 flags);
static void UpdateRideMonSprites(struct PokeRideObjectEvent* rideObject);
static void UpdateRideSpriteInternal(struct PokeRideObjectEvent* rideObject, const struct PokeRideInfo* rideInfo);
static bool8 AdjustFlyingAnimation(struct PokeRideObjectEvent* rideObject);
static u16 GetCurrentRideMonSpecies();
static const struct PokeRideInfo* GetPokeRideInfoForSpecies(u16 species);

#define POKERIDE_B_LONG_HOLD_COUNTER 30
static u16 sPokeRideBHoldTimer;
static bool16 sPokeRideBWasPressed;
static bool16 sPokeRideBShortPress;
static bool16 sPokeRideBLongHold;
static bool16 sPokeRideBLongHoldFired;
static void PokeRideUpdateBButton(void);

#include "data/pokeride_info.h"

void SavePokeRideData(struct PokeRide *pokeRide)
{
    memcpy(&gSaveBlock3Ptr->PokeRide, pokeRide, sizeof(struct PokeRide));
}

void LoadPokeRideData(struct PokeRide *pokeRide)
{
    memcpy(pokeRide, &gSaveBlock3Ptr->PokeRide, sizeof(struct PokeRide));
}

void ClearPokeRideData(void)
{
    memset(&gSaveBlock3Ptr->PokeRide, 0, sizeof(gSaveBlock3Ptr->PokeRide));
}

static void ResetRideObject(struct PokeRideObjectEvent* rideObject)
{
    rideObject->isActive = FALSE;
    rideObject->riderObjectEventId = 0;
    rideObject->riderSpriteId = SPRITE_NONE;
    rideObject->monSpriteId = SPRITE_NONE;

    rideObject->state.monGfxId = SPECIES_NONE;
    rideObject->state.desiredMonGfxId = SPECIES_NONE;
    rideObject->state.flyingState = 0;
    rideObject->state.flyingHeight = 0;
}


void PokeRide_Init()
{
    sPokeRideData.rideFrameCounter = 0;
    sPokeRideData.recentRideIndex = 0;
    sPokeRideData.isReady = TRUE;

    struct PokeRideObjectEvent *rideObject = &sPokeRideData.rideObject;
    ResetRideObject(rideObject);
    LoadPokeRideData(&rideObject->state);
    UpdatePlayerRideState();
}

static bool8 IsValidSpeciesToRideNow(u16 species)
{
    return (species != SPECIES_NONE && TestRideFlags(species, POKERIDE_FLAG_CAN_RIDE));
}

static bool8 IsValidMonToRideNow(struct Pokemon* mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    return IsValidSpeciesToRideNow(species);
}

static u8 GetRideOptionCountFor()
{
    return gPlayerPartyCount;
}

static u8 GetRideOptionCount()
{
    return GetRideOptionCountFor();
}

static u16 GetMonGraphicsId(struct Pokemon* mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    bool8 isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
    bool8 isFemale = GetMonGender(mon) == MON_FEMALE;

    u16 graphicsId = species + OBJ_EVENT_MON;
    if (isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;
    if (isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;
    return graphicsId;
}

void SetShadowFieldEffectVisible(struct ObjectEvent *objectEvent, bool8 hideShadow)
{
    if (!hideShadow && objectEvent->noShadow) {
        objectEvent->noShadow = FALSE;
        StartFieldEffectForObjectEvent(FLDEFF_SHADOW, objectEvent);
    }
    else if (hideShadow && !objectEvent->noShadow) {
        objectEvent->noShadow = TRUE;
    }
}

static u8 CreateObjectGraphicsSpriteInObjectEventSpace(u16 graphicsId, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority) {
    u8 spriteId;
    struct Sprite *sprite;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);
    x += MAP_OFFSET;
    y += MAP_OFFSET;
    SetSpritePosToOffsetMapCoords(&x, &y, 8, 16);

    spriteId = CreateObjectGraphicsSprite(graphicsId, callback, x, y, subpriority);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->y += sprite->centerToCornerVecY;

        sprite->coordOffsetEnabled = TRUE;
    }
    return spriteId;
}

static u16 GetRideOptionGfxId(u8 slot)
{
    if (IsValidMonToRideNow(&gPlayerParty[slot]))
        return GetMonGraphicsId(&gPlayerParty[slot]);
    return SPECIES_NONE;
}

static bool8 CalculateRideSpecies(s8 dir)
{
    u8 rideOptionCount = GetRideOptionCount();

    // Loop through mons from last riden
    sPokeRideData.recentRideIndex = min(sPokeRideData.recentRideIndex, rideOptionCount - 1);
    sPokeRideData.rideObject.state.desiredMonGfxId = SPECIES_NONE;

    for (u8 counter = 0; counter < rideOptionCount; ++counter)
    {
        s8 monIdx = sPokeRideData.recentRideIndex;

        if (dir != 0)
            monIdx += (1 + counter) * dir;
        else
            monIdx = counter;

        while(monIdx < 0)
            monIdx += rideOptionCount;

        monIdx %= rideOptionCount;
        u16 rideOptionGfxId = GetRideOptionGfxId(monIdx);

        if (IsValidSpeciesToRideNow(rideOptionGfxId & OBJ_EVENT_MON_SPECIES_MASK))
        {
            sPokeRideData.recentRideIndex = monIdx;
            sPokeRideData.rideObject.state.desiredMonGfxId = rideOptionGfxId;
            return TRUE;
        }
    }

    return FALSE;
}

static bool8 CalculateInitialRideSpecies()
{
    u8 rideOptionCount = GetRideOptionCount();

    sPokeRideData.recentRideIndex = min(sPokeRideData.recentRideIndex, rideOptionCount - 1);

    // Try to ride the same species we were previously riding
    for (u8 counter = 0; counter < rideOptionCount; ++counter)
    {
        u8 monIdx = (sPokeRideData.recentRideIndex + counter) % rideOptionCount;
        u16 rideOptionGfxId = GetRideOptionGfxId(monIdx);

        if (IsValidSpeciesToRideNow(rideOptionGfxId & OBJ_EVENT_MON_SPECIES_MASK))
        {
            sPokeRideData.recentRideIndex = monIdx;
            sPokeRideData.rideObject.state.desiredMonGfxId = rideOptionGfxId;
            return TRUE;
        }
    }

    // Can't ride the mon we were previously riding, so try to pick next avaliable
    return CalculateRideSpecies(0);
}

static void PlayRideMonCry()
{
    if (sPokeRideData.rideObject.state.desiredMonGfxId != sPokeRideData.rideObject.state.monGfxId)
    {
        u16 species = sPokeRideData.rideObject.state.desiredMonGfxId & OBJ_EVENT_MON_SPECIES_MASK;

        if (IsCryPlaying())
            StopCry();
        PlayCry_Normal(species, 0);
    }
}

// Based on GetOnOffBike
void GetOnOffPokeRide()
{
    if (PokeRide_IsRideFlying() || PokeRide_IsRideSwimming())
    {
        // We're not allowed to dismount here
        PlaySE(SE_WALL_HIT);
        return;
    }

    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_RIDING))
    {
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    }
    else
    {
        if (CalculateInitialRideSpecies())
        {
            SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_RIDING);
            PlayRideMonCry();
        }
        else
        {
            PlaySE(SE_FAILURE);
        }
    }
}

static bool8 CanCycleRideMons()
{
    return !PokeRide_IsRideFlying() && !PokeRide_IsRideSwimming();
}


static void PokeRideUpdateBButton(void)
{
    sPokeRideBShortPress = FALSE;

    if (JOY_NEW(B_BUTTON) && (!JOY_HELD(DPAD_DOWN) && !JOY_HELD(DPAD_LEFT) && !JOY_HELD(DPAD_RIGHT) && !JOY_HELD(DPAD_UP)))
    {
        sPokeRideBHoldTimer = 0;
        sPokeRideBWasPressed = TRUE;
        sPokeRideBLongHold = FALSE;
        sPokeRideBLongHoldFired = FALSE;
    }
    if (sPokeRideBWasPressed && JOY_HELD(B_BUTTON) && (!JOY_HELD(DPAD_DOWN) && !JOY_HELD(DPAD_LEFT) && !JOY_HELD(DPAD_RIGHT) && !JOY_HELD(DPAD_UP)))
    {
        if (sPokeRideBHoldTimer < POKERIDE_B_LONG_HOLD_COUNTER)
            sPokeRideBHoldTimer++;
        if ((sPokeRideBHoldTimer >= POKERIDE_B_LONG_HOLD_COUNTER) && (sPokeRideBLongHoldFired == FALSE))
            sPokeRideBLongHold = TRUE;
    }
    if (sPokeRideBWasPressed && !JOY_HELD(B_BUTTON))
    {
        if (sPokeRideBHoldTimer < POKERIDE_B_LONG_HOLD_COUNTER)
            sPokeRideBShortPress = TRUE;

        sPokeRideBHoldTimer = 0;
        sPokeRideBWasPressed = FALSE;    
        sPokeRideBLongHold = FALSE;
        sPokeRideBLongHoldFired = FALSE;
    }
}

bool8 PokeRide_ProcessInput()
{
    if (PokeRide_IsRideActive())
    {
        PokeRideUpdateBButton();

        if (sPokeRideBShortPress)
        {
            GetOnOffPokeRide();
            StartPokeRideUnmountFieldEffect();
            sPokeRideBHoldTimer = 0;
            sPokeRideBWasPressed = FALSE;
            sPokeRideBShortPress = FALSE;
        }
        /*
        // Cycle through mons, when pressing L or R
        if (JOY_NEW(L_BUTTON))
        {
            if (CanCycleRideMons())
            {
                CalculateRideSpecies(-1);
                PlayRideMonCry();
            }
            else
            {
                PlaySE(SE_FAILURE);
            }
        }
        else if (JOY_NEW(R_BUTTON))
        {
            if (CanCycleRideMons())
            {
                CalculateRideSpecies(1);
                PlayRideMonCry();
            }
            else
            {
                PlaySE(SE_FAILURE);
            }
        }*/
    }

    // Never block input from here
    return FALSE;
}

static bool8 ShouldRideMonBeVisible()
{
    return PokeRide_IsRideActive() && !gObjectEvents[gPlayerAvatar.objectEventId].invisible;
}

static void UpdatePlayerRideState()
{
    bool8 wasActive = sPokeRideData.rideObject.isActive;

    // Update player ride state now
    sPokeRideData.rideObject.riderObjectEventId = gPlayerAvatar.objectEventId;
    sPokeRideData.rideObject.riderSpriteId = gPlayerAvatar.spriteId;
    sPokeRideData.rideObject.isActive = ShouldRideMonBeVisible();

    if (sPokeRideData.rideObject.isActive)
    {
        AGB_ASSERT(sPokeRideData.rideObject.state.desiredMonGfxId != SPECIES_NONE);
    }
    else
    {
        sPokeRideData.rideObject.state.monGfxId = SPECIES_NONE;

        if (wasActive)
        {
            // Final update to ensure this sprite is destroyed
            UpdateRideMonSprites(&sPokeRideData.rideObject);
        }
    }
}

bool8 PokeRide_IsActiveObject(u8 objectEventId)
{
    return (gPlayerAvatar.objectEventId == objectEventId
            && sPokeRideData.rideObject.isActive);
}

void PokeRide_OnObjectEventMovement(u8 objectEventId)
{
    AGB_ASSERT(sPokeRideData.isReady);

    if (gPlayerAvatar.objectEventId == objectEventId)
        UpdatePlayerRideState();

    if (sPokeRideData.rideObject.isActive && sPokeRideData.rideObject.riderObjectEventId == objectEventId)
        UpdateRideMonSprites(&sPokeRideData.rideObject);
}

void PokeRide_ResetSprites()
{
    sPokeRideData.rideObject.riderSpriteId = SPRITE_NONE;
    sPokeRideData.rideObject.monSpriteId = SPRITE_NONE;
}

static u16 ToRideSpecies(u16 species)
{
    // If we don't have valid ride flag then check the base mon ride info
    // this handles stuff like arceus and other forms which are very similar
    if (sPokeRideInfo[species].flags & POKERIDE_FLAG_CAN_RIDE)
    {
        return species;
    }

    return GET_BASE_SPECIES_ID(species);
}

static const struct PokeRideInfo* GetPokeRideInfoForSpecies(u16 species)
{
    species = SanitizeSpeciesId(species);

    if (species == SPECIES_NONE)
        return NULL;

    const struct PokeRideInfo* rideInfo = &sPokeRideInfo[ToRideSpecies(species)];

    return rideInfo;
}

static inline bool8 TestRideFlags(u16 species, u8 flags)
{
    const struct PokeRideInfo* rideInfo = GetPokeRideInfoForSpecies(species);

    if (rideInfo == NULL)
        return FALSE;

    return ((rideInfo->flags & flags) == flags);
}

bool8 PokeRide_IsValidRideSpecies(u16 species)
{
    return TestRideFlags(species, POKERIDE_FLAG_CAN_RIDE);
}

bool8 PokeRide_IsValidRideClimbSpecies(u16 species)
{
    return TestRideFlags(species, POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_CLIMB);
}

bool8 PokeRide_IsValidRideSwimSpecies(u16 species)
{
    return TestRideFlags(species, POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_SWIM);
}

bool8 PokeRide_IsValidRideFlySpecies(u16 species)
{
    return TestRideFlags(species, POKERIDE_FLAG_CAN_RIDE | POKERIDE_FLAG_CAN_FLY);
}

// Grabs movement speed based on Base Speed
static u8 CalculateMovementModeFor(u16 species)
{
    u8 speed = sPokeRideInfo[species].rideSpeed;

    if (speed == 1)
        return POKERIDE_MOVEMENT_SLOW;
    if (speed == 3)
        return POKERIDE_MOVEMENT_FAST;
    if (speed == 4)
        return POKERIDE_MOVEMENT_VERY_FAST;
    /*
    if (speed <= 70)
        return POKERIDE_MOVEMENT_SLOW;

    if (speed <= 90)
        return POKERIDE_MOVEMENT_ACCELERATE_AVERAGE;

    if (speed <= 100)
        return POKERIDE_MOVEMENT_AVERAGE;

    if (speed <= 110)
        return POKERIDE_MOVEMENT_ACCELERATE_FAST;
*/
    return POKERIDE_MOVEMENT_AVERAGE;           //ZETA - Default to average speed
}

static u16 GetCurrentRideMonSpecies()
{
    u16 graphicsId = sPokeRideData.rideObject.state.monGfxId;
    u16 species = graphicsId & OBJ_EVENT_MON_SPECIES_MASK;
    return species;
}

static const struct PokeRideInfo* GetCurrentPokeRideInfo()
{
    return GetPokeRideInfoForSpecies(GetCurrentRideMonSpecies());
}

static bool8 IsRideObjectFlying(struct PokeRideObjectEvent* rideObject)
{
    return rideObject->state.flyingState || rideObject->state.flyingHeight != 0;
}

static const struct PokeRideInfo* GetRideObjectPokeRideInfo(struct PokeRideObjectEvent* rideObject)
{
    u16 species = rideObject->state.monGfxId & OBJ_EVENT_MON_SPECIES_MASK;
    return GetPokeRideInfoForSpecies(species);
}

static void UpdateRideMonSprites(struct PokeRideObjectEvent* rideObject)
{
    if (rideObject->isActive)
    {
        AGB_ASSERT(rideObject->state.desiredMonGfxId != SPECIES_NONE);

        if (rideObject->monSpriteId != SPRITE_NONE && rideObject->state.monGfxId != rideObject->state.desiredMonGfxId)
        {
            // Species changed so dealloc sprite ready to make new sprite
            DestroySpriteAndFreeResources(&gSprites[rideObject->monSpriteId]);
            rideObject->monSpriteId = SPRITE_NONE;
        }

        // Alloc sprite
        if (rideObject->monSpriteId == SPRITE_NONE)
        {
            s16 spriteX = gObjectEvents[rideObject->riderObjectEventId].currentCoords.x;
            s16 spriteY = gObjectEvents[rideObject->riderObjectEventId].currentCoords.y;

            rideObject->state.monGfxId = rideObject->state.desiredMonGfxId;
            rideObject->monSpriteId = CreateObjectGraphicsSpriteInObjectEventSpace(rideObject->state.monGfxId, SpriteCallbackDummy, spriteX, spriteY, 0);

            UpdatePokeRideOnSpawn(&gObjectEvents[rideObject->riderObjectEventId], &gSprites[rideObject->riderSpriteId]);
            gSprites[rideObject->monSpriteId].oam.priority = 2;
            StartSpriteAnim(&gSprites[rideObject->monSpriteId], ANIM_STD_GO_SOUTH);

            // Handle returning to the screen after flying
            if (IsRideObjectFlying(rideObject))
            {
                SetShadowFieldEffectVisible(&gObjectEvents[rideObject->riderObjectEventId], TRUE);
                gObjectEvents[rideObject->riderObjectEventId].hideReflection = TRUE;
            }
        }

        if (rideObject->monSpriteId != SPRITE_NONE)
        {
            const struct PokeRideInfo* rideInfo = GetRideObjectPokeRideInfo(rideObject);

            if (rideInfo != NULL)
            {
                UpdateRideSpriteInternal(rideObject, rideInfo);
            }
        }
    }
    else
    {
        // Dealloc sprite
        if (rideObject->monSpriteId != SPRITE_NONE)
        {
            DestroySpriteAndFreeResources(&gSprites[rideObject->monSpriteId]);
            rideObject->monSpriteId = SPRITE_NONE;
            rideObject->riderObjectEventId = OBJECT_EVENTS_COUNT;
        }
    }

    if (rideObject->monSpriteId != SPRITE_NONE)
        SavePokeRideData(&rideObject->state);
    else
        ClearPokeRideData();
}

void PokeRide_OnWarp()
{
    if (PokeRide_IsRideFlying())
    {
        // Instantly snap to ground
        struct PokeRideObjectEvent *rideObject = &sPokeRideData.rideObject;
        rideObject->state.flyingState = FALSE;
        rideObject->state.flyingHeight = 0;
        // Prevent saving outdated data. Probably not necessary.
        SavePokeRideData(&rideObject->state);
        AdjustFlyingAnimation(rideObject);
    }
}

u8 PokeRide_GetMonSpriteId(struct ObjectEvent* objectEvent)
{
    if (objectEvent->localId == OBJ_EVENT_ID_PLAYER)
    {
        return sPokeRideData.rideObject.monSpriteId;
    }

    return SPRITE_NONE;
}

bool8 PokeRide_CanRideInvJumpLedge()
{
    return (
        FlagGet(FLAG_SYS_POKERIDE_JUMP)
        && TestRideFlags(GetCurrentRideMonSpecies(), POKERIDE_FLAG_CAN_CLIMB)
    );
}

bool8 PokeRide_CanRideSwim()
{
    return (
        FlagGet(FLAG_SYS_POKERIDE_SURF)
        && TestRideFlags(GetCurrentRideMonSpecies(), POKERIDE_FLAG_CAN_SWIM)
    );
}

bool8 PokeRide_CanRideFly()
{
    return (
        FlagGet(FLAG_SYS_POKERIDE_FLY)
        && TestRideFlags(GetCurrentRideMonSpecies(), POKERIDE_FLAG_CAN_FLY)
    );
}

bool8 PokeRide_IsRideActive()
{
    return TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_RIDING);
}

bool8 PokeRide_IsRideSwimming()
{
    if (PokeRide_IsRideActive())
    {
        s16 x, y;
        u16 tileBehavior;

        if (PokeRide_IsRideFlying())
            return FALSE;

        PlayerGetDestCoords(&x, &y);
        tileBehavior = MapGridGetMetatileBehaviorAt(x, y);

        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior) && !MapGridGetCollisionAt(x, y))
            return TRUE;
        if (MetatileBehavior_IsBridgeOverWaterNoEdge(tileBehavior) == TRUE)
            return TRUE;
    }

    return FALSE;
}

bool8 PokeRide_IsRideFlying()
{
    if (PokeRide_IsRideActive())
    {
        return IsRideObjectFlying(&sPokeRideData.rideObject);
    }

    return FALSE;
}

bool8 PokeRide_IsRideCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider)
{
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (PokeRide_IsRideFlying())
        return (obstacle == player || collider == player);

    return FALSE;
}

static void UpdateRideSpriteInternal(struct PokeRideObjectEvent* rideObject, const struct PokeRideInfo* rideInfo)
{
    s8 xFlip;
    const struct PokeRideSpriteInfo* rideSpriteInfo;
    struct Sprite* mountSprite = &gSprites[rideObject->monSpriteId];
    struct Sprite* riderSprite = &gSprites[rideObject->riderSpriteId];
    s16 bobbingAnim = ((mountSprite->animCmdIndex % 2) ? 0 : -1);
    u8 facingDirection = gObjectEvents[rideObject->riderObjectEventId].facingDirection;
    u16 species = rideObject->state.monGfxId & OBJ_EVENT_MON_SPECIES_MASK;
    u8 rideSpeed;

    rideSpeed = CalculateMovementModeFor(species);

    AGB_ASSERT(rideObject->monSpriteId != SPRITE_NONE);
    AGB_ASSERT(rideObject->riderSpriteId != SPRITE_NONE);

    // Fix stairs directions
    switch (facingDirection)
    {
    case DIR_SOUTHWEST:
    case DIR_NORTHWEST:
        facingDirection = DIR_WEST;
        break;

    case DIR_SOUTHEAST:
    case DIR_NORTHEAST:
        facingDirection = DIR_EAST;
        break;
    }

    switch (facingDirection)
    {
    case DIR_NORTH:
        xFlip = 1;
        rideSpriteInfo = &rideInfo->spriteInfo[POKERIDE_SPRITE_UP];
        break;

    case DIR_EAST:
        xFlip = 1;
        rideSpriteInfo = &rideInfo->spriteInfo[POKERIDE_SPRITE_SIDE];
        break;

    case DIR_SOUTH:
        xFlip = 1;
        rideSpriteInfo = &rideInfo->spriteInfo[POKERIDE_SPRITE_DOWN];
        break;

    case DIR_WEST:
    default:
        xFlip = -1;
        rideSpriteInfo = &rideInfo->spriteInfo[POKERIDE_SPRITE_SIDE];
        break;
    };

    {
        u16 idleAnim = ANIM_STD_FACE_SOUTH;
        u16 movingAnim = ANIM_STD_FACE_SOUTH;

        if (rideSpeed <= POKERIDE_MOVEMENT_ACCELERATE_AVERAGE) {
            idleAnim = ANIM_STD_FACE_SOUTH;
            movingAnim = ANIM_STD_GO_SOUTH;
        }

        if (rideSpeed > POKERIDE_MOVEMENT_ACCELERATE_AVERAGE)
        {
            idleAnim = ANIM_STD_GO_SOUTH;
            movingAnim = ANIM_STD_GO_SOUTH;
        }

        if (rideSpeed == POKERIDE_MOVEMENT_FAST)
        {
            movingAnim = ANIM_STD_GO_FAST_SOUTH;
        }

        if (rideObject->state.flyingHeight != 0)
        {
            // Increase anims by a phase so it's faster when in the air
            idleAnim += 4;
            movingAnim = idleAnim;
        }

        switch (gObjectEvents[rideObject->riderObjectEventId].movementActionId)
        {
        case MOVEMENT_ACTION_FACE_DOWN:
        case MOVEMENT_ACTION_FACE_UP:
        case MOVEMENT_ACTION_FACE_LEFT:
        case MOVEMENT_ACTION_FACE_RIGHT:
            StartSpriteAnimIfDifferent(mountSprite, idleAnim + facingDirection - DIR_SOUTH);
            //riderSprite->x2 = 0;
            //riderSprite->y2 = 0;
            break;

        case MOVEMENT_ACTION_JUMP_2_DOWN:
        case MOVEMENT_ACTION_JUMP_2_UP:
        case MOVEMENT_ACTION_JUMP_2_LEFT:
        case MOVEMENT_ACTION_JUMP_2_RIGHT:
        case MOVEMENT_ACTION_JUMP_DOWN:
        case MOVEMENT_ACTION_JUMP_UP:
        case MOVEMENT_ACTION_JUMP_LEFT:
        case MOVEMENT_ACTION_JUMP_RIGHT:
            StartSpriteAnimIfDifferent(mountSprite, idleAnim + facingDirection - DIR_SOUTH);
            // Don't reset xy2 for these movement actions
            break;

        case MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN:
        case MOVEMENT_ACTION_JUMP_IN_PLACE_UP:
        case MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT:
        case MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT:
        case MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN_UP:
        case MOVEMENT_ACTION_JUMP_IN_PLACE_UP_DOWN:
        case MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT_RIGHT:
        case MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT_LEFT:
            StartSpriteAnimIfDifferent(mountSprite, idleAnim + facingDirection - DIR_SOUTH);
            // Don't reset xy2 for these movement actions
            break;

        default:
            StartSpriteAnimIfDifferent(mountSprite, movingAnim + facingDirection - DIR_SOUTH);
            break;
        }
    }

    // Move mount sprite
    mountSprite->x = riderSprite->x;
    mountSprite->y = riderSprite->y;
    mountSprite->x2 = riderSprite->x2 + rideSpriteInfo->monX * xFlip;
    mountSprite->y2 = riderSprite->y2 + rideSpriteInfo->monY + bobbingAnim;

    mountSprite->subpriority = riderSprite->subpriority;

    mountSprite->oam.x = riderSprite->oam.x;
    mountSprite->oam.y = riderSprite->oam.y;
    mountSprite->oam.priority = riderSprite->oam.priority;

    if (rideSpriteInfo->playerRendersInFront)
        mountSprite->subpriority = riderSprite->subpriority + 1;
    else if (riderSprite->subpriority != 0)
        mountSprite->subpriority = riderSprite->subpriority - 1;

    // Move player
    riderSprite->x2 += rideSpriteInfo->playerX * xFlip;
    riderSprite->y2 += rideSpriteInfo->playerY + bobbingAnim;

    // Offset both for flying anim
    if (rideObject->state.flyingHeight != 0)
    {
        riderSprite->y2 -= rideObject->state.flyingHeight;
        mountSprite->y2 -= rideObject->state.flyingHeight;
    }
}

//
// Movement code
//

static u8 CheckMovementInputOnRideMon(u8 direction);
static void PlayerOnRideMonNotMoving(u8 direction, u16, u16);
static void PlayerOnRideMonTurningInPlace(u8 direction, u16, u16);
static void PlayerOnRideMonMoving(u8 direction, u16, u16);

static bool8 PlayerOnRideMonAdjustFlyingState(u8 direction, u16, u16);

static u8 CheckForPlayerAvatarCollision(u8 direction);
static u8 CheckForPlayerLandingCollision();
static void PlayerOnRideMonCollide(u8 direction);
static void PlayCollisionSoundIfNotFacingWarp(u8 direction);

static void (*const sPlayerOnRideMonFuncs[])(u8 direction, u16, u16) =
{
    [NOT_MOVING]     = PlayerOnRideMonNotMoving,
    [TURN_DIRECTION] = PlayerOnRideMonTurningInPlace,
    [MOVING]         = PlayerOnRideMonMoving,
};

static bool8 (*const sArrowWarpMetatileBehaviorChecks3[])(u8) =  //Duplicate of sArrowWarpMetatileBehaviorChecks
{
    [DIR_SOUTH - 1] = MetatileBehavior_IsSouthArrowWarp,
    [DIR_NORTH - 1] = MetatileBehavior_IsNorthArrowWarp,
    [DIR_WEST - 1]  = MetatileBehavior_IsWestArrowWarp,
    [DIR_EAST - 1]  = MetatileBehavior_IsEastArrowWarp,
};

void MovePlayerOnPokeRide(u8 direction, u16 newKeys, u16 heldKeys)
{
    AGB_ASSERT(sPokeRideData.isReady);

    if (PlayerOnRideMonAdjustFlyingState(direction, newKeys, heldKeys))
        return;

    if (PokeRide_IsRideFlying())
    {
        SetShadowFieldEffectVisible(&gObjectEvents[gPlayerAvatar.objectEventId], TRUE);
        gObjectEvents[gPlayerAvatar.objectEventId].hideReflection = TRUE;
    }

    sPlayerOnRideMonFuncs[CheckMovementInputOnRideMon(direction)](direction, newKeys, heldKeys);
}

static u8 CheckMovementInputOnRideMon(u8 direction)
{
    if (direction == DIR_NONE)
        return gPlayerAvatar.runningState = NOT_MOVING;
    else if (direction != GetPlayerMovementDirection() && gPlayerAvatar.runningState != MOVING)
        return gPlayerAvatar.runningState = TURN_DIRECTION;
    else
        return gPlayerAvatar.runningState = MOVING;
}

static void PlayerOnRideMonNotMoving(u8 direction, u16 newKeys, u16 heldKeys)
{
    if ((!JOY_HELD(DPAD_DOWN) && !JOY_HELD(DPAD_LEFT) && !JOY_HELD(DPAD_RIGHT) && !JOY_HELD(DPAD_UP) && sPokeRideBLongHold)
         && (PokeRide_IsRideFlying() || PokeRide_CanRideFly()))
    {
        // Toggle between flying modes
        bool8 desiredFlyState = !sPokeRideData.rideObject.state.flyingState;
        sPokeRideBLongHold = FALSE;
        sPokeRideBLongHoldFired = TRUE;

        if (!desiredFlyState && CheckForPlayerLandingCollision())
        {
            // We're not allowed to land here
            PlaySE(SE_FAILURE);
            return;
        }

        sPokeRideData.rideObject.state.flyingState = desiredFlyState;
        PlaySE(sPokeRideData.rideObject.state.flyingState ? SE_M_FLY : SE_M_WING_ATTACK);
    }
    else
    {
        sPokeRideData.rideFrameCounter = 0;
        PlayerFaceDirection(GetPlayerFacingDirection());
    }
}

static void PlayerOnRideMonTurningInPlace(u8 direction, u16 newKeys, u16 heldKeys)
{
    PlayerTurnInPlace(direction);
}

static void PlayerJumpLedgeShort(u8 direction)
{
    PlaySE(SE_LEDGE);
    PlayerSetAnimId(GetJumpMovementAction(direction), COPY_MOVE_JUMP);
}

static void PlayerOnRideMonMoving(u8 direction, u16 newKeys, u16 heldKeys)
{
    u8 collision = CheckForPlayerAvatarCollision(direction);
    const struct PokeRideInfo* rideInfo = GetCurrentPokeRideInfo();

    if (rideInfo != NULL)
    {
        u8 frameIdx;

        if (collision == COLLISION_START_SWIMMING || collision == COLLISION_STOP_SWIMMING)
        {
            if (PokeRide_IsRideFlying())
            {
                collision = COLLISION_NONE;
            }
        }

        if (collision)
        {
            sPokeRideData.rideFrameCounter = 0;

            if (collision == COLLISION_START_SWIMMING || collision == COLLISION_STOP_SWIMMING)
            {
                PlayerJumpLedgeShort(direction);
            }
            else if (collision == COLLISION_LEDGE_JUMP)
            {
                PlayerJumpLedge(direction);
            }
            else
            {
                u8 adjustedCollision = collision - COLLISION_STOP_SURFING;
                if (adjustedCollision > 3)
                    PlayerOnRideMonCollide(direction);
            }

            return;
        }

        // MOVE_SPEED_NORMAL     walking                                   PlayerWalkNormal
        // MOVE_SPEED_FAST_1     running / surfing / sliding (ice tile)    PlayerWalkFast
        // MOVE_SPEED_FAST_2     water current / acro bike                 PlayerRideWaterCurrent
        // MOVE_SPEED_FASTER     mach bike's max speed                     PlayerWalkFaster
        // MOVE_SPEED_FASTEST                                              ??

        switch (CalculateMovementModeFor(GetCurrentRideMonSpecies()))
        {
            case POKERIDE_MOVEMENT_SLOW:        //ZETA - Very slow pokemon have slow speed (dexnav creep/sneak speed), holding B to dash does normal walk speed
            {
                if (JOY_HELD(B_BUTTON))
                    PlayerWalkNormal(direction);
                else
                    PlayerWalkSlow(direction);
                break;
            }
/*
            case POKERIDE_MOVEMENT_ACCELERATE_AVERAGE:
                frameIdx = sPokeRideData.rideFrameCounter / 4;

                if (sPokeRideData.rideFrameCounter == 0)
                    PlayerWalkNormal(direction);
                else if (frameIdx == 0)
                    PlayerWalkFast(direction);
                else
                    PlayerRideWaterCurrent(direction);
                break;*/

        case POKERIDE_MOVEMENT_FAST:        //ZETA - Hold B to Acro Bike speed, else do walk speed
            {
                if (JOY_HELD(B_BUTTON))
                    PlayerRideWaterCurrent(direction);
                else
                    PlayerWalkNormal(direction);
                break;
            }
/*
        case POKERIDE_MOVEMENT_ACCELERATE_FAST:
            frameIdx = (sPokeRideData.rideFrameCounter - 1) / 3;

            if (sPokeRideData.rideFrameCounter == 0)
                PlayerWalkFast(direction);
            else if (frameIdx == 0)
                PlayerRideWaterCurrent(direction);
            else
                PlayerWalkFaster(direction);
            break;*/

         case POKERIDE_MOVEMENT_VERY_FAST:
            {
                if (JOY_HELD(B_BUTTON))     //ZETA - Mach Bike speed when holding B to dash, otherwise do running speed
                {
                    frameIdx = (sPokeRideData.rideFrameCounter - 1) / 3;
                    if (sPokeRideData.rideFrameCounter == 0)
                        PlayerWalkFast(direction);
                    else if (frameIdx == 0)
                        PlayerRideWaterCurrent(direction);
                    else
                        PlayerWalkFaster(direction);
                }
                else
                    PlayerWalkFast(direction);
                break;
            }

        default:
        case POKERIDE_MOVEMENT_AVERAGE:        //ZETA - hold B to dash (running speed), else do normal walk speed
            {
                if (JOY_HELD(B_BUTTON))
                    PlayerWalkFast(direction);
                else
                    PlayerWalkNormal(direction);
                break;
            }
            break;
        }

        if (sPokeRideData.rideFrameCounter < 255)
            ++sPokeRideData.rideFrameCounter;
    }
}

static bool8 PlayerOnRideMonAdjustFlyingState(u8 direction, u16 newKeys, u16 heldKeys)
{
    return AdjustFlyingAnimation(&sPokeRideData.rideObject);
}

static bool8 AdjustFlyingAnimation(struct PokeRideObjectEvent* rideObject)
{
    AGB_ASSERT(rideObject->riderObjectEventId != OBJECT_EVENTS_COUNT);

    if (rideObject->state.flyingState)
    {
        if (rideObject->state.flyingHeight < POKERIDE_FLY_HEIGHT)
        {
            if (rideObject->state.flyingHeight == 0)
            {
                SetShadowFieldEffectVisible(&gObjectEvents[rideObject->riderObjectEventId], TRUE);
                gObjectEvents[rideObject->riderObjectEventId].hideReflection = TRUE;
            }

            ++rideObject->state.flyingHeight;
            return TRUE;
        }
    }
    else
    {
        if (rideObject->state.flyingHeight > 0)
        {
            --rideObject->state.flyingHeight;

            if (rideObject->state.flyingHeight == 0)
            {
                SetShadowFieldEffectVisible(&gObjectEvents[rideObject->riderObjectEventId], FALSE);
                gObjectEvents[rideObject->riderObjectEventId].hideReflection = FALSE;
            }
            return TRUE;
        }
    }

    return FALSE;
}

static u8 CheckForPlayerAvatarCollision(u8 direction)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return CheckForObjectEventCollision(playerObjEvent, x, y, direction, MapGridGetMetatileBehaviorAt(x, y));
}

static bool8 AreElevationsCompatible(u8 a, u8 b)
{
    if (a == 0 || b == 0)
        return TRUE;

    if (a != b)
        return FALSE;

    return TRUE;
}

static bool8 CheckNonPlayerObjectAt(struct ObjectEvent *playerObjEvent, s16 x, s16 y)
{
    struct ObjectEvent *curObject;

    for (u8 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        curObject = &gObjectEvents[i];
        if (curObject->active && curObject != playerObjEvent)
        {
            // Check for collision if curObject is active, not the object in question, and not exempt from collisions
            if ((curObject->currentCoords.x == x && curObject->currentCoords.y == y) || (curObject->previousCoords.x == x && curObject->previousCoords.y == y))
            {
                if (AreElevationsCompatible(playerObjEvent->currentElevation, curObject->currentElevation))
                    return TRUE;
            }
        }
    }
    return FALSE;
}

static u8 CheckForPlayerLandingCollision()
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;

    if (MapGridGetCollisionAt(x, y))
    {
        return TRUE;
    }

    if (!PokeRide_CanRideSwim())
    {
        u32 tileBehaviour = MapGridGetMetatileBehaviorAt(x, y);

        // Can't land on water
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehaviour))
            return TRUE;
    }

    if (CheckNonPlayerObjectAt(playerObjEvent, x, y))
    {
        return TRUE;
    }

    return FALSE;
}

static void PlayerOnRideMonCollide(u8 direction)
{
    sPokeRideData.rideFrameCounter = 0;

    PlayCollisionSoundIfNotFacingWarp(direction);
    PlayerSetAnimId(GetWalkInPlaceSlowMovementAction(direction), COPY_MOVE_WALK);
}

static void PlayCollisionSoundIfNotFacingWarp(u8 direction)
{
    s16 x, y;
    u8 metatileBehavior = gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior;

    if (!sArrowWarpMetatileBehaviorChecks3[direction - 1](metatileBehavior))
    {
        // Check if walking up into a door
        if (direction == DIR_NORTH)
        {
            PlayerGetDestCoords(&x, &y);
            MoveCoords(direction, &x, &y);
            if (MetatileBehavior_IsWarpDoor(MapGridGetMetatileBehaviorAt(x, y)))
                return;
        }
        PlaySE(SE_WALL_HIT);
    }
}

void CheckFollowerFriendship(void)
{
    gSpecialVar_Result = GetMonData(&gPlayerParty[GetFollowerMonIndex()], MON_DATA_FRIENDSHIP);
}

void FollowerSpeciesCanRide(void)
{
    if ((sPokeRideInfo[GetMonData(&gPlayerParty[GetFollowerMonIndex()], MON_DATA_SPECIES)].flags & POKERIDE_FLAG_CAN_RIDE))
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

