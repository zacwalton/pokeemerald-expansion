#include "global.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "event_data.h"
#include "faraway_island.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "item.h"
#include "malloc.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "party_menu.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "constants/abilities.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

extern struct MapPosition gPlayerFacingPosition;

extern const u8 FarawayIsland_Interior_EventScript_HideMewWhenGrassCut[];

extern const u8 gFieldEffectPic_CutGrass[];
extern const u16 gFieldEffectPal_CutGrass[];

// cut 'square' defines
#define CUT_NORMAL_SIDE 3
#define CUT_NORMAL_AREA CUT_NORMAL_SIDE * CUT_NORMAL_SIDE

#define CUT_HYPER_SIDE 5
#define CUT_HYPER_AREA CUT_HYPER_SIDE * CUT_HYPER_SIDE

#define CUT_MAX_SIDE 7
#define CUT_MAX_AREA CUT_MAX_SIDE * CUT_MAX_SIDE

#define CUT_SPRITE_ARRAY_COUNT 8

struct HyperCutterUnk
{
    s8 x;
    s8 y;
    u8 unk2[2];
};

// this file's functions
static void FieldCallback_CutTree(void);
static void FieldCallback_CutGrass(void);
static void StartCutTreeFieldEffect(void);
static void StartCutGrassFieldEffect(void);
static void SetCutGrassMetatile(s16, s16);
static void SetCutGrassMetatiles(s16, s16);
static void CutGrassSpriteCallback1(struct Sprite *);
static void CutGrassSpriteCallback2(struct Sprite *);
static void CutGrassSpriteCallbackEnd(struct Sprite *);
static void HandleLongGrassOnHyper(u8, s16, s16);

// IWRAM variables
static u8 sCutSquareSide;
static u8 sTileCountFromPlayer_X;
static u8 sTileCountFromPlayer_Y;
static bool8 sHyperCutTiles[CUT_HYPER_AREA];

// EWRAM variables
static EWRAM_DATA u8 *sCutGrassSpriteArrayPtr = NULL;

// const rom data
static const struct HyperCutterUnk sHyperCutStruct[] =
{
    {-2, -2, {1}},
    {-1, -2, {1}},
    {0, -2, {2}},
    {1, -2, {3}},
    {2, -2, {3}},
    {-2, -1, {1}},
    {2, -1, {3}},
    {-2, 0, {4}},
    {2, 0, {6}},
    {-2, 1, {7}},
    {2, 1, {9}},
    {-2, 2, {7}},
    {-1, 2, {7}},
    {0, 2, {8}},
    {1, 2, {9}},
    {2, 2, {9}},
};

static const struct OamData sOamData_CutGrass =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 1,
    .priority = 1,
    .paletteNum = 1,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_CutGrass[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_CutGrass[] =
{
    sSpriteAnim_CutGrass,
};

static const struct SpriteFrameImage sSpriteImageTable_CutGrass[] =
{
    {gFieldEffectPic_CutGrass, 0x20},
};

const struct SpritePalette gSpritePalette_CutGrass = {gFieldEffectPal_CutGrass, FLDEFF_PAL_TAG_CUT_GRASS};

static const struct SpriteTemplate sSpriteTemplate_CutGrass =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_CUT_GRASS,
    .oam = &sOamData_CutGrass,
    .anims = sSpriteAnimTable_CutGrass,
    .images = sSpriteImageTable_CutGrass,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = CutGrassSpriteCallback1,
};

// code
bool8 SetUpFieldMove_Cut(void)
{
    s16 x, y;
    u8 i, j;
    u8 tileBehavior;
    u16 userAbility;
    bool8 cutTiles[CUT_NORMAL_AREA];
    bool8 ret;

    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_CUTTABLE_TREE) == TRUE)
    {
        // Standing in front of cuttable tree.
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_CutTree;
        return TRUE;
    }
    else
    {
        PlayerGetDestCoords(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
        userAbility = GetMonAbility(&gPlayerParty[GetCursorSelectionMonId()]);
		VarSet(VAR_0x8007, userAbility);
        if ((userAbility == ABILITY_HYPER_CUTTER)
			|| (userAbility == ABILITY_TECHNICIAN)
			|| (userAbility == ABILITY_SHEER_FORCE)
			|| (userAbility == ABILITY_HARVEST)
			|| (userAbility == ABILITY_LONG_REACH)
			|| (userAbility == ABILITY_SHARPNESS))
        {
            sCutSquareSide = CUT_HYPER_SIDE;
            sTileCountFromPlayer_X = 2;
            sTileCountFromPlayer_Y = 2;
        }
        else
        {
            sCutSquareSide = CUT_NORMAL_SIDE;
            sTileCountFromPlayer_X = 1;
            sTileCountFromPlayer_Y = 1;
        }

        for (i = 0; i < CUT_NORMAL_AREA; i++)
            cutTiles[i] = FALSE;
        for (i = 0; i < CUT_HYPER_AREA; i++)
            sHyperCutTiles[i] = FALSE;

        ret = FALSE;

        for (i = 0; i < CUT_NORMAL_SIDE; i++)
        {
            y = i - 1 + gPlayerFacingPosition.y;
            for (j = 0; j < CUT_NORMAL_SIDE; j++)
            {
                x = j - 1 + gPlayerFacingPosition.x;
                if (MapGridGetElevationAt(x, y) == gPlayerFacingPosition.elevation)
                {
                    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                    if (MetatileBehavior_IsPokeGrass(tileBehavior) == TRUE
                    || MetatileBehavior_IsAshGrass(tileBehavior) == TRUE)
                    {
                        // Standing in front of grass.
                        sHyperCutTiles[6 + (i * 5) + j] = TRUE;
                        ret = TRUE;
                    }
                #ifdef BUGFIX
                    // Collision has a range 0-3, any value != 0 is impassable
                    if (MapGridGetCollisionAt(x, y))
                #else
                    if (MapGridGetCollisionAt(x, y) == 1)
                #endif
                    {
                        cutTiles[i * 3 + j] = FALSE;
                    }
                    else
                    {
                        cutTiles[i * 3 + j] = TRUE;
                        if (MetatileBehavior_IsCuttableGrass(tileBehavior) == TRUE)
                            sHyperCutTiles[6 + (i * 5) + j] = TRUE;
                    }
                }
                else
                {
                    cutTiles[i * 3 + j] = FALSE;
                }
            }
        }

        if ((userAbility != ABILITY_HYPER_CUTTER)
			&& (userAbility != ABILITY_TECHNICIAN)
			&& (userAbility != ABILITY_SHEER_FORCE)
			&& (userAbility != ABILITY_HARVEST)
			&& (userAbility != ABILITY_LONG_REACH)
			&& (userAbility != ABILITY_SHARPNESS))
        {
            if (ret == TRUE)
            {
                gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
                gPostMenuFieldCallback = FieldCallback_CutGrass;
            }
        }
        else
        {
            bool8 tileCuttable;
            for (i = 0; i < 16; i++)
            {
                x = gPlayerFacingPosition.x + sHyperCutStruct[i].x;
                y = gPlayerFacingPosition.y + sHyperCutStruct[i].y;
                tileCuttable = TRUE;

                for (j = 0; j < 2; ++j)
                {
                    if (sHyperCutStruct[i].unk2[j] == 0) break; // one line required to match -g
                    if (cutTiles[(u8)(sHyperCutStruct[i].unk2[j] - 1)] == FALSE)
                    {
                        tileCuttable = FALSE;
                        break;
                    }
                }

                if (tileCuttable == TRUE)
                {
                    if (MapGridGetElevationAt(x, y) == gPlayerFacingPosition.elevation)
                    {
                        u8 tileArrayId = ((sHyperCutStruct[i].y * 5) + 12) + (sHyperCutStruct[i].x);
                        tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                        if (MetatileBehavior_IsPokeGrass(tileBehavior) == TRUE
                        || MetatileBehavior_IsAshGrass(tileBehavior) == TRUE)
                        {
                            gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
                            gPostMenuFieldCallback = FieldCallback_CutGrass;
                            sHyperCutTiles[tileArrayId] = TRUE;
                            ret = TRUE;
                        }
                        else
                        {
                            if (MetatileBehavior_IsCuttableGrass(tileBehavior) == TRUE)
                                sHyperCutTiles[tileArrayId] = TRUE;
                        }
                    }
                }
            }

            if (ret == TRUE)
            {
                gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
                gPostMenuFieldCallback = FieldCallback_CutGrass;
            }
        }

        return ret;
    }
}

static void FieldCallback_CutGrass(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseCutGrass);
}

bool8 FldEff_UseCutOnGrass(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartCutGrassFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartCutGrassFieldEffect;
    IncrementGameStat(GAME_STAT_USED_CUT);
    return FALSE;
}

static void FieldCallback_CutTree(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseCut);
}

bool8 FldEff_UseCutOnTree(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartCutTreeFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartCutTreeFieldEffect;
    IncrementGameStat(GAME_STAT_USED_CUT);
    return FALSE;
}

static void StartCutGrassFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_CUT_ON_GRASS);
    FieldEffectStart(FLDEFF_CUT_GRASS);
}

// Checks if the Metatile Behaviour is a member of MetatileBehavior_IsCuttableGrass
//If you have custom behaviours (e.g. snow), make sure they are added to src/metatile_behaviour.c MetatileBehavior_IsCuttableGrass
bool8 IsTileTallGrass(s16 x, s16 y)
{
	u8 metatilebehaviour = MapGridGetMetatileBehaviorAt(x, y);
	
    if (MetatileBehavior_IsCuttableGrass(metatilebehaviour) == TRUE)
		return TRUE;
	else
	{
		return FALSE;
	}
	
}
	
	// defines x, y coord
static const s8 sNeighbourTileOffsets[8][2] =
{
	{-1, -1}, 	//	[0] Top Left 		(1)
	{0, -1},	//	[1] Up				(2)
	{1, -1}, 	//	[2] Top Right		(4)
	{1, 0},		//	[3] Right			(8)
	{1, 1},		//	[4] Bottom Right	(16)
	{0, 1},		//	[5] Down			(32)
	{-1, 1},	//	[6] Bottom Left		(64)
	{-1, 0}		//	[7] Left			(128)
};	

//Calculates tile value based on neighbours
u8 GetTileCalculatedTallGrassValue (s16 x, s16 y)
{
    //s32 metatileId = MapGridGetMetatileIdAt(x, y);
	u8 tileCalculatedValue = 0;
	u8 i;
	
    for (i = 0; i < 8; i++)
	{
		s16 neighbourX = x + sNeighbourTileOffsets[i][0];
		s16 neighbourY = y + sNeighbourTileOffsets[i][1];
		
		if (IsTileTallGrass(neighbourX, neighbourY))
			tileCalculatedValue |= (1 << i);
	}
	
	return tileCalculatedValue;
}


#define AUTOGRASS_TOPLEFT		(1 << 0)
#define AUTOGRASS_UP			(1 << 1)
#define AUTOGRASS_TOPRIGHT		(1 << 2)
#define AUTOGRASS_RIGHT			(1 << 3)

#define AUTOGRASS_BOTTOMRIGHT	(1 << 4)
#define AUTOGRASS_DOWN			(1 << 5)
#define AUTOGRASS_BOTTOMLEFT	(1 << 6)
#define AUTOGRASS_LEFT			(1 << 7)

// Add grass variation types here
enum {
	TALL_GRASS_DEFAULT,
	TREE_GREEN_LEFT,
	TREE_GREEN_RIGHT,
	TREE_BLUE_LEFT,
	TREE_BLUE_RIGHT,
	TREE_GREEN_SMALL,
	TREE_BLUE_SMALL,
	SHRUB_GREEN,
	SHRUB_BLUE,
	ASH,
	ASH_CLEAR,
	NUM_TALL_GRASS_VARIANTS,
};

struct TallGrassVariantType
{
	s32 metatileId;
	u8 variantType;
};

// Defines all tiles for each variation type
static const struct TallGrassVariantType sTallGrassVariants[] =
{
	//Green Tree Left
	{METATILE_Hoenn_Summer_TallGrass_BL_GreenTreeLeft, TREE_GREEN_LEFT},
	{METATILE_Hoenn_Summer_TallGrass_BC_GreenTreeLeft, TREE_GREEN_LEFT},
	{METATILE_Hoenn_Summer_TallGrass_BR_GreenTreeLeft, TREE_GREEN_LEFT},
	{METATILE_Hoenn_Summer_TallGrass_Single_GreenTree_Left, TREE_GREEN_LEFT},
	//Green Tree Right
	{METATILE_Hoenn_Summer_TallGrass_BL_GreenTreeRight, TREE_GREEN_RIGHT},
	{METATILE_Hoenn_Summer_TallGrass_BC_GreenTreeRight, TREE_GREEN_RIGHT},
	{METATILE_Hoenn_Summer_TallGrass_BR_GreenTreeRight, TREE_GREEN_RIGHT},
	{METATILE_Hoenn_Summer_TallGrass_Single_GreenTree_Right, TREE_GREEN_RIGHT},
	//Blue Tree Left
	{METATILE_Hoenn_Summer_TallGrass_BL_BlueTreeLeft, TREE_BLUE_LEFT},
	{METATILE_Hoenn_Summer_TallGrass_BC_BlueTreeLeft, TREE_BLUE_LEFT},
	{METATILE_Hoenn_Summer_TallGrass_BR_BlueTreeLeft, TREE_BLUE_LEFT},
	{METATILE_Hoenn_Summer_TallGrass_Single_BlueTree_Left, TREE_BLUE_LEFT},
	//Blue Tree Right
	{METATILE_Hoenn_Summer_TallGrass_BL_BlueTreeRight, TREE_BLUE_RIGHT},
	{METATILE_Hoenn_Summer_TallGrass_BC_BlueTreeRight, TREE_BLUE_RIGHT},
	{METATILE_Hoenn_Summer_TallGrass_BR_BlueTreeRight, TREE_BLUE_RIGHT},
	{METATILE_Hoenn_Summer_TallGrass_Single_BlueTree_Right, TREE_BLUE_RIGHT},
	//Small Tree Green
	{METATILE_Hoenn_Summer_TallGrass_BL_SmallTreeGreen, TREE_GREEN_SMALL},
	{METATILE_Hoenn_Summer_TallGrass_BC_SmallTreeGreen, TREE_GREEN_SMALL},
	{METATILE_Hoenn_Summer_TallGrass_BR_SmallTreeGreen, TREE_GREEN_SMALL},
	{METATILE_Hoenn_Summer_TallGrass_Single_SmallGreenTree, TREE_GREEN_SMALL},
	//Small Tree Green
	{METATILE_Hoenn_Summer_TallGrass_BL_SmallTreeBlue, TREE_BLUE_SMALL},
	{METATILE_Hoenn_Summer_TallGrass_BC_SmallTreeBlue, TREE_BLUE_SMALL},
	{METATILE_Hoenn_Summer_TallGrass_BR_SmallTreeBlue, TREE_BLUE_SMALL},
	{METATILE_Hoenn_Summer_TallGrass_Single_SmallBlueTree, TREE_BLUE_SMALL},
	//Shrub Green
	{METATILE_Hoenn_Summer_TallGrass_BL_ShrubGreen, SHRUB_GREEN},
	{METATILE_Hoenn_Summer_TallGrass_BC_ShrubGreen, SHRUB_GREEN},
	{METATILE_Hoenn_Summer_TallGrass_BR_ShrubGreen, SHRUB_GREEN},
	{METATILE_Hoenn_Summer_TallGrass_Single_SmallGreenShrub, SHRUB_GREEN},
	//Shrub Green
	{METATILE_Hoenn_Summer_TallGrass_BL_ShrubBlue, SHRUB_BLUE},
	{METATILE_Hoenn_Summer_TallGrass_BC_ShrubBlue, SHRUB_BLUE},
	{METATILE_Hoenn_Summer_TallGrass_BR_ShrubBlue, SHRUB_BLUE},
	{METATILE_Hoenn_Summer_TallGrass_Single_SmallBlueShrub, SHRUB_BLUE},
	//Ash Grass
	{METATILE_Fallarbor_Summer_TallGrass_Ash, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_BottomCenter, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_BottomLeft, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_BottomRight, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerBL, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerBR, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTL, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTLBR, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTR, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTRBL, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_MidCenter, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_MidLeft, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_MidRight, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_TopCenter, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_TopLeft, ASH},
	{METATILE_Fallarbor_Summer_TallGrass_Ash_TopRight, ASH},
	//Ash Grass (Cleared)
	{METATILE_Fallarbor_Summer_TallGrass_AshClear, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_BottomCenter, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_BottomLeft, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_BottomRight, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerBL, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerBR, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTL, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTLBR, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTR, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTRBL, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_MidCenter, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_MidLeft, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_MidRight, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_TopCenter, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_TopLeft, ASH_CLEAR},
	{METATILE_Fallarbor_Summer_TallGrass_AshClear_TopRight, ASH_CLEAR},
};

// Get the tall grass variant type from the above
static u8 GetTallGrassVariantType (s16 x, s16 y)
{
	s32 metatileId = MapGridGetMetatileIdAt(x, y);
	u32 i;
	
	for (i = 0; i < ARRAY_COUNT(sTallGrassVariants); i++)
	{
		if (sTallGrassVariants[i].metatileId == metatileId)
            return sTallGrassVariants[i].variantType;
	}
	return 0;
}

	// Define the metatiles to use for each tall grass variant type
// 1x1 Single Grass Tile Variants
static const s32 sTallGrassSingleVariant[] = 
{
    [TALL_GRASS_DEFAULT]	= METATILE_General_TallGrass,
    [TREE_GREEN_LEFT]		= METATILE_Hoenn_Summer_TallGrass_Single_GreenTree_Left,
    [TREE_GREEN_RIGHT]		= METATILE_Hoenn_Summer_TallGrass_Single_GreenTree_Right,
    [TREE_BLUE_LEFT]		= METATILE_Hoenn_Summer_TallGrass_Single_BlueTree_Left,
    [TREE_BLUE_RIGHT]		= METATILE_Hoenn_Summer_TallGrass_Single_BlueTree_Right,
    [TREE_GREEN_SMALL]		= METATILE_Hoenn_Summer_TallGrass_Single_SmallGreenTree,
    [TREE_BLUE_SMALL]		= METATILE_Hoenn_Summer_TallGrass_Single_SmallBlueTree,
    [SHRUB_GREEN]			= METATILE_Hoenn_Summer_TallGrass_Single_SmallGreenShrub,
    [SHRUB_BLUE]			= METATILE_Hoenn_Summer_TallGrass_Single_SmallBlueShrub,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear,
};

//Top Left Corner Variants
static const s32 sTallGrassTopLeftVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_TopLeft,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_TopLeft,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_TopLeft,
};

//Top Edge Variants
static const s32 sTallGrassTopCenterVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_TopCenter,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_TopCenter,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_TopCenter,
};

//Top Right Corner Variants
static const s32 sTallGrassTopRightVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_TopRight,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_TopRight,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_TopRight,
};

//Left Edge Variants
static const s32 sTallGrassMidLeftVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_MidLeft,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_MidLeft,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_MidLeft,
};

//Center Tile Variants
static const s32 sTallGrassMidCenterVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_MidCenter,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_MidCenter,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_MidCenter,
};

// Right Edge Variants
static const s32 sTallGrassMidRightVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_MidRight,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_MidRight,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_MidRight,
};

//Bottom Right Corner Variants
static const s32 sTallGrassBottomRightVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_BottomRight,
    [TREE_GREEN_LEFT]  = METATILE_Hoenn_Summer_TallGrass_BR_GreenTreeLeft,
    [TREE_GREEN_RIGHT] = METATILE_Hoenn_Summer_TallGrass_BR_GreenTreeRight,
    [TREE_BLUE_LEFT]   = METATILE_Hoenn_Summer_TallGrass_BR_BlueTreeLeft,
    [TREE_BLUE_RIGHT]  = METATILE_Hoenn_Summer_TallGrass_BR_BlueTreeRight,
    [TREE_GREEN_SMALL] = METATILE_Hoenn_Summer_TallGrass_BR_SmallTreeGreen,
    [TREE_BLUE_SMALL]  = METATILE_Hoenn_Summer_TallGrass_BR_SmallTreeBlue,
    [SHRUB_GREEN]      = METATILE_Hoenn_Summer_TallGrass_BR_ShrubBlue,
    [SHRUB_BLUE]       = METATILE_Hoenn_Summer_TallGrass_BR_ShrubGreen,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_BottomRight,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_BottomRight,
};

//Bottom Edge Variants
static const s32 sTallGrassBottomCenterVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_BottomCenter,
    [TREE_GREEN_LEFT]  = METATILE_Hoenn_Summer_TallGrass_BC_GreenTreeLeft,
    [TREE_GREEN_RIGHT] = METATILE_Hoenn_Summer_TallGrass_BC_GreenTreeRight,
    [TREE_BLUE_LEFT]   = METATILE_Hoenn_Summer_TallGrass_BC_BlueTreeLeft,
    [TREE_BLUE_RIGHT]  = METATILE_Hoenn_Summer_TallGrass_BC_BlueTreeRight,
    [TREE_GREEN_SMALL] = METATILE_Hoenn_Summer_TallGrass_BC_SmallTreeGreen,
    [TREE_BLUE_SMALL]  = METATILE_Hoenn_Summer_TallGrass_BC_SmallTreeBlue,
    [SHRUB_GREEN]      = METATILE_Hoenn_Summer_TallGrass_BC_ShrubBlue,
    [SHRUB_BLUE]       = METATILE_Hoenn_Summer_TallGrass_BC_ShrubGreen,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_BottomCenter,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_BottomCenter,
};

//Bottom Left Corner Variants
static const s32 sTallGrassBottomLeftVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_BottomLeft,
    [TREE_GREEN_LEFT]  = METATILE_Hoenn_Summer_TallGrass_BL_GreenTreeLeft,
    [TREE_GREEN_RIGHT] = METATILE_Hoenn_Summer_TallGrass_BL_GreenTreeRight,
    [TREE_BLUE_LEFT]   = METATILE_Hoenn_Summer_TallGrass_BL_BlueTreeLeft,
    [TREE_BLUE_RIGHT]  = METATILE_Hoenn_Summer_TallGrass_BL_BlueTreeRight,
    [TREE_GREEN_SMALL] = METATILE_Hoenn_Summer_TallGrass_BL_SmallTreeGreen,
    [TREE_BLUE_SMALL]  = METATILE_Hoenn_Summer_TallGrass_BL_SmallTreeBlue,
    [SHRUB_GREEN]      = METATILE_Hoenn_Summer_TallGrass_BL_ShrubBlue,
    [SHRUB_BLUE]       = METATILE_Hoenn_Summer_TallGrass_BL_ShrubGreen,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_BottomLeft,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_BottomLeft,
};

//Bottom Right Inner Corner Variants
static const s32 sTallGrassInnerCornerBRVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_InnerCornerBR,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerBR,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerBR,
};

//Bottom Left Inner Corner Variants
static const s32 sTallGrassInnerCornerBLVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_InnerCornerBL,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerBL,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerBL,
};

//Top Left Inner Corner Variants
static const s32 sTallGrassInnerCornerTLVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_InnerCornerTL,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTL,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTL,
};

// Top Right Inner Corner Variants
static const s32 sTallGrassInnerCornerTRVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_General_TallGrass_InnerCornerTR,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTR,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTR,
};

//Top Left+Bottom Right Inner Corner Intersect Variants
static const s32 sTallGrassInnerCornerTLBRVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_Hoenn_Summer_TallGrass_InnerCornerTLBR,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTLBR,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTLBR,
};

//Top Right+Bottom Left Inner Corner Intersect Variants
static const s32 sTallGrassInnerCornerTRBLVariant[] = 
{
    [TALL_GRASS_DEFAULT]  = METATILE_Hoenn_Summer_TallGrass_InnerCornerTRBL,
	[ASH]					= METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTRBL,
	[ASH_CLEAR]				= METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTRBL,
};


// Set the metatile based on the value calculated from its neighbours
static void SetAutotileMetatileId (s16 x, s16 y)
{
	u8 variantType = GetTallGrassVariantType(x, y);
	u8 autotileValue = GetTileCalculatedTallGrassValue(x, y);
	//Tall Grass Center
	if (autotileValue == 0xFF) //1111 1111
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassMidCenterVariant[variantType]);
		else
		{
			MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_MidCenter);
		}
	}
	
	//Inner Corners
	
	//Tall Grass Bottom Right Inner Corner
	else if ((autotileValue & (AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) ==
    (AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) //0111 1111
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassInnerCornerBRVariant[variantType]);
		else
		{
			MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_InnerCornerBR);
		}
	}
	
	//Tall Grass Bottom Left Inner Corner
	else if ((autotileValue & (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) ==
    (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) //11011111
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassInnerCornerBLVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_InnerCornerBL);
		}
	}
	
	//Tall Grass Top Left Inner Corner
	else if ((autotileValue & (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT | AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) ==
    (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT | AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) //1111 0111
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassInnerCornerTLVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_InnerCornerTL);
		}
	}
	
	//Tall Grass Top Right Inner Corner
	else if ((autotileValue & (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN | AUTOGRASS_LEFT)) ==
    (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN | AUTOGRASS_LEFT)) //1111 1101
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassInnerCornerTRVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_InnerCornerTR);
		}
	}
	
	//Tall Grass Top Left and Bottom Right Inner Corner
	else if ((autotileValue & (AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT | AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) ==
    (AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT | AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) //0111 0111
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassInnerCornerTLBRVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_Hoenn_Summer_TallGrass_InnerCornerTLBR);
		}
	}
	
	//Tall Grass Top Right and Bottom Left Inner Corner
	else if ((autotileValue & (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN | AUTOGRASS_LEFT)) ==
    (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN | AUTOGRASS_LEFT)) //1101 1101
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassInnerCornerTRBLVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_Hoenn_Summer_TallGrass_InnerCornerTRBL);
		}
	}	
	
	//Cardinal Directions
	
	//Tall Grass Bottom
	else if ((autotileValue & (AUTOGRASS_UP | AUTOGRASS_LEFT | AUTOGRASS_RIGHT | AUTOGRASS_TOPLEFT | AUTOGRASS_TOPRIGHT)) ==
    (AUTOGRASS_UP | AUTOGRASS_LEFT | AUTOGRASS_RIGHT | AUTOGRASS_TOPLEFT | AUTOGRASS_TOPRIGHT)) //1111 0001
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassBottomCenterVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_BottomCenter);
		}
	}
	
	//Tall Grass Left
	else if ((autotileValue & (AUTOGRASS_UP | AUTOGRASS_RIGHT | AUTOGRASS_DOWN | AUTOGRASS_TOPRIGHT | AUTOGRASS_BOTTOMRIGHT)) ==
    (AUTOGRASS_UP | AUTOGRASS_RIGHT | AUTOGRASS_DOWN | AUTOGRASS_TOPRIGHT | AUTOGRASS_BOTTOMRIGHT)) //01111 1000
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassMidLeftVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_MidLeft);
		}
	}
	
	//Tall Grass Top
	else if ((autotileValue & (AUTOGRASS_RIGHT | AUTOGRASS_DOWN | AUTOGRASS_LEFT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_BOTTOMLEFT)) ==
    (AUTOGRASS_RIGHT | AUTOGRASS_DOWN | AUTOGRASS_LEFT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_BOTTOMLEFT)) //0001 1111
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassTopCenterVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_TopCenter);
		}
	}
	
	//Tall Grass Right
	else if ((autotileValue & (AUTOGRASS_UP | AUTOGRASS_DOWN | AUTOGRASS_LEFT | AUTOGRASS_TOPLEFT | AUTOGRASS_BOTTOMLEFT)) ==
    (AUTOGRASS_UP | AUTOGRASS_DOWN | AUTOGRASS_LEFT | AUTOGRASS_TOPLEFT | AUTOGRASS_BOTTOMLEFT)) //1100 0111
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassMidRightVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_MidRight);
		}
	}
	
	//Corners
	
	//Tall Grass Top Left Corner
	else if ((autotileValue & (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_LEFT)) ==
    (AUTOGRASS_TOPLEFT | AUTOGRASS_UP | AUTOGRASS_LEFT)) //1100 0001
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassBottomRightVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_BottomRight);
		}
	}
	
	//Tall Grass Top Right Corner
	else if ((autotileValue & (AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT)) ==
    (AUTOGRASS_UP | AUTOGRASS_TOPRIGHT | AUTOGRASS_RIGHT)) //0111 0000
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassBottomLeftVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_BottomLeft);
		}
	}
	
	//Tall Grass Bottom Right Corner
	else if ((autotileValue & (AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN)) ==
    (AUTOGRASS_RIGHT | AUTOGRASS_BOTTOMRIGHT | AUTOGRASS_DOWN)) //0001 1100
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassTopLeftVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_TopLeft);
		}
	}
	
	//Tall Grass Bottom Left Corner
	else if ((autotileValue & (AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) ==
    (AUTOGRASS_DOWN | AUTOGRASS_BOTTOMLEFT | AUTOGRASS_LEFT)) //0000 0111
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassTopRightVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass_TopRight);
		}
	}
	
	//Defaults to 1x1 grass tile
	else
	{
		if (variantType > 0)
			MapGridSetMetatileIdAt(x, y, sTallGrassSingleVariant[variantType]);
		else
		{
		MapGridSetMetatileIdAt(x, y, METATILE_General_TallGrass);
		}
	}
}



bool8 FldEff_CutGrass(void)
{
    s16 x, y;
    u8 i = 0;
	u8 yieldCount = 0;
	u8 itemChance = 0;
    u16 *ashGatherCount;
	u16 userAbility = VarGet(VAR_0x8007);

    PlaySE(SE_M_CUT);
    PlayerGetDestCoords(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    for (i = 0; i < CUT_HYPER_AREA; i++)
    {
        if (sHyperCutTiles[i] == TRUE)
        {
            s8 xAdd = (i % 5) - 2;
            s8 yAdd = (i / 5) - 2;

            x = xAdd + gPlayerFacingPosition.x;
            y = yAdd + gPlayerFacingPosition.y;

			if (IsTileTallGrass(x, y) == TRUE)
			{
				yieldCount += Random() % 2;
				if ((userAbility == ABILITY_KEEN_EYE)
					|| (userAbility == ABILITY_ILLUMINATE)
					|| (userAbility == ABILITY_PICKUP)
					|| (userAbility == ABILITY_SUPER_LUCK)
					|| (userAbility == ABILITY_FRISK)
					|| (userAbility == ABILITY_HARVEST))
					{
						itemChance += 4;
					}
				else if ((userAbility == ABILITY_OBLIVIOUS)
					|| (userAbility == ABILITY_UNAWARE))
					{
						itemChance += 1;
					}
				else
				itemChance += 2;
			}
			
			if (MetatileBehavior_IsAshGrass(MapGridGetMetatileBehaviorAt(x, y)))
			{
				// Try to gather ash
				if (CheckBagHasItem(ITEM_SOOT_SACK, 1))
				{
					ashGatherCount = GetVarPointer(VAR_ASH_GATHER_COUNT);
					if (*ashGatherCount < 9999)
						(*ashGatherCount)++;
				}
			}
			
            SetCutGrassMetatile(x, y);
            AllowObjectAtPosTriggerGroundEffects(x, y);
        }
    }

	if (yieldCount > 0)
	{
		VarSet(VAR_0x8008, yieldCount);
		ScriptContext_SetupScript(EventScript_Harvest_CutGrassScript);
	}
	if ((Random() % 100) < itemChance)
	{
		ScriptContext_SetupScript(EventScript_Harvest_CutGrassScript_Item);
	}

    SetCutGrassMetatiles(gPlayerFacingPosition.x - sTileCountFromPlayer_X, gPlayerFacingPosition.y - (1 + sTileCountFromPlayer_Y));
    DrawWholeMapView();
	//Check surrounding tiles for autotile system
	for (i = 0; i < (CUT_MAX_AREA); i++)
    {
            s8 xAdd = (i % 7) - 3;
            s8 yAdd = (i / 7) - 3;

            x = xAdd + gPlayerFacingPosition.x;
            y = yAdd + gPlayerFacingPosition.y;
			
		if (IsTileTallGrass(x, y) == TRUE)
		{			
		SetAutotileMetatileId(x, y);
		}
    }
	
    DrawWholeMapView();
    sCutGrassSpriteArrayPtr = AllocZeroed(CUT_SPRITE_ARRAY_COUNT);

    // populate sprite ID array
    for (i = 0; i < CUT_SPRITE_ARRAY_COUNT; i++)
    {
        sCutGrassSpriteArrayPtr[i] = CreateSprite(&sSpriteTemplate_CutGrass,
        gSprites[gPlayerAvatar.spriteId].oam.x + 8, gSprites[gPlayerAvatar.spriteId].oam.y + 20, 0);
        gSprites[sCutGrassSpriteArrayPtr[i]].data[2] = 32 * i;
    }

    return FALSE;
}

struct CutGrassTileMapping {	
    u16 tallGrassTile;
    u16 cutTile;
};

// Map Tall Grass tiles to Cut tiles
static const struct CutGrassTileMapping sCutGrassTileMap[] = {
    { METATILE_Fortree_LongGrass_Root, 								METATILE_General_Grass },
    { METATILE_General_LongGrass, 									METATILE_General_Grass },
    { METATILE_General_TallGrass, 									METATILE_General_Grass },

    // Tall Grass Grid
    { METATILE_General_TallGrass_TopLeft, 							METATILE_General_Grass },
    { METATILE_General_TallGrass_TopCenter, 						METATILE_General_Grass },
    { METATILE_General_TallGrass_TopRight, 							METATILE_General_Grass },
    { METATILE_General_TallGrass_MidLeft, 							METATILE_General_Grass },
    { METATILE_General_TallGrass_MidCenter, 						METATILE_General_Grass },
    { METATILE_General_TallGrass_MidRight, 							METATILE_General_Grass },
    { METATILE_General_TallGrass_BottomLeft, 						METATILE_General_Grass },
    { METATILE_General_TallGrass_BottomCenter, 						METATILE_General_Grass },
    { METATILE_General_TallGrass_BottomRight, 						METATILE_General_Grass },
    { METATILE_General_TallGrass_InnerCornerTL, 					METATILE_General_Grass },
    { METATILE_General_TallGrass_InnerCornerTR, 					METATILE_General_Grass },
    { METATILE_General_TallGrass_InnerCornerBL, 					METATILE_General_Grass },
    { METATILE_General_TallGrass_InnerCornerBR, 					METATILE_General_Grass },
    { METATILE_Hoenn_Summer_TallGrass_InnerCornerTLBR, 				METATILE_General_Grass },
    { METATILE_Hoenn_Summer_TallGrass_InnerCornerTRBL, 				METATILE_General_Grass },

    { METATILE_Hoenn_Summer_TallGrass_BL_GreenTreeRight, 			METATILE_General_Grass_TreeRight },
    { METATILE_Hoenn_Summer_TallGrass_BC_GreenTreeRight, 			METATILE_General_Grass_TreeRight },
    { METATILE_Hoenn_Summer_TallGrass_BR_GreenTreeRight, 			METATILE_General_Grass_TreeRight },
    { METATILE_Hoenn_Summer_TallGrass_Single_GreenTree_Right, 		METATILE_General_Grass_TreeRight },

    { METATILE_Hoenn_Summer_TallGrass_BL_GreenTreeLeft, 			METATILE_General_Grass_TreeLeft },
    { METATILE_Hoenn_Summer_TallGrass_BC_GreenTreeLeft, 			METATILE_General_Grass_TreeLeft },
    { METATILE_Hoenn_Summer_TallGrass_BR_GreenTreeLeft, 			METATILE_General_Grass_TreeLeft },
    { METATILE_Hoenn_Summer_TallGrass_Single_GreenTree_Left, 		METATILE_General_Grass_TreeLeft },

    // Tall Grass Blue Tree
    { METATILE_Hoenn_Summer_TallGrass_BL_BlueTreeLeft, 				METATILE_Hoenn_Summer_Blue_TreeLeft },
    { METATILE_Hoenn_Summer_TallGrass_BC_BlueTreeLeft, 				METATILE_Hoenn_Summer_Blue_TreeLeft },
    { METATILE_Hoenn_Summer_TallGrass_BR_BlueTreeLeft, 				METATILE_Hoenn_Summer_Blue_TreeLeft },

    { METATILE_Hoenn_Summer_TallGrass_BL_BlueTreeRight, 			METATILE_Hoenn_Summer_Blue_TreeRight },
    { METATILE_Hoenn_Summer_TallGrass_BC_BlueTreeRight, 			METATILE_Hoenn_Summer_Blue_TreeRight },
    { METATILE_Hoenn_Summer_TallGrass_BR_BlueTreeRight, 			METATILE_Hoenn_Summer_Blue_TreeRight },

    // Small Trees / Shrubs
    { METATILE_Hoenn_Summer_TallGrass_BL_SmallTreeGreen, 			METATILE_Hoenn_Summer_SmallGreenTree },
    { METATILE_Hoenn_Summer_TallGrass_BC_SmallTreeGreen, 			METATILE_Hoenn_Summer_SmallGreenTree },
    { METATILE_Hoenn_Summer_TallGrass_BR_SmallTreeGreen, 			METATILE_Hoenn_Summer_SmallGreenTree },
    { METATILE_Hoenn_Summer_TallGrass_Single_SmallGreenTree, 		METATILE_Hoenn_Summer_SmallGreenTree },

    { METATILE_Hoenn_Summer_TallGrass_BL_SmallTreeBlue, 			METATILE_Hoenn_Summer_SmallBlueTree },
    { METATILE_Hoenn_Summer_TallGrass_BC_SmallTreeBlue, 			METATILE_Hoenn_Summer_SmallBlueTree },
    { METATILE_Hoenn_Summer_TallGrass_BR_SmallTreeBlue, 			METATILE_Hoenn_Summer_SmallBlueTree },
    { METATILE_Hoenn_Summer_TallGrass_Single_SmallBlueTree, 		METATILE_Hoenn_Summer_SmallBlueTree },

    { METATILE_Hoenn_Summer_TallGrass_BL_ShrubBlue, 				METATILE_Hoenn_Summer_BlueShrub },
    { METATILE_Hoenn_Summer_TallGrass_BC_ShrubBlue, 				METATILE_Hoenn_Summer_BlueShrub },
    { METATILE_Hoenn_Summer_TallGrass_BR_ShrubBlue, 				METATILE_Hoenn_Summer_BlueShrub },
    { METATILE_Hoenn_Summer_TallGrass_Single_SmallBlueShrub, 		METATILE_Hoenn_Summer_BlueShrub },

    { METATILE_Hoenn_Summer_TallGrass_BL_ShrubGreen, 				METATILE_Hoenn_Summer_GreenShrub },
    { METATILE_Hoenn_Summer_TallGrass_BC_ShrubGreen, 				METATILE_Hoenn_Summer_GreenShrub },
    { METATILE_Hoenn_Summer_TallGrass_BR_ShrubGreen, 				METATILE_Hoenn_Summer_GreenShrub },
    { METATILE_Hoenn_Summer_TallGrass_Single_SmallGreenShrub, 		METATILE_Hoenn_Summer_GreenShrub },

    // Other
    { METATILE_Fortree_SecretBase_LongGrass_BottomLeft, 			METATILE_Fortree_SecretBase_LongGrass_TopLeft },
    { METATILE_Fortree_SecretBase_LongGrass_BottomMid, 				METATILE_Fortree_SecretBase_LongGrass_TopMid },
    { METATILE_Fortree_SecretBase_LongGrass_BottomRight, 			METATILE_Fortree_SecretBase_LongGrass_TopRight },

    { METATILE_Lavaridge_NormalGrass, 								METATILE_Lavaridge_LavaField },
    { METATILE_Lavaridge_AshGrass, 									METATILE_Lavaridge_LavaField },

    { METATILE_Fallarbor_NormalGrass, 								METATILE_Fallarbor_AshField },
    { METATILE_Fallarbor_AshGrass, 									METATILE_Fallarbor_AshField },

    { METATILE_Fallarbor_Summer_TallGrass_Ash, 						METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear, 				METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_BottomCenter, 	METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_BottomLeft, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_BottomRight, 	METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerBL, 	METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerBR, 	METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTL, 	METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTLBR, METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTR, 	METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_InnerCornerTRBL, METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_MidCenter, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_MidLeft, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_MidRight, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_TopCenter, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_TopLeft, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_AshClear_TopRight, 		METATILE_Fallarbor_Summer_AshField },

    { METATILE_Fallarbor_Summer_TallGrass_Ash_BottomCenter, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_BottomLeft, 			METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_BottomRight, 			METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerBL, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerBR, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTL, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTLBR, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTR, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_InnerCornerTRBL, 		METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_MidCenter, 			METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_MidLeft, 				METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_MidRight, 			METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_TopCenter, 			METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_TopLeft, 				METATILE_Fallarbor_Summer_AshField },
    { METATILE_Fallarbor_Summer_TallGrass_Ash_TopRight, 			METATILE_Fallarbor_Summer_AshField },

    { METATILE_General_TallGrass_TreeUp, 							METATILE_General_Grass_TreeUp },
};


// set map grid metatile depending on tile variant
static void SetCutGrassMetatile(s16 x, s16 y)
{
    s32 metatileId = MapGridGetMetatileIdAt(x, y);

    for (int i = 0; i < ARRAY_COUNT(sCutGrassTileMap); i++)
	{
		if (metatileId == sCutGrassTileMap[i].tallGrassTile)
		{
			MapGridSetMetatileIdAt(x, y, sCutGrassTileMap[i].cutTile);
			break;
		}
	}
}

enum
{
    LONG_GRASS_NONE,
    LONG_GRASS_FIELD,
    LONG_GRASS_BASE_LEFT,
    LONG_GRASS_BASE_CENTER,
    LONG_GRASS_BASE_RIGHT
};

static u8 GetLongGrassCaseAt(s16 x, s16 y)
{
    u16 metatileId = MapGridGetMetatileIdAt(x, y);

    if (metatileId == METATILE_General_Grass)
        return LONG_GRASS_FIELD;
    else if (metatileId == METATILE_Fortree_SecretBase_LongGrass_TopLeft)
        return LONG_GRASS_BASE_LEFT;
    else if (metatileId == METATILE_Fortree_SecretBase_LongGrass_TopMid)
        return LONG_GRASS_BASE_CENTER;
    else if (metatileId == METATILE_Fortree_SecretBase_LongGrass_TopRight)
        return LONG_GRASS_BASE_RIGHT;
    else
        return LONG_GRASS_NONE;
}

static void SetCutGrassMetatiles(s16 x, s16 y)
{
    s16 i;
    s16 lowerY = y + sCutSquareSide;

    for (i = 0; i < sCutSquareSide; i++)
    {
        s16 currentX = x + i;
        if (MapGridGetMetatileIdAt(currentX, y) == METATILE_General_LongGrass)
        {
            switch (GetLongGrassCaseAt(currentX, y + 1))
            {
            case LONG_GRASS_FIELD:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_Fortree_LongGrass_Root);
                break;
            case LONG_GRASS_BASE_LEFT:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_Fortree_SecretBase_LongGrass_BottomLeft);
                break;
            case LONG_GRASS_BASE_CENTER:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_Fortree_SecretBase_LongGrass_BottomMid);
                break;
            case LONG_GRASS_BASE_RIGHT:
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_Fortree_SecretBase_LongGrass_BottomRight);
                break;
            }
        }
        if (MapGridGetMetatileIdAt(currentX, lowerY) == METATILE_General_Grass)
        {
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_Fortree_LongGrass_Root)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_General_Grass);
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_Fortree_SecretBase_LongGrass_BottomLeft)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_Fortree_SecretBase_LongGrass_TopLeft);
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_Fortree_SecretBase_LongGrass_BottomMid)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_Fortree_SecretBase_LongGrass_TopMid);
            if (MapGridGetMetatileIdAt(currentX, lowerY + 1) == METATILE_Fortree_SecretBase_LongGrass_BottomRight)
                MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_Fortree_SecretBase_LongGrass_TopRight);
        }
    }

    if (sCutSquareSide == CUT_HYPER_SIDE)
    {
        HandleLongGrassOnHyper(0, x, y);
        HandleLongGrassOnHyper(1, x, y);
    }
}

static void HandleLongGrassOnHyper(u8 caseId, s16 x, s16 y)
{
    s16 newX;
    bool8 arr[3];

    if (caseId == 0)
    {
        arr[0] = sHyperCutTiles[5];
        arr[1] = sHyperCutTiles[10];
        arr[2] = sHyperCutTiles[15];
        newX = x;
    }
    else if (caseId == 1)
    {
        arr[0] = sHyperCutTiles[9];
        arr[1] = sHyperCutTiles[14];
        arr[2] = sHyperCutTiles[19];
        newX = x + 4;
    }
    else // invalid case
    {
        return;
    }

    if (arr[0] == TRUE)
    {
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_Fortree_LongGrass_Root)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_General_Grass);
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_Fortree_SecretBase_LongGrass_BottomLeft)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_Fortree_SecretBase_LongGrass_TopLeft);
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_Fortree_SecretBase_LongGrass_BottomMid)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_Fortree_SecretBase_LongGrass_TopMid);
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_Fortree_SecretBase_LongGrass_BottomRight)
            MapGridSetMetatileIdAt(newX, y + 3, METATILE_Fortree_SecretBase_LongGrass_TopRight);
    }
    if (arr[1] == TRUE)
    {
        if (MapGridGetMetatileIdAt(newX, y + 2) == METATILE_General_LongGrass)
        {
            switch (GetLongGrassCaseAt(newX, y + 3))
            {
            case LONG_GRASS_FIELD:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_Fortree_LongGrass_Root);
                break;
            case LONG_GRASS_BASE_LEFT:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_Fortree_SecretBase_LongGrass_BottomLeft);
                break;
            case LONG_GRASS_BASE_CENTER:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_Fortree_SecretBase_LongGrass_BottomMid);
                break;
            case LONG_GRASS_BASE_RIGHT:
                MapGridSetMetatileIdAt(newX, y + 3, METATILE_Fortree_SecretBase_LongGrass_BottomRight);
                break;
            }
        }

        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_Fortree_LongGrass_Root)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_General_Grass);
        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_Fortree_SecretBase_LongGrass_BottomLeft)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_Fortree_SecretBase_LongGrass_TopLeft);
        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_Fortree_SecretBase_LongGrass_BottomMid)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_Fortree_SecretBase_LongGrass_TopMid);
        if (MapGridGetMetatileIdAt(newX, y + 4) == METATILE_Fortree_SecretBase_LongGrass_BottomRight)
            MapGridSetMetatileIdAt(newX, y + 4, METATILE_Fortree_SecretBase_LongGrass_TopRight);
    }
    if (arr[2] == TRUE)
    {
        if (MapGridGetMetatileIdAt(newX, y + 3) == METATILE_General_LongGrass)
        {
            switch (GetLongGrassCaseAt(newX, y + 4))
            {
            case LONG_GRASS_FIELD:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_Fortree_LongGrass_Root);
                break;
            case LONG_GRASS_BASE_LEFT:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_Fortree_SecretBase_LongGrass_BottomLeft);
                break;
            case LONG_GRASS_BASE_CENTER:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_Fortree_SecretBase_LongGrass_BottomMid);
                break;
            case LONG_GRASS_BASE_RIGHT:
                MapGridSetMetatileIdAt(newX, y + 4, METATILE_Fortree_SecretBase_LongGrass_BottomRight);
                break;
            }
        }
    }
}

static void CutGrassSpriteCallback1(struct Sprite *sprite)
{
    sprite->data[0] = 8;
    sprite->data[1] = 0;
    sprite->data[3] = 0;
    sprite->callback = CutGrassSpriteCallback2;
}

static void CutGrassSpriteCallback2(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[2], sprite->data[0]);
    sprite->y2 = Cos(sprite->data[2], sprite->data[0]);

    sprite->data[2] = (sprite->data[2] + 8) & 0xFF;
    sprite->data[0] += 1 + (sprite->data[3] >> 2); // right shift by 2 is dividing by 4
    sprite->data[3]++;

    if (sprite->data[1] != 28)
        sprite->data[1]++;
    else
        sprite->callback = CutGrassSpriteCallbackEnd; // done rotating the grass, execute clean up function
}

static void CutGrassSpriteCallbackEnd(struct Sprite *sprite)
{
    u8 i;

    for (i = 1; i < CUT_SPRITE_ARRAY_COUNT; i++)
        DestroySprite(&gSprites[sCutGrassSpriteArrayPtr[i]]);

    FieldEffectStop(&gSprites[sCutGrassSpriteArrayPtr[0]], FLDEFF_CUT_GRASS);
    FREE_AND_SET_NULL(sCutGrassSpriteArrayPtr);
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();

    if (IsMewPlayingHideAndSeek() == TRUE)
        ScriptContext_SetupScript(FarawayIsland_Interior_EventScript_HideMewWhenGrassCut);
}

void FixLongGrassMetatilesWindowTop(s16 x, s16 y)
{
    u8 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (MetatileBehavior_IsLongGrass_Duplicate(metatileBehavior))
    {
        switch (GetLongGrassCaseAt(x, y + 1))
        {
        case LONG_GRASS_FIELD:
            MapGridSetMetatileIdAt(x, y + 1, METATILE_Fortree_LongGrass_Root);
            break;
        case LONG_GRASS_BASE_LEFT:
            MapGridSetMetatileIdAt(x, y + 1, METATILE_Fortree_SecretBase_LongGrass_BottomLeft);
            break;
        case LONG_GRASS_BASE_CENTER:
            MapGridSetMetatileIdAt(x, y + 1, METATILE_Fortree_SecretBase_LongGrass_BottomMid);
            break;
        case LONG_GRASS_BASE_RIGHT:
            MapGridSetMetatileIdAt(x, y + 1, METATILE_Fortree_SecretBase_LongGrass_BottomRight);
            break;
        }
    }
}

void FixLongGrassMetatilesWindowBottom(s16 x, s16 y)
{
    if (MapGridGetMetatileIdAt(x, y) == METATILE_General_Grass)
    {
        u8 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y + 1);
        if (MetatileBehavior_IsLongGrassSouthEdge(metatileBehavior))
        {
            s32 metatileId = MapGridGetMetatileIdAt(x, y + 1);
            switch (metatileId)
            {
            case METATILE_Fortree_LongGrass_Root:
                MapGridSetMetatileIdAt(x, y + 1, METATILE_General_Grass);
                break;
            case METATILE_Fortree_SecretBase_LongGrass_BottomLeft:
                MapGridSetMetatileIdAt(x, y + 1, METATILE_Fortree_SecretBase_LongGrass_TopLeft);
                break;
            case METATILE_Fortree_SecretBase_LongGrass_BottomMid:
                MapGridSetMetatileIdAt(x, y + 1, METATILE_Fortree_SecretBase_LongGrass_TopMid);
                break;
            case METATILE_Fortree_SecretBase_LongGrass_BottomRight:
                MapGridSetMetatileIdAt(x, y + 1, METATILE_Fortree_SecretBase_LongGrass_TopRight);
                break;
            }
        }
    }
}

static void StartCutTreeFieldEffect(void)
{
    PlaySE(SE_M_CUT);
    FieldEffectActiveListRemove(FLDEFF_USE_CUT_ON_TREE);
    ScriptContext_Enable();
}
