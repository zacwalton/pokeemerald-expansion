@ Example setup of the lower floor where a Boulder can fall into

GraniteCave_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_B2F_CheckBoulderFlag
	.byte 0

GraniteCave_B2F_CheckBoulderFlag::
	@ If the top Boulder's flag is set that means it fell down, so we clear the lower one
	goto_if_set FLAG_BOULDER_GRANITE_CAVE_B1F, GraniteCave_B2F_ShowBoulder
	@ Otherwise hide this Boulder
	setflag FLAG_BOULDER_GRANITE_CAVE_B2F
	end

GraniteCave_B2F_ShowBoulder::
	clearflag FLAG_BOULDER_GRANITE_CAVE_B2F
	end
