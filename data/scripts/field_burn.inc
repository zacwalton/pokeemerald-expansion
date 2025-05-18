EventScript_FieldBurn::
	lockall
	special TryFieldBurnWhiteOut
	waitstate
	goto_if_eq VAR_RESULT, FLDBRN_WHITEOUT, EventScript_FieldWhiteOut
	goto_if_eq VAR_RESULT, FLDBRN_FRONTIER_WHITEOUT, EventScript_FrontierFieldWhiteOut
	releaseall
	end
