#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "fishing_game.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define BAR_DIR_LEFT    0
#define BAR_DIR_RIGHT   1

#define FISHING_BAR_WIDTH       36
#define FISHING_AREA_WIDTH      156
#define FISHING_BAR_MAX         (FISHING_AREA_WIDTH - FISHING_BAR_WIDTH) * 10
#define FISHING_BAR_MAX_SPEED   200
#define SPEED_MODIFIER          FISHING_BAR_MAX_SPEED / 20

#define TAG_FISHING_BAR 0x1000

static void CB2_FishingGame(void);
static void Task_FishingGame(u8 taskId);
static void Task_FishingPauseUntilFadeIn(u8 taskId);
static void Task_HandleFishingGameInput(u8 taskId);
static void Task_AskWantToQuit(u8 taskId);
static void Task_HandleConfirmQuitInput(u8 taskId);
static void Task_QuitFishing(u8 taskId);
static void SpriteCB_Fishing_Bar(struct Sprite *sprite);

const u16 gFishingGameBG_Pal[] = INCBIN_U16("graphics/fishing_game/fishing_bg_tiles.gbapal");
const u32 gFishingGameBG_Tilemap[] = INCBIN_U32("graphics/fishing_game/fishing_bg_tiles.bin.lz");
const u32 gFishingGameBG_Gfx[] = INCBIN_U32("graphics/fishing_game/fishing_bg_tiles.4bpp.lz");
const u32 gFishingBar_Gfx[] = INCBIN_U32("graphics/fishing_game/fishing_bar.4bpp.lz");
static const u16 sFishingBar_Pal[] = INCBIN_U16("graphics/fishing_game/fishing_bar.gbapal");

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x0200
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sWindowTemplate_AskQuit =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 0x0260
};

static const struct BgTemplate sBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const u8 sTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY};

static const struct OamData sOam_FishingBar =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_FishingBar[] =
{
    {
        .data = gFishingBar_Gfx,
        .size = 1024,
        .tag = TAG_FISHING_BAR
    },
    {}
};

static const struct SpritePalette sSpritePalettes_FishingGame[] =
{
    {
        .data = sFishingBar_Pal,
        .tag = TAG_FISHING_BAR
    },
    {},
};

static const struct SpriteTemplate sSpriteTemplate_FishingBar =
{
    .tileTag = TAG_FISHING_BAR,
    .paletteTag = TAG_FISHING_BAR,
    .oam = &sOam_FishingBar,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Fishing_Bar
};

static void VblankCB_FishingGame(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// Data for Tasks
#define tBarSpriteId data[5]
#define tPaused data[15]

// Data for all sprites
#define sTaskId data[0]

// Data for Fishing Bar sprite
#define sBarPosition data[6]
#define sBarSpeed data[7]
#define sBarDirection data[8]

void CB2_InitFishingGame(void)
{
    u8 taskId;
    u8 spriteId;

    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);

    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);

    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);

    LZ77UnCompVram(gFishingGameBG_Gfx, (void *)VRAM);
    LZ77UnCompVram(gFishingGameBG_Tilemap, (void *)(BG_SCREEN_ADDR(7)));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);

    DeactivateAllTextPrinters();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();

    LoadPalette(gFishingGameBG_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadUserWindowBorderGfx(0, 0x2A8, BG_PLTT_ID(13));
    LoadCompressedSpriteSheet(&sSpriteSheet_FishingBar[0]);
    //LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_GRAY_SMOKE)]);
    //LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_GRAY_SMOKE)]);
    LoadSpritePalettes(sSpritePalettes_FishingGame);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_FishingGame);
    SetMainCallback2(CB2_FishingGame);

    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 7);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);
    
    taskId = CreateTask(Task_FishingGame, 0);

    gTasks[taskId].tPaused = TRUE;

    // Create fishing bar sprite
    spriteId = CreateSprite(&sSpriteTemplate_FishingBar, 36, 90, 2);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sBarDirection = BAR_DIR_RIGHT;
    gTasks[taskId].tBarSpriteId = spriteId;

    //sStarterLabelWindowId = WINDOW_NONE;
}

static void CB2_FishingGame(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_FishingGame(u8 taskId)
{
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x2A8, 0xD);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_ReelItIn, 0, 1, 0, NULL);
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_FishingPauseUntilFadeIn;
}

static void Task_FishingPauseUntilFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].tPaused = FALSE;
        gTasks[taskId].func = Task_HandleFishingGameInput;
    }
}

static void Task_HandleFishingGameInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_HELD(A_BUTTON))
    {
        
    }
    if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].tPaused = TRUE;
        gTasks[taskId].func = Task_AskWantToQuit;
    }
}

static void Task_AskWantToQuit(u8 taskId)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_FishingWantToQuit, 0, 1, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
    CreateYesNoMenu(&sWindowTemplate_AskQuit, 0x2A8, 0xD, 0);
    gTasks[taskId].func = Task_HandleConfirmQuitInput;
}

static void Task_HandleConfirmQuitInput(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:  // YES
        PlaySE(SE_FLEE);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_QuitFishing;
        break;
    case 1:  // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_ReelItIn, 0, 1, 0, NULL);
        gTasks[taskId].tPaused = FALSE;
        gTasks[taskId].func = Task_HandleFishingGameInput;
        break;
    }
}

static void Task_QuitFishing(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResetAllPicSprites();
        SetMainCallback2(gMain.savedCallback);
        DestroyTask(taskId);
    }
}

static void SpriteCB_Fishing_Bar(struct Sprite *sprite)
{
        DebugPrintf("sBarDirection = %u", sprite->sBarDirection);
        DebugPrintf("sBarSpeed = %u", sprite->sBarSpeed);
        DebugPrintf("sBarPosition = %u", sprite->sBarPosition);
    if (gTasks[sprite->sTaskId].tPaused == FALSE)
    {
        if (JOY_NEW(A_BUTTON) || JOY_HELD(A_BUTTON))
        {
            if (sprite->sBarDirection == BAR_DIR_LEFT)
            {
                u8 increment;

                if (sprite->sBarSpeed == 0) 
                {
                    sprite->sBarDirection = BAR_DIR_RIGHT;
                }
                else
                {
                    sprite->sBarSpeed--;
                }

                increment = (sprite->sBarSpeed / SPEED_MODIFIER);

                if (sprite->sBarPosition > 0 && sprite->sBarPosition > increment)
                {
                    sprite->sBarPosition -= increment;
                }
                else if (sprite->sBarPosition < increment)
                {
                    sprite->sBarPosition = 0;
                }
            }
            else if (sprite->sBarDirection == BAR_DIR_RIGHT)
            {
                if (sprite->sBarSpeed < FISHING_BAR_MAX_SPEED)
                {
                    sprite->sBarSpeed++;
                }

                if (sprite->sBarPosition < FISHING_BAR_MAX)
                {
                    sprite->sBarPosition += (sprite->sBarSpeed / SPEED_MODIFIER);
                }
            }
        }
        else
        {
            if (sprite->sBarDirection == BAR_DIR_RIGHT)
            {
                if (sprite->sBarSpeed == 0 && sprite->sBarPosition != 0) 
                {
                    sprite->sBarDirection = BAR_DIR_LEFT;
                }
                else if (sprite->sBarSpeed > 0)
                {
                    sprite->sBarSpeed--;
                }

                if (sprite->sBarPosition < FISHING_BAR_MAX)
                {
                    sprite->sBarPosition += (sprite->sBarSpeed / SPEED_MODIFIER);
                }
            }
            else if (sprite->sBarDirection == BAR_DIR_LEFT)
            {
                u8 increment;
                
                if (sprite->sBarSpeed <= FISHING_BAR_MAX_SPEED && sprite->sBarPosition > 0)
                {
                    sprite->sBarSpeed++;
                }

                increment = (sprite->sBarSpeed / SPEED_MODIFIER);

                if (sprite->sBarPosition > 0)
                {
                    if (increment > sprite->sBarPosition)
                    {
                        sprite->sBarPosition = 0;
                    }
                    else
                    {
                        sprite->sBarPosition -= increment;
                    }
                }
            }
        }

        if (sprite->sBarPosition > FISHING_BAR_MAX)
        {
            sprite->sBarPosition = FISHING_BAR_MAX;
        }
        if (sprite->sBarPosition < 0)
        {
            sprite->sBarPosition = 0;
        }

        if (sprite->sBarSpeed > FISHING_BAR_MAX_SPEED)
        {
            sprite->sBarSpeed = FISHING_BAR_MAX_SPEED;
        }
        if (sprite->sBarSpeed < 0)
        {
            sprite->sBarSpeed = 0;
        }

        if (sprite->sBarPosition == 0 && sprite->sBarDirection == BAR_DIR_LEFT && sprite->sBarSpeed > 0)
        {
            sprite->sBarDirection = BAR_DIR_RIGHT;
        }
        if (sprite->sBarPosition == FISHING_BAR_MAX && sprite->sBarDirection == BAR_DIR_RIGHT && sprite->sBarSpeed > 0)
        {
            sprite->sBarSpeed = 0;
        }

        sprite->x = ((sprite->sBarPosition / 10) + 36);
    }
}