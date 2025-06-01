EventScript_UseFlash::
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
