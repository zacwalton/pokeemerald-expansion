.set LOCALID_WOOD1, 3
.set LOCALID_WOOD2, 4
.set LOCALID_MUSHROOM1, 5
.set LOCALID_VIVICHOKE1, 6

Route102_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route102_OnResume
	.byte 0

Route102_OnResume:
	call_if_Set FLAG_ROUTE102_WOOD1, Route102_Resource_Wood1
	call_if_Set FLAG_ROUTE102_WOOD2, Route102_Resource_Wood2
	call_if_Set FLAG_ROUTE102_MUSHROOM1, Route102_Resource_Mushroom1
	call_if_Set FLAG_ROUTE102_VIVICHOKE1, Route102_Resource_Vivichoke1
	end

Route102_Resource_Wood1::
	setmetatileateatbgeventid LOCALID_WOOD1, METATILE_General_Grass, FALSE
	return

Route102_Resource_Wood2::
	setmetatileateatbgeventid LOCALID_WOOD2, METATILE_General_Grass, FALSE
	return

Route102_Resource_Mushroom1::
	setmetatileateatbgeventid LOCALID_MUSHROOM1, METATILE_General_Grass, FALSE
	return

Route102_Resource_Vivichoke1::
	setmetatileateatbgeventid LOCALID_VIVICHOKE1, METATILE_General_Grass, FALSE
	return

Route102_Resource_Wood1Harvest::
	goto_if_set FLAG_ROUTE102_WOOD1, Harvest_Resource_Collected
	setflag FLAG_ROUTE102_WOOD1
	call Route102_Resource_Wood1
	special DrawWholeMapView
	call Harvest_WoodScript
	releaseall
	end

Route102_Resource_Wood2Harvest::
	goto_if_set FLAG_ROUTE102_WOOD2, Harvest_Resource_Collected
	setflag FLAG_ROUTE102_WOOD2
	call Route102_Resource_Wood2
	special DrawWholeMapView
	call Harvest_WoodScript
	releaseall
	end

Route102_Resource_Mushroom1Harvest::
	goto_if_set FLAG_ROUTE102_MUSHROOM1, Harvest_Resource_Collected
	setflag FLAG_ROUTE102_MUSHROOM1
	call Route102_Resource_Mushroom1
	special DrawWholeMapView
	call Harvest_MushroomSmallScript
	releaseall
	end

Route102_Resource_Vivichoke1Harvest::
	goto_if_set FLAG_ROUTE102_VIVICHOKE1, Harvest_Resource_Collected
	setflag FLAG_ROUTE102_VIVICHOKE1
	call Route102_Resource_Vivichoke1
	special DrawWholeMapView
	call Harvest_VivichokeScript
	releaseall
	end

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route102_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"
