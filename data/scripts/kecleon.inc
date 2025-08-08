Route120_EventScript_Kecleon1::
	lock
	faceplayer
	setvar VAR_0x8009, 1
	goto EventScript_Kecleon
	end

Route120_EventScript_Kecleon2::
	lock
	faceplayer
	setvar VAR_0x8009, 2
	goto EventScript_Kecleon
	end

Route120_EventScript_Kecleon3::
	lock
	faceplayer
	setvar VAR_0x8009, 3
	goto EventScript_Kecleon
	end

Route120_EventScript_Kecleon4::
	lock
	faceplayer
	setvar VAR_0x8009, 4
	goto EventScript_Kecleon
	end

Route120_EventScript_Kecleon5::
	lock
	faceplayer
	setvar VAR_0x8009, 5
	goto EventScript_Kecleon
	end

Route119_EventScript_Kecleon1::
	lock
	faceplayer
	setvar VAR_0x8009, 6
	goto EventScript_Kecleon
	end

Route119_EventScript_Kecleon2::
	lock
	faceplayer
	setvar VAR_0x8009, 7
	goto EventScript_Kecleon
	end

EventScript_Kecleon::
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, EventScript_AskUseDevonScope
	checkmovefieldeffectflag IS_FIELD_MOVE_DETECT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantIdentify
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	msgbox Kecleon_Text_WantToIdentify, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CantIdentify
	closemessage
	goto EventScript_KecleonCommon
	end
	
EventScript_KecleonCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_DETECT
	waitstate
	goto EventScript_KecleonBattleFieldMoveSetup
	releaseall
	end

EventScript_CantIdentify:
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

EventScript_AskUseDevonScope::
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_KecleonBattleDevonSetup
	release
	end

EventScript_KecleonBattleDevonSetup:
	msgbox Kecleon_Text_UseDevonScopeMonAttacked, MSGBOX_DEFAULT
	closemessage
	goto EventScript_BattleKecleon
	end
	
EventScript_KecleonBattleFieldMoveSetup:
	msgbox Kecleon_Text_IdentifiedMonAttacked, MSGBOX_DEFAULT
	closemessage
	goto EventScript_BattleKecleon
	end

EventScript_BattleKecleon::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KECLEON, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, EventScript_RemoveKecleon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EventScript_RemoveKecleon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, EventScript_RemoveKecleon
	release
	end

EventScript_RemoveKecleon::
	goto Common_EventScript_RemoveStaticPokemon
	end

Movement_KecleonAppears:
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_16
	set_invisible
	delay_16
	set_visible
	step_end

Kecleon_Text_SomethingUnseeable::
	.string "Something unseeable is in the way.$"

Kecleon_Text_WantToUseDevonScope::
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"

Kecleon_Text_UseDevonScopeMonAttacked::
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"
	
Kecleon_Text_WantToIdentify::
	.string "Something unseeable is in the way.\p"
	.string "Want to identify it?$"

Kecleon_Text_IdentifiedMonAttacked::
	.string "{PLAYER} used {STR_VAR_2}.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"
	
