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
#define tState                  data[1]

#define ITEM_TOAST_DURATION     90      //number of frames each toast will display for (divide by 60 to get seconds)
#define TOAST_QUEUE_SIZE        8       //number of entries the toast queue can hold - 8 should be sufficient

//Task states
enum{
    STATE_TOAST_DRAW,
    STATE_TOAST_WAIT,
};

EWRAM_DATA static u8 sHeaderBoxWindowId = 0;
EWRAM_DATA u8 sItemToastIconSpriteId = 0;
EWRAM_DATA u8 sItemToastIconSpriteId2 = 0;

static void Task_ItemToastDraw(u8 taskId);
static void Task_ItemToastWait(u8 taskId);

//Circular Queue (Ring Buffer) data
struct ToastMessage
{
    u16 item;
    u16 quantity;
};

//defines the RingBuf (circular queue) structure
typedef struct RingBuf
{
    size_t readPtr;
    size_t writePtr;
    struct ToastMessage arr[TOAST_QUEUE_SIZE];
    bool8 full;
}RingBuf;

//Maps toast task state to functions
static void (*const sToastTaskFunctions[])(u8) = 
{
    [STATE_TOAST_DRAW]       = Task_ItemToastDraw,
    [STATE_TOAST_WAIT]       = Task_ItemToastWait,
};

static RingBuf sRingBuf = {0};                      //initialize sRingBuf

static void ConstructItemToastMessage(u16 item, u16 amount);
static void ShowItemToastIconSprite(u16 item, bool8 firstTime, bool8 flash);
static void DestroyItemToastIconSprite(void);
static void ToastRingBufferWrite(RingBuf* rb, struct ToastMessage newToast);
static struct ToastMessage ToastRingBufferRead(RingBuf* rb);
static void DestroyItemToast(void);

//Item Toast strings
static u8 sToastMessage[ITEM_NAME_LENGTH + MOVE_NAME_LENGTH];                           //Actual size of the array doesnt seem to matter
static u8 sToastItemAmount[3];
static u8 sToastItemName[ITEM_NAME_LENGTH];

//Constructs Item Toast message from strings
static void ConstructItemToastMessage(u16 item, u16 amount)
{
    //Copy item name to sToastItemName
    StringCopy(sToastItemName, GetItemName(item));
    //Set sToastItemAmount to amount
    ConvertIntToDecimalStringN(sToastItemAmount, amount, STR_CONV_MODE_LEFT_ALIGN, 3); //converts amount into string

    u8 *txtPtr = sToastMessage;
    //Appends string sections
    //Text Colour is set in the initial string, and reset at the end string
    txtPtr = StringCopy(txtPtr, gText_ItemToastPlus);
    txtPtr = StringAppend(txtPtr, sToastItemAmount);
    StringAppend(txtPtr, gText_Space);
    StringAppend(txtPtr, sToastItemName);

    switch (GetPocketByItemId(item))
    {
        default:
        case POCKET_NONE:
            txtPtr = StringAppend(txtPtr, gText_ItemToastEndNoPocket);                //If no pocket is found: Empty string that sets text colour back to default
            break;
        case POCKET_ITEMS:
            txtPtr = StringAppend(txtPtr, gText_ItemToastNewline);
            txtPtr = StringAppend(txtPtr, gText_Items);
            txtPtr = StringAppend(txtPtr, gText_ItemToastEndBracket);
            break;
        case POCKET_POKE_BALLS:
            txtPtr = StringAppend(txtPtr, gText_ItemToastNewline);
            txtPtr = StringAppend(txtPtr, gText_Poke_Balls);
            txtPtr = StringAppend(txtPtr, gText_ItemToastEndBracket);
            break;
        case POCKET_TM_HM:
            txtPtr = StringAppend(txtPtr, gText_ItemToastColon);                      //For TMs and HMs - append move name after colon
            txtPtr = StringAppend(txtPtr, GetMoveName(ItemIdToBattleMoveId(item)));
            txtPtr = StringAppend(txtPtr, gText_ItemToastNewline);
            txtPtr = StringAppend(txtPtr, gText_TMs_Hms);
            txtPtr = StringAppend(txtPtr, gText_ItemToastEndBracket);
            break;
        case POCKET_BERRIES:
            txtPtr = StringAppend(txtPtr, gText_ItemToastNewline);
            txtPtr = StringAppend(txtPtr, gText_Berries2);
            txtPtr = StringAppend(txtPtr, gText_ItemToastEndBracket);
            break;
        case POCKET_KEY_ITEMS:
            txtPtr = StringAppend(txtPtr, gText_ItemToastNewline);
            txtPtr = StringAppend(txtPtr, gText_Key_Items);
            txtPtr = StringAppend(txtPtr, gText_ItemToastEndBracket);
            break;
    }
}

//Checks if toast task is NOT active
bool8 ItemToastIsNotActive(void)
{
    if ((FindTaskIdByFunc(Task_ItemToastMessage) == TASK_NONE))
        return TRUE;
    else
        return FALSE;
}

//Function that gets called from scripts when obtaining items
void ScriptCreateItemToast(struct ScriptContext *ctx)
{
    struct ToastMessage newToast;
    newToast.item = VarGet(ScriptReadHalfword(ctx));
    newToast.quantity = VarGet(ScriptReadHalfword(ctx));
    ToastRingBufferWrite(&sRingBuf, newToast);

    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);
    if (ItemToastIsNotActive())
    {
        gTasks[CreateTask(Task_ItemToastMessage, 0)].tState = STATE_TOAST_DRAW;
    }
}

//Calls the function based on the task state
void Task_ItemToastMessage(u8 taskId)
{
    sToastTaskFunctions[gTasks[taskId].tState](taskId);
}

//Task to setup and draw the sprite and toast text
static void Task_ItemToastDraw(u8 taskId)
{
    struct ToastMessage toast = ToastRingBufferRead(&sRingBuf);
    //If next index is empty, destroy the task
    if (toast.item == 0 && toast.quantity == 0)
    {
        DestroyTask(taskId);
        return;
    }

    struct WindowTemplate template;
    u8 textY = 0;
    bool8 handleFlash = FALSE;
    u8 color[3] = {0, 2, 3};                                    //Defines BG colour 0 (transparent), actual text colour is set in the strings

    ConstructItemToastMessage(toast.item, toast.quantity);    //Construct toast popup message from item and quantity

    if (GetFlashLevel() > 0 || InBattlePyramid_())          //Prevents flash tint blending over icons
        handleFlash = TRUE;

    //Sets up window template for text
    SetWindowTemplateFields(&template, 0, 1, 3, 18, 3, 15, 8);
    sHeaderBoxWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sHeaderBoxWindowId, PIXEL_FILL(0));   //This should not have been removed in the previous commit, fixes some display issues
    PutWindowTilemap(sHeaderBoxWindowId);
    CopyWindowToVram(sHeaderBoxWindowId, 3);
    
    PlayFanfare(MUS_OBTAIN_ITEM);                               //Moves fanfare SFX to item toast to sync with display
    ShowItemToastIconSprite(toast.item, TRUE, handleFlash);     //Creates icon sprite
    AddTextPrinterParameterized4(sHeaderBoxWindowId, FONT_SMALL, ITEM_ICON_X + 2, textY, 1, 0, color, TEXT_SKIP_DRAW, sToastMessage);  //Used by things like Credits for transparent BG text
    gTasks[taskId].tTimer = 0;                                  //Reset task timer to 0
    gTasks[taskId].tState = STATE_TOAST_WAIT;                   //Advance toast state to WAIT after toast is drawn
}

//Wait task - continue displaying toast until ITEM_TOAST_DURATION is reached
static void Task_ItemToastWait(u8 taskId)
{
    if (++gTasks[taskId].tTimer >= ITEM_TOAST_DURATION)
    {
        DestroyItemToast();
        gTasks[taskId].tState = STATE_TOAST_DRAW;
    }
}

//Destroy the toast when done, clears icon sprite and text window
static void DestroyItemToast(void)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE | SCREFF_HARDWARE);
    DestroyItemToastIconSprite();
    ClearStdWindowAndFrameToTransparent(sHeaderBoxWindowId, FALSE);
    CopyWindowToVram(sHeaderBoxWindowId, 3);
    RemoveWindow(sHeaderBoxWindowId);
}

//Cloned from ShowItemIconSprite in overworld.c
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

//Cloned from DestroyItemIconSprite in overworld.c
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

//------
//Circular Queue (Ring Buffer)
//Writes incoming toast data to the circular queue
static void ToastRingBufferWrite(RingBuf* rb, struct ToastMessage newToast)
{
    if (rb->full == TRUE)
    {
        rb->readPtr += 1;                           //increment read pointer by 1
        if (rb->readPtr > (TOAST_QUEUE_SIZE - 1))
            rb->readPtr = 0;                        //if index is about to exceed que size, loop back to index 0
    }
    rb->arr[rb->writePtr] = newToast;
    rb->writePtr += 1;                              //increment write pointer by 1
    if (rb->writePtr > (TOAST_QUEUE_SIZE - 1))      //Out of bounds check for writePtr
        rb->writePtr = 0;
    if (rb->writePtr == rb->readPtr)
        rb->full = TRUE;                            //if write pointer == read pointer, set full to TRUE
}

//Reads next (oldest first) toast data from circular queue
static struct ToastMessage ToastRingBufferRead(RingBuf* rb)
{
    struct ToastMessage toastData = {0};                      //initialize ToastMessage struct (set data to 0)
    if (rb->readPtr != rb->writePtr || rb->full == TRUE)
    {
        toastData = rb->arr[rb->readPtr];
        rb->readPtr += 1;
        rb->full = FALSE;
        if (rb->readPtr > (TOAST_QUEUE_SIZE - 1))
            rb->readPtr = 0;
    }
    return toastData;
}

#undef tTimer
#undef tState
