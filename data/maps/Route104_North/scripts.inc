Route104_North_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route104_North_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
	.byte 0

Route104_North_OnResume:
	call_if_Set FLAG_ROUTE104_LEEK1, Route104_North_Resource_Leek1
	call_if_Set FLAG_ROUTE104_LEEK2, Route104_North_Resource_Leek2
	call_if_Set FLAG_ROUTE104_LEEK3, Route104_North_Resource_Leek3
	call_if_Set FLAG_ROUTE104_MUSHROOM1, Route104_North_Resource_Mushroom1
	call_if_Set FLAG_ROUTE104_VIVICHOKE1, Route104_North_Resource_Vivichoke1
	call_if_Set FLAG_ROUTE104_VIVICHOKE2, Route104_North_Resource_Vivichoke2
	end

Route104_North_Resource_Leek1::
	setmetatile 40, 21, METATILE_General_Grass, FALSE
	return

Route104_North_Resource_Leek2::
	setmetatile 51, 20, METATILE_General_Grass, FALSE
	return

Route104_North_Resource_Leek3::
	setmetatile 63, 4, METATILE_General_Grass, FALSE
	return

Route104_North_Resource_Mushroom1::
	setmetatile 38, 17, METATILE_General_Grass, FALSE
	return

Route104_North_Resource_Vivichoke1::
	setmetatile 48, 5, METATILE_General_Grass, FALSE
	return

Route104_North_Resource_Vivichoke2::
	setmetatile 48, 15, METATILE_General_Grass, FALSE
	return

Route104_North_Resource_Leek1Harvest::
	goto_if_set FLAG_ROUTE104_LEEK1, Route104_North_Resource_Collected
	setflag FLAG_ROUTE104_LEEK1
	call Route104_North_Resource_Leek1
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route104_North_Resource_Give_Herb
	giveitem ITEM_STICK
	releaseall
	end

Route104_North_Resource_Leek2Harvest::
	goto_if_set FLAG_ROUTE104_LEEK2, Route104_North_Resource_Collected
	setflag FLAG_ROUTE104_LEEK2
	call Route104_North_Resource_Leek2
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route104_North_Resource_Give_Herb
	giveitem ITEM_STICK
	releaseall
	end

Route104_North_Resource_Leek3Harvest::
	goto_if_set FLAG_ROUTE104_LEEK3, Route104_North_Resource_Collected
	setflag FLAG_ROUTE104_LEEK3
	call Route104_North_Resource_Leek3
	special DrawWholeMapView
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Route104_North_Resource_Give_Herb
	giveitem ITEM_LEEK
	releaseall
	end

Route104_North_Resource_Mushroom1Harvest::
	goto_if_set FLAG_ROUTE104_MUSHROOM1, Route104_North_Resource_Collected
	setflag FLAG_ROUTE104_MUSHROOM1
	call Route104_North_Resource_Mushroom1
	special DrawWholeMapView
    random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_TINY_MUSHROOM, VAR_RESULT
	releaseall
	end

Route104_North_Resource_Vivichoke1Harvest::
	goto_if_set FLAG_ROUTE104_VIVICHOKE1, Route104_North_Resource_Collected
	giveitem ITEM_VIVICHOKE
	setflag FLAG_ROUTE104_VIVICHOKE1
	call Route104_North_Resource_Vivichoke1
	special DrawWholeMapView
	releaseall
	end

Route104_North_Resource_Vivichoke2Harvest::
	goto_if_set FLAG_ROUTE104_VIVICHOKE1, Route104_North_Resource_Collected
	giveitem ITEM_VIVICHOKE
	setflag FLAG_ROUTE104_VIVICHOKE1
	call Route104_North_Resource_Vivichoke1
	special DrawWholeMapView
	releaseall
	end

Route104_North_Resource_Collected::
	releaseall
	end

Route104_North_Resource_Give_Leek::
	giveitem ITEM_LEEK
	releaseall
	end
	
Route104_North_Resource_Give_Herb::
	giveitem ITEM_REVIVAL_HERB
	releaseall
	end

Route104_North_OnTransition:
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
	end

Route104_EventScript_ShowOrHideWhiteHerbFlorist::
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	return

Route104_EventScript_HideWhiteHerbFlorist::
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	return
	
Route104_EventScript_ExpertF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ReceivedBerry
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_CHESTO_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_ReceivedBerry::
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_WhiteHerbFlorist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
	giveitem ITEM_WHITE_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_WHITE_HERB
	release
	end

Route104_EventScript_ReceivedWhiteHerb::
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
	release
	end
	
Route104_EventScript_RouteSignRustboro::
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route104_EventScript_FlowerShopSign::
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
	end

Route104_EventScript_TrainerTipsDoubleBattles::
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
	end

Route104_EventScript_Boy2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_BULLET_SEED, Route104_EventScript_ReceivedBulletSeed
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BULLET_SEED
	release
	end

Route104_EventScript_ReceivedBulletSeed::
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
	release
	end
	
Route104_EventScript_Ivan::
	trainerbattle_single TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end
	
Route104_EventScript_Haley::
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat, Route104_EventScript_TryRegisterHaleyAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchHaley
	setvar VAR_0x8004, TRAINER_HALEY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterHaley
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_TryRegisterHaleyAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
	release
	end

Route104_EventScript_RegisterHaleyAfterBattle::
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_HALEY_1
	release
	end

Route104_EventScript_TryRegisterHaley::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RegisterHaley::
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_HALEY_1
	release
	end

Route104_EventScript_RematchHaley::
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Winston::
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Route104_EventScript_TryRegisterWinstonAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchWinston
	setvar VAR_0x8004, TRAINER_WINSTON_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterWinston
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_TryRegisterWinstonAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
	release
	end

Route104_EventScript_RegisterWinstonAfterBattle::
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end

Route104_EventScript_TryRegisterWinston::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RegisterWinston::
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end

Route104_EventScript_RematchWinston::
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Gina::
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Mia::
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_Text_LikeFillingMouthWithSeedsTakeThis:
	.string "I like filling my mouth with seeds,\n"
	.string "then spitting them out fast!\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for firing seeds rapidly.$"

Route104_Text_TMsAreOneTimeUse:
	.string "A word of advice!\p"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
	.string "for one-time use.\p"
	.string "Once you use it, it's gone.\n"
	.string "Think twice before using it!$"

Route104_Text_DontNeedThisTakeIt:
	.string "This FLOWER SHOP started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping.\p"
	.string "I don't need this WHITE HERB anymore.\n"
	.string "Would you take it, please?$"

Route104_Text_FlowerShopSellingSaplings:
	.string "This FLOWER SHOP started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping. Where should I put them?$"

Route104_Text_RouteSignRustboro:
	.string "ROUTE 1O4\n"
	.string "{UP_ARROW} RUSTBORO CITY$"

Route104_Text_PrettyPetalFlowShop:
	.string "PRETTY PETAL FLOWER SHOP$"

Route104_Text_TrainerTipsDoubleBattles:
	.string "TRAINER TIPS\p"
	.string "In the HOENN region there are pairs\n"
	.string "of TRAINERS who challenge others\l"
	.string "for 2-on-2 POKéMON battles called\l"
	.string "DOUBLE BATTLES.\p"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
	.string "send out two POKéMON, the one at the\l"
	.string "left of the list and the top one.\l"
	.string "Watch how POKéMON are lined up.$"

