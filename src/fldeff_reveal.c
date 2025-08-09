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
static void FieldCallback_Reveal_Kecleon(void);
void StartRevealFieldEffect(void);


bool8 SetUpFieldMove_Reveal(void)
{
    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_KECLEON) == TRUE)
    {
        // Standing in front of large fire.
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Reveal_Kecleon;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void FieldCallback_Reveal_Kecleon(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseReveal_Kecleon);
}

bool8 FldEff_UseReveal(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (uintptr_t)StartRevealFieldEffect >> 16;
    gTasks[taskId].data[9] = (uintptr_t)StartRevealFieldEffect;
	DoFieldMoveFriendshipChance(&gPlayerParty[gFieldEffectArguments[0]]);
    //IncrementGameStat(GAME_STAT_USED_DOUSE);
    return FALSE;
}

void StartRevealFieldEffect(void)
{
    PlaySE(SE_SHIP);
    FieldEffectActiveListRemove(FLDEFF_USE_REVEAL);
    ScriptContext_Enable();
}

