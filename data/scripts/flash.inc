EventScript_UseFlash::
    lockall
    isfollowerfieldmoveuser VAR_0x8004
    setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
    setflag FLAG_SAFE_FOLLOWER_MOVEMENT
    call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
    waitmovement 0
    setfieldeffectargument 0, VAR_0x8007
	releaseall
	end
