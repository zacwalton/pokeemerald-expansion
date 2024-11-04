EventScript_UseSeaStride::
	checkpartymove MOVE_SEA_STRIDE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_EndUseSeaStride
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSeaStride
	msgbox gText_PlayerUsedSeaStride, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSeaStride::
	releaseall
EventScript_EndUseSeaStride::
	end

	
EventScript_UseMuddyWater::
	checkpartymove MOVE_MUDDY_WATER
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_EndUseMuddyWater
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseMuddyWater
	msgbox gText_PlayerUsedMuddyWater, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseMuddyWater::
	releaseall
EventScript_EndUseMuddyWater::
	end

	
EventScript_UseSurf::
	checkpartymove MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_EndUseSurf
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end
