#include "global.h"
#include "battle_pyramid.h"
#include "gpu_regs.h"
#include "event_data.h"
#include "item.h"
#include "item_icon.h"
#include "item_toasts.h"
#include "menu.h"
#include "move.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "constants/item.h"
#include "constants/songs.h"

// ----------------
// Repurposes a lot of code from ShowItemDescriptions
// Item Toast Header

#define ITEM_ICON_X             26
#define ITEM_ICON_Y             24 + 16
#define ITEM_TAG                0x2722 //same as money label
#define tTimer                  data[0]
#define ITEM_TOAST_DURATION     90
static bool8 sToastActive = FALSE;      //Uses a bool to check if task is active - to be replaced with more robust task states

EWRAM_DATA static u8 sHeaderBoxWindowId = 0;
EWRAM_DATA u8 sItemToastIconSpriteId = 0;
EWRAM_DATA u8 sItemToastIconSpriteId2 = 0;

static void ConstructItemToastMessage(u16 item, u16 amount);
static void ShowItemToastIconSprite(u16 item, bool8 firstTime, bool8 flash);
static void Task_HideItemToast(u8 taskId);
static void DestroyItemToastIconSprite(void);

//Item Toast strings
static u8 sToastMessage[40];
static u8 sToastItemAmount[3];
static u8 sToastItemName[ITEM_NAME_LENGTH + 2];

//Constructs Item Toast message from strings
static void ConstructItemToastMessage(u16 item, u16 amount)
{
    //Copy item name to sToastItemName
    StringCopy(sToastItemName, GetItemName(item));
    //Set sToastItemAmount to amount
    ConvertIntToDecimalStringN(sToastItemAmount, amount, STR_CONV_MODE_LEFT_ALIGN, 3); //converts amount into string
    //Appends string sections
    //Text Colour is set in the string
    StringCopy(sToastMessage, gText_ItemToastPlus);
    StringAppend(sToastMessage, sToastItemAmount);
    StringAppend(sToastMessage, gText_Space);
    StringAppend(sToastMessage, sToastItemName);

    switch (GetPocketByItemId(item))
    {
        default:
        case POCKET_NONE:
            StringAppend(sToastMessage, gText_ItemToastEndNoPocket);                //If no pocket is found: Empty string that sets text colour back to default
            break;
        case POCKET_ITEMS:
            StringAppend(sToastMessage, gText_ItemToastNewline);
            StringAppend(sToastMessage, gText_Items);
            StringAppend(sToastMessage, gText_ItemToastEndBracket);
            break;
        case POCKET_POKE_BALLS:
            StringAppend(sToastMessage, gText_ItemToastNewline);
            StringAppend(sToastMessage, gText_Poke_Balls);
            StringAppend(sToastMessage, gText_ItemToastEndBracket);
            break;
        case POCKET_TM_HM:
            StringAppend(sToastMessage, gText_ItemToastColon);                      //For TMs and HMs - append move name after colon
            StringAppend(sToastMessage, GetMoveName(ItemIdToBattleMoveId(item)));
            StringAppend(sToastMessage, gText_ItemToastNewline);
            StringAppend(sToastMessage, gText_TMs_Hms);
            StringAppend(sToastMessage, gText_ItemToastEndBracket);
            break;
        case POCKET_BERRIES:
            StringAppend(sToastMessage, gText_ItemToastNewline);
            StringAppend(sToastMessage, gText_Berries2);
            StringAppend(sToastMessage, gText_ItemToastEndBracket);
            break;
        case POCKET_KEY_ITEMS:
            StringAppend(sToastMessage, gText_ItemToastNewline);
            StringAppend(sToastMessage, gText_Key_Items);
            StringAppend(sToastMessage, gText_ItemToastEndBracket);
            break;
    }
}


void ScriptShowItemToast(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);
    if (sToastActive == TRUE)
        DestroyItemToastIconSprite();               //ToDo: Add circular queue. For now, it just destroy existing sprite before creating a new one

    struct WindowTemplate template;
    u16 item = VarGet(ScriptReadHalfword(ctx));
    u16 amount = VarGet(ScriptReadHalfword(ctx));
    u8 textY = 0;
    bool8 handleFlash = FALSE;
    u8 color[3] = {0, 2, 3};                    //Defines BG colour 0 (transparent)
    ConstructItemToastMessage(item, amount);    //Construct toast popup message from item and amount

    if (GetFlashLevel() > 0 || InBattlePyramid_())
        handleFlash = TRUE;

    //Sets up window template for text
    SetWindowTemplateFields(&template, 0, 1, 3, 18, 3, 15, 8);
    sHeaderBoxWindowId = AddWindow(&template);
    PutWindowTilemap(sHeaderBoxWindowId);
    CopyWindowToVram(sHeaderBoxWindowId, 3);
    
    PlayFanfare(MUS_OBTAIN_ITEM);               //Moves fanfare SFX to item toast to sync with display
    ShowItemToastIconSprite(item, TRUE, handleFlash);
    AddTextPrinterParameterized4(sHeaderBoxWindowId, FONT_SMALL, ITEM_ICON_X + 2, textY, 1, 0, color, TEXT_SKIP_DRAW, sToastMessage);  //Used by things like Credits for transparent BG text
    sToastActive = TRUE;
    CreateTask(Task_HideItemToast, 0);
}

static void Task_HideItemToast(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE | SCREFF_HARDWARE);
    if (tTimer >= ITEM_TOAST_DURATION)
    {
        DestroyItemToastIconSprite();
        ClearStdWindowAndFrameToTransparent(sHeaderBoxWindowId, FALSE);
        CopyWindowToVram(sHeaderBoxWindowId, 3);
        RemoveWindow(sHeaderBoxWindowId);
        sToastActive = FALSE;
        tTimer = 0;
        DestroyTask(taskId);
    }
    else
        tTimer++;
}

static void ShowItemToastIconSprite(u16 item, bool8 firstTime, bool8 flash)
{
    s16 x = 0, y = 0;
    u8 iconSpriteId;
    u8 spriteId2 = MAX_SPRITES;

    if (flash)
    {
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
    }

    iconSpriteId = AddItemIconSprite(ITEM_TAG, ITEM_TAG, item);
    if (flash)
        spriteId2 = AddItemIconSprite(ITEM_TAG, ITEM_TAG, item);
    if (iconSpriteId != MAX_SPRITES)
    {
        if (!firstTime)
        {
            //show in message box
            x = 213;
            y = 140;
        }
        else
        {
            // show in header box
            x = ITEM_ICON_X;
            y = ITEM_ICON_Y;
        }

        gSprites[iconSpriteId].x2 = x;
        gSprites[iconSpriteId].y2 = y;
        gSprites[iconSpriteId].oam.priority = 0;
    }

    if (spriteId2 != MAX_SPRITES)
    {
        gSprites[spriteId2].x2 = x;
        gSprites[spriteId2].y2 = y;
        gSprites[spriteId2].oam.priority = 0;
        gSprites[spriteId2].oam.objMode = ST_OAM_OBJ_WINDOW;
        sItemToastIconSpriteId2 = spriteId2;
    }

    sItemToastIconSpriteId = iconSpriteId;
}

static void DestroyItemToastIconSprite(void)
{
    FreeSpriteTilesByTag(ITEM_TAG);
    FreeSpritePaletteByTag(ITEM_TAG);
    FreeSpriteOamMatrix(&gSprites[sItemToastIconSpriteId]);
    DestroySprite(&gSprites[sItemToastIconSpriteId]);

    if ((GetFlashLevel() > 0 || InBattlePyramid_()) && sItemToastIconSpriteId2 != MAX_SPRITES)
    {
        FreeSpriteOamMatrix(&gSprites[sItemToastIconSpriteId2]);
        DestroySprite(&gSprites[sItemToastIconSpriteId2]);
    }
}

#undef tTimer
