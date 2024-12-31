PetalburgWoods_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PetalburgWoods_Entrance_OnResume
	.byte 0

PetalburgWoods_Entrance_OnResume:
	call_if_Set FLAG_PETALBURGWOODS_ENTRANCE_MUSHROOM1, PetalburgWoods_Entrance_Resource_Mushroom1
	end

PetalburgWoods_Entrance_Resource_Mushroom1::
	setmetatile 30, 12, METATILE_General_Grass, FALSE
	return

PetalburgWoods_Entrance_Resource_Mushroom1Harvest::
	goto_if_set FLAG_PETALBURGWOODS_ENTRANCE_MUSHROOM1, PetalburgWoods_Entrance_Resource_Collected
	setflag FLAG_PETALBURGWOODS_ENTRANCE_MUSHROOM1
	call PetalburgWoods_Entrance_Resource_Mushroom1
	special DrawWholeMapView
    random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_TINY_MUSHROOM, VAR_RESULT
	releaseall
	end

PetalburgWoods_Entrance_Resource_Collected::
	releaseall
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_Text_TrainerTipsExperience:
	.string "TRAINER TIPS\p"
	.string "Any POKéMON that appears even once\n"
	.string "in a battle is awarded EXP Points.\p"
	.string "To raise a weak POKéMON, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn EXP Points without\l"
	.string "being exposed to any harm.$"
	
PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "I caught a whole bunch of POKéMON!\p"
	.string "Go, go, go!\n"
	.string "My BUG POKéMON team!$"

PetalburgWoods_Text_ICouldntWin:
	.string "I have all these POKéMON,\n"
	.string "but I couldn't win…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "I caught a bunch of POKéMON.\n"
	.string "Now I'm out of POKé BALLS.$"
	