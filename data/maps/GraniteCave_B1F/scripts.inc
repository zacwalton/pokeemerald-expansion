@ Example setup of a top floor where a Boulder resides before falling down
@ The Event Script that does the actual falling is EventScript_FallObjectDownHole in data/scripts/cave_hole.inc

GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp::
	setstepcallback STEP_CB_CRACKED_FLOOR
	setobjectstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end
