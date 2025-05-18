#include "global.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "faraway_island.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "malloc.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "party_menu.h"
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


// this file's functions
static void FieldCallback_Douse(void);
static void StartDouseFieldEffect(void);


bool8 SetUpFieldMove_Douse(void)
{
    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LARGE_FIRE) == TRUE)
    {
        // Standing in front of large fire.
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Douse;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void FieldCallback_Douse(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseDouse);
}

bool8 FldEff_UseDouse(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartDouseFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartDouseFieldEffect;
	DoFieldMoveFriendshipChance(&gPlayerParty[gFieldEffectArguments[0]]);
    IncrementGameStat(GAME_STAT_USED_DOUSE);
    return FALSE;
}

static void StartDouseFieldEffect(void)
{
    PlaySE(SE_M_SURF);
    FieldEffectActiveListRemove(FLDEFF_USE_DOUSE);
    ScriptContext_Enable();
}

