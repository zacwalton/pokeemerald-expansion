Route111_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_North_OnTransition
	.byte 0
	
Route111_North_OnTransition:
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special SetMirageTowerVisibility
	call Route111_North_EventScript_CheckSetSandstorm
	end
	
	Route111_North_EventScript_CheckSetSandstorm::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 34, Route111_North_EventScript_EndCheckSetSandstorm
	goto_if_gt VAR_TEMP_1, 107, Route111_North_EventScript_EndCheckSetSandstorm
	goto_if_gt VAR_TEMP_1, 72, Route111_North_EventScript_SetSandstorm
	goto_if_gt VAR_TEMP_0, 2000, Route111_North_EventScript_EndCheckSetSandstorm
	goto_if_lt VAR_TEMP_0, 8, Route111_EventScript_EndCheckSetSandstorm
Route111_North_EventScript_SetSandstorm::
	setweather WEATHER_SANDSTORM
	fadenewbgm MUS_DESERT
Route111_North_EventScript_EndCheckSetSandstorm::
	return
	
@ Unused
Route111_North_EventScript_ViciousSandstormTriggerUp::
	lockall
	setvar VAR_0x8004, 0
	goto Route111_North_EventScript_ViciousSandstormTrigger
	end

Route111_North_EventScript_ViciousSandstormTriggerDown::
	lockall
	setvar VAR_0x8004, 1
	goto Route111_North_EventScript_ViciousSandstormTrigger
	end

Route111_North_EventScript_ViciousSandstormTriggerLeft::
	lockall
	setvar VAR_0x8004, 2
	goto Route111_North_EventScript_ViciousSandstormTrigger
	end

@ Unused
Route111_North_EventScript_ViciousSandstormTriggerRight::
	lockall
	setvar VAR_0x8004, 3
	goto Route111_North_EventScript_ViciousSandstormTrigger
	end

Route111_North_EventScript_ViciousSandstormTrigger::
	checkitem ITEM_GO_GOGGLES
	goto_if_eq VAR_RESULT, FALSE, Route111_North_EventScript_PreventRouteAccess
	setvar VAR_TEMP_3, 1
	releaseall
	end

Route111_North_EventScript_PreventRouteAccess::
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8004, 0, Route111_North_EventScript_PushUpFromRoute
	call_if_eq VAR_0x8004, 1, Route111_North_EventScript_PushDownFromRoute
	call_if_eq VAR_0x8004, 2, Route111_North_EventScript_PushLeftFromRoute
	call_if_eq VAR_0x8004, 3, Route111_North_EventScript_PushRightFromRoute
	releaseall
	end

Route111_North_EventScript_PushUpFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_North_Movement_PushUpFromRoute
	waitmovement 0
	return

Route111_North_EventScript_PushDownFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_North_Movement_PushDownFromRoute
	waitmovement 0
	return

Route111_North_EventScript_PushLeftFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_North_Movement_PushLeftFromRoute
	waitmovement 0
	return

Route111_North_EventScript_PushRightFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_North_Movement_PushRightFromRoute
	waitmovement 0
	return

Route111_North_Movement_PushUpFromRoute:
	walk_up
	step_end

Route111_North_Movement_PushDownFromRoute:
	walk_down
	step_end

Route111_North_Movement_PushLeftFromRoute:
	walk_left
	step_end

Route111_North_Movement_PushRightFromRoute:
	walk_right
	step_end

Route111_North_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	fadenewbgm MUS_ROUTE110
	doweather
	setvar VAR_TEMP_3, 0
	end

Route111_North_EventScript_SandstormTrigger::
	setweather WEATHER_SANDSTORM
	fadenewbgm MUS_DESERT
	doweather
	end
