.set LOCALID_BIRCH, 2
.set LOCALID_ZIGZAGOON, 4

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route101_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, Route101_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnLoad:
	end
	
Route101_OnResume:
	call_if_Set FLAG_ROUTE101_LEEK1, Route101_Resource_leek1
	call_if_Set FLAG_ROUTE101_LEEK2, Route101_Resource_leek2
	call_if_Set FLAG_ROUTE101_LEEK3, Route101_Resource_leek3
	call_if_Set FLAG_ROUTE101_MUSHROOM1, Route101_Resource_Mushroom1
	call_if_Set FLAG_ROUTE101_MUSHROOM2, Route101_Resource_Mushroom2
	call_if_Set FLAG_ROUTE101_BALM1, Route101_Resource_Balm1
	call_if_Set FLAG_ROUTE101_STONE1, Route101_Resource_Stone1
	call_if_Set FLAG_ROUTE101_STONE2, Route101_Resource_Stone2
	call_if_Set FLAG_ROUTE101_WOOD1, Route101_Resource_Wood1
	call_if_Set FLAG_ROUTE101_WOOD2, Route101_Resource_Wood2
	call_if_Set FLAG_ROUTE101_VIVICHOKE1, Route101_Resource_Vivichoke1
	call_if_Set FLAG_ROUTE101_KINGSLEAF1, Route101_Resource_KingsLeaf1
	end

Route101_Resource_leek1::
	setmetatile 18, 4, METATILE_General_Grass, FALSE
	return

Route101_Resource_leek2::
	setmetatile 23, 18, METATILE_General_Grass, FALSE
	return

Route101_Resource_leek3::
	setmetatile 29, 23, METATILE_General_Grass, FALSE
	return

Route101_Resource_Mushroom1::
	setmetatile 36, 23, METATILE_General_Grass, FALSE
	return

Route101_Resource_Mushroom2::
	setmetatile 11, 12, METATILE_General_Grass, FALSE
	return

Route101_Resource_Balm1::
	setmetatile 37, 21, METATILE_General_Grass, FALSE
	return
	
Route101_Resource_Stone1::
	setmetatile 8, 7, METATILE_General_Grass, FALSE
	return

Route101_Resource_Stone2::
	setmetatile 7, 17, METATILE_General_Grass, FALSE
	return

Route101_Resource_Wood1::
	setmetatile 5, 12, METATILE_General_Grass, FALSE
	return

Route101_Resource_Wood2::
	setmetatile 19, 21, METATILE_General_Grass, FALSE
	return

Route101_Resource_Vivichoke1::
	setmetatile 29, 17, METATILE_General_Grass, FALSE
	return

Route101_Resource_KingsLeaf1::
	setmetatile 23, 21, METATILE_General_Grass, FALSE
	return

Route101_OnTransition:
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_Resource_leek1Harvest::
	goto_if_set FLAG_ROUTE101_LEEK1, Route101_Resource_Collected
	setflag FLAG_ROUTE101_LEEK1
	call Route101_Resource_leek1
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route101_Resource_Give_Herb
	giveitem ITEM_STICK
	releaseall
	end

Route101_Resource_leek2Harvest::
	goto_if_set FLAG_ROUTE101_LEEK2, Route101_Resource_Collected
	setflag FLAG_ROUTE101_LEEK2
	call Route101_Resource_leek2
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route101_Resource_Give_Herb
	giveitem ITEM_STICK
	releaseall
	end

Route101_Resource_leek3Harvest::
	goto_if_set FLAG_ROUTE101_LEEK3, Route101_Resource_Collected
	setflag FLAG_ROUTE101_LEEK3
	call Route101_Resource_leek3
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route101_Resource_Give_Herb
	giveitem ITEM_STICK
	releaseall
	end

Route101_Resource_Mushroom1Harvest::
	goto_if_set FLAG_ROUTE101_MUSHROOM1, Route101_Resource_Collected
	setflag FLAG_ROUTE101_MUSHROOM1
	call Route101_Resource_Mushroom1
	special DrawWholeMapView
    random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_TINY_MUSHROOM, VAR_RESULT
	releaseall
	end

Route101_Resource_Mushroom2Harvest::
	goto_if_set FLAG_ROUTE101_MUSHROOM2, Route101_Resource_Collected
	setflag FLAG_ROUTE101_MUSHROOM2
	call Route101_Resource_Mushroom2
	special DrawWholeMapView
    random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_TINY_MUSHROOM, VAR_RESULT
	releaseall
	end

Route101_Resource_Balm1Harvest::
	goto_if_set FLAG_ROUTE101_BALM1, Route101_Resource_Collected
	setflag FLAG_ROUTE101_BALM1
	call Route101_Resource_Balm1
	special DrawWholeMapView
	giveitem ITEM_BALM_MUSHROOM
	releaseall
	end

Route101_Resource_Stone1Harvest::
	goto_if_set FLAG_ROUTE101_STONE1, Route101_Resource_Collected
	setflag FLAG_ROUTE101_STONE1
	call Route101_Resource_Stone1
	special DrawWholeMapView
	random 4
	switch VAR_RESULT
	case 0, Route101_Resource_Give_Stone2
	case 1, Route101_Resource_Give_Stone3
	case 2, Route101_Resource_Give_Mud2
	case 3, Route101_Resource_Give_Mud3
	releaseall
	end

Route101_Resource_Stone2Harvest::
	goto_if_set FLAG_ROUTE101_STONE2, Route101_Resource_Collected
	setflag FLAG_ROUTE101_STONE2
	call Route101_Resource_Stone2
	special DrawWholeMapView
	random 4
	switch VAR_RESULT
	case 0, Route101_Resource_Give_Stone2
	case 1, Route101_Resource_Give_Stone3
	case 2, Route101_Resource_Give_Mud2
	case 3, Route101_Resource_Give_Mud3
	releaseall
	end

Route101_Resource_Wood1Harvest::
	goto_if_set FLAG_ROUTE101_WOOD1, Route101_Resource_Collected
	setflag FLAG_ROUTE101_WOOD1
	call Route101_Resource_Wood1
	special DrawWholeMapView
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_WOOD, VAR_RESULT
	releaseall
	end

Route101_Resource_Wood2Harvest::
	goto_if_set FLAG_ROUTE101_WOOD2, Route101_Resource_Collected
	setflag FLAG_ROUTE101_WOOD2
	call Route101_Resource_Wood2
	special DrawWholeMapView
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_WOOD, VAR_RESULT
	releaseall
	end

Route101_Resource_Vivichoke1Harvest::
	goto_if_set FLAG_ROUTE101_VIVICHOKE1, Route101_Resource_Collected
	giveitem ITEM_VIVICHOKE
	setflag FLAG_ROUTE101_VIVICHOKE1
	call Route101_Resource_Vivichoke1
	special DrawWholeMapView
	releaseall
	end

Route101_Resource_KingsLeaf1Harvest::
	goto_if_set FLAG_ROUTE101_KINGSLEAF1, Route101_Resource_Collected
	giveitem ITEM_KINGS_LEAF
	setflag FLAG_ROUTE101_KINGSLEAF1
	call Route101_Resource_KingsLeaf1
	special DrawWholeMapView
	releaseall
	end

Route101_Resource_Collected::
	releaseall
	end

Route101_Resource_Give_Stone2::
	giveitem ITEM_STONE, 2
	releaseall
	end
	
Route101_Resource_Give_Stone3::
	giveitem ITEM_STONE, 3
	releaseall
	end
	
Route101_Resource_Give_Mud2::
	giveitem ITEM_STONE, 2
	giveitem ITEM_MUD
	releaseall
	end
	
Route101_Resource_Give_Mud3::
	giveitem ITEM_STONE
	giveitem ITEM_MUD, 2
	releaseall
	end

Route101_Resource_Give_Leek::
	giveitem ITEM_LEEK
	releaseall
	end
	
Route101_Resource_Give_Herb::
	giveitem ITEM_REVIVAL_HERB
	releaseall
	end

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_BIRCH, 0, 15
	setobjectxy LOCALID_ZIGZAGOON, 0, 16
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZIGZAGOON
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer:
	walk_right
	step_end

Route101_Text_HelpMe:
	.string "H-help me!$"

Route101_Text_PleaseHelp:
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_Text_DontLeaveMe:
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe:
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass:
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign:
	.string "ROUTE 101\n"
	.string "{UP_ARROW} OLDALE TOWN$"

