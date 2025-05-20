EventScript_Service_Man_EventScript_ServiceMan::
	message EventScript_Service_Man_Text_ServiceMan
	waitmessage
	multichoice 17, 6, MULTI_POKEMON_CENTER_SERVICE, 0
	switch VAR_RESULT
	case 0, EventScript_Service_Man_EventScript_ChooseMonToRate
	case 1, EventScript_Service_Man_EventScript_ChooseMonAndMoveToForget
	case 2, EventScript_Service_Man__EventScript_AskTeachMove
	case 3, EventScript_Service_Man_EventScript_ExitService
	case MULTI_B_PRESSED, EventScript_Service_Man_EventScript_ExitService
	end

EventScript_Service_Man_Text_ServiceMan:
	.string "What can I do for you today?.$"
	
EventScript_Service_Man_EventScript_ExitService::
	release
	end

EventScript_Service_Man_EventScript_NameRater::
	lock
	faceplayer
	msgbox EventScript_Service_Man_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_Service_Man_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, EventScript_Service_Man_EventScript_DeclineNameRate
	end

EventScript_Service_Man_EventScript_ChooseMonToRate::
	msgbox EventScript_Service_Man_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_Service_Man_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_Service_Man_EventScript_DeclineNameRate
	end

EventScript_Service_Man_EventScript_DeclineNameRate::
	msgbox EventScript_Service_Man_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

EventScript_Service_Man_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, EventScript_Service_Man_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, EventScript_Service_Man_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, EventScript_Service_Man_EventScript_PlayerNotMonsOT
	msgbox EventScript_Service_Man_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_Service_Man_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, EventScript_Service_Man_EventScript_DeclineNameRate
	end

EventScript_Service_Man_EventScript_CantRateEgg::
	msgbox EventScript_Service_Man_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

EventScript_Service_Man_EventScript_PlayerNotMonsOT::
	msgbox EventScript_Service_Man_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

EventScript_Service_Man_EventScript_ChangeNickname::
	msgbox EventScript_Service_Man_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, EventScript_Service_Man_EventScript_NewNameDifferent
	msgbox EventScript_Service_Man_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

EventScript_Service_Man_EventScript_NewNameDifferent::
	msgbox EventScript_Service_Man_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

EventScript_Service_Man_Text_PleasedToRateMonNickname:
	.string "I shall be pleased to rate your\n"
	.string "POKéMON's nickname.$"

EventScript_Service_Man_Text_CritiqueWhichMonNickname:
	.string "Which POKéMON's nickname should\n"
	.string "I critique?$"

EventScript_Service_Man_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
	.string "quite a fine name you bestowed.\p"
	.string "But! What say you, if I were to\n"
	.string "suggest a slightly better name?$"

EventScript_Service_Man_Text_WhatShallNewNameBe:
	.string "Ah, good. Then, what shall the new\n"
	.string "nickname be?$"

EventScript_Service_Man_Text_MonShallBeKnownAsName:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It is a better name than before!\n"
	.string "How fortunate for you!$"

EventScript_Service_Man_Text_DoVisitAgain:
	.string "I see.\n"
	.string "Do come visit again.$"

EventScript_Service_Man_Text_NameNoDifferentYetSuperior:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It looks no different from before,\n"
	.string "and yet, this is vastly superior!\p"
	.string "How fortunate for you!$"

EventScript_Service_Man_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} it is!\p"
	.string "This is a magnificent nickname!\n"
	.string "It is impeccably beyond reproach!\p"
	.string "You'll do well to cherish your\n"
	.string "{STR_VAR_1} now and beyond.$"

EventScript_Service_Man_Text_ThatIsMerelyAnEgg:
	.string "Now, now.\n"
	.string "That is merely an EGG!$"
	
EventScript_Service_Man_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_SERVICE_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EventScript_Service_Man_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, EventScript_Service_Man_EventScript_ChooseMonAndMoveToForget
	case NO, EventScript_Service_Man_EventScript_ComeAgain
	releaseall
	end

EventScript_Service_Man_EventScript_ChooseMonAndMoveToForget::
	msgbox EventScript_Service_Man_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_Service_Man_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EventScript_Service_Man_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, EventScript_Service_Man_EventScript_MonOnlyKnowsOneMove
	msgbox EventScript_Service_Man_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, EventScript_Service_Man_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox EventScript_Service_Man_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, EventScript_Service_Man_EventScript_TryForgetMove
	case NO, EventScript_Service_Man_EventScript_ComeAgain
	releaseall
	end

EventScript_Service_Man_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, EventScript_Service_Man_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox EventScript_Service_Man_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Service_Man_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox EventScript_Service_Man_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Service_Man_EventScript_EggCantForgetMoves::
	msgbox EventScript_Service_Man_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Service_Man_EventScript_ComeAgain::
	msgbox EventScript_Service_Man_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Service_Man_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox EventScript_Service_Man_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Service_Man_Text_ICanMakeMonForgetMove:
	.string "I can make POKéMON forget their moves.\p"
	.string "Would you like me to do that?$"

EventScript_Service_Man_Text_WhichMonShouldForget:
	.string "Which POKéMON should forget a move?$"

EventScript_Service_Man_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

EventScript_Service_Man_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

EventScript_Service_Man_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

EventScript_Service_Man_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

EventScript_Service_Man_Text_ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

EventScript_Service_Man_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No EGG should know any moves.$"

EventScript_Service_Man_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"


EventScript_Service_Man__EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, EventScript_Service_Man__EventScript_AskTeachMove
	msgbox EventScript_Service_Man__Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto EventScript_Service_Man__EventScript_AskTeachMove
	end

EventScript_Service_Man__EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, EventScript_Service_Man__EventScript_ComeBackWithHeartScale
	msgbox EventScript_Service_Man__Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EventScript_Service_Man__EventScript_ComeBackWithHeartScale
	goto EventScript_Service_Man__EventScript_ChooseMon
	end

EventScript_Service_Man__EventScript_ChooseMon::
	msgbox EventScript_Service_Man__Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_Service_Man__EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EventScript_Service_Man__EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, EventScript_Service_Man__EventScript_NoMoveToTeachMon
	goto EventScript_Service_Man__EventScript_ChooseMove
	end

EventScript_Service_Man__EventScript_ChooseMove::
	msgbox EventScript_Service_Man__Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, EventScript_Service_Man__EventScript_ChooseMon
	msgbox EventScript_Service_Man__Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto EventScript_Service_Man__EventScript_ComeBackWithHeartScale
	end

EventScript_Service_Man__EventScript_NoMoveToTeachMon::
	msgbox EventScript_Service_Man__Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto EventScript_Service_Man__EventScript_ChooseMon
	end

EventScript_Service_Man__EventScript_CantTeachEgg::
	msgbox EventScript_Service_Man__Text_CantTeachEgg, MSGBOX_DEFAULT
	goto EventScript_Service_Man__EventScript_ChooseMon
	end

EventScript_Service_Man__EventScript_ComeBackWithHeartScale::
	msgbox EventScript_Service_Man__Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

EventScript_Service_Man__Text_ImTheMoveTutor:
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a HEART SCALE.\n"
	.string "I'm collecting those now.$"

EventScript_Service_Man__Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness HEART SCALE!\p"
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

EventScript_Service_Man__Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

EventScript_Service_Man__Text_TeachWhichMove:
	.string "Which move should I teach?$"

EventScript_Service_Man__Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

EventScript_Service_Man__Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

EventScript_Service_Man__Text_ComeBackWithHeartScale:
	.string "If your POKéMON need to learn a move,\n"
	.string "come back with a HEART SCALE.$"

EventScript_Service_Man__Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an EGG.$"
