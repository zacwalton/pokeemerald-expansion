.set LOCALID_NURSE, 1
.set LOCALID_SERVICE_MAN, 2

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "My pokémon has a {COLOR GREEN}naive{COLOR DARK_GRAY} nature, and my\n"
	.string "friend's has a {COLOR BLUE}jolly{COLOR DARK_GRAY} nature.\p"
	.string "It's fascinating how pokémon have\n"
	.string "personalities!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Just like people, there are male and\n"
	.string "female pokémon.\p"
	.string "Some pokémon even have different forms\n"
	.string "or evolutions depending on their gender.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "The man down the road gave me a TM!\p"
	.string "I used it to teach my POKéMON how to\n"
	.string "CUT down skinny trees.$"

RustboroCity_PokemonCenter_1F_EventScript_ServiceMan::
	message RustboroCity_PokemonCenter_1F_Text_ServiceMan
	waitmessage
	multichoice 17, 6, MULTI_POKEMON_CENTER_SERVICE, 0
	switch VAR_RESULT
	case 0, RustboroCity_PokemonCenter_1F_EventScript_NameRater
	case 1, RustboroCity_PokemonCenter_1F_EventScript_MoveDeleter
	case 2, RustboroCity_PokemonCenter_1F_EventScript_ExitService
	case MULTI_B_PRESSED, RustboroCity_PokemonCenter_1F_EventScript_ExitService
	end

RustboroCity_PokemonCenter_1F_Text_ServiceMan:
	.string "What can I do for you today?.$"
	
RustboroCity_PokemonCenter_1F_EventScript_ExitService::
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_NameRater::
	lock
	faceplayer
	msgbox RustboroCity_PokemonCenter_1F_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_PokemonCenter_1F_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, RustboroCity_PokemonCenter_1F_EventScript_DeclineNameRate
	end

RustboroCity_PokemonCenter_1F_EventScript_ChooseMonToRate::
	msgbox RustboroCity_PokemonCenter_1F_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_PokemonCenter_1F_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_PokemonCenter_1F_EventScript_DeclineNameRate
	end

RustboroCity_PokemonCenter_1F_EventScript_DeclineNameRate::
	msgbox RustboroCity_PokemonCenter_1F_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, RustboroCity_PokemonCenter_1F_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_PokemonCenter_1F_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_PokemonCenter_1F_EventScript_PlayerNotMonsOT
	msgbox RustboroCity_PokemonCenter_1F_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_PokemonCenter_1F_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, RustboroCity_PokemonCenter_1F_EventScript_DeclineNameRate
	end

RustboroCity_PokemonCenter_1F_EventScript_CantRateEgg::
	msgbox RustboroCity_PokemonCenter_1F_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_PlayerNotMonsOT::
	msgbox RustboroCity_PokemonCenter_1F_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_ChangeNickname::
	msgbox RustboroCity_PokemonCenter_1F_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_PokemonCenter_1F_EventScript_NewNameDifferent
	msgbox RustboroCity_PokemonCenter_1F_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_NewNameDifferent::
	msgbox RustboroCity_PokemonCenter_1F_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_Text_PleasedToRateMonNickname:
	.string "I shall be pleased to rate your\n"
	.string "POKéMON's nickname.$"

RustboroCity_PokemonCenter_1F_Text_CritiqueWhichMonNickname:
	.string "Which POKéMON's nickname should\n"
	.string "I critique?$"

RustboroCity_PokemonCenter_1F_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
	.string "quite a fine name you bestowed.\p"
	.string "But! What say you, if I were to\n"
	.string "suggest a slightly better name?$"

RustboroCity_PokemonCenter_1F_Text_WhatShallNewNameBe:
	.string "Ah, good. Then, what shall the new\n"
	.string "nickname be?$"

RustboroCity_PokemonCenter_1F_Text_MonShallBeKnownAsName:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It is a better name than before!\n"
	.string "How fortunate for you!$"

RustboroCity_PokemonCenter_1F_Text_DoVisitAgain:
	.string "I see.\n"
	.string "Do come visit again.$"

RustboroCity_PokemonCenter_1F_Text_NameNoDifferentYetSuperior:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It looks no different from before,\n"
	.string "and yet, this is vastly superior!\p"
	.string "How fortunate for you!$"

RustboroCity_PokemonCenter_1F_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} it is!\p"
	.string "This is a magnificent nickname!\n"
	.string "It is impeccably beyond reproach!\p"
	.string "You'll do well to cherish your\n"
	.string "{STR_VAR_1} now and beyond.$"

RustboroCity_PokemonCenter_1F_Text_ThatIsMerelyAnEgg:
	.string "Now, now.\n"
	.string "That is merely an EGG!$"
	
RustboroCity_PokemonCenter_1F_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_SERVICE_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_PokemonCenter_1F_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, RustboroCity_PokemonCenter_1F_EventScript_ChooseMonAndMoveToForget
	case NO, RustboroCity_PokemonCenter_1F_EventScript_ComeAgain
	releaseall
	end

RustboroCity_PokemonCenter_1F_EventScript_ChooseMonAndMoveToForget::
	msgbox RustboroCity_PokemonCenter_1F_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_PokemonCenter_1F_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_PokemonCenter_1F_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, RustboroCity_PokemonCenter_1F_EventScript_MonOnlyKnowsOneMove
	msgbox RustboroCity_PokemonCenter_1F_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, RustboroCity_PokemonCenter_1F_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox RustboroCity_PokemonCenter_1F_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, RustboroCity_PokemonCenter_1F_EventScript_TryForgetMove
	case NO, RustboroCity_PokemonCenter_1F_EventScript_ComeAgain
	releaseall
	end

RustboroCity_PokemonCenter_1F_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_PokemonCenter_1F_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox RustboroCity_PokemonCenter_1F_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PokemonCenter_1F_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox RustboroCity_PokemonCenter_1F_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PokemonCenter_1F_EventScript_EggCantForgetMoves::
	msgbox RustboroCity_PokemonCenter_1F_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PokemonCenter_1F_EventScript_ComeAgain::
	msgbox RustboroCity_PokemonCenter_1F_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PokemonCenter_1F_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox RustboroCity_PokemonCenter_1F_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PokemonCenter_1F_Text_ICanMakeMonForgetMove:
	.string "I can make POKéMON forget their moves.\p"
	.string "Would you like me to do that?$"

RustboroCity_PokemonCenter_1F_Text_WhichMonShouldForget:
	.string "Which POKéMON should forget a move?$"

RustboroCity_PokemonCenter_1F_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

RustboroCity_PokemonCenter_1F_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

RustboroCity_PokemonCenter_1F_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

RustboroCity_PokemonCenter_1F_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

RustboroCity_PokemonCenter_1F_Text_ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

RustboroCity_PokemonCenter_1F_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No EGG should know any moves.$"

RustboroCity_PokemonCenter_1F_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"
