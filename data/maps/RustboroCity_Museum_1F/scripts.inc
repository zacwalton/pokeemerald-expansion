RustboroCity_Museum_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Museum_1F_OnTransition
	.byte 0

RustboroCity_Museum_1F_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_Museum_1F_EventScript_SetFossilReady
	end

RustboroCity_Museum_1F_EventScript_SetFossilReady::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_Museum_1F_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_Museum_1F_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_Museum_1F_EventScript_StillRegenerating
	msgbox RustboroCity_Museum_1F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Museum_1F_EventScript_NoticeRootFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Museum_1F_EventScript_NoticeClawFossil
	release
	end

@ This whole section has needless duplication and could be condensed considerably
RustboroCity_Museum_1F_EventScript_NoticeRootFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST_MUSEUM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST_MUSEUM, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_Museum_1F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Museum_1F_EventScript_DeclineGiveFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Museum_1F_EventScript_ChooseFossil
	goto RustboroCity_Museum_1F_EventScript_GiveRootFossil
	end

RustboroCity_Museum_1F_EventScript_GiveRootFossil::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	msgbox RustboroCity_Museum_1F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_ROOT_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RustboroCity_Museum_1F_EventScript_NoticeClawFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST_MUSEUM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST_MUSEUM, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_Museum_1F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Museum_1F_EventScript_DeclineGiveFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Museum_1F_EventScript_ChooseFossil
	goto RustboroCity_Museum_1F_EventScript_GiveClawFossil
	end

RustboroCity_Museum_1F_EventScript_GiveClawFossil::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	msgbox RustboroCity_Museum_1F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem ITEM_CLAW_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RustboroCity_Museum_1F_EventScript_DeclineGiveFossil::
	msgbox RustboroCity_Museum_1F_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Museum_1F_EventScript_StillRegenerating::
	msgbox RustboroCity_Museum_1F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RustboroCity_Museum_1F_EventScript_FossilMonReady::
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_Museum_1F_EventScript_LileepReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_Museum_1F_EventScript_AnorithReady
	end

RustboroCity_Museum_1F_EventScript_LileepReady::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	msgbox RustboroCity_Museum_1F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_Museum_1F_EventScript_ReceiveLileep
	end

RustboroCity_Museum_1F_EventScript_AnorithReady::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	msgbox RustboroCity_Museum_1F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_Museum_1F_EventScript_ReceiveAnorith
	end

RustboroCity_Museum_1F_EventScript_ReceiveLileep::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
	givemon SPECIES_LILEEP, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_Museum_1F_EventScript_ReceiveLileepParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_Museum_1F_EventScript_ReceiveLileepPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_Museum_1F_EventScript_ReceiveLileepParty::
	call RustboroCity_Museum_1F_EventScript_ReceivedLileepFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Museum_1F_EventScript_FinishReceivingLileep
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_Museum_1F_EventScript_FinishReceivingLileep
	end

RustboroCity_Museum_1F_EventScript_ReceiveLileepPC::
	call RustboroCity_Museum_1F_EventScript_ReceivedLileepFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Museum_1F_EventScript_TransferLileepToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_Museum_1F_EventScript_TransferLileepToPC
	end

RustboroCity_Museum_1F_EventScript_TransferLileepToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_Museum_1F_EventScript_FinishReceivingLileep
	end

RustboroCity_Museum_1F_EventScript_ReceivedLileepFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_Museum_1F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	return

RustboroCity_Museum_1F_EventScript_FinishReceivingLileep::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_Museum_1F_EventScript_ReceiveAnorith::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
	givemon SPECIES_ANORITH, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_Museum_1F_EventScript_ReceiveAnorithParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_Museum_1F_EventScript_ReceiveAnorithPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_Museum_1F_EventScript_ReceiveAnorithParty::
	call RustboroCity_Museum_1F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Museum_1F_EventScript_FinishReceivingAnorith
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_Museum_1F_EventScript_FinishReceivingAnorith
	end

RustboroCity_Museum_1F_EventScript_ReceiveAnorithPC::
	call RustboroCity_Museum_1F_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Museum_1F_EventScript_TransferAnorithToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_Museum_1F_EventScript_TransferAnorithToPC
	end

RustboroCity_Museum_1F_EventScript_TransferAnorithToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_Museum_1F_EventScript_FinishReceivingAnorith
	end

RustboroCity_Museum_1F_EventScript_ReceivedAnorithFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_Museum_1F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	return

RustboroCity_Museum_1F_EventScript_FinishReceivingAnorith::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_Museum_1F_EventScript_ChooseFossil::
	message RustboroCity_Museum_1F_Text_TwoFossilsPickOne
	waitmessage
	multichoice 17, 6, MULTI_FOSSIL, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_Museum_1F_EventScript_ChooseClawFossil
	case 1, RustboroCity_Museum_1F_EventScript_ChooseRootFossil
	case 2, RustboroCity_Museum_1F_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, RustboroCity_Museum_1F_EventScript_CancelFossilSelect
	end

RustboroCity_Museum_1F_EventScript_ChooseClawFossil::
	goto RustboroCity_Museum_1F_EventScript_GiveClawFossil
	end

RustboroCity_Museum_1F_EventScript_ChooseRootFossil::
	goto RustboroCity_Museum_1F_EventScript_GiveRootFossil
	end

RustboroCity_Museum_1F_EventScript_CancelFossilSelect::
	release
	end

RustboroCity_Museum_1F_EventScript_Fossil::
	msgbox RustboroCity_Museum_1F_Text_Fossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_Fossil:
	.string "It's a fossil.\p"
	.string "I wonder how old it is?$"

RustboroCity_Museum_1F_EventScript_RelicanthFossil::
	msgbox RustboroCity_Museum_1F_Text_RelicanthFossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_RelicanthFossil:
	.string "“This ancient fossil fish dates back \n"
	.string "over 100 million years.\p"
	.string "Yet it appears virtually unchanged\n"
	.string "compared to modern Relicanth.”$"

RustboroCity_Museum_1F_EventScript_KabutoFossil::
	msgbox RustboroCity_Museum_1F_Text_KabutoFossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_KabutoFossil:
	.string "“The fossilised remains of Kabuto have\n"
	.string "been dated up to 300 million years old!\p"
	.string "They were likely solitary animals\n"
	.string "but may have congregated on occasion.”$"

RustboroCity_Museum_1F_EventScript_OmanyteFossil::
	msgbox RustboroCity_Museum_1F_Text_OmanyteFossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_OmanyteFossil:
	.string "“A series of Helix Fossils embedded in\n"
	.string "stone. These fossils correspond to the \p"
	.string "pokémon we now know of as Omanyte.”$"

RustboroCity_Museum_1F_EventScript_FossilMount::
	msgbox RustboroCity_Museum_1F_Text_FossilMount, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_FossilMount:
	.string "It's a replica of an ancient pokémon.$"

RustboroCity_Museum_1F_EventScript_FossilShell::
	msgbox RustboroCity_Museum_1F_Text_FossilShell, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_FossilShell:
	.string "It appears to be a shell from\n"
	.string "a super ancient pokémon.$"

RustboroCity_Museum_1F_EventScript_FossilSkulls::
	checkleadspecies SPECIES_ARON
	bufferlivemonnickname STR_VAR_1
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Museum_1F_EventScript_FossilSkullsAron
	msgbox RustboroCity_Museum_1F_Text_FossilSkulls, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_EventScript_FossilSkullsAron::
	msgbox RustboroCity_Museum_1F_Text_FossilSkullsAron, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_FossilSkulls:
	.string "It's a collection of skulls.\n"
	.string "They almost look like shields.$"
	end

RustboroCity_Museum_1F_Text_FossilSkullsAron:
	.string "It's a collection of skulls.\p"
	.string "Huh... They look a bit like {STR_VAR_1}.$"

RustboroCity_Museum_1F_EventScript_FossilSkullBig::
	msgbox RustboroCity_Museum_1F_Text_FossilSkullBig, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_FossilSkullBig:
	.string "It's a large imposing skull.\n"
	.string "I wonder how old it is?.$"

RustboroCity_Museum_1F_EventScript_ArmaldoFossil::
	msgbox RustboroCity_Museum_1F_Text_ArmaldoFossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_ArmaldoFossil:
	.string "“The ancient pokémon Armaldo would\n"
	.string "have been a top predator in its time.”$"
	
RustboroCity_Museum_1F_EventScript_CradilyFossil::
	msgbox RustboroCity_Museum_1F_Text_CradilyFossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_CradilyFossil:
	.string "“Cradily would have anchored itself to\n"
	.string "the sea floor, waiting to ambush prey.\p"
	.string "Fossils of its roots are often found \n"
	.string "near Route 111, which is thought to \p"
	.string "have been a shallow sea in the past.”$"
	
RustboroCity_Museum_1F_EventScript_RampardosFossil::
	msgbox RustboroCity_Museum_1F_Text_RampardosFossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_RampardosFossil:
	.string "“Rampardos' thick skull fossilises \n"
	.string "much easier than the rest of its body.\p"
	.string "Marks found on the skulls indicate \n"
	.string "this pokémon was fiercely territorial.\p"
	.string "It may have been a natural rival to \n"
	.string "the pokémon Bastiodon.”$"
	
RustboroCity_Museum_1F_EventScript_TyrantrumFossil::
	msgbox RustboroCity_Museum_1F_Text_TyrantrumFossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_TyrantrumFossil:
	.string "“Behold Tyrantrum! \n"
	.string "The King of the ancient world.\p"
	.string "Tyrantrum is one of the largest\n"
	.string "predators to walk the planet.\p"
	.string "Nothing in its environment would\n"
	.string "dare to challenge it.”$"
	
RustboroCity_Museum_1F_EventScript_AurorusFossil::
	msgbox RustboroCity_Museum_1F_Text_AurorusFossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_AurorusFossil:
	.string "“Deep grooves found in the neck bones\n"
	.string "of Aurorus were once attributed to\p"
	.string "Tyrantrum attacks. We now know them\n"
	.string "to be achor points for gigantic sails!”$"

RustboroCity_Museum_1F_EventScript_PoseFossil::
	msgbox RustboroCity_Museum_1F_Text_PoseFossil, MSGBOX_SIGN
	end

RustboroCity_Museum_1F_Text_PoseFossil:
	.string "“Many bipedal pokémon use their heavy\n"
	.string "tails as a counter-balance. \p"
	.string "Thick tendons running from the head to\n"
	.string "to the tail keep the pokémon upright.\p"
	.string "When the pokémon dies, these tendons\n"
	.string "dry out, shrinking in the process.\p"
	.string "This pulls the head and tail together,\n"
	.string "leading to this iconic pose.”$"


RustboroCity_Museum_1F_Text_DevelopDeviceToResurrectFossils:
	.string "I've been trying to develop a device\n"
	.string "that resurrects POKéMON from fossils…\p"
	.string "And, it's working!$"

RustboroCity_Museum_1F_Text_WantToBringFossilBackToLife:
	.string "Wait! That thing you have there…\n"
	.string "Is that a POKéMON fossil?\p"
	.string "Would you like to bring that POKéMON\n"
	.string "back to life?\p"
	.string "I can with my newly developed\n"
	.string "FOSSIL REGENERATOR.$"

RustboroCity_Museum_1F_Text_OhIsThatSo:
	.string "Oh, is that so?\p"
	.string "DEVON's technological expertise\n"
	.string "is outstanding, I tell you.$"

RustboroCity_Museum_1F_Text_TwoFossilsPickOne:
	.string "Oh, now that's a surprise!\n"
	.string "You have not one, but two, fossils?\p"
	.string "Unfortunately, my machine can only\n"
	.string "regenerate one POKéMON at a time.\p"
	.string "Would you like to pick one of your\n"
	.string "fossils for regeneration?$"

RustboroCity_Museum_1F_Text_HandedFossilToResearcher:
	.string "Excellent!\n"
	.string "Let's do this right away.\p"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
	.string "the DEVON RESEARCHER.$"

RustboroCity_Museum_1F_Text_FossilRegeneratorTakesTime:
	.string "The FOSSIL REGENERATOR, which I made,\n"
	.string "is incredible.\p"
	.string "But it has one drawback--it takes\n"
	.string "a long time to work.\p"
	.string "So, uh… How about you go for a stroll\n"
	.string "and look around for a while?$"

RustboroCity_Museum_1F_Text_FossilizedMonBroughtBackToLife:
	.string "Thanks for waiting!\p"
	.string "Your fossilized POKéMON has been\n"
	.string "brought back to life!\p"
	.string "The fossil was an ancient POKéMON.\n"
	.string "{STR_VAR_2}, it was!$"

RustboroCity_Museum_1F_Text_ReceivedMonFromResearcher:
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the DEVON RESEARCHER.$"

@ Unused
RustboroCity_Museum_1F_Text_TooManyPokemon:
	.string "Uh-oh, you've got too many POKéMON.\n"
	.string "You have no room for this one.$"

RustboroCity_Museum_1F_EventScript_Security1::
	msgbox RustboroCity_Museum_1F_Text_Security1, MSGBOX_NPC
	end

RustboroCity_Museum_1F_Text_Security1:
	.string "Devon was once a small mining company.\p"
	.string "Back then, people didn't really know\n"
	.string "much about fossils.\p"
	.string "Can you imagine how many fossils were\n"
	.string "lost by miners who tossed them aside?\p"
	.string "Heck, even the fossil experts used\n"
	.string "dymanite to blast them out the ground!\p"
	.string "Devon founded this museum as a way\n"
	.string "to honor its humble beginings.\p"
	.string "...and to repay all that lost knowledge.$"

RustboroCity_Museum_1F_EventScript_Security2::
	msgbox RustboroCity_Museum_1F_Text_Security2, MSGBOX_NPC
	end

RustboroCity_Museum_1F_Text_Security2:
	.string "Please do not touch the displays.$"

RustboroCity_Museum_1F_EventScript_Picknicker::
	msgbox RustboroCity_Museum_1F_Text_Picknicker, MSGBOX_NPC
	end

RustboroCity_Museum_1F_Text_Picknicker:
	.string "We came all the way from\n"
	.string "the Sinnoh region.\p"
	.string "our home town has a museum just\n"
	.string "like this one.$"

RustboroCity_Museum_1F_EventScript_Man1::
	msgbox RustboroCity_Museum_1F_Text_Man1, MSGBOX_NPC
	end

RustboroCity_Museum_1F_Text_Man1:
	.string "The age of these species blows my mind.\p"
	.string "For something to last that long is\n"
	.string "nothing short of a miracle.$"

RustboroCity_Museum_1F_EventScript_Man2::
	msgbox RustboroCity_Museum_1F_Text_Man2, MSGBOX_NPC
	end

RustboroCity_Museum_1F_Text_Man2:
	.string "I heard all life started in the ocean.\p"
	.string "...Something about thermal vents...$"

RustboroCity_Museum_1F_EventScript_Man3::
	msgbox RustboroCity_Museum_1F_Text_Man3, MSGBOX_NPC
	end

RustboroCity_Museum_1F_Text_Man3:
	.string "Can you imagine walking around\n"
	.string "100 million years ago?\p"
	.string "I sure can't.$"

RustboroCity_Museum_1F_EventScript_Mom::
	msgbox RustboroCity_Museum_1F_Text_Mom MSGBOX_NPC
	end

RustboroCity_Museum_1F_Text_Mom:
	.string "I take my son here whenever I'm in town.\n"
	.string "He just loves the displays.$"

RustboroCity_Museum_1F_EventScript_Child::
	checkleadspecies SPECIES_TYRANTRUM
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Museum_1F_EventScript_ChildSeeFossilMon
	checkleadspecies SPECIES_AURORUS
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Museum_1F_EventScript_ChildSeeFossilMon
	msgbox RustboroCity_Museum_1F_Text_Child MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_Museum_1F_EventScript_ChildHappy
	msgbox RustboroCity_Museum_1F_Text_ChildSad MSGBOX_NPC
	end

RustboroCity_Museum_1F_EventScript_ChildHappy::
	msgbox RustboroCity_Museum_1F_Text_ChildHappy MSGBOX_NPC
	end

RustboroCity_Museum_1F_EventScript_ChildSeeFossilMon::
	playse SE_PIN
	applymovement 12, Common_Movement_ExclamationMark
	msgbox RustboroCity_Museum_1F_Text_ChildSeeFossilMon MSGBOX_NPC
	end

RustboroCity_Museum_1F_Text_Child:
	.string "Were they really this big?$"

RustboroCity_Museum_1F_Text_ChildHappy:
	.string "Wowwy!$"

RustboroCity_Museum_1F_Text_ChildSad:
	.string "Aw... \p"
	.string "Disappointing.$"

RustboroCity_Museum_1F_Text_ChildSeeFossilMon:
	.string "Wow! They're so big!\p"
	.string "But yours is small compared \n"
	.string "to the statue.\p"
	.string "Awh.$"

RustboroCity_Museum_1F_EventScript_Hiker::
	goto_if_set FLAG_RUSTBORO_MUSEUM_HIKER, RustboroCity_Museum_1F_EventScript_HikerHappy
	msgbox RustboroCity_Museum_1F_Text_HikerGeneric, MSGBOX_NPC
	checkleadspecies SPECIES_RAMPARDOS
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Museum_1F_EventScript_HikerRampardos
	release
	end

	RustboroCity_Museum_1F_EventScript_HikerRampardos::
	closemessage
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_Museum_1F_Text_HikerRampardos, MSGBOX_NPC
	giveitem ITEM_BLACK_AUGURITE 
	setflag FLAG_RUSTBORO_MUSEUM_HIKER
	release
	end

RustboroCity_Museum_1F_EventScript_HikerHappy::
	msgbox RustboroCity_Museum_1F_Text_HikerHappy, MSGBOX_NPC
	release
	end

RustboroCity_Museum_1F_Text_HikerGeneric:
	.string "What I'd give to see these things in life.$"
	
RustboroCity_Museum_1F_Text_HikerHappy:
	.string "I can't believe I got to see these things\n"
	.string "in in the flesh. Thank you. Truly.$"

RustboroCity_Museum_1F_Text_HikerRampardos:
	.string "Wait... Is that a...? \p"
	.string "You have a Rampardos?!\p"
	.string "You just made my whole year!\n"
	.string "Please, take this. I insist.\p"
	.string "It's a lucky token from my home region.$"
