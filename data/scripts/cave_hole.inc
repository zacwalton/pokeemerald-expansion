CaveHole_CheckFallDownHole: @ If the player can fall in a hole an object probably can as well
	map_script_2 VAR_OBJECT_HOLE, 1, EventScript_FallObjectDownHole
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
	.2byte 0

CaveHole_FixCrackedGround:
	copyvar VAR_OBJECT_HOLE, 0
	copyvar VAR_ICE_STEP_COUNT, 1
	end

EventScript_FallDownHole::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_UNDEFINED
	waitstate
	end

EventScript_FallDownHoleMtPyre::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	special DoFallWarp
	waitstate
	end

Movement_SetInvisible:
	set_invisible
	step_end

EventScript_FallObjectDownHole::
	lockall
	delay 20
	copyvar VAR_OBJECT_HOLE, 0 @ We don't need to know that an object fell anymore
	removeobject VAR_OBJECT_HOLE_ID @ Sets the object flag and removes it
	playse SE_FALL
	waitse
	delay 30
	msgbox Text_FellDown, MSGBOX_DEFAULT
	releaseall
	end

Text_FellDown::
	.string "It fell down!$"
