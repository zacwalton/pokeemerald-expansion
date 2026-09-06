#include "global.h"
#include "event_data.h"
#include "menu.h"
#include "move.h"
#include "party_menu.h"
#include "pokemon.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "constants/party_menu.h"
#include "constants/songs.h"

static void Task_StatusHealRemoveStatus(u8 taskId);
static void Task_DisplayStatusRestoredMessage(u8 taskId);
static void Task_FinishStatusHeal(u8 taskId);
static void CantUseStatusHealOnMon(u8 taskId);

bool8 SetUpFieldMove_StatusHeal(void)
{
    u16 moveId = VarGet(VAR_0x8008);
    u8 i;
    u8 j;
    u8 status;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        status = GetMonAilment(&gPlayerParty[i]);

        for (j = 0; gMovesInfo[moveId].fieldStatusHeal[j] != AILMENT_NONE; j++)
        {
            if (status == gMovesInfo[moveId].fieldStatusHeal[j])
                return TRUE;
        }
    }

    return FALSE;
}

void ChooseMonForStatusHeal(u8 taskId)
{
    gPartyMenu.action = PARTY_ACTION_STATUS_HEAL;
    gPartyMenu.slotId2 =  gPartyMenu.slotId;
    AnimatePartySlot(GetCursorSelectionMonId(), 1);
    DisplayPartyMenuStdMessage(PARTY_MSG_USE_ON_WHICH_MON);
    gTasks[taskId].func = Task_HandleChooseMonInput;
}

void Task_TryUseStatusHealOnPartyMon(u8 taskId)
{
    u8 status;
    u8 j;
    u16 moveId = VarGet(VAR_0x8008);
    u8 recipientPartyId = gPartyMenu.slotId2;
    if(recipientPartyId > PARTY_SIZE)
    {
        gPartyMenu.action = 0;
        DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
        gTasks[taskId].func = Task_HandleChooseMonInput;
        return;
    }

    bool8 statusFound = FALSE;
    status = GetMonAilment(&gPlayerParty[recipientPartyId]);
    for (j = 0; gMovesInfo[moveId].fieldStatusHeal[j] != AILMENT_NONE; j++)
    {
        if (status == gMovesInfo[moveId].fieldStatusHeal[j])
        {
            statusFound = TRUE;
            break;
        }
    }
    
    if (statusFound == FALSE)
    {
        CantUseStatusHealOnMon(taskId);
        return;
    }

    status = AILMENT_NONE;
    SetMonData(&gPlayerParty[recipientPartyId], MON_DATA_STATUS, &status);
    UpdatePartyMonStatusGfx(recipientPartyId);
    Task_StatusHealRemoveStatus(taskId);
}

static void Task_StatusHealRemoveStatus(u8 taskId)
{
    PlaySE(SE_USE_ITEM);
    Task_DisplayStatusRestoredMessage(taskId);
}

static void Task_DisplayStatusRestoredMessage(u8 taskId)
{
    //GetMonNickname(&gPlayerParty[gPartyMenu.slotId2], gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_PkmnRemovedStatus);
    DisplayPartyMenuMessage(gStringVar4, FALSE);
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_FinishStatusHeal;
}

static void Task_FinishStatusHeal(u8 taskId)
{
    if(IsPartyMenuTextPrinterActive() == TRUE)
        return;
    gPartyMenu.action = 0;
    AnimatePartySlot(gPartyMenu.slotId, 0);
    gPartyMenu.slotId = gPartyMenu.slotId2;
    AnimatePartySlot(gPartyMenu.slotId2, 1);
    ClearStdWindowAndFrameToTransparent(6, FALSE);
    ClearWindowTilemap(6);
    DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
    gTasks[taskId].func = Task_HandleChooseMonInput;
}

static void Task_ChooseNewMonForStatusHeal(u8 taskId)
{
    if(IsPartyMenuTextPrinterActive() == TRUE)
        return;
    DisplayPartyMenuStdMessage(PARTY_MSG_USE_ON_WHICH_MON);
    gTasks[taskId].func = Task_HandleChooseMonInput;
}

static void CantUseStatusHealOnMon(u8 taskId)
{
    PlaySE(SE_SELECT);
    DisplayPartyMenuMessage(gText_CantBeUsedOnPkmn, FALSE);
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_ChooseNewMonForStatusHeal;
}
