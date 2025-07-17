@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	//goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
	checkmovefieldeffectflag 0x0001
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	goto EventScript_CutTreeSuccess
	
EventScript_CutTreeSuccess::
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMoveCut, MSGBOX_DEFAULT
	closemessage
EventScript_CutTreeCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
EventScript_CutTreeDown:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	special CutWildEncounter
	random 5
    addvar VAR_RESULT, 1
    giveitem ITEM_WOOD, VAR_RESULT
	releaseall
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	goto EventScript_CutTreeCommon

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "This tree looks like it can be\n"
	.string "{COLOR GREEN}Cut{COLOR DARK_GRAY} down!\p"
	.string "Would you like to{COLOR GREEN} Cut {COLOR DARK_GRAY}it?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} used{COLOR BLUE} {STR_VAR_2}{COLOR DARK_GRAY}!$"

Text_MonUsedFieldMoveCut:
	.string "{STR_VAR_1} used{COLOR GREEN} {STR_VAR_2}{COLOR DARK_GRAY}!$"

Text_MonUsedFieldMoveSmash:
	.string "{STR_VAR_1} used{COLOR RED} {STR_VAR_2}{COLOR DARK_GRAY}!$"

Text_MonUsedFieldMoveShake:
	.string "{STR_VAR_1} used{COLOR LIGHT_BLUE} {STR_VAR_2}{COLOR DARK_GRAY}!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "{COLOR GREEN}Cut {COLOR DARK_GRAY}down!$"

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	goto EventScript_RockSmashCommon

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	//goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
	checkmovefieldeffectflag 0x0002
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	copyvar VAR_0x8008, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	goto EventScript_RockSmashSuccess
	
EventScript_RockSmashSuccess::
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMoveSmash, MSGBOX_DEFAULT
	closemessage
EventScript_RockSmashCommon:
	@ check if follower should use the field move
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
EventScript_SmashRock:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_SmashRockEndNoItem
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_FollowerFieldMove:
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
	specialvar VAR_0x8006, GetPlayerFacingDirection
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
	@ Swap follower and player
	call EventScript_FollowerSwap
	@ Face follower in direction and jump
	switch VAR_0x8006
	case DIR_NORTH, EventScript_FollowerJumpNorth
	case DIR_EAST, EventScript_FollowerJumpEast
	case DIR_SOUTH, EventScript_FollowerJumpSouth
	case DIR_WEST, EventScript_FollowerJumpWest
EventScript_FollowerFieldMoveEnd:
	return

EventScript_FollowerSwap:
	switch VAR_0x8005
	case DIR_NORTH, EventScript_FollowerMoveNorth
	case DIR_EAST, EventScript_FollowerMoveEast
	case DIR_SOUTH, EventScript_FollowerMoveSouth
	case DIR_WEST, EventScript_FollowerMoveWest
	return

EventScript_FollowerMoveNorth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

EventScript_FollowerMoveEast:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

EventScript_FollowerMoveSouth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

EventScript_FollowerMoveWest:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

EventScript_FollowerJumpNorth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
	waitmovement 0
	return

EventScript_FollowerJumpEast:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
	waitmovement 0
	return

EventScript_FollowerJumpSouth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
	waitmovement 0
	return

EventScript_FollowerJumpWest:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
	waitmovement 0
	return

Movement_WalkUp:
	walk_up
	step_end

Movement_JumpUp:
	jump_in_place_up
	step_end

Movement_WalkRight:
	walk_right
	step_end

Movement_JumpRight:
	jump_in_place_right
	step_end

Movement_WalkDown:
	walk_down
	step_end

Movement_JumpDown:
	jump_in_place_down
	step_end

Movement_WalkLeft:
	walk_left
	step_end

Movement_JumpLeft:
	jump_in_place_left
	step_end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_EndSmash::
	special RockSmashFindItem
	copyvar VAR_0x800A, VAR_RESULT
	goto_if_eq VAR_0x8009, 0, EventScript_RockSmashCheckforItem
    giveitem ITEM_STONE, VAR_0x8009
EventScript_RockSmashCheckforItem::
	goto_if_eq VAR_0x800A, TRUE, EventScript_Harvest_RockSmash
EventScript_SmashRockEndNoItem::
	releaseall
	end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to {COLOR RED} Smash{COLOR DARK_GRAY} it?$"

Text_CantSmash:
	.string "It's a rugged rock, but a POKéMON\n"
	.string "may be able to {COLOR RED}Smash {COLOR DARK_GRAY}it.$"

EventScript_StrengthBoulder::
	lockall
	//goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkmovefieldeffectflag 0x0008
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	msgbox Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_StrengthCommon
	end

EventScript_StrengthCommon::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "It looks heavy, but a POKéMON\n"
	.string "may be able to {COLOR DYNAMIC_COLOR2}push {COLOR DARK_GRAY}it aside.\p"
	.string "Would you like to {COLOR DYNAMIC_COLOR2}push {COLOR DARK_GRAY}it?$"

Text_MonUsedStrength:
	.string "{STR_VAR_1} used {COLOR DYNAMIC_COLOR2}{STR_VAR_2}{COLOR DARK_GRAY}!\p"
	.string "{STR_VAR_1} made it possible\n"
	.string "to {COLOR DYNAMIC_COLOR2}push {COLOR DARK_GRAY}objects around!$"

Text_ActivateStrength:
	.string "{STR_VAR_1} made it possible\n"
	.string "to {COLOR DYNAMIC_COLOR2}push {COLOR DARK_GRAY}objects around!$"

Text_CantStrength:
	.string "It looks heavy, but a POKéMON\n"
	.string "may be able to {COLOR DYNAMIC_COLOR2}push {COLOR DARK_GRAY}it aside.$"

Text_StrengthActivated:
	.string "{STR_VAR_1} made it possible to {COLOR DYNAMIC_COLOR2}push{COLOR DARK_GRAY}\n"
	.string "objects around.$"

EventScript_UseWaterfall::
	lockall
	checkmovefieldeffectflag 0x0040
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	hidefollowernpc
	dofieldeffect FLDEFF_USE_WATERFALL
	setflag FLAG_SYS_USE_WATERFALL
	callnative FollowerNPC_WarpSetEnd
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down.\n"
	.string "A Pokémon may be able to{COLOR LIGHT_GREEN} Scale{COLOR DARK_GRAY} it.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to {COLOR LIGHT_GREEN}Scale{COLOR DARK_GRAY} it?$"

Text_MonUsedWaterfall:
	.string "{STR_VAR_1} used {COLOR LIGHT_GREEN}{STR_VAR_2}{COLOR DARK_GRAY}.$"

EventScript_UseDive::
	lockall
	checkmovefieldeffectflag 0x0080
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	copyvar 0x8004 VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	hidefollowernpc
	setfieldeffectargument 0, VAR_0x8004
	setfieldeffectargument 1, 1
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkmovefieldeffectflag 0x0080
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_NoSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	hidefollowernpc
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	callnative SetFollowerNPCSurfSpriteAfterDive
EventScript_NoSurface::
	releaseall
	end
	
@ Interact with fast currents
EventScript_Whirlpool::
	lockall
	goto_if_set FLAG_SYS_USE_WHIRLPOOL, EventScript_CheckActivatedWhirlpool
	checkmovefieldeffectflag 0x0400
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWhirlpool
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToUseWhirlpool, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelWhirlpool
	closemessage
	dofieldeffect FLDEFF_USE_WHIRLPOOL
	waitstate
	goto EventScript_ActivateWhirlpool
	end
	
@ Use whirlpool from party menu
EventScript_WhirlpoolCommon::
	lockall
	dofieldeffect FLDEFF_USE_WHIRLPOOL
	setflag FLAG_SYS_USE_WHIRLPOOL
	waitstate
	msgbox Text_ActivateWhirlpool, MSGBOX_DEFAULT
	releaseall
	end
	
EventScript_ActivateWhirlpool::
	setflag FLAG_SYS_USE_WHIRLPOOL
	msgbox Text_PlayerUsedWhirlpool, MSGBOX_DEFAULT
	releaseall
	end
	
@ Use whirlpool from party menu
EventScript_UseWhirlpool::
	goto_if_set FLAG_SYS_USE_WHIRLPOOL, EventScript_CheckActivatedWhirlpool
	lockall
	goto EventScript_WhirlpoolCommon
	
EventScript_CantWhirlpool::
	lockall
	msgbox Text_CantWhirlpool, MSGBOX_DEFAULT
	goto EventScript_CancelWhirlpool
	end
	
EventScript_CancelWhirlpool::
	releaseall
	end
	
EventScript_CheckActivatedWhirlpool::
	msgbox Text_CantWhirlpool, MSGBOX_DEFAULT
	releaseall
	end

Text_CantWhirlpool::
	.string "The current is strong…\n$"

Text_WantToUseWhirlpool::
	.string "The current is strong…\n"
	.string "Would you like to{COLOR DYNAMIC_COLOR5} Surf{COLOR DARK_GRAY} across?$"

Text_PlayerUsedWhirlpool::
	.string "{STR_VAR_1} used{COLOR DYNAMIC_COLOR5} {STR_VAR_2}{COLOR DARK_GRAY}!\p"
	.string "{STR_VAR_1} made it possible\n"
	.string "to {COLOR DYNAMIC_COLOR5}surf {COLOR DARK_GRAY}the currents!$"

Text_ActivateWhirlpool::
	.string "{STR_VAR_1} made it possible\n"
	.string "to {COLOR DYNAMIC_COLOR5}surf {COLOR DARK_GRAY}the currents!$"

@ Interact with a tree a Pokémon can use headbutt on
EventScript_Headbutt::
	lockall
	checkmovefieldeffectflag 0x0004
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantHeadbuttTree
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	goto EventScript_HeadbuttSuccess
	
EventScript_HeadbuttSuccess::
	msgbox Text_WantToHeadbutt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelHeadbutt
	msgbox Text_MonUsedFieldMoveShake, MSGBOX_DEFAULT
	closemessage
EventScript_HeadbuttCommon::
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
	goto EventScript_HeadbuttTree
@ Use headbutt from party menu
EventScript_UseHeadbutt::
	lockall
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
EventScript_HeadbuttTree:
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_Headbutt
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	special HeadbuttWildEncounter
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_EndHeadbutt
	waitstate
EventScript_EndHeadbutt:
	releaseall
	end

Movement_Headbutt:
	cut_tree
	step_end

EventScript_CantHeadbuttTree::
	msgbox Text_CantHeadbuttTree, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelHeadbutt::
	closemessage
	releaseall
	end

EventScript_DigCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_DIG
	waitstate
EventScript_DigSealedChamber:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	callnative DoBrailleDigEffect
	releaseall
	end

@ Use Dig from party menu
EventScript_UseDig::
	lockall
	goto EventScript_DigCommon


EventScript_CutGrassCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
	waitstate

@ Use Cut grass from party menu
EventScript_UseCutGrass::
	lockall
	goto EventScript_CutGrassCommon

Text_CantDive:
	.string "The sea is deep here. A POKéMON\n"
	.string "may be able to {COLOR DYNAMIC_COLOR5}Dive {COLOR DARK_GRAY}underwater.$"

Text_WantToDive:
	.string "The sea is deep here.\n"
	.string "Would you like to {COLOR DYNAMIC_COLOR5}Dive{COLOR DARK_GRAY}?$"

Text_MonUsedDive:
	.string "{STR_VAR_1} used{COLOR DYNAMIC_COLOR5} {STR_VAR_2}{COLOR DARK_GRAY}.$"

Text_CantSurface:
	.string "Light is filtering down from above.\n"
	.string "A POKéMON may be able to {COLOR DYNAMIC_COLOR5}Surface{COLOR DARK_GRAY}.$"

Text_WantToSurface:
	.string "Light is filtering down from above.\n"
	.string "Would you like to {COLOR DYNAMIC_COLOR5}Surface{COLOR DARK_GRAY}?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"

Text_WantToHeadbutt:
	.string "It's a large, formidable tree.\n"
	.string "Would you like to{COLOR LIGHT_BLUE} Shake{COLOR DARK_GRAY} it?$"

Text_CantHeadbuttTree:
	.string "There's a large, formidable tree.\n"
	.string "It looks like it can be{COLOR LIGHT_BLUE} Shook{COLOR DARK_GRAY}!$"
	
EventScript_UseRockClimb::
	lockall
	checkmovefieldeffectflag 0x0010
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantRockClimb
	bufferpartymonnick 0, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToRockClimb, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EndRockClimb
	msgbox Text_MonUsedRockClimb, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_CLIMB
	waitstate
	goto EventScript_EndRockClimb
	
EventScript_CantRockClimb::
	msgbox Text_CantRockClimb, MSGBOX_DEFAULT
	
EventScript_EndRockClimb::
	releaseall
	end
	
Text_WantToRockClimb:
    .string "The cliff is steep.\n"
    .string "Would you like to{COLOR LIGHT_GREEN} Climb{COLOR DARK_GRAY} it?$"
    
Text_MonUsedRockClimb:
    .string "{STR_VAR_1} used {COLOR LIGHT_GREEN}Rock Climb{COLOR DARK_GRAY}!$"
    
Text_CantRockClimb:
    .string "The cliff is steep.\n"
    .string "A Pokémon may be able to{COLOR LIGHT_GREEN} Climb{COLOR DARK_GRAY} it.$"

EventScript_UseLava::
	checkmovefieldeffectflag 0x1000
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantLavaSurf
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox Text_WantToUseLavaSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseLavaSurf
	msgbox Text_PlayerUsedLavaSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_LAVA
EventScript_ReleaseUseLavaSurf::
	releaseall
	end
EventScript_EndUseLavaSurf::
	msgbox Text_CantLavaSurf, MSGBOX_YESNO
	releaseall
	end
	
EventScript_CantLavaSurf::
	msgbox Text_CantLavaSurf, MSGBOX_DEFAULT
	
EventScript_CancelLavaSurf::
	releaseall
	end

Text_CantLavaSurf:
	.string "The lava is hot and bubbling.\n$"
	
Text_WantToUseLavaSurf:
    .string "The lava is hot and bubbling.\n"
    .string "Would you like to {COLOR DYNAMIC_COLOR5}Surf{COLOR DARK_GRAY} it?$"

Text_PlayerUsedLavaSurf:
    .string "{STR_VAR_1} used {COLOR DYNAMIC_COLOR5}{STR_VAR_2}{COLOR DARK_GRAY}!$"
	

	
EventScript_UseSludge::
	checkmovefieldeffectflag  0x200000
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_CantSludgeSurf
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox Text_WantToUseSludgeSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSludgeSurf
	msgbox Text_PlayerUsedSludgeSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SLUDGE
EventScript_ReleaseUseSludgeSurf::
	releaseall
	end
EventScript_EndUseSludgeSurf::
	msgbox Text_CantSludgeSurf, MSGBOX_YESNO
	releaseall
	end
	
EventScript_CantSludgeSurf::
	msgbox Text_CantSludgeSurf, MSGBOX_DEFAULT
	
EventScript_CancelSludgeSurf::
	releaseall
	end

Text_CantSludgeSurf:
	.string "The water is foul and contaminated.\n$"
	
Text_WantToUseSludgeSurf:
    .string "The water is foul and contaminated.\n"
    .string "Would you like to {COLOR DYNAMIC_COLOR5}Surf {COLOR DARK_GRAY}it?$"

Text_PlayerUsedSludgeSurf:
    .string "{STR_VAR_1} used {COLOR DYNAMIC_COLOR5}{STR_VAR_2}{COLOR DARK_GRAY}!$"
	
@ Interact with large fire
EventScript_DouseFire::
	//lockall
	//goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
	checkmovefieldeffectflag 0x400000
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckCantDouse
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, VAR_0x8008
	goto EventScript_DouseFireSuccess
	
EventScript_DouseFireSuccess::
	msgbox Text_WantToDouse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelDouse
	msgbox Text_MonUsedFieldMoveDouse, MSGBOX_DEFAULT
	closemessage
EventScript_DouseFireCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_DOUSE
	waitstate
EventScript_DouseFireDown:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_DouseFire
	waitmovement 0
	removeobject VAR_LAST_TALKED
	special DouseWildEncounter
	random 10
	goto_if_eq VAR_RESULT, 1, EventScript_DouseFireItem
	releaseall
	end

@ Use Douse from party menu
EventScript_UseDouse::
	//lockall
	goto EventScript_DouseFireCommon

Movement_DouseFire:
	douse_fire
	step_end

EventScript_CheckCantDouse::
	msgbox Text_CantDouse, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelDouse::
	closemessage
	releaseall
	end
	
EventScript_DouseFireItem::
    giveitem ITEM_CHARCOAL
	releaseall
	end


Text_WantToDouse:
	.string "This fire looks like it can be {COLOR DYNAMIC_COLOR6}Doused{COLOR DARK_GRAY}!\p"
	.string "Would you like to{COLOR DYNAMIC_COLOR6} Extinguish {COLOR DARK_GRAY}it?$"

Text_MonUsedFieldMoveDouse:
	.string "{STR_VAR_1} used{COLOR DYNAMIC_COLOR6} {STR_VAR_2}{COLOR DARK_GRAY}!$"


Text_CantDouse:
	.string "This fire looks like it can be {COLOR DYNAMIC_COLOR6}Doused{COLOR DARK_GRAY}!$"
	
EventScript_UseDefog::
    lockall
    isfollowerfieldmoveuser VAR_0x8004
    setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
    setflag FLAG_SAFE_FOLLOWER_MOVEMENT
    call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
    waitmovement 0
    setfieldeffectargument 0, VAR_0x8007
    dofieldeffect FLDEFF_DEFOG
    waitstate
    msgbox Text_ActivateDefog, MSGBOX_DEFAULT
    closemessage
    releaseall
    end
	

Text_ActivateDefog::
	.string "{STR_VAR_1} cleared the{COLOR BLUE} fog{COLOR DARK_GRAY}!$"

EventScript_UseSweetScent::
    lockall
    isfollowerfieldmoveuser VAR_0x8004
    setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
    setflag FLAG_SAFE_FOLLOWER_MOVEMENT
    call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
    waitmovement 0
    setfieldeffectargument 0, VAR_0x8007
    dofieldeffect FLDEFF_SWEET_SCENT
    releaseall
    end
	
	
