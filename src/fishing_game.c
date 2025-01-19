#include "global.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "battle_transition.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "field_control_avatar.h"
#include "fishing_game.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "tv.h"
#include "util.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define TAG_FISHING_BAR         0x1000
#define TAG_FISHING_BAR_RIGHT   0x1001
#define TAG_SCORE_METER         0x1002
#define TAG_PERFECT             0x1003

static void CB2_FishingGame(void);
static void Task_FishingGame(u8 taskId);
static void Task_FishingPauseUntilFadeIn(u8 taskId);
static void Task_HandleFishingGameInput(u8 taskId);
static void Task_AskWantToQuit(u8 taskId);
static void Task_HandleConfirmQuitInput(u8 taskId);
static void Task_ReeledInFish(u8 taskId);
static void Task_FishGotAway(u8 taskId);
static void Task_QuitFishing(u8 taskId);
static u8 CalculateInitialScoreMeterInterval(void);
static void CalculateScoreMeterPalette(struct Sprite *sprite);
static void UpdateHelpfulTextHigher(u8 taskId);
static void UpdateHelpfulTextLower(u8 taskId);
static void HandleScore(u8 taskId);
static void SetFishingBarPosition(u8 taskId);
static void SetMonIconPosition(u8 taskId);
static void SpriteCB_FishingBar(struct Sprite *sprite);
static void SpriteCB_FishingBarRight(struct Sprite *sprite);
static void SpriteCB_FishingMonIcon(struct Sprite *sprite);
static void SpriteCB_ScoreMeter(struct Sprite *sprite);
static void SpriteCB_ScoreMeterAdditional(struct Sprite *sprite);
static void SpriteCB_Perfect(struct Sprite *sprite);
static void CB2_FishingBattleTransition(void);
static void CB2_FishingBattleStart(void);

const u16 gFishingGameBG_Pal[] = INCBIN_U16("graphics/fishing_game/fishing_bg_tiles.gbapal");
const u32 gFishingGameBG_Tilemap[] = INCBIN_U32("graphics/fishing_game/fishing_bg_tiles.bin.lz");
const u32 gScoreBG_Tilemap[] = INCBIN_U32("graphics/fishing_game/score_bg_tilemap.bin.lz");
const u32 gFishingGameBG_Gfx[] = INCBIN_U32("graphics/fishing_game/fishing_bg_tiles.4bpp.lz");
const u32 gFishingBar_Gfx[] = INCBIN_U32("graphics/fishing_game/fishing_bar.4bpp.lz");
const u32 gFishingBarRight_Gfx[] = INCBIN_U32("graphics/fishing_game/fishing_bar_right.4bpp.lz");
static const u16 sFishingBar_Pal[] = INCBIN_U16("graphics/fishing_game/fishing_bar.gbapal");
static const u16 sFishingBarOff_Pal[] = INCBIN_U16("graphics/fishing_game/fishing_bar_off.gbapal");
const u32 gScoreMeter_Gfx[] = INCBIN_U32("graphics/fishing_game/score_meter.4bpp.lz");
static const u16 sScoreMeter_Pal[] = INCBIN_U16("graphics/fishing_game/score_meter.gbapal");
const u32 gPerfect_Gfx[] = INCBIN_U32("graphics/fishing_game/perfect.4bpp.lz");
static const u16 sPerfect_Pal[] = INCBIN_U16("graphics/fishing_game/perfect.gbapal");

static const u16 sFishBehavior[][6] =
{
    [SPECIES_MAGIKARP] = {
        2,   // Speed
        0,   // Speed Variability
        240, // Movement Delay
        60,  // Delay Variability
        10,  // Distance
        5    // Distance Variability
    },
    [SPECIES_GOLDEEN] = {
        7,   // Speed
        3,   // Speed Variability
        480, // Movement Delay
        60,  // Delay Variability
        70,  // Distance
        10   // Distance Variability
    },
    [SPECIES_CORPHISH] = {
        10,  // Speed
        3,   // Speed Variability
        50,  // Movement Delay
        20,  // Delay Variability
        5,   // Distance
        5    // Distance Variability
    },
    [SPECIES_GYARADOS] = {
        12,  // Speed
        4,   // Speed Variability
        25,  // Movement Delay
        10,  // Delay Variability
        40,  // Distance
        30   // Distance Variability
    },
    [SPECIES_TENTACOOL] = {
        4,   // Speed
        1,   // Speed Variability
        5,   // Movement Delay
        4,   // Delay Variability
        30,  // Distance
        25   // Distance Variability
    },
    [SPECIES_WAILMER] = {
        7,   // Speed
        1,   // Speed Variability
        5,   // Movement Delay
        10,  // Delay Variability
        80,  // Distance
        60   // Distance Variability
    }
};

const u8 * const sHelpfulTextTable[6] =
{
    gText_HelpfulTextHigher0,
    gText_HelpfulTextHigher1,
    gText_HelpfulTextHigher2,
    gText_HelpfulTextLower0,
    gText_HelpfulTextLower1,
    gText_HelpfulTextLower2
};

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

static const struct BgTemplate sBgTemplates[3] =
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
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

//static const u8 sTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY};

static const struct OamData sOam_FishingBar =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_ScoreMeter =
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
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_Perfect =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sSpriteSheets_FishingGame[] =
{
    [SCORE_METER] = {
        .data = gScoreMeter_Gfx,
        .size = 1024,
        .tag = TAG_SCORE_METER
    },
    [FISHING_BAR] = {
        .data = gFishingBar_Gfx,
        .size = 256,
        .tag = TAG_FISHING_BAR
    },
    [FISHING_BAR_RIGHT] = {
        .data = gFishingBarRight_Gfx,
        .size = 256,
        .tag = TAG_FISHING_BAR_RIGHT
    },
    [PERFECT] = {
        .data = gPerfect_Gfx,
        .size = 128,
        .tag = TAG_PERFECT
    }
};

static const struct SpritePalette sSpritePalettes_FishingGame[] =
{
    {
        .data = sFishingBar_Pal,
        .tag = TAG_FISHING_BAR
    },
    {
        .data = sScoreMeter_Pal,
        .tag = TAG_SCORE_METER
    },
    {
        .data = sPerfect_Pal,
        .tag = TAG_PERFECT
    },
    {NULL},
};

static const struct SpriteTemplate sSpriteTemplate_FishingBar =
{
    .tileTag = TAG_FISHING_BAR,
    .paletteTag = TAG_FISHING_BAR,
    .oam = &sOam_FishingBar,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FishingBar
};

static const struct SpriteTemplate sSpriteTemplate_FishingBarRight =
{
    .tileTag = TAG_FISHING_BAR_RIGHT,
    .paletteTag = TAG_FISHING_BAR,
    .oam = &sOam_FishingBar,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FishingBarRight
};

static const struct SpriteTemplate sSpriteTemplate_ScoreMeter =
{
    .tileTag = TAG_SCORE_METER,
    .paletteTag = TAG_SCORE_METER,
    .oam = &sOam_ScoreMeter,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ScoreMeter
};

static const struct SpriteTemplate sSpriteTemplate_Perfect =
{
    .tileTag = TAG_PERFECT,
    .paletteTag = TAG_PERFECT,
    .oam = &sOam_Perfect,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Perfect
};

static void VblankCB_FishingGame(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// Data for Tasks
#define tFrameCounter       data[0]
#define tFishSpecies        data[1]
#define tFishIconSpriteId   data[2]
#define tBarLeftSpriteId    data[3]
#define tBarRightSpriteId   data[4]
#define tScoreMeterSpriteId data[5]
#define tFishSpeedCounter   data[6]
#define tInitialFishSpeed   data[7]
#define tScore              data[8]
#define tScoreDirection     data[9]
#define tFishIsMoving       data[10]
#define tPerfectCatch       data[11]
#define tPaused             data[15]

// Data for all sprites
#define sTaskId             data[0]

// Data for Fishing Bar sprite
#define sBarPosition        data[2]
#define sBarSpeed           data[3]
#define sBarDirection       data[4]

// Data for Mon Icon sprite
#define sFishPosition       data[1]
#define sFishSpeed          data[2]
#define sTimeToNextMove     data[3]
#define sFishDestination    data[4]
#define sFishDestInterval   data[5]
#define sFishDirection      data[6]

// Data for Score Meter sprites
#define sScorePosition      data[1]
#define sScoreWinCheck      data[2]
#define sCurrColorInterval  data[3]
#define sScoreThird         data[4]
#define sTextCooldown       data[5]

// Data for Perfect sprite
#define sPerfectFrameCount       data[1]
#define sPerfectMoveFrames data[2]

void CB2_InitFishingGame(void)
{
    u8 taskId;
    u8 spriteId;

    SetVBlankCallback(NULL);

    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);

    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);

    LZ77UnCompVram(gFishingGameBG_Gfx, (void *)VRAM);
    LZ77UnCompVram(gScoreBG_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
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

    LoadPalette(gFishingGameBG_Pal, BG_PLTT_ID(0), 3 * PLTT_SIZE_4BPP);
    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadUserWindowBorderGfx(0, 0x2A8, BG_PLTT_ID(13));
    LoadCompressedSpriteSheet(&sSpriteSheets_FishingGame[SCORE_METER]);
    LoadCompressedSpriteSheet(&sSpriteSheets_FishingGame[FISHING_BAR]);
    LoadCompressedSpriteSheet(&sSpriteSheets_FishingGame[FISHING_BAR_RIGHT]);
    LoadCompressedSpriteSheet(&sSpriteSheets_FishingGame[PERFECT]);
    LoadSpritePalettes(sSpritePalettes_FishingGame);
    LoadMonIconPalettes();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_FishingGame);
    SetMainCallback2(CB2_FishingGame);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);
    ShowBg(3);
    
    taskId = CreateTask(Task_FishingGame, 0);
    gTasks[taskId].tPaused = TRUE; // Pause the sprite animations/movements until the game starts.
    gTasks[taskId].tPerfectCatch = TRUE; // Allow a perfect catch.
    gTasks[taskId].tScore = STARTING_SCORE; // Set the starting score.
    gTasks[taskId].tScoreDirection = FISH_DIR_RIGHT;

    // Create fishing bar sprites.
    spriteId = CreateSprite(&sSpriteTemplate_FishingBar, FISHING_BAR_START_X, FISHING_BAR_Y, 1);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sBarDirection = FISH_DIR_RIGHT;
    gTasks[taskId].tBarLeftSpriteId = spriteId;
    
    spriteId = CreateSprite(&sSpriteTemplate_FishingBarRight, (FISHING_BAR_START_X + FISHING_BAR_WIDTH_ADJUST), FISHING_BAR_Y, 2);
    gSprites[spriteId].sTaskId = taskId;
    gTasks[taskId].tBarRightSpriteId = spriteId;

    // Create mon icon sprite.
    spriteId = CreateMonIcon(GetMonData(&gEnemyParty[0], MON_DATA_SPECIES), SpriteCB_FishingMonIcon, FISH_ICON_START_X, FISH_ICON_Y, 1, GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY));
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].oam.priority = 0;
    gSprites[spriteId].sFishPosition = (FISH_ICON_START_X - FISH_ICON_MIN_X) * POSITION_ADJUSTMENT;
    gSprites[spriteId].sTimeToNextMove = (FISH_FIRST_MOVE_DELAY * 60);
    gTasks[taskId].tFishSpecies = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    gTasks[taskId].tFishIconSpriteId = spriteId;

    // Create score meter sprite.
    spriteId = CreateSprite(&sSpriteTemplate_ScoreMeter, SCORE_SECTION_INIT_X, SCORE_SECTION_INIT_Y, 2);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sScorePosition = (STARTING_SCORE / SCORE_INTERVAL);
    gSprites[spriteId].sScoreThird = (gSprites[spriteId].sScorePosition / SCORE_THIRD_SIZE);
    gSprites[spriteId].sCurrColorInterval = CalculateInitialScoreMeterInterval();
    gTasks[taskId].tScoreMeterSpriteId = spriteId;

    // Create enough score meter sprites to fill the whole score area.
    if (SCORE_AREA_WIDTH > SCORE_SECTION_WIDTH)
    {
        u8 i;
        u8 sections = NUM_SCORE_SECTIONS;

        if (((SCORE_AREA_WIDTH * 100) % SCORE_SECTION_WIDTH) > 0)
            sections++;

        for (i = 1; i <= (sections - 1); i++)
        {
            spriteId = CreateSprite(&sSpriteTemplate_ScoreMeter, (SCORE_SECTION_INIT_X - (SCORE_SECTION_WIDTH * i)), SCORE_SECTION_INIT_Y, 2);
            gSprites[spriteId].callback = SpriteCB_ScoreMeterAdditional;
            gSprites[spriteId].sTaskId = taskId;
        }
    }
}

static void CB2_FishingGame(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_FishingGame(u8 taskId)
{
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x2A8, 0xD);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_ReelItIn, 0, 1, 0, NULL); // Show the fishing game instructions.
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_FishingPauseUntilFadeIn;
}

static void Task_FishingPauseUntilFadeIn(u8 taskId)
{
    if (!gPaletteFade.active) // Keep the game paused until the screen has fully faded in.
    {
        gTasks[taskId].tPaused = FALSE; // Unpause.
        gTasks[taskId].func = Task_HandleFishingGameInput;
    }
}

static void Task_HandleFishingGameInput(u8 taskId)
{
    HandleScore(taskId);
    SetFishingBarPosition(taskId);
    SetMonIconPosition(taskId);

    if (JOY_NEW(B_BUTTON)) // If the B Button is pressed.
    {
        gTasks[taskId].tPaused = TRUE; // Pause the game.
        gTasks[taskId].func = Task_AskWantToQuit;
    }

    if (!gTasks[taskId].tFishIsMoving && gTasks[taskId].tPaused == FALSE) // If the fish is not doing a movement and the game isn't paused.
        gTasks[taskId].tFrameCounter++; // The time until the next fish movement is decreased.
}

static void Task_AskWantToQuit(u8 taskId)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1)); // Make the text box blank.
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_FishingWantToQuit, 0, 1, 0, NULL); // Ask to quit the game.
    ScheduleBgCopyTilemapToVram(0);
    CreateYesNoMenu(&sWindowTemplate_AskQuit, 0x2A8, 0xD, 0); // Display the YES/NO option box.
    gTasks[taskId].func = Task_HandleConfirmQuitInput;
}

static void Task_HandleConfirmQuitInput(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:  // YES
        PlaySE(SE_FLEE);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
        gTasks[taskId].func = Task_QuitFishing;
        break;
    case 1:  // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        FillWindowPixelBuffer(0, PIXEL_FILL(1)); // Make the text box blank.
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_ReelItIn, 0, 1, 0, NULL); // Show the instructions again.
        gTasks[taskId].tPaused = FALSE; // Unpause the game.
        gTasks[taskId].func = Task_HandleFishingGameInput;
        break;
    }
}

static void Task_ReeledInFish(u8 taskId)
{
    if (gTasks[taskId].tFrameCounter == 0)
    {
        if (gTasks[taskId].tPerfectCatch == TRUE) // If it was a perfect catch.
        {
            u8 spriteId;

            PlaySE(SE_RG_POKE_JUMP_SUCCESS);
            spriteId = CreateSprite(&sSpriteTemplate_Perfect, PERFECT_X, PERFECT_Y, 1);
            gSprites[spriteId].sTaskId = taskId;
        }
        else // If it wasn't a perfect catch.
            PlaySE(SE_PIN);

        FillWindowPixelBuffer(0, PIXEL_FILL(1)); // Make the text box blank.
        AddTextPrinterParameterized2(0, FONT_NORMAL, gText_ReeledInAPokemon, 1, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY); // Congratulations text.
        gTasks[taskId].tFrameCounter++;
    }

    if (gTasks[taskId].tFrameCounter == 1)
    {
        if (!IsTextPrinterActive(0))
        {
            IncrementGameStat(GAME_STAT_FISHING_ENCOUNTERS);
            SetMainCallback2(CB2_FishingBattleTransition);
            gTasks[taskId].tFrameCounter++;
        }
    }
}

static void Task_FishGotAway(u8 taskId)
{
    if (gTasks[taskId].tFrameCounter == 0)
    {
        PlaySE(SE_FLEE);
        FillWindowPixelBuffer(0, PIXEL_FILL(1)); // Make the text box blank.
        AddTextPrinterParameterized2(0, FONT_NORMAL, gText_PokemonGotAway, 1, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY); // Failure text.
        gTasks[taskId].tFrameCounter++;
    }

    if (gTasks[taskId].tFrameCounter == 1)
    {
        if (!IsTextPrinterActive(0)) // If a button was pressed.
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
            gTasks[taskId].func = Task_QuitFishing;
        }
    }
}

static void Task_QuitFishing(u8 taskId)
{
    if (!gPaletteFade.active) // If the screen has fully faded to black.
    {
        ResetAllPicSprites();
        PlayBGM(GetCurrLocationDefaultMusic()); // Play the map's default music.
        SetMainCallback2(gMain.savedCallback);
        DestroyTask(taskId); // Stop the fishing game task.
    }
}

static u8 CalculateInitialScoreMeterInterval(void)
{
    u8 i;
    u8 startColorInterval = 0;
    u8 r = 31; // Max out the red level.
    u8 g = 0;

    for (i = 0; i <= (STARTING_SCORE / SCORE_INTERVAL); i += SCORE_COLOR_INTERVAL) // Set the starting color interval based on the starting score.
    {
        startColorInterval++;
    }

    if (startColorInterval < (NUM_COLOR_INTERVALS / 2)) // If the starting score interval is less than half of the total number of intervals.
    {
        g = (startColorInterval); // Set the green level to match the interval.
    }
    else
    {
        g = 31; // Max out the green level.
        r -= (startColorInterval - (NUM_COLOR_INTERVALS / 2)); // Set the red level to match the interval.
    }

    FillPalette(RGB(r, g, 0), OBJ_PLTT_ID(1), PLTT_SIZE_4BPP); // Set the score meter palette to the new color value.

    return startColorInterval;
}

static void CalculateScoreMeterPalette(struct Sprite *sprite)
{
    u8 r = 31;
    u8 g = 0;

    if (sprite->sCurrColorInterval > NUM_COLOR_INTERVALS) // Cannot exceed the maximum color interval.
        sprite->sCurrColorInterval = NUM_COLOR_INTERVALS;

    if (sprite->sCurrColorInterval <= (NUM_COLOR_INTERVALS / 2)) // If the score meter is less than half full.
    {
        g = (sprite->sCurrColorInterval - 1); // Set the green level to match the interval.
    }
    else
    {
        g = 31; // Max out the green level.
        r -= ((sprite->sCurrColorInterval - 1) - (NUM_COLOR_INTERVALS / 2)); // Set the red level to match the interval.
    }

    FillPalette(RGB(r, g, 0), OBJ_PLTT_ID(1), PLTT_SIZE_4BPP); // Set the score meter palette to the new color value.
}

#define scoreMeterData  gSprites[gTasks[taskId].tScoreMeterSpriteId]

static void UpdateHelpfulTextHigher(u8 taskId)
{
        FillWindowPixelBuffer(0, PIXEL_FILL(1)); // Make the text box blank.
        AddTextPrinterParameterized(0, FONT_NORMAL, sHelpfulTextTable[scoreMeterData.sScoreThird], 0, 1, 1, NULL); // Print the helpful text that corresponds with the current score third.
        scoreMeterData.sTextCooldown = 60; // Reset the text cooldown counter.
}

static void UpdateHelpfulTextLower(u8 taskId)
{
        FillWindowPixelBuffer(0, PIXEL_FILL(1)); // Make the text box blank.
        AddTextPrinterParameterized(0, FONT_NORMAL, sHelpfulTextTable[scoreMeterData.sScoreThird + 3], 0, 1, 1, NULL); // Print the helpful text that corresponds with the current score third.
        scoreMeterData.sTextCooldown = 60; // Reset the text cooldown counter.
}

#define barData         gSprites[gTasks[taskId].tBarLeftSpriteId]
#define fishData        gSprites[gTasks[taskId].tFishIconSpriteId]
#define fishCenter      (fishData.sFishPosition + ((FISH_ICON_WIDTH / 4) * POSITION_ADJUSTMENT))
#define barLeftEdge     barData.sBarPosition
#define barRightEdge    (barLeftEdge + (FISHING_BAR_WIDTH * POSITION_ADJUSTMENT))
#define fishHBLeftEdge  (fishCenter - ((FISH_ICON_HITBOX_WIDTH / 2) * POSITION_ADJUSTMENT))
#define fishHBRightEdge (fishCenter + ((FISH_ICON_HITBOX_WIDTH / 2) * POSITION_ADJUSTMENT))

static void HandleScore(u8 taskId)
{
    if (fishHBLeftEdge <= barRightEdge && fishHBRightEdge >= barLeftEdge) // If the fish hitbox is within the fishing bar.
    {
        gTasks[taskId].tScore += SCORE_INCREASE; // Increase the score.

        if (gTasks[taskId].tScoreDirection == FISH_DIR_LEFT) // Only on the frame when the fish enters the fishing bar area.
        {
            LoadPalette(sFishingBar_Pal, OBJ_PLTT_ID(0), PLTT_SIZE_4BPP);
            gTasks[taskId].tScoreDirection = FISH_DIR_RIGHT; // Change the direction the score meter is moving.

            if (scoreMeterData.sTextCooldown < 30) // If there is less than half a second left on the text cooldown counter.
            {
                UpdateHelpfulTextHigher(taskId); // Display the appropriate helpful text.
            }
        }
    }
    else // If the fish hitbox is outside the fishing bar.
    {
        gTasks[taskId].tScore -= SCORE_DECREASE; // Decrease the score.
        gTasks[taskId].tPerfectCatch = FALSE; // Can no longer achieve a perfect catch.

        if (gTasks[taskId].tScoreDirection == FISH_DIR_RIGHT) // Only on the frame when the fish exits the fishing bar area.
        {
            LoadPalette(sFishingBarOff_Pal, OBJ_PLTT_ID(0), PLTT_SIZE_4BPP);
            gTasks[taskId].tScoreDirection = FISH_DIR_LEFT; // Change the direction the score meter is moving.

            if (scoreMeterData.sTextCooldown < 30) // If there is less than half a second left on the text cooldown counter.
            {
                UpdateHelpfulTextLower(taskId); // Display the appropriate helpful text.
            }
        }
    }

    if (gTasks[taskId].tScore >= SCORE_MAX) // If the score goal has been achieved.
    {
        gTasks[taskId].tPaused = TRUE; // Freeze all sprite animations/movements.
        gTasks[taskId].tFrameCounter = 0; // Reset the frame counter.
        gTasks[taskId].func = Task_ReeledInFish;
    }

    if (gTasks[taskId].tScore <= 0) // If the score has hit 0.
    {
        gTasks[taskId].tPaused = TRUE; // Freeze all sprite animations/movements.
        gTasks[taskId].tFrameCounter = 0; // Reset the frame counter.
        gTasks[taskId].func = Task_FishGotAway;
    }
}

#define fishingBarData      gSprites[gTasks[taskId].tBarLeftSpriteId]

static void SetFishingBarPosition(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_HELD(A_BUTTON)) // If the A Button is pressed.
    {
        u8 increment;

        if (fishingBarData.sBarDirection == FISH_DIR_LEFT) // If the bar is traveling to left.
        {
            if (fishingBarData.sBarSpeed == 0) // If the bar is not moving, switch directions.
                fishingBarData.sBarDirection = FISH_DIR_RIGHT;
            else
                fishingBarData.sBarSpeed--; // Decrease the bar speed.

            increment = (fishingBarData.sBarSpeed / BAR_SPEED_MODIFIER);

            if (fishingBarData.sBarPosition > 0 && fishingBarData.sBarPosition > increment) // If the bar won't exceed the left edge.
                fishingBarData.sBarPosition -= increment; // Move the bar to the left.
            else if (fishingBarData.sBarPosition < increment)
                fishingBarData.sBarPosition = 0; // Does not exceed left edge.
        }
        else if (fishingBarData.sBarDirection == FISH_DIR_RIGHT) // If the bar is traveling to right.
        {
            if (fishingBarData.sBarSpeed < FISHING_BAR_MAX_SPEED) // If the bar speed isn't at max.
                    fishingBarData.sBarSpeed++; // Increase the bar speed.

            increment = (fishingBarData.sBarSpeed / BAR_SPEED_MODIFIER);

            if (fishingBarData.sBarPosition < FISHING_BAR_MAX) // If the bar isn't against the right edge.
            {
                if ((fishingBarData.sBarPosition + increment) > FISHING_BAR_MAX) // If the bar movement would exceed the right edge.
                    fishingBarData.sBarPosition = FISHING_BAR_MAX; // Set the bar along the right edge.
                else
                    fishingBarData.sBarPosition += increment; // Move the bar to the right.
            }
        }
    }
    else // The A Button is not pressed.
    {
        u8 increment;
                
        if (fishingBarData.sBarDirection == FISH_DIR_RIGHT) // If the bar is traveling to right.
        {
            if (fishingBarData.sBarSpeed == 0 && fishingBarData.sBarPosition != 0) // If the bar isn't moving and isn't against the left edge, switch directions.
                fishingBarData.sBarDirection = FISH_DIR_LEFT;
            else if (fishingBarData.sBarSpeed > 0) // If the bar is moving.
                fishingBarData.sBarSpeed--; // Decrease the bar speed.
                
            increment = (fishingBarData.sBarSpeed / BAR_SPEED_MODIFIER);

            if ((fishingBarData.sBarPosition + increment) <= FISHING_BAR_MAX) // If the bar won't exceed the right edge.
                fishingBarData.sBarPosition += increment; // Move the bar to the right.
            else
                fishingBarData.sBarPosition = FISHING_BAR_MAX; // Set the bar along the right edge.
        }
        else if (fishingBarData.sBarDirection == FISH_DIR_LEFT) // If the bar is traveling to left.
        {
            if (fishingBarData.sBarSpeed < FISHING_BAR_MAX_SPEED && fishingBarData.sBarPosition > 0) // If the bar speed isn't at max and the bar isn't against the left edge.
                fishingBarData.sBarSpeed++; // Increase the bar speed.

            increment = (fishingBarData.sBarSpeed / BAR_SPEED_MODIFIER);

            if (fishingBarData.sBarPosition > 0) // If the bar isn't against the left edge.
            {
                if ((fishingBarData.sBarPosition - increment) < 0) // If the bar movement would exceed the left edge.
                    fishingBarData.sBarPosition = 0; // Set the bar along the left edge.
                else
                    fishingBarData.sBarPosition -= increment; // Move the bar to the left.
            }
        }
    }
}

#undef fishingBarData

#define fishIconData            gSprites[gTasks[taskId].tFishIconSpriteId]
#define sBehavior               sFishBehavior[gTasks[taskId].tFishSpecies]
#define s60PercentMovedRight    (fishIconData.sFishDestination - ((fishIconData.sFishDestInterval / 100) * 40))
#define s70PercentMovedRight    (fishIconData.sFishDestination - ((fishIconData.sFishDestInterval / 100) * 30))
#define s80PercentMovedRight    (fishIconData.sFishDestination - ((fishIconData.sFishDestInterval / 100) * 20))
#define s90PercentMovedRight    (fishIconData.sFishDestination - ((fishIconData.sFishDestInterval / 100) * 10))
#define s60PercentMovedLeft     (fishIconData.sFishDestination + ((fishIconData.sFishDestInterval / 100) * 40))
#define s70PercentMovedLeft     (fishIconData.sFishDestination + ((fishIconData.sFishDestInterval / 100) * 30))
#define s80PercentMovedLeft     (fishIconData.sFishDestination + ((fishIconData.sFishDestInterval / 100) * 20))
#define s90PercentMovedLeft     (fishIconData.sFishDestination + ((fishIconData.sFishDestInterval / 100) * 10))

static void SetMonIconPosition(u8 taskId)
{
    if (gTasks[taskId].tFishIsMoving) // Fish is moving.
    {
        if (fishIconData.sFishDirection == FISH_DIR_RIGHT) // If the mon is moving to the right.
        {
            if (fishIconData.sFishPosition >= s60PercentMovedRight && gTasks[taskId].tFishSpeedCounter == 0) // If the mon has traveled at least 60% of the total movement distance.
            {
                if (fishIconData.sFishSpeed > 2)
                    fishIconData.sFishSpeed -= (gTasks[taskId].tInitialFishSpeed / 4); // Reduce the speed by a quarter of the initial speed value.
                gTasks[taskId].tFishSpeedCounter++;
            }
            else if (fishIconData.sFishPosition >= s70PercentMovedRight && gTasks[taskId].tFishSpeedCounter == 1) // If the mon has traveled at least 70% of the total movement distance.
            {
                if (fishIconData.sFishSpeed > 2)
                    fishIconData.sFishSpeed -= (gTasks[taskId].tInitialFishSpeed / 4); // Reduce the speed by a quarter of the initial speed value.
                gTasks[taskId].tFishSpeedCounter++;
            }
            else if (fishIconData.sFishPosition >= s80PercentMovedRight && gTasks[taskId].tFishSpeedCounter == 2) // If the mon has traveled at least 80% of the total movement distance.
            {
                if (fishIconData.sFishSpeed > 2)
                    fishIconData.sFishSpeed -= (gTasks[taskId].tInitialFishSpeed / 4); // Reduce the speed by a quarter of the initial speed value.
                gTasks[taskId].tFishSpeedCounter++;
            }
            else if (fishIconData.sFishPosition >= s90PercentMovedRight && gTasks[taskId].tFishSpeedCounter == 3 && fishIconData.sFishSpeed > 2) // If the mon has traveled at least 90% of the total movement distance.
                fishIconData.sFishSpeed *= 0.5; // Reduce the current fish speed by half.

            if ((fishIconData.sFishPosition + fishIconData.sFishSpeed) <= FISH_ICON_MAX_X) // If the fish position wouldn't exceed the right edge.
                fishIconData.sFishPosition += fishIconData.sFishSpeed; // Move the fish to the right.
            else
                fishIconData.sFishPosition = FISH_ICON_MAX_X; // Cap the position at the right edge.

            if (fishIconData.sFishPosition >= fishIconData.sFishDestination)
                gTasks[taskId].tFishIsMoving = FALSE; // Return to idle behavior if movement has completed.
        }
        else if (fishIconData.sFishDirection == FISH_DIR_LEFT) // If the mon is moving to the left.
        {
            if (fishIconData.sFishPosition <= s60PercentMovedLeft && gTasks[taskId].tFishSpeedCounter == 0) // If the mon has traveled at least 60% of the total movement distance.
            {
                if (fishIconData.sFishSpeed > 2)
                    fishIconData.sFishSpeed -= (gTasks[taskId].tInitialFishSpeed / 4); // Reduce the speed by a quarter of the initial speed value.
                gTasks[taskId].tFishSpeedCounter++;
            }
            else if (fishIconData.sFishPosition <= s70PercentMovedLeft && gTasks[taskId].tFishSpeedCounter == 1) // If the mon has traveled at least 70% of the total movement distance.
            {
                if (fishIconData.sFishSpeed > 2)
                    fishIconData.sFishSpeed -= (gTasks[taskId].tInitialFishSpeed / 4); // Reduce the speed by a quarter of the initial speed value.
                gTasks[taskId].tFishSpeedCounter++;
            }
            else if (fishIconData.sFishPosition <= s80PercentMovedLeft && gTasks[taskId].tFishSpeedCounter == 2) // If the mon has traveled at least 80% of the total movement distance.
            {
                if (fishIconData.sFishSpeed > 2)
                    fishIconData.sFishSpeed -= (gTasks[taskId].tInitialFishSpeed / 4); // Reduce the speed by a quarter of the initial speed value.
                gTasks[taskId].tFishSpeedCounter++;
            }
            else if (fishIconData.sFishPosition <= s90PercentMovedLeft && gTasks[taskId].tFishSpeedCounter == 3 && fishIconData.sFishSpeed > 2) // If the mon has traveled at least 90% of the total movement distance.
                fishIconData.sFishSpeed *= 0.5; // Reduce the current fish speed by half.

            if ((fishIconData.sFishPosition - fishIconData.sFishSpeed) >= FISH_ICON_MIN_X) // If the fish position wouldn't exceed the left edge.
                fishIconData.sFishPosition -= fishIconData.sFishSpeed; // Move the fish to the left.
            else
                fishIconData.sFishPosition = FISH_ICON_MIN_X; // Cap the position at the left edge.

            if (fishIconData.sFishPosition <= fishIconData.sFishDestination) // If movement has completed.
                gTasks[taskId].tFishIsMoving = FALSE; // Return to idle behavior.
        }
    }
    else // Fish is idle.
    {
        u8 rand;
        u16 leftProbability;
        u16 distance;

        if (gTasks[taskId].tFrameCounter == fishIconData.sTimeToNextMove) // Begin new movement.
        {
            u8 i;
            u16 variablility;

            gTasks[taskId].tFishIsMoving = TRUE;
            gTasks[taskId].tFrameCounter = 0;
            gTasks[taskId].tFishSpeedCounter = 0;

            // Set fish movement speed.
            rand = (Random() % 20);
            variablility = (Random() % sBehavior[FISH_SPEED_VARIABILITY]);
            fishIconData.sFishSpeed = sBehavior[FISH_SPEED];
            if (rand < 10)
                fishIconData.sFishSpeed -= variablility;
            else
                fishIconData.sFishSpeed += variablility;
            if (fishIconData.sFishSpeed < 1)
                fishIconData.sFishSpeed = 1;
            gTasks[taskId].tInitialFishSpeed = fishIconData.sFishSpeed;

            // Set time until next movement.
            rand = (Random() % 20);
            variablility = (Random() % sBehavior[FISH_DELAY_VARIABILITY]);
            fishIconData.sTimeToNextMove = sBehavior[FISH_MOVE_DELAY];
            for (i = 0; i < variablility; i++)
            {
                if (rand < 10)
                    fishIconData.sTimeToNextMove--;
                else
                    fishIconData.sTimeToNextMove++;

                if (fishIconData.sTimeToNextMove < 1)
                    fishIconData.sTimeToNextMove = 1;
            }

            // Set movement direction.
            leftProbability = (fishIconData.sFishPosition / (FISH_ICON_MAX_X / 100));
            rand = (Random() % 100);
            if (rand < leftProbability)
                fishIconData.sFishDirection = FISH_DIR_LEFT;
            else
                fishIconData.sFishDirection = FISH_DIR_RIGHT;

            // Set fish destination and interval.
            distance = sBehavior[FISH_DISTANCE];
            rand = (Random() % 20);
            variablility = (Random() % sBehavior[FISH_DIST_VARIABILITY]);
            for (i = 0; i < variablility; i++)
            {
                distance++;
            }
            distance *= POSITION_ADJUSTMENT;
            if (fishIconData.sFishDirection == FISH_DIR_LEFT)
            {
                fishIconData.sFishDestination = (fishIconData.sFishPosition - distance);
                if (fishIconData.sFishDestination < FISH_ICON_MIN_X)
                    fishIconData.sFishDestination = FISH_ICON_MIN_X;
                fishIconData.sFishDestInterval = (fishIconData.sFishPosition - fishIconData.sFishDestination);
            }
            else
            {
                fishIconData.sFishDestination = (fishIconData.sFishPosition + distance);
                if (fishIconData.sFishDestination > FISH_ICON_MAX_X)
                    fishIconData.sFishDestination = FISH_ICON_MAX_X;
                fishIconData.sFishDestInterval = (fishIconData.sFishDestination - fishIconData.sFishPosition);
            }
        }

        // Fish idle movement.
        rand = (Random() % 20);
        if (rand < 7) // Nudge to right.
        {
            rand = (Random() % 4);
            if ((fishIconData.sFishPosition + rand) > FISH_ICON_MAX_X)
                fishIconData.sFishPosition = FISH_ICON_MAX_X;
            else
                fishIconData.sFishPosition += rand;
        }
        else if (rand < 14) // Nudge to left.
        {
            rand = (Random() % 4);
            if ((fishIconData.sFishPosition - rand) < FISH_ICON_MIN_X)
                fishIconData.sFishPosition = FISH_ICON_MIN_X;
            else
                fishIconData.sFishPosition -= rand;
        }
    }
}

#undef fishIconData
#undef sBehavior
#undef s60PercentMovedRight
#undef s70PercentMovedRight
#undef s80PercentMovedRight
#undef s90PercentMovedRight
#undef s60PercentMovedLeft
#undef s70PercentMovedLeft
#undef s80PercentMovedLeft
#undef s90PercentMovedLeft

static void SpriteCB_FishingBar(struct Sprite *sprite)
{
    if (gTasks[sprite->sTaskId].tPaused == TRUE) // Don't do anything if paused.
        goto END;

    // Does not exceed max speed.
    if (sprite->sBarSpeed > FISHING_BAR_MAX_SPEED)
        sprite->sBarSpeed = FISHING_BAR_MAX_SPEED;

    // Bounce bar off of left edge.
    if (sprite->sBarPosition == 0 && sprite->sBarDirection == FISH_DIR_LEFT && sprite->sBarSpeed > 0)
    {
        sprite->sBarDirection = FISH_DIR_RIGHT;
        sprite->sBarSpeed /= FISHING_BAR_BOUNCINESS;
    }

    // Stop bar at right edge.
    if (sprite->sBarPosition == FISHING_BAR_MAX && sprite->sBarDirection == FISH_DIR_RIGHT && sprite->sBarSpeed > 0)
        sprite->sBarSpeed = 0;

    // Set the bar sprite location.
    sprite->x2 = ((sprite->sBarPosition / POSITION_ADJUSTMENT));

    END:
}

static void SpriteCB_FishingBarRight(struct Sprite *sprite)
{
    sprite->x2 = (gSprites[gTasks[sprite->sTaskId].tBarLeftSpriteId].x2); // Set the location of the bar's right edge.
}

static void SpriteCB_FishingMonIcon(struct Sprite *sprite)
{
    if (gTasks[sprite->sTaskId].tPaused == FALSE) // Don't do anything if paused.
    {
        UpdateMonIconFrame(sprite); // Animate the mon icon.

        sprite->x = ((sprite->sFishPosition / POSITION_ADJUSTMENT) + FISH_ICON_MIN_X); // Set the fish sprite location.
    }
}

static void SpriteCB_ScoreMeter(struct Sprite *sprite)
{
    if (gTasks[sprite->sTaskId].tScore <= 0 && sprite->sScorePosition > 0) // If the current score is 0.
    {
        sprite->sScorePosition = 0;
        sprite->x2--; // Move the score meter out of the score area.
    }

    if (gTasks[sprite->sTaskId].tPaused == TRUE) // Don't do anything else if paused.
    {
        goto END;
    }

    if (gTasks[sprite->sTaskId].tScore > (sprite->sScorePosition * SCORE_INTERVAL)) // If the current score has increased to a greater score interval.
    {
        sprite->sScorePosition++;
        sprite->x2++; // Increase the score meter's location by one pixel.
    }
    else if (gTasks[sprite->sTaskId].tScore < ((sprite->sScorePosition - 1) * SCORE_INTERVAL)) // If the current score has decreased to a lower score interval.
    {
        sprite->sScorePosition--;
        sprite->x2--; // Decrease the score meter's location by one pixel.
    }

    if (sprite->sScorePosition > ((sprite->sCurrColorInterval * SCORE_COLOR_INTERVAL) - 1)) // If the score meter has gone above the current color interval.
    {
        sprite->sCurrColorInterval++; // Increase the color interval by 1.
        CalculateScoreMeterPalette(sprite); // Change the score meter palette to reflect the change in color interval.
    }
    else if (sprite->sScorePosition < ((sprite->sCurrColorInterval - 1) * SCORE_COLOR_INTERVAL)) // If the score meter has gone below the current color interval.
    {
        sprite->sCurrColorInterval--; // Decrease the color interval by 1.
        CalculateScoreMeterPalette(sprite); // Change the score meter palette to reflect the change in color interval.
    }

    if (sprite->sScorePosition >= ((sprite->sScoreThird + 1) * SCORE_THIRD_SIZE)) // If the score position has gone above the current score third.
    {
        if (sprite->sScoreThird < 2) // If the score third isn't already at the maximum.
        {
            sprite->sScoreThird++; // Increase the score third by one.

            if (sprite->sTextCooldown == 0) // If the text cooldown counter is at 0.
                UpdateHelpfulTextHigher(sprite->sTaskId); // Show the relevant helpful text.
        }
    }
    else if (sprite->sScorePosition < (((sprite->sScoreThird + 1) * SCORE_THIRD_SIZE) - SCORE_THIRD_SIZE)) // If the score position has gone below the current score third.
    {
        if (sprite->sScoreThird > 0) // If the score third isn't already at the minimum.
        {
            sprite->sScoreThird--; // Decrease the score third by one.

            if (sprite->sTextCooldown == 0) // If the counter is at 0.
                UpdateHelpfulTextLower(sprite->sTaskId); // Show the relevant helpful text.
        }
    }
    if (sprite->sTextCooldown != 0) // If the text cooldown counter is active.
        sprite->sTextCooldown--; // Decrease the text cooldown counter by 1.

    END:
}

static void SpriteCB_ScoreMeterAdditional(struct Sprite *sprite)
{
    if (gTasks[sprite->sTaskId].tPaused == FALSE) // Don't do anything if paused.
    {
        sprite->x2 = (gSprites[gTasks[sprite->sTaskId].tScoreMeterSpriteId].x2); // Set the locations of the additional score meter sprites.
    }
}

static void SpriteCB_Perfect(struct Sprite *sprite)
{
    if (sprite->sPerfectMoveFrames > 2)
    {
        sprite->y2--;
        sprite->sPerfectMoveFrames = 0;
        sprite->sPerfectFrameCount++;
    }

    if (sprite->sPerfectFrameCount == 25)
        DestroySprite(sprite);

    sprite->sPerfectMoveFrames++;
}

static void CB2_FishingBattleTransition(void)
{
    ResetTasks();
    PlayBattleBGM(); // Play the battle music.
    SetMainCallback2(CB2_FishingBattleStart);
    BattleTransition_Start(B_TRANSITION_WAVE); // Start the battle transition. The only other transitions that work properly here are B_TRANSITION_SLICE and B_TRANSITION_GRID_SQUARES.
}

static void CB2_FishingBattleStart(void)
{
    UpdatePaletteFade();
    RunTasks();

    if (IsBattleTransitionDone() == TRUE) // If the battle transition has fully completed.
    {
        gMain.savedCallback = CB2_ReturnToField;
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitBattle); // Start the battle.
        RestartWildEncounterImmunitySteps();
        ClearPoisonStepCounter();
        IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
        IncrementGameStat(GAME_STAT_WILD_BATTLES);
        IncrementDailyWildBattles();
        if (GetGameStat(GAME_STAT_WILD_BATTLES) % 60 == 0)
            UpdateGymLeaderRematch();
    }
}
