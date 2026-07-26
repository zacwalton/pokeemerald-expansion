EventScript_UseFlash::
    lockall
    isfollowerfieldmoveuser VAR_0x8004
    setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
    setflag FLAG_SAFE_FOLLOWER_MOVEMENT
    call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
    waitmovement 0
    setfieldeffectargument 0, VAR_0x8007
    goto_if_set FLAG_SYS_BONUS_FLASH, EventScript_UseFlash_Boosted
	animateflash 2
	setflashlevel 2
	releaseall
	end

EventScript_UseFlash_Boosted::
	animateflash 1
	setflashlevel 1
	releaseall
	end
