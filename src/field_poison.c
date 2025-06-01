#include "global.h"
#include "battle.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_message_box.h"
#include "field_poison.h"
#include "field_specials.h"
#include "fldeff_misc.h"
#include "frontier_util.h"
#include "party_menu.h"
#include "pokenav.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trainer_hill.h"
#include "constants/abilities.h"
#include "constants/field_poison.h"
#include "constants/form_change_types.h"
#include "constants/party_menu.h"

static bool32 IsMonValidSpecies(struct Pokemon *pokemon)
{
    u16 species = GetMonData(pokemon, MON_DATA_SPECIES_OR_EGG);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return FALSE;

    return TRUE;
}

static bool32 AllMonsFainted(void)
{
    int i;
    struct Pokemon *pokemon = gPlayerParty;

    for (i = 0; i < PARTY_SIZE; i++, pokemon++)
    {
        if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) != 0)
            return FALSE;
    }
    return TRUE;
}

static void FaintFromFieldPoison(u8 partyIdx)
{
    struct Pokemon *pokemon = &gPlayerParty[partyIdx];
    u32 status = STATUS1_NONE;

    if ((OW_POISON_DAMAGE < GEN_4) && (GetMonAbility(pokemon) != ABILITY_GUTS))
        AdjustFriendship(pokemon, FRIENDSHIP_EVENT_FAINT_FIELD_STATUS);

    SetMonData(pokemon, MON_DATA_STATUS, &status);
    GetMonData(pokemon, MON_DATA_NICKNAME, gStringVar1);
    StringGet_Nickname(gStringVar1);
}

static bool32 MonFaintedFromPoison(u8 partyIdx)
{
    struct Pokemon *pokemon = &gPlayerParty[partyIdx];
    if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) == ((OW_POISON_DAMAGE < GEN_4) ? 0 : 1) && GetAilmentFromStatus(GetMonData(pokemon, MON_DATA_STATUS)) == AILMENT_PSN)
        return TRUE;

    return FALSE;
}

#define tState    data[0]
#define tPartyIdx data[1]

static void Task_TryFieldPoisonWhiteOut(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        for (; tPartyIdx < PARTY_SIZE; tPartyIdx++)
        {
            if (MonFaintedFromPoison(tPartyIdx))
            {
                FaintFromFieldPoison(tPartyIdx);
                ShowFieldMessage(gText_PkmnFainted_FldPsn);
                tState++;
                return;
            }
        }
        tState = 2; // Finished checking party
        break;
    case 1:
        // Wait for "{mon} fainted" message, then return to party loop
        if (IsFieldMessageBoxHidden())
            tState--;
        break;
    case 2:
        if (AllMonsFainted())
        {
            // Battle facilities have their own white out script to handle the challenge loss
#ifdef BUGFIX
            if (InBattlePyramid() || InBattlePike() || InTrainerHillChallenge())
#else
            if (InBattlePyramid() | InBattlePike() || InTrainerHillChallenge())
#endif
                gSpecialVar_Result = FLDPSN_FRONTIER_WHITEOUT;
            else
                gSpecialVar_Result = FLDPSN_WHITEOUT;
        }
        else
        {
            gSpecialVar_Result = FLDPSN_NO_WHITEOUT;
            UpdateFollowingPokemon();
        }
        ScriptContext_Enable();
        DestroyTask(taskId);
        break;
    }
}

#undef tState
#undef tPartyIdx

void TryFieldPoisonWhiteOut(void)
{
    CreateTask(Task_TryFieldPoisonWhiteOut, 80);
    ScriptContext_Stop();
}

s32 DoPoisonFieldEffect(void)
{
    int i = GetFollowerMonIndex();
    struct Pokemon *pokemon = &gPlayerParty[GetFollowerMonIndex()];
    u32 hp = GetMonData(pokemon, MON_DATA_HP);
	u32 maxHp = GetMonData(pokemon, MON_DATA_MAX_HP);
	u16 userAbility = GetMonAbility(pokemon);
	
    u32 numPoisoned = 0;
    u32 numFainted = 0;

        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES) && GetAilmentFromStatus(GetMonData(pokemon, MON_DATA_STATUS)) == AILMENT_PSN)
        {
            // Apply poison damage			
			if (userAbility == ABILITY_POISON_HEAL)
			{
				if (hp < maxHp) //ZETA- Poison heal recovers HP instead
				{
					hp++;
				}
			}
			else if (userAbility != ABILITY_MAGIC_GUARD)					//ZETA- No damage if Magic Guard
			{
				if (OW_POISON_DAMAGE < GEN_4 && (hp == 0 || --hp == 0))
				{
					TryFormChange(i, B_SIDE_PLAYER, FORM_CHANGE_FAINT);
					numFainted++;
				}
				else if (OW_POISON_DAMAGE >= GEN_4 && (hp == 1 || --hp == 1))
				{
					numFainted++;
				}
				
				numPoisoned++;
			}

            SetMonData(pokemon, MON_DATA_HP, &hp);
        }

    // Do screen flash effect
    if (numFainted != 0 || numPoisoned != 0)
        FldEffPoison_Start();

    if (numFainted != 0)
        return FLDPSN_FNT;

    if (numPoisoned != 0)
        return FLDPSN_PSN;

    return FLDPSN_NONE;
}
