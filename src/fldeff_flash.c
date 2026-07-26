#include "global.h"
#include "braille_puzzles.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "fldeff.h"
#include "gpu_regs.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "overworld.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/abilities.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/map_types.h"

struct FlashStruct
{
    u8 fromType;
    u8 toType;
    bool8 isEnter;
    bool8 isExit;
    void (*func)(void);
};

static void FieldCallback_Flash(void);
static void FldEff_UseFlash(void);
static bool8 TryDoMapTransition(void);
static void DoExitCaveTransition(void);
static void Task_ExitCaveTransition1(u8 taskId);
static void Task_ExitCaveTransition2(u8 taskId);
static void Task_ExitCaveTransition3(u8 taskId);
static void Task_ExitCaveTransition4(u8 taskId);
static void Task_ExitCaveTransition5(u8 taskId);
static void DoEnterCaveTransition(void);
static void Task_EnterCaveTransition1(u8 taskId);
static void Task_EnterCaveTransition2(u8 taskId);
static void Task_EnterCaveTransition3(u8 taskId);
static void Task_EnterCaveTransition4(u8 taskId);

static const struct FlashStruct sTransitionTypes[] =
{
    {MAP_TYPE_TOWN,        MAP_TYPE_UNDERGROUND,  TRUE, FALSE, DoEnterCaveTransition},
    {MAP_TYPE_CITY,        MAP_TYPE_UNDERGROUND,  TRUE, FALSE, DoEnterCaveTransition},
    {MAP_TYPE_ROUTE,       MAP_TYPE_UNDERGROUND,  TRUE, FALSE, DoEnterCaveTransition},
    {MAP_TYPE_UNDERWATER,  MAP_TYPE_UNDERGROUND,  TRUE, FALSE, DoEnterCaveTransition},
    {MAP_TYPE_OCEAN_ROUTE, MAP_TYPE_UNDERGROUND,  TRUE, FALSE, DoEnterCaveTransition},
    {MAP_TYPE_UNKNOWN,     MAP_TYPE_UNDERGROUND,  TRUE, FALSE, DoEnterCaveTransition},
    {MAP_TYPE_INDOOR,      MAP_TYPE_UNDERGROUND,  TRUE, FALSE, DoEnterCaveTransition},
    {MAP_TYPE_SECRET_BASE, MAP_TYPE_UNDERGROUND,  TRUE, FALSE, DoEnterCaveTransition},
    {MAP_TYPE_UNDERGROUND, MAP_TYPE_TOWN,        FALSE,  TRUE, DoExitCaveTransition},
    {MAP_TYPE_UNDERGROUND, MAP_TYPE_CITY,        FALSE,  TRUE, DoExitCaveTransition},
    {MAP_TYPE_UNDERGROUND, MAP_TYPE_ROUTE,       FALSE,  TRUE, DoExitCaveTransition},
    {MAP_TYPE_UNDERGROUND, MAP_TYPE_UNDERWATER,  FALSE,  TRUE, DoExitCaveTransition},
    {MAP_TYPE_UNDERGROUND, MAP_TYPE_OCEAN_ROUTE, FALSE,  TRUE, DoExitCaveTransition},
    {MAP_TYPE_UNDERGROUND, MAP_TYPE_UNKNOWN,     FALSE,  TRUE, DoExitCaveTransition},
    {MAP_TYPE_UNDERGROUND, MAP_TYPE_INDOOR,      FALSE,  TRUE, DoExitCaveTransition},
    {MAP_TYPE_UNDERGROUND, MAP_TYPE_SECRET_BASE, FALSE,  TRUE, DoExitCaveTransition},
    {},
};

static const u16 sCaveTransitionPalette_White[] = INCBIN_U16("graphics/cave_transition/white.gbapal");
static const u16 sCaveTransitionPalette_Black[] = INCBIN_U16("graphics/cave_transition/black.gbapal");

static const u16 sCaveTransitionPalette_Enter[] = INCBIN_U16("graphics/cave_transition/enter.gbapal");

static const u32 sCaveTransitionTilemap[] = INCBIN_U32("graphics/cave_transition/tilemap.bin.lz");
static const u32 sCaveTransitionTiles[] = INCBIN_U32("graphics/cave_transition/tiles.4bpp.lz");

static bool8 MoveHasBonusRadius(u16 moveId)
{
    switch (moveId)
    {
    case MOVE_FLASH:
    case MOVE_DAZZLING_GLEAM:
    case MOVE_FLASH_CANNON:
    case MOVE_PHOTON_GEYSER:
    case MOVE_PRISMATIC_LASER:
    case MOVE_LUSTER_PURGE:
    case MOVE_TAIL_GLOW:
    case MOVE_SUNSTEEL_STRIKE:
    case MOVE_LIGHT_OF_RUIN:
    case MOVE_BLUE_FLARE:
    case MOVE_BURN_UP:
    case MOVE_LAVA_PLUME:
        return TRUE;
    default:
        return FALSE;
    }
}

bool8 SetUpFieldMove_Flash(void)
{
    u16 moveId = VarGet(VAR_0x8008);
    // In Ruby and Sapphire, Registeel's tomb is opened by using Fly. In Emerald,
    // Flash is used instead.
    if (ShouldDoBrailleRegisteelEffect())
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = SetUpPuzzleEffectRegisteel;
        return TRUE;
    }
    else if (gMapHeader.cave == TRUE && !FlagGet(FLAG_SYS_USE_FLASH)/* && (gSaveBlock1Ptr->flashLevel > 1)*/)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Flash;
        if (MoveHasBonusRadius(moveId))
            FlagSet(FLAG_SYS_USE_FLASH_MOVE_BONUS);
        return TRUE;
    }
    else if (gMapHeader.cave == TRUE && (FlagGet(FLAG_SYS_USE_FLASH)) && (!FlagGet(FLAG_SYS_USE_FLASH_MOVE_BONUS)) && (MoveHasBonusRadius(moveId))) //Allow boosted flash moves to be used even if flash is already set
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Flash;
        FlagSet(FLAG_SYS_USE_FLASH_MOVE_BONUS);
        return TRUE;
    }
    return FALSE;
}

static void FieldCallback_Flash(void)
{
    u8 taskId = CreateFieldMoveTask();
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    gTasks[taskId].data[8] = (uintptr_t)FldEff_UseFlash >> 16;
    gTasks[taskId].data[9] = (uintptr_t)FldEff_UseFlash;
}

static void FldEff_UseFlash(void)
{
    FlagSet(FLAG_SYS_USE_FLASH);
	//FlagClear(FLAG_SYS_BONUS_FLASH);													//ZETA- Follower flag is mutually exclusive and cannot be re-set from followers while field move is active
	DoFieldMoveFriendshipChance(&gPlayerParty[GetCursorSelectionMonId()]);
	if (GetMonAbility(&gPlayerParty[GetCursorSelectionMonId()]) == ABILITY_ILLUMINATE)
		FlagSet(FLAG_SYS_BONUS_FLASH);												//ZETA- repurpose follower flag for boosted field move, max flash radius only achieved if ability == illuminate
    VarSet(VAR_0x8007, GetCursorSelectionMonId());
	ScriptContext_SetupScript(EventScript_UseFlash);
}

static void CB2_ChangeMapMain(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBC_ChangeMapVBlank(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_DoChangeMap(void)
{
    u16 ime;

    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
    ResetPaletteFade();
    ResetTasks();
    ResetSpriteData();
    ime = REG_IME;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_VBLANK;
    REG_IME = ime;
    SetVBlankCallback(VBC_ChangeMapVBlank);
    SetMainCallback2(CB2_ChangeMapMain);
    if (!TryDoMapTransition())
        SetMainCallback2(gMain.savedCallback);
}

static bool8 TryDoMapTransition(void)
{
    u8 i;
    u8 fromType = GetLastUsedWarpMapType();
    u8 toType = GetCurrentMapType();

    for (i = 0; sTransitionTypes[i].fromType; i++)
    {
        if (sTransitionTypes[i].fromType == fromType && sTransitionTypes[i].toType == toType)
        {
            sTransitionTypes[i].func();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 GetMapPairFadeToType(u8 _fromType, u8 _toType)
{
    u8 i;
    u8 fromType = _fromType;
    u8 toType = _toType;

    for (i = 0; sTransitionTypes[i].fromType; i++)
    {
        if (sTransitionTypes[i].fromType == fromType && sTransitionTypes[i].toType == toType)
        {
            return sTransitionTypes[i].isEnter;
        }
    }

    return FALSE;
}

bool8 GetMapPairFadeFromType(u8 _fromType, u8 _toType)
{
    u8 i;
    u8 fromType = _fromType;
    u8 toType = _toType;

    for (i = 0; sTransitionTypes[i].fromType; i++)
    {
        if (sTransitionTypes[i].fromType == fromType && sTransitionTypes[i].toType == toType)
        {
            return sTransitionTypes[i].isExit;
        }
    }

    return FALSE;
}

static void DoExitCaveTransition(void)
{
    CreateTask(Task_ExitCaveTransition1, 0);
}

static void Task_ExitCaveTransition1(u8 taskId)
{
    gTasks[taskId].func = Task_ExitCaveTransition2;
}

static void Task_ExitCaveTransition2(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    LZ77UnCompVram(sCaveTransitionTiles, (void *)(VRAM + 0xC000));
    LZ77UnCompVram(sCaveTransitionTilemap, (void *)(VRAM + 0xF800));
    LoadPalette(sCaveTransitionPalette_White, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadPalette(&sCaveTransitionPalette_Enter[8], BG_PLTT_ID(14), PLTT_SIZEOF(8));
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0
                                | BLDCNT_EFFECT_BLEND
                                | BLDCNT_TGT2_BG1
                                | BLDCNT_TGT2_BG2
                                | BLDCNT_TGT2_BG3
                                | BLDCNT_TGT2_OBJ
                                | BLDCNT_TGT2_BD);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(3)
                               | BGCNT_SCREENBASE(31)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_OBJ_ON);
    gTasks[taskId].func = Task_ExitCaveTransition3;
    gTasks[taskId].data[0] = 16;
    gTasks[taskId].data[1] = 0;
}

static void Task_ExitCaveTransition3(u8 taskId)
{
    u16 count = gTasks[taskId].data[1];
    u16 blend = count + 0x1000;

    SetGpuReg(REG_OFFSET_BLDALPHA, blend);
    if (count <= 16)
    {
        gTasks[taskId].data[1]++;
    }
    else
    {
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].func = Task_ExitCaveTransition4;
    }
}

static void Task_ExitCaveTransition4(u8 taskId)
{
    u16 count;

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 16));
    count = gTasks[taskId].data[2];

    if (count < 8)
    {
        gTasks[taskId].data[2]++;
        LoadPalette(&sCaveTransitionPalette_Enter[8 + count], BG_PLTT_ID(14), PLTT_SIZEOF(8) - PLTT_SIZEOF(count));
    }
    else
    {
        LoadPalette(sCaveTransitionPalette_White, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        gTasks[taskId].func = Task_ExitCaveTransition5;
        gTasks[taskId].data[2] = 8;
    }
}

static void Task_ExitCaveTransition5(u8 taskId)
{
    if (gTasks[taskId].data[2])
        gTasks[taskId].data[2]--;
    else
        SetMainCallback2(gMain.savedCallback);
}

static void DoEnterCaveTransition(void)
{
    CreateTask(Task_EnterCaveTransition1, 0);
}

static void Task_EnterCaveTransition1(u8 taskId)
{
    gTasks[taskId].func = Task_EnterCaveTransition2;
}

static void Task_EnterCaveTransition2(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    LZ77UnCompVram(sCaveTransitionTiles, (void *)(VRAM + 0xC000));
    LZ77UnCompVram(sCaveTransitionTilemap, (void *)(VRAM + 0xF800));
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(3)
                               | BGCNT_SCREENBASE(31)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_OBJ_ON);
    LoadPalette(sCaveTransitionPalette_White, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadPalette(sCaveTransitionPalette_Black, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    gTasks[taskId].func = Task_EnterCaveTransition3;
    gTasks[taskId].data[0] = 16;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0;
}

static void Task_EnterCaveTransition3(u8 taskId)
{
    u16 count = gTasks[taskId].data[2];

    if (count < 16)
    {
        gTasks[taskId].data[2]++;
        gTasks[taskId].data[2]++;
        LoadPalette(&sCaveTransitionPalette_Enter[15 - count], BG_PLTT_ID(14), PLTT_SIZEOF(count + 1));
    }
    else
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 16));
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0
                                    | BLDCNT_EFFECT_BLEND
                                    | BLDCNT_TGT2_BG1
                                    | BLDCNT_TGT2_BG2
                                    | BLDCNT_TGT2_BG3
                                    | BLDCNT_TGT2_OBJ
                                    | BLDCNT_TGT2_BD);
        gTasks[taskId].func = Task_EnterCaveTransition4;
    }
}

static void Task_EnterCaveTransition4(u8 taskId)
{
    u16 count = 16 - gTasks[taskId].data[1];
    u16 blend = count + 0x1000;

    SetGpuReg(REG_OFFSET_BLDALPHA, blend);
    if (count)
    {
        gTasks[taskId].data[1]++;
    }
    else
    {
        LoadPalette(sCaveTransitionPalette_Black, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        SetMainCallback2(gMain.savedCallback);
    }
}

extern const struct BlendSettings gCustomDNSTintBlend[];
#define FLASH_LEVEL_DEFAULT 7

void UpdateFlashTint(void)
{
    if (!gMapHeader.cave)
		return;
    
    u16 flashTrackerPacked = VarGet(VAR_FLASH_TRACKER_PACKED);
    u8 followerTint = GET_FOLLOWER_TINT(flashTrackerPacked);
    u8 moveTint = GET_MOVE_TINT(flashTrackerPacked);

	u8 followerIndex = GetFollowerMonIndex();
	s32 previousFlashLevel = gSaveBlock1Ptr->flashLevel;
	s32 newFlashLevel;
	
    s8 followerFlashLevel = gSpeciesInfo[GetMonData(&gPlayerParty[followerIndex], MON_DATA_SPECIES)].flashLevel;
    u8 followerFlashTint = gSpeciesInfo[GetMonData(&gPlayerParty[followerIndex], MON_DATA_SPECIES)].flashTint;
    u8 followerFlashTintShiny = gSpeciesInfo[GetMonData(&gPlayerParty[followerIndex], MON_DATA_SPECIES)].flashTintShiny;
    u8 currentFlashTint = followerTint;
    u8 newFlashTint = 1;
    

    //Get Flash DNS Tint
    if (GetMonData(&gPlayerParty[followerIndex], MON_DATA_IS_SHINY) && followerFlashTintShiny > 0)
        newFlashTint = followerFlashTintShiny;
    else if (followerFlashTint > 0)
        newFlashTint = followerFlashTint;
    else if (FlagGet(FLAG_SYS_USE_FLASH))
        newFlashTint = DNS_BLEND_CAVE_STANDARD;
    else
        newFlashTint = DNS_BLEND_CAVE_DARK;                                                            //ZETA- Default to DNS Darker Cave blend if Flash is not active
		
    //Do Custom DNS Blend
    if (currentFlashTint != newFlashTint)
    {
        SET_FOLLOWER_TINT(flashTrackerPacked, newFlashTint);
        VarSet(VAR_FLASH_TRACKER_PACKED, flashTrackerPacked);
    }

    u32 palettes = FilterTimeBlendPalettes(PALETTES_ALL);
    const struct BlendSettings *blend = &gCustomDNSTintBlend[newFlashTint];
    TimeMixPalettes(palettes, gPlttBufferUnfaded, gPlttBufferFaded, (struct BlendSettings *)blend, (struct BlendSettings *)blend, 256);
}

void UpdateFlashStrength(void)
{
    if (!gMapHeader.cave)
		return;
        
    u16 flashTrackerPacked = VarGet(VAR_FLASH_TRACKER_PACKED);
	u8 followerIndex = GetFollowerMonIndex();
	s32 previousFlashLevel = gSaveBlock1Ptr->flashLevel;
	s32 newFlashLevel;
	
    s8 followerFlashLevel = gSpeciesInfo[GetMonData(&gPlayerParty[followerIndex], MON_DATA_SPECIES)].flashLevel;
    u8 flashShadowStrength = OW_FLASH_SHADOW_STRENGTH;

    //Flash Radius and Shadow strength
    if (followerFlashLevel > 0)
        newFlashLevel = followerFlashLevel;
    else 
        newFlashLevel = FLASH_LEVEL_DEFAULT;

    if ((GetMonAbility(&gPlayerParty[followerIndex]) == ABILITY_ILLUMINATE) || FlagGet(FLAG_SYS_BONUS_FLASH))
    {
        newFlashLevel = newFlashLevel - OW_FLASH_ILLUMINATE_BONUS;
        flashShadowStrength = flashShadowStrength - OW_FLASH_ILLUMINATE_SHADOW;
    }

    if (FlagGet(FLAG_SYS_USE_FLASH))
    {
        newFlashLevel = newFlashLevel - OW_FLASH_FIELDMOVE_BONUS;
        flashShadowStrength = flashShadowStrength - OW_FLASH_FIELDMOVE_SHADOW;
    }

    if (FlagGet(FLAG_SYS_USE_FLASH_MOVE_BONUS))
    {
        newFlashLevel = newFlashLevel - 1;
        flashShadowStrength = flashShadowStrength - 1;
    }

    if (newFlashLevel < 1)
        newFlashLevel = 1;                  //Clamp flash level to minimum

    if (flashShadowStrength < 1)
        flashShadowStrength = 1;         //Clamp flash level to minimum

    //Set Flash Shadow strength
    if (followerFlashLevel > 0)
        flashShadowStrength = flashShadowStrength - ((8 - followerFlashLevel) / 2);

    
    SET_SHADOW_STRENGTH(flashTrackerPacked, flashShadowStrength);
    VarSet(VAR_FLASH_TRACKER_PACKED, flashTrackerPacked);
    
    if (newFlashLevel == previousFlashLevel)
        return;

    AnimateFlash(newFlashLevel);
	SetFlashLevel(newFlashLevel);
	return;
}

//ZETA- Passive Flash effect from followers
void UpdateFlashRadiusOnStep(void)
{
	if (!gMapHeader.cave)
		return;
	
    UpdateFlashTint();
	UpdateFlashStrength();
	return;
}

