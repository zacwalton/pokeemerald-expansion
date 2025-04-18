#include "global.h"
#include "dynamic_palettes.h"
#include "list_menu.h"
#include "menu.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"

// *MODIFY*
// Define all dynamic palettes here and in dynamic_palettes.h
EWRAM_DATA u16 sDynPalPlayerOverworld[16] = {0};
EWRAM_DATA u16 sDynPalPlayerReflection[16] = {0};
EWRAM_DATA u16 sDynPalPlayerUnderwater[16] = {0};
EWRAM_DATA u16 sDynPalPlayerBattleFront[16] = {0};
EWRAM_DATA u16 sDynPalPlayerBattleBack[16] = {0};

// *MODIFY*
// Define palette colors from files
const u16 sDynPal_Base[] = INCBIN_U16("graphics/dynpal/player_dynpal_base.gbapal");
// SAMPLE PALETTE PARTS
const u16 sDynPal_Part_Skin1[] = INCBIN_U16("graphics/dynpal/player_dynpal_skin_1.gbapal");
const u16 sDynPal_Part_Skin2[] = INCBIN_U16("graphics/dynpal/player_dynpal_skin_2.gbapal");
const u16 sDynPal_Part_Skin3[] = INCBIN_U16("graphics/dynpal/player_dynpal_skin_3.gbapal");
const u16 sDynPal_Part_Skin4[] = INCBIN_U16("graphics/dynpal/player_dynpal_skin_4.gbapal");
const u16 sDynPal_Part_Hair1[] = INCBIN_U16("graphics/dynpal/player_dynpal_hair_blonde.gbapal");
const u16 sDynPal_Part_Hair2[] = INCBIN_U16("graphics/dynpal/player_dynpal_hair_brown.gbapal");
const u16 sDynPal_Part_Hair3[] = INCBIN_U16("graphics/dynpal/player_dynpal_hair_black.gbapal");
const u16 sDynPal_Part_Hair4[] = INCBIN_U16("graphics/dynpal/player_dynpal_hair_red.gbapal");
const u16 sDynPal_Part_Eyes1[] = INCBIN_U16("graphics/dynpal/player_dynpal_eyes_blue.gbapal");
const u16 sDynPal_Part_Eyes2[] = INCBIN_U16("graphics/dynpal/player_dynpal_eyes_green.gbapal");
const u16 sDynPal_Part_Eyes3[] = INCBIN_U16("graphics/dynpal/player_dynpal_eyes_hazel.gbapal");
const u16 sDynPal_Part_Eyes4[] = INCBIN_U16("graphics/dynpal/player_dynpal_eyes_brown.gbapal");
const u16 sDynPal_Part_Clothes_Blue[] = INCBIN_U16("graphics/dynpal/player_dynpal_clothes_blue.gbapal");
const u16 sDynPal_Part_Clothes_Red[] = INCBIN_U16("graphics/dynpal/player_dynpal_clothes_red.gbapal");
const u16 sDynPal_Part_Clothes_Green[] = INCBIN_U16("graphics/dynpal/player_dynpal_clothes_green.gbapal");
const u16 sDynPal_Part_Clothes_Black[] = INCBIN_U16("graphics/dynpal/player_dynpal_clothes_black.gbapal");
const u16 sDynPal_Part_Clothes_White[] = INCBIN_U16("graphics/dynpal/player_dynpal_clothes_white.gbapal");
const u16 sDynPal_Part_Clothes_Grey[] = INCBIN_U16("graphics/dynpal/player_dynpal_clothes_grey.gbapal");
const u16 sDynPal_Part_Clothes_Yellow[] = INCBIN_U16("graphics/dynpal/player_dynpal_clothes_yellow.gbapal");
const u16 sDynPal_Part_Clothes_Orange[] = INCBIN_U16("graphics/dynpal/player_dynpal_clothes_orange.gbapal");

// *MODIFY*
// Text definitions for intro / menus
const u8 sText_DynPal_Skin1[] = _("SKIN TONE 1");
const u8 sText_DynPal_Skin2[] = _("SKIN TONE 2");
const u8 sText_DynPal_Skin3[] = _("SKIN TONE 3");
const u8 sText_DynPal_Skin4[] = _("SKIN TONE 4");
const u8 sText_DynPal_Hair1[] = _("BLONDE");
const u8 sText_DynPal_Hair2[] = _("BROWN");
const u8 sText_DynPal_Hair3[] = _("BLACK");
const u8 sText_DynPal_Hair4[] = _("RED");
const u8 sText_DynPal_Eyes1[] = _("BLUE");
const u8 sText_DynPal_Eyes2[] = _("GREEN");
const u8 sText_DynPal_Eyes3[] = _("HAZEL");
const u8 sText_DynPal_Eyes4[] = _("BROWN");
const u8 sText_DynPal_Clothes_Blue[] = _("BLUE");
const u8 sText_DynPal_Clothes_Red[] = _("RED");
const u8 sText_DynPal_Clothes_Green[] = _("GREEN");
const u8 sText_DynPal_Clothes_Black[] = _("BLACK");
const u8 sText_DynPal_Clothes_White[] = _("WHITE");
const u8 sText_DynPal_Clothes_Grey[] = _("GREY");
const u8 sText_DynPal_Clothes_Yellow[] = _("YELLOW");
const u8 sText_DynPal_Clothes_Orange[] = _("ORANGE");

// *MODIFY*
// Preset lists (indices in these lists are what is saved to game save)
static const struct SpritePalette sDynPalPartAPresets[] = {
    {sDynPal_Part_Skin1, 0x1301},
    {sDynPal_Part_Skin2, 0x1302},
    {sDynPal_Part_Skin3, 0x1303},
    {sDynPal_Part_Skin4, 0x1304}
};

// *MODIFY*
static const struct SpritePalette sDynPalPartBPresets[] = {
    {sDynPal_Part_Hair1, 0x1305},
    {sDynPal_Part_Hair2, 0x1306},
    {sDynPal_Part_Hair3, 0x1307},
    {sDynPal_Part_Hair4, 0x1308}
};

// *MODIFY*
static const struct SpritePalette sDynPalPartEPresets[] = {
    {sDynPal_Part_Eyes1, 0x1309},
    {sDynPal_Part_Eyes2, 0x130A},
    {sDynPal_Part_Eyes3, 0x130B},
    {sDynPal_Part_Eyes4, 0x130C}
};

// *MODIFY*
static const struct SpritePalette sDynPalPartCPresets[] = {
    {sDynPal_Part_Clothes_Blue, 	0x130D},
    {sDynPal_Part_Clothes_Red, 		0x130E},
    {sDynPal_Part_Clothes_Green, 	0x130F},
    {sDynPal_Part_Clothes_Black, 	0x1310},
    {sDynPal_Part_Clothes_White, 	0x1311},
    {sDynPal_Part_Clothes_Grey, 	0x1312},
    {sDynPal_Part_Clothes_Yellow, 	0x1313},
    {sDynPal_Part_Clothes_Orange, 	0x1314}
};

// *MODIFY*
static const struct SpritePalette sDynPalPartDPresets[] = {
    {sDynPal_Part_Clothes_Blue, 	0x130D},
    {sDynPal_Part_Clothes_Red, 		0x130E},
    {sDynPal_Part_Clothes_Green, 	0x130F},
    {sDynPal_Part_Clothes_Black, 	0x1310},
    {sDynPal_Part_Clothes_White, 	0x1311},
    {sDynPal_Part_Clothes_Grey, 	0x1312},
    {sDynPal_Part_Clothes_Yellow, 	0x1313},
    {sDynPal_Part_Clothes_Orange, 	0x1314}
};

// *MODIFY*
// Change to match counts for preceding arrays
#define COUNT_PART_A_TONES 4
#define COUNT_PART_B_TONES 4
#define COUNT_PART_E_TONES 4
#define COUNT_PART_C_TONES 8
#define COUNT_PART_D_TONES 8

// *MODIFY*
// List text definitions for menu
static const struct ListMenuItem sListItems_DynPal_PartATones[] = {
    {sText_DynPal_Skin1, 0},
    {sText_DynPal_Skin2, 1},
    {sText_DynPal_Skin3, 2},
    {sText_DynPal_Skin4, 3}
};
static const struct ListMenuItem sListItems_DynPal_PartBTones[] = {
    {sText_DynPal_Hair1, 0},
    {sText_DynPal_Hair2, 1},
    {sText_DynPal_Hair3, 2},
    {sText_DynPal_Hair4, 3}
};
static const struct ListMenuItem sListItems_DynPal_PartETones[] = {
    {sText_DynPal_Eyes1, 0},
    {sText_DynPal_Eyes2, 1},
    {sText_DynPal_Eyes3, 2},
    {sText_DynPal_Eyes4, 3}
};
static const struct ListMenuItem sListItems_DynPal_PartCTones[] = {
    {sText_DynPal_Clothes_Blue, 0},
    {sText_DynPal_Clothes_Red, 1},
    {sText_DynPal_Clothes_Green, 2},
    {sText_DynPal_Clothes_Black, 3},
    {sText_DynPal_Clothes_White, 4},
    {sText_DynPal_Clothes_Grey, 5},
    {sText_DynPal_Clothes_Yellow, 6},
    {sText_DynPal_Clothes_Orange, 7}
};
static const struct ListMenuItem sListItems_DynPal_PartDTones[] = {
    {sText_DynPal_Clothes_Blue, 0},
    {sText_DynPal_Clothes_Red, 1},
    {sText_DynPal_Clothes_Green, 2},
    {sText_DynPal_Clothes_Black, 3},
    {sText_DynPal_Clothes_White, 4},
    {sText_DynPal_Clothes_Grey, 5},
    {sText_DynPal_Clothes_Yellow, 6},
    {sText_DynPal_Clothes_Orange, 7}
};

// Dynamic palette definitions are split into 3 groups of 5, starting from palette index 1.
#define DYNPAL_COLOR_GROUP_NORMAL 0
#define DYNPAL_COLOR_GROUP_REFLECTION 5
#define DYNPAL_COLOR_GROUP_UNDERWATER 10

static void DynPal_InitOverworld(u16* dest, const u16* partAPalData, const u16* partBPalData, const u16* partCPalData, const u16* partDPalData, const u16* partEPalData, int groupOffset);
static void DynPal_InitBattleFront(u16* dest, const u16* partAPalData, const u16* partBPalData, const u16* partCPalData, const u16* partDPalData, const u16* partEPalData, int groupOffset);
static void DynPal_InitBattleBack(u16* dest, const u16* partAPalData, const u16* partBPalData, const u16* partCPalData, const u16* partDPalData, const u16* partEPalData, int groupOffset);

static void DynPal_CopySection(const u16* src, u16* dest, int srcInd, int destInd, int groupOffset, int numberOfColors);
static void DynPal_SetToneIndices(u8 partATone, u8 partBTone, u8 partCTone, u8 partDTone, u8 partETone);

static void Task_DynPal_MenuOne(u8 taskId);
static void Task_DynPal_MenuSequence(u8 taskId);
static void Task_DynPal_MenuFinish(u8 taskId);
static void Task_DynPal_MenuCancel(u8 taskId);
static void Task_HandleDynPalMultichoiceInput(u8 taskId);

static void DynPal_MenuInit();
static void DynPal_MenuShow(u8 taskId);
static void DynPal_MenuCursorMoved(s32 itemIndex, bool8 onInit, struct ListMenu* list);
static void DynPal_MenuSaveToneIndex(int dynPalType, int tone);
static void DynPal_ReloadToneForMenuByType(int dynPalType, int tone);
static void DynPal_ReloadPlayerPaletteForMenu(u16 paletteTag, u8 partATone, u8 partBTone, u8 partCTone, u8 partDTone, u8 partETone);

// *MODIFY*
// Fill all dynamic palettes with data according to indices in Save Block
void DynPal_InitAllDynamicPalettes()
{
    const u16* partAPalData = sDynPalPartAPresets[min(gSaveBlock2Ptr->dynPalPartAPreset, COUNT_PART_A_TONES)].data;
    const u16* partBPalData = sDynPalPartBPresets[min(gSaveBlock2Ptr->dynPalPartBPreset, COUNT_PART_B_TONES)].data;
    const u16* partCPalData = sDynPalPartCPresets[min(gSaveBlock2Ptr->dynPalPartCPreset, COUNT_PART_C_TONES)].data;
    const u16* partDPalData = sDynPalPartDPresets[min(gSaveBlock2Ptr->dynPalPartDPreset, COUNT_PART_D_TONES)].data;
    const u16* partEPalData = sDynPalPartEPresets[min(gSaveBlock2Ptr->dynPalPartEPreset, COUNT_PART_E_TONES)].data;

    // Player Normal
    DynPal_InitOverworld(sDynPalPlayerOverworld, partAPalData, partBPalData, partCPalData, partDPalData, partEPalData, DYNPAL_COLOR_GROUP_NORMAL);
    // Player Reflection
    DynPal_InitOverworld(sDynPalPlayerReflection, partAPalData, partBPalData, partCPalData, partDPalData, partEPalData, DYNPAL_COLOR_GROUP_REFLECTION);
    // Player Underwater
    DynPal_InitOverworld(sDynPalPlayerUnderwater, partAPalData, partBPalData, partCPalData, partDPalData, partEPalData, DYNPAL_COLOR_GROUP_UNDERWATER);
    // Player Battle Front
    DynPal_InitBattleFront(sDynPalPlayerBattleFront, partAPalData, partBPalData, partCPalData, partDPalData, partEPalData, DYNPAL_COLOR_GROUP_NORMAL);
    // Player Battle Back
    DynPal_InitBattleBack(sDynPalPlayerBattleBack, partAPalData, partBPalData, partCPalData, partDPalData, partEPalData, DYNPAL_COLOR_GROUP_NORMAL);
}

// *MODIFY*
// Load each section of the palette. Your implementation will differ depending on how the sprite palette is arranged.
// For any sections of the palette that should remain constant regardless of parts, use sDynPal_Base as <src>
static void DynPal_InitOverworld(u16* dest, const u16* partAPalData, const u16* partBPalData, const u16* partCPalData, const u16* partDPalData, const u16* partEPalData, int groupOffset)
{
    // Change this function to match your palette setup

    // This setup assumes your male and female characters will be using the same base palette
    // If they don't, you can create a second base palette and check against the selected gender

    //Skin 1-3
    DynPal_CopySection(partAPalData, dest, 1, 1, groupOffset, 3);
    //Eyes 4
    DynPal_CopySection(partEPalData, dest, 1, 4, groupOffset, 1);
    //Hair (+pokeball @8) 5-8
    DynPal_CopySection(partBPalData, dest, 1, 5, groupOffset, 4);
    //Grey 9
    DynPal_CopySection(sDynPal_Base, dest, 1, 9, groupOffset, 1);
    //Clothes 10-11
    DynPal_CopySection(partCPalData, dest, 1, 10, groupOffset, 2);
    //Clothes2 12-13
    DynPal_CopySection(partDPalData, dest, 1, 12, groupOffset, 2);
    //Black&White 14-15
    DynPal_CopySection(sDynPal_Base, dest, 2, 14, groupOffset, 2);
}

// *MODIFY*
// Derive battle front sprite palette - first load the overworld palette, then make modifications. Your specific implementation may differ.
static void DynPal_InitBattleFront(u16* dest, const u16* partAPalData, const u16* partBPalData, const u16* partCPalData, const u16* partDPalData, const u16* partEPalData, int groupOffset)
{
    DynPal_InitOverworld(dest, partAPalData, partBPalData, partCPalData, partDPalData, partEPalData, groupOffset);

    //Add any modifications you need here
}

// *MODIFY*
// Derive battle front sprite palette - first load the overworld palette, then make modifications. Your specific implementation may differ.
static void DynPal_InitBattleBack(u16* dest, const u16* partAPalData, const u16* partBPalData, const u16* partCPalData, const u16* partDPalData, const u16* partEPalData, int groupOffset)
{
    DynPal_InitOverworld(dest, partAPalData, partBPalData, partCPalData, partDPalData, partEPalData, groupOffset);
    
    //Add any modifications you need here
}

// *MODIFY*
// If you don't want the character sprites to load with parts {0, 0, 0} in the intro, you can set the preferred palette indices here
void DynPal_LoadIntroToneIndices()
{
    DynPal_ReloadPlayerPaletteForMenu(TRAINER_PIC_BRENDAN, 0, 1, 2, 0, 0);
    DynPal_ReloadPlayerPaletteForMenu(TRAINER_PIC_MAY, 0, 1, 2, 0, 0);
}

// Copies <numberOfColors> values from the ROM palette <src>, to dynamic palette <dest>
static void DynPal_CopySection(const u16* src, u16* dest, int srcInd, int destInd, int groupOffset, int numberOfColors)
{
    CpuCopy16(&src[srcInd + groupOffset], &dest[destInd], numberOfColors * 2);
}

// Load the palette to active palettes using a known offset
void DynPal_LoadPaletteByOffset(u16* paletteData, u16 paletteOffset)
{
    // Standard palette loading expects the palette to be in ROM (const). Circumvent that
    memcpy(&gPlttBufferFaded[paletteOffset], paletteData, PLTT_SIZE_4BPP);
    memcpy(&gPlttBufferUnfaded[paletteOffset], paletteData, PLTT_SIZE_4BPP);
}

// Load the palette to active palettes using a known sprite tag
void DynPal_LoadPaletteByTag(u16* paletteData, u16 paletteTag)
{
    struct SpritePalette dest;

    // Free the palette tag if it is already initialized
    FreeSpritePaletteByTag(paletteTag);
    // Could just memcpy but nominally doing this the 'right' way for no particular reason
    dest.data = paletteData;
    dest.tag = paletteTag;
    LoadSpritePalette(&dest);
}

// Write palette indices to save block (can send 0xFF to exclude that tone list)
static void DynPal_SetToneIndices(u8 partATone, u8 partBTone, u8 partCTone, u8 partDTone, u8 partETone)
{
    if (partATone != 0xFF)
    {
        gSaveBlock2Ptr->dynPalPartAPreset = partATone % COUNT_PART_A_TONES;
    }
    if (partBTone != 0xFF)
    {
        gSaveBlock2Ptr->dynPalPartBPreset = partBTone % COUNT_PART_B_TONES;
    }
    if (partETone != 0xFF)
    {
        gSaveBlock2Ptr->dynPalPartEPreset = partETone % COUNT_PART_E_TONES;
    }
    if (partCTone != 0xFF)
    {
        gSaveBlock2Ptr->dynPalPartCPreset = partCTone % COUNT_PART_C_TONES;
    }
    if (partDTone != 0xFF)
    {
        gSaveBlock2Ptr->dynPalPartDPreset = partDTone % COUNT_PART_D_TONES;
    }
}

// LIST HANDLER DATA

#define DYNPAL_MENU_ID_CANCEL -1
#define DYNPAL_MENU_ID_PART_A 0
#define DYNPAL_MENU_ID_PART_B 1
#define DYNPAL_MENU_ID_PART_E 2
#define DYNPAL_MENU_ID_PART_C 3
#define DYNPAL_MENU_ID_PART_D 4
#define DYNPAL_MENU_ID_FINISH 5

// Dynpal list menu template
static const struct ListMenuTemplate sListTemplate_DynPal =
{
    .moveCursorFunc = DynPal_MenuCursorMoved,
    .itemPrintFunc = NULL,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Dynpal list flow extra data
static EWRAM_DATA struct {
    s16 menuSeq;
    bool8 isActive;
    bool8 isOverworld;
    TaskFunc funcCancel;
    TaskFunc funcFinish;
    u8 partATone;
    u8 partBTone;
    u8 partCTone;
    u8 partDTone;
    u8 partETone;
    u16 scrollOffset;
} sDynPalMenu = {0};

// Task data
#define tDynpalListMenuTask data[0]
#define tDynpalWindowId     data[1]
#define tDynpalNumItems     data[2]
#define tDynpalMaxItems     data[3]
#define tDynpalScrollArrows data[4]
#define tDynpalParentTask   data[5]

// Show just a single menu. Use this if you want text or whatever in between menus
void DynPal_ShowMenuSingleton(s16 dynPalType, u8 taskId, TaskFunc nFuncFinish, TaskFunc nFuncCancel, bool8 isOverworld)
{
    sDynPalMenu.menuSeq = dynPalType;
    sDynPalMenu.funcCancel = nFuncCancel;
    sDynPalMenu.funcFinish = nFuncFinish;
    sDynPalMenu.isOverworld = isOverworld;
    DynPal_MenuInit();
    gTasks[taskId].func = Task_DynPal_MenuOne;
}

// Show all three menus in sequence with nothing in between
void DynPal_ShowMenuSequence(u8 taskId, TaskFunc nFuncFinish, TaskFunc nFuncCancel, bool8 isOverworld)
{
    sDynPalMenu.menuSeq = DYNPAL_MENU_ID_PART_A;
    sDynPalMenu.funcCancel = nFuncCancel;
    sDynPalMenu.funcFinish = nFuncFinish;
    sDynPalMenu.isOverworld = isOverworld;
    DynPal_MenuInit();
    gTasks[taskId].func = Task_DynPal_MenuSequence;
}

// Manager task for singleton dynpal menu
static void Task_DynPal_MenuOne(u8 taskId)
{
    if (!sDynPalMenu.isActive)
    {
        DynPal_MenuShow(taskId);
        gTasks[taskId].func = Task_DynPal_MenuFinish;
    }
}

// Manager task for full sequence dynpal menu
static void Task_DynPal_MenuSequence(u8 taskId)
{
    if (!sDynPalMenu.isActive)
    {
        switch (sDynPalMenu.menuSeq)
        {
        case DYNPAL_MENU_ID_FINISH:
            gTasks[taskId].func = Task_DynPal_MenuFinish;
            break;
        case DYNPAL_MENU_ID_CANCEL:
            gTasks[taskId].func = Task_DynPal_MenuCancel;
            break;
        default:
            DynPal_MenuShow(taskId);
            break;
        }
    }
}

// Set tone indices, init palettes, and exit dynpal menu flow
static void Task_DynPal_MenuFinish(u8 taskId)
{
    // For singleton case, only continue after menu is deactivated again
    if (!sDynPalMenu.isActive)
    {
        DynPal_SetToneIndices(sDynPalMenu.partATone, sDynPalMenu.partBTone, sDynPalMenu.partCTone, sDynPalMenu.partDTone, sDynPalMenu.partETone);
        DynPal_InitAllDynamicPalettes();

        // For overworld use case, reload player palette.
        // This code assumes fixed IDs for player palette, so you may need to change this.
        if (sDynPalMenu.isOverworld)
        {
            DynPal_LoadPaletteByOffset(sDynPalPlayerOverworld, OBJ_PLTT_ID(0));
            DynPal_LoadPaletteByOffset(sDynPalPlayerReflection, OBJ_PLTT_ID(1));
            ScriptContext_Enable();
        }

        if (sDynPalMenu.funcFinish != NULL)
        {
            gTasks[taskId].func = sDynPalMenu.funcFinish;
        }
        else
        {
            DestroyTask(taskId);
        }
    }
}

// Identical to above, minus setting the tone indices from the temp vars
static void Task_DynPal_MenuCancel(u8 taskId)
{
    if (!sDynPalMenu.isActive)
    {
        DynPal_InitAllDynamicPalettes();

        if (sDynPalMenu.isOverworld)
        {
            DynPal_LoadPaletteByOffset(sDynPalPlayerOverworld, OBJ_PLTT_ID(0));
            DynPal_LoadPaletteByOffset(sDynPalPlayerReflection, OBJ_PLTT_ID(1));
            ScriptContext_Enable();
        }

        if (sDynPalMenu.funcFinish != NULL)
        {
            gTasks[taskId].func = sDynPalMenu.funcCancel;
        }
        else
        {
            DestroyTask(taskId);
        }
    }
}


static void DynPal_MenuInit()
{
    sDynPalMenu.isActive = FALSE;
    sDynPalMenu.partATone = 0xFF;
    sDynPalMenu.partBTone = 0xFF;
    sDynPalMenu.partCTone = 0xFF;
    sDynPalMenu.partDTone = 0xFF;
    sDynPalMenu.partETone = 0xFF;
    sDynPalMenu.scrollOffset = 0;
}

// Shows the color menu corresponding to the value in sDynPalMenu.menuSeq
static void DynPal_MenuShow(u8 taskId)
{
    const struct ListMenuItem* menuItems;
    struct WindowTemplate windowTemplate;
    u8 numItems, maxShownItems, listTaskId, windowId;
    switch (sDynPalMenu.menuSeq)
    {
    case DYNPAL_MENU_ID_PART_A:
        menuItems = sListItems_DynPal_PartATones;
        numItems = COUNT_PART_A_TONES;
        break;
    case DYNPAL_MENU_ID_PART_B:
        menuItems = sListItems_DynPal_PartBTones;
        numItems = COUNT_PART_B_TONES;
        break;
    default: // prevent compiler from being sad
    case DYNPAL_MENU_ID_PART_C:
        menuItems = sListItems_DynPal_PartCTones;
        numItems = COUNT_PART_C_TONES;
        break;
    case DYNPAL_MENU_ID_PART_D:
        menuItems = sListItems_DynPal_PartDTones;
        numItems = COUNT_PART_D_TONES;
        break;
    case DYNPAL_MENU_ID_PART_E:
        menuItems = sListItems_DynPal_PartETones;
        numItems = COUNT_PART_E_TONES;
        break;
    }
    // If the menu has no values, skip past it. If you don't want to use one of the part groups this should handle it
    if (numItems == 0)
    {
        ++sDynPalMenu.menuSeq;
        return;
    }

    maxShownItems = min(5, numItems);

    // Create window and menu templates
    windowTemplate = CreateWindowTemplate(0, 2, 2, 10, maxShownItems * 2, 15, 0x80);
    windowId = AddWindow(&windowTemplate);
    LoadUserWindowBorderGfx_(windowId, 0xF3, BG_PLTT_ID(2));
    DrawTextBorderOuter(windowId, 0xF3, 2);

    gMultiuseListMenuTemplate = sListTemplate_DynPal;
    gMultiuseListMenuTemplate.items = menuItems;
    gMultiuseListMenuTemplate.totalItems = numItems;
    gMultiuseListMenuTemplate.maxShowed = maxShownItems;
    gMultiuseListMenuTemplate.windowId = windowId;

    listTaskId = CreateTask(Task_HandleDynPalMultichoiceInput, 0);
    gTasks[listTaskId].tDynpalListMenuTask = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
    gTasks[listTaskId].tDynpalWindowId = windowId;
    gTasks[listTaskId].tDynpalNumItems = numItems;
    gTasks[listTaskId].tDynpalMaxItems = maxShownItems;
    gTasks[listTaskId].tDynpalParentTask = taskId;

    sDynPalMenu.scrollOffset = 0;
    sDynPalMenu.isActive = TRUE;

    if (numItems > maxShownItems)
    {
        gTasks[listTaskId].tDynpalScrollArrows = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP, 56, 12, 100, numItems - 1, 2000, 100, &(sDynPalMenu.scrollOffset));
    }
    else
    {
        gTasks[listTaskId].tDynpalScrollArrows = -1;
    }

    CopyWindowToVram(windowId, COPYWIN_MAP);
}

// Handler for scrollable list input
static void Task_HandleDynPalMultichoiceInput(u8 taskId)
{
    bool32 done = FALSE;
    s32 input = ListMenu_ProcessInput(gTasks[taskId].tDynpalListMenuTask);
    switch (input)
    {
    case LIST_HEADER:
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        // Return to previous list in sequence, or exit to fallback func
        --sDynPalMenu.menuSeq;
        done = TRUE;
        break;
    default:
        // Selection made
        done = TRUE;

        PlaySE(SE_SELECT);

        DynPal_ReloadToneForMenuByType(sDynPalMenu.menuSeq, input);
        DynPal_MenuSaveToneIndex(sDynPalMenu.menuSeq, input);
        // Prepare for next menu in sequence
        ++sDynPalMenu.menuSeq;
        break;
    }

    if (done)
    {
        // Cleanup
        sDynPalMenu.isActive = FALSE;
        // Make sure these were actually initialized before continuing
        if (gTasks[taskId].tDynpalScrollArrows != -1)
        {
            RemoveScrollIndicatorArrowPair(gTasks[taskId].tDynpalScrollArrows);
        }
        DestroyListMenuTask(gTasks[taskId].tDynpalListMenuTask, NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].tDynpalWindowId, TRUE);
        RemoveWindow(gTasks[taskId].tDynpalWindowId);
        DestroyTask(taskId);
    }
}

// Hot reload displayed player palette on cursor move 
static void DynPal_MenuCursorMoved(s32 itemIndex, bool8 onInit, struct ListMenu* list)
{
    sDynPalMenu.scrollOffset = itemIndex;
    DynPal_ReloadToneForMenuByType(sDynPalMenu.menuSeq, itemIndex);
}

// Write selected tones to temp vars. The vars in save block are not written until end of menu sequence, so backing out will cancel any changes
static void DynPal_MenuSaveToneIndex(int dynPalType, int tone)
{
    switch (dynPalType)
    {
    case DYNPAL_MENU_ID_PART_A:
        sDynPalMenu.partATone = tone;
        break;
    case DYNPAL_MENU_ID_PART_B:
        sDynPalMenu.partBTone = tone;
        break;
    case DYNPAL_MENU_ID_PART_C:
        sDynPalMenu.partCTone = tone;
        break;
    case DYNPAL_MENU_ID_PART_D:
        sDynPalMenu.partDTone = tone;
        break;
    case DYNPAL_MENU_ID_PART_E:
        sDynPalMenu.partETone = tone;
        break;
    }
}

// Helper for hot reloading player palette in intro menu
static void DynPal_ReloadToneForMenuByType(int dynPalType, int tone)
{
    switch (dynPalType)
    {
        case DYNPAL_MENU_ID_PART_A:
            DynPal_ReloadPlayerPaletteForMenu(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), tone, 0xFF, 0xFF, 0xFF, 0xFF);
            break;
        case DYNPAL_MENU_ID_PART_B:
            DynPal_ReloadPlayerPaletteForMenu(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), 0xFF, tone, 0xFF, 0xFF, 0xFF);
            break;
        case DYNPAL_MENU_ID_PART_C:
            DynPal_ReloadPlayerPaletteForMenu(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), 0xFF, 0xFF, tone, 0xFF, 0xFF);
            break;
        case DYNPAL_MENU_ID_PART_D:
            DynPal_ReloadPlayerPaletteForMenu(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), 0xFF, 0xFF, 0xFF, tone, 0xFF);
            break;
        case DYNPAL_MENU_ID_PART_E:
            DynPal_ReloadPlayerPaletteForMenu(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), 0xFF, 0xFF, 0xFF, 0xFF, tone);
            break;
    }
}

// *MODIFY*
// Hot reload player palette - Main section should be identical to DynPal_InitOverworld, but split up between each tone
static void DynPal_ReloadPlayerPaletteForMenu(u16 paletteTag, u8 partATone, u8 partBTone, u8 partCTone, u8 partDTone, u8 partETone)
{
    u16 offset;
    if (sDynPalMenu.isOverworld)
    {
        offset = OBJ_PLTT_ID(0);
    }
    else
    {
        offset = OBJ_PLTT_ID(IndexOfSpritePaletteTag(paletteTag));
    }

    if (partATone != 0xFF)
    {
        const u16* partAPalData = sDynPalPartAPresets[min(partATone, COUNT_PART_A_TONES)].data;
        DynPal_CopySection(partAPalData, &gPlttBufferUnfaded[offset], 1, 1, DYNPAL_COLOR_GROUP_NORMAL, 3);
    }
    if (partETone != 0xFF)
    {
        const u16* partEPalData = sDynPalPartEPresets[min(partETone, COUNT_PART_E_TONES)].data;
        DynPal_CopySection(partEPalData, &gPlttBufferUnfaded[offset], 1, 4, DYNPAL_COLOR_GROUP_NORMAL, 1);
    }
    if (partBTone != 0xFF)
    {
        const u16* partBPalData = sDynPalPartBPresets[min(partBTone, COUNT_PART_B_TONES)].data;
        DynPal_CopySection(partBPalData, &gPlttBufferUnfaded[offset], 1, 5, DYNPAL_COLOR_GROUP_NORMAL, 4);
    }
    if (partCTone != 0xFF)
    {
        const u16* partCPalData = sDynPalPartCPresets[min(partCTone, COUNT_PART_C_TONES)].data;
        DynPal_CopySection(partCPalData, &gPlttBufferUnfaded[offset], 1, 10, DYNPAL_COLOR_GROUP_NORMAL, 2);
    }
    if (partDTone != 0xFF)
    {
        const u16* partDPalData = sDynPalPartDPresets[min(partDTone, COUNT_PART_D_TONES)].data;
        DynPal_CopySection(partDPalData, &gPlttBufferUnfaded[offset], 1, 12, DYNPAL_COLOR_GROUP_NORMAL, 2);
    }
    DynPal_CopySection(sDynPal_Base, &gPlttBufferUnfaded[offset], 1, 9, DYNPAL_COLOR_GROUP_NORMAL, 1);
    DynPal_CopySection(sDynPal_Base, &gPlttBufferUnfaded[offset], 2, 14, DYNPAL_COLOR_GROUP_NORMAL, 2);

    /*
    if (!sDynPalMenu.isOverworld)
    {
        // Reflect the code in DynPal_InitBattleFront here
    }
    */

    memcpy(&gPlttBufferFaded[offset], &gPlttBufferUnfaded[offset], PLTT_SIZE_4BPP);
}

// SCRIPT SPECIAL WRAPPERS
void DynPal_ShowFullToneMenu(void)
{
    DynPal_ShowMenuSequence(CreateTask(NULL, 0), NULL, NULL, TRUE);
}

void DynPal_ShowToneMenuA(void)
{
    DynPal_ShowMenuSingleton(DYNPAL_MENU_ID_PART_A, CreateTask(NULL, 0), NULL, NULL, TRUE);
}

void DynPal_ShowToneMenuB(void)
{
    DynPal_ShowMenuSingleton(DYNPAL_MENU_ID_PART_B, CreateTask(NULL, 0), NULL, NULL, TRUE);
}

void DynPal_ShowToneMenuC(void)
{
    DynPal_ShowMenuSingleton(DYNPAL_MENU_ID_PART_C, CreateTask(NULL, 0), NULL, NULL, TRUE);
}

void DynPal_ShowToneMenuD(void)
{
    DynPal_ShowMenuSingleton(DYNPAL_MENU_ID_PART_D, CreateTask(NULL, 0), NULL, NULL, TRUE);
}

void DynPal_ShowToneMenuE(void)
{
    DynPal_ShowMenuSingleton(DYNPAL_MENU_ID_PART_E, CreateTask(NULL, 0), NULL, NULL, TRUE);
}

#undef DYNPAL_MENU_ID_CANCEL
#undef DYNPAL_MENU_ID_PART_A
#undef DYNPAL_MENU_ID_PART_B
#undef DYNPAL_MENU_ID_PART_E
#undef DYNPAL_MENU_ID_PART_C
#undef DYNPAL_MENU_ID_PART_D
#undef DYNPAL_MENU_ID_FINISH
#undef tDynpalListMenuTask
#undef tDynpalWindowId
#undef tDynpalNumItems
#undef tDynpalMaxItems
#undef tDynpalScrollArrows
#undef tDynpalParentTask
