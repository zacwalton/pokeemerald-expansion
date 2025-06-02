Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnResume
	.byte 0

Route103_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

Route103_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return

Route103_OnResume:
	call_if_Set FLAG_ROUTE103_LEEK1, Route103_Resource_leek1
	call_if_Set FLAG_ROUTE103_LEEK2, Route103_Resource_leek2
	call_if_Set FLAG_ROUTE103_LEEK3, Route103_Resource_leek3
	call_if_Set FLAG_ROUTE103_LEEK4, Route103_Resource_leek3
	call_if_Set FLAG_ROUTE103_MUSHROOM1, Route103_Resource_Mushroom1
	call_if_Set FLAG_ROUTE103_STONE1, Route103_Resource_Stone1
	call_if_Set FLAG_ROUTE103_STONE2, Route103_Resource_Stone2
	call_if_Set FLAG_ROUTE103_WOOD1, Route103_Resource_Wood1
	call_if_Set FLAG_ROUTE103_WOOD2, Route103_Resource_Wood2
	call_if_Set FLAG_ROUTE103_WOOD3, Route103_Resource_Wood3
	call_if_Set FLAG_ROUTE103_VIVICHOKE1, Route103_Resource_Vivichoke1
	call_if_Set FLAG_ROUTE103_VIVICHOKE2, Route103_Resource_Vivichoke2
	end

Route103_Resource_leek1::
	setmetatile 17, 13, METATILE_General_Grass, FALSE
	return

Route103_Resource_leek2::
	setmetatile 21, 19, METATILE_General_Grass, FALSE
	return

Route103_Resource_leek3::
	setmetatile 63, 15, METATILE_General_Grass, FALSE
	return

Route103_Resource_leek4::
	setmetatile 69, 20, METATILE_General_Grass, FALSE
	return

Route103_Resource_Mushroom1::
	setmetatile 82, 15, METATILE_General_Grass, FALSE
	return
	
Route103_Resource_Stone1::
	setmetatile 4, 19, METATILE_General_Grass, FALSE
	return

Route103_Resource_Stone2::
	setmetatile 80, 5, METATILE_General_Grass, FALSE
	return

Route103_Resource_Wood1::
	setmetatile 4, 11, METATILE_General_Grass, FALSE
	return

Route103_Resource_Wood2::
	setmetatile 7, 9, METATILE_General_Grass, FALSE
	return

Route103_Resource_Wood3::
	setmetatile 89, 14, METATILE_General_Grass, FALSE
	return

Route103_Resource_Vivichoke1::
	setmetatile 10, 8, METATILE_General_Grass, FALSE
	return

Route103_Resource_Vivichoke2::
	setmetatile 68, 16, METATILE_General_Grass, FALSE
	return

Route103_Resource_leek1Harvest::
	goto_if_set FLAG_ROUTE103_LEEK1, Route103_Resource_Collected
	setflag FLAG_ROUTE103_LEEK1
	call Route103_Resource_leek1
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route103_Resource_Give_Herb
	giveitem ITEM_STICK
	releaseall
	end

Route103_Resource_leek2Harvest::
	goto_if_set FLAG_ROUTE103_LEEK2, Route103_Resource_Collected
	setflag FLAG_ROUTE103_LEEK2
	call Route103_Resource_leek2
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route103_Resource_Give_Herb
	giveitem ITEM_STICK
	releaseall
	end

Route103_Resource_leek3Harvest::
	goto_if_set FLAG_ROUTE103_LEEK3, Route103_Resource_Collected
	setflag FLAG_ROUTE103_LEEK3
	call Route103_Resource_leek3
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route103_Resource_Give_Herb
	giveitem ITEM_STICK
	releaseall
	end

Route103_Resource_leek4Harvest::
	goto_if_set FLAG_ROUTE103_LEEK4, Route103_Resource_Collected
	setflag FLAG_ROUTE103_LEEK4
	call Route103_Resource_leek4
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route103_Resource_Give_Herb
	giveitem ITEM_STICK
	releaseall
	end

Route103_Resource_Mushroom1Harvest::
	goto_if_set FLAG_ROUTE103_MUSHROOM1, Route103_Resource_Collected
	setflag FLAG_ROUTE103_MUSHROOM1
	call Route103_Resource_Mushroom1
	special DrawWholeMapView
    random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_TINY_MUSHROOM, VAR_RESULT
	releaseall
	end

Route103_Resource_Stone1Harvest::
	goto_if_set FLAG_ROUTE103_STONE1, Route103_Resource_Collected
	setflag FLAG_ROUTE103_STONE1
	call Route103_Resource_Stone1
	special DrawWholeMapView
	random 4
	switch VAR_RESULT
	case 0, Route103_Resource_Give_Stone2
	case 1, Route103_Resource_Give_Stone3
	case 2, Route103_Resource_Give_Mud2
	case 3, Route103_Resource_Give_Mud3
	releaseall
	end

Route103_Resource_Stone2Harvest::
	goto_if_set FLAG_ROUTE103_STONE2, Route103_Resource_Collected
	setflag FLAG_ROUTE103_STONE2
	call Route103_Resource_Stone2
	special DrawWholeMapView
	random 4
	switch VAR_RESULT
	case 0, Route103_Resource_Give_Stone2
	case 1, Route103_Resource_Give_Stone3
	case 2, Route103_Resource_Give_Mud2
	case 3, Route103_Resource_Give_Mud3
	releaseall
	end

Route103_Resource_Wood1Harvest::
	goto_if_set FLAG_ROUTE103_WOOD1, Route103_Resource_Collected
	setflag FLAG_ROUTE103_WOOD1
	call Route103_Resource_Wood1
	special DrawWholeMapView
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_WOOD, VAR_RESULT
	releaseall
	end

Route103_Resource_Wood2Harvest::
	goto_if_set FLAG_ROUTE103_WOOD2, Route103_Resource_Collected
	setflag FLAG_ROUTE103_WOOD2
	call Route103_Resource_Wood2
	special DrawWholeMapView
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_WOOD, VAR_RESULT
	releaseall
	end

Route103_Resource_Wood3Harvest::
	goto_if_set FLAG_ROUTE103_WOOD3, Route103_Resource_Collected
	setflag FLAG_ROUTE103_WOOD3
	call Route103_Resource_Wood3
	special DrawWholeMapView
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_WOOD, VAR_RESULT
	releaseall
	end

Route103_Resource_Vivichoke1Harvest::
	goto_if_set FLAG_ROUTE103_VIVICHOKE1, Route103_Resource_Collected
	giveitem ITEM_VIVICHOKE
	setflag FLAG_ROUTE103_VIVICHOKE1
	call Route103_Resource_Vivichoke1
	special DrawWholeMapView
	releaseall
	end

Route103_Resource_Vivichoke2Harvest::
	goto_if_set FLAG_ROUTE103_VIVICHOKE2, Route103_Resource_Collected
	giveitem ITEM_VIVICHOKE
	setflag FLAG_ROUTE103_VIVICHOKE2
	call Route103_Resource_Vivichoke2
	special DrawWholeMapView
	releaseall
	end

Route103_Resource_Collected::
	releaseall
	end

Route103_Resource_Give_Stone2::
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_STONE, VAR_RESULT
	releaseall
	end
	
Route103_Resource_Give_Stone3::
	random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_STONE, VAR_RESULT
	giveitem ITEM_MUD
	releaseall
	end
	
Route103_Resource_Give_Mud2::
    giveitem ITEM_STONE
	random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_MUD, VAR_RESULT
	releaseall
	end
	
Route103_Resource_Give_Mud3::
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_MUD, VAR_RESULT
	releaseall
	end

Route103_Resource_Give_Leek::
	giveitem ITEM_LEEK
	releaseall
	end
	
Route103_Resource_Give_Herb::
	giveitem ITEM_REVIVAL_HERB
	releaseall
	end

Route103_EventScript_Rival::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
	end

Route103_EventScript_RivalMay::
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTreecko
	case 1, Route103_EventScript_StartMayBattleTorchic
	case 2, Route103_EventScript_StartMayBattleMudkip
	end

Route103_EventScript_RivalBrendan::
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTreecko
	case 1, Route103_EventScript_StartBrendanBattleTorchic
	case 2, Route103_EventScript_StartBrendanBattleMudkip
	end

Route103_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_AfterMayBattle::
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle::
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd::
	removeobject LOCALID_ROUTE103_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Movement_RivalExitFacingNorth1:
	walk_left
	walk_down
	step_end

Route103_Movement_RivalExitFacingNorth2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth:
	delay_16
	delay_4
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

Route103_Movement_RivalExit1:
	walk_down
	step_end

Route103_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest:
	delay_16
	walk_in_place_faster_down
	step_end

Route103_EventScript_Boy::
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man::
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign::
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_Text_MayRoute103Pokemon:
	.string "MAY: Let's see… The POKéMON found\n"
	.string "on ROUTE 103 include…$"

Route103_Text_MayLetsBattle:
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

Route103_Text_MayDefeated:
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

Route103_Text_MayTimeToHeadBack:
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

Route103_Text_BrendanRoute103Pokemon:
	.string "BRENDAN: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 103…$"

Route103_Text_BrendanLetsBattle:
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

Route103_Text_BrendanDefeated:
	.string "Huh, {PLAYER}, you're not too shabby.$"

Route103_Text_BrendanTimeToHeadBack:
	.string "BRENDAN: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

Route103_Text_ShouldHaveBroughtPotion:
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route103_Text_ShortcutToOldale:
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign:
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"

