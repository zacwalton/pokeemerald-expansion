
EventScript_UseSurf::
	checkmovefieldeffectflag 0x0020
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_EndUseSurf
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
	doesmovehavefieldeffect VAR_0x8008, 0x0400
	call_if_eq VAR_RESULT, TRUE, EventScript_Surf_ActivateWhirlpool
	doesmovehavefieldeffect VAR_0x8008, 0x0040
	call_if_eq VAR_RESULT, TRUE, EventScript_Surf_ActivateWaterfall
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end
	
EventScript_Surf_ActivateWhirlpool:
	setflag FLAG_SYS_USE_WHIRLPOOL
	return 
	
EventScript_Surf_ActivateWaterfall:
	setflag FLAG_SYS_USE_WATERFALL
	return 
