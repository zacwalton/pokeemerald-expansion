Eventscript_Harvest_Tile::
	goto_if_flag VAR_0x8004, Harvest_Resource_Collected
	special SetHiddenItemFlag
	setallharvestablemetatiles
	special DrawWholeMapView
	switch VAR_0x8005
	case 2, Harvest_Script_Leek
	case 3, Harvest_Script_Wood
	case 4, Harvest_Script_MushroomSmall
	case 5, Harvest_Script_MushroomLarge
	case 6, Harvest_Script_BalmSmall
	case 7, Harvest_Script_BalmSmall
	case 8, Harvest_Script_Vivichoke
	case 9, Harvest_Script_KingsLeaf
	case 10, Harvest_Script_Stone
	releaseall
	end


Harvest_Script_Leek::
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Harvest_Script_Leek_GiveHerb
	call Harvest_Script_Leek_GiveLeek
	releaseall
	end

Harvest_Script_Leek_GiveLeek::
	giveitem ITEM_LEEK
	releaseall
	end
	
Harvest_Script_Leek_GiveHerb::
	giveitem ITEM_REVIVAL_HERB
	releaseall
	end

Harvest_Script_Wood::
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_WOOD, VAR_RESULT
	releaseall
	end

Harvest_Script_MushroomSmall::
    random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_TINY_MUSHROOM, VAR_RESULT
	releaseall
	end

Harvest_Script_MushroomLarge::
	giveitem ITEM_BIG_MUSHROOM
    random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_TINY_MUSHROOM, VAR_RESULT
	releaseall
	end
	
Harvest_Script_BalmSmall::
	giveitem ITEM_BALM_MUSHROOM
	releaseall
	end

Harvest_Script_Vivichoke::
	giveitem ITEM_VIVICHOKE
	releaseall
	end
	
Harvest_Script_KingsLeaf::
	giveitem ITEM_KINGS_LEAF
	releaseall
	end

Harvest_Script_Stone::
	random 4
	switch VAR_RESULT
	case 0, Harvest_Script_Stone_GiveMud
	call Harvest_Script_Stone_GiveStone
	releaseall
	end

Harvest_Script_Stone_GiveStone::
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_STONE, VAR_RESULT
	releaseall
	end
	
Harvest_Script_Stone_GiveMud::
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_MUD, VAR_RESULT
	releaseall
	end

	
Harvest_Resource_Collected::
	releaseall
	end
	
EventScript_Harvest_CutGrassScript::
	giveitem ITEM_PLANT_FIBRE, VAR_0x8008
	releaseall
	end
	
EventScript_Harvest_CutGrassScript_Item::
	random 6
	switch VAR_RESULT
	case 0, EventScript_GiveRandomBerry
	case 1, EventScript_Harvest_CutGrassScript_GreatBall
	case 2, EventScript_Harvest_CutGrassScript_Potion
	case 3, EventScript_GiveRandomBerry
	case 4, EventScript_Harvest_CutGrassScript_Pokeball
	case 5, EventScript_GiveRandomFeather
	releaseall
	end


EventScript_Harvest_CutGrassScript_Pokeball::
	giveitem ITEM_POKE_BALL
	releaseall
	end

EventScript_Harvest_CutGrassScript_GreatBall::
	giveitem ITEM_GREAT_BALL
	releaseall
	end

EventScript_Harvest_CutGrassScript_Potion::
	giveitem ITEM_POTION
	releaseall
	end
	
	
EventScript_GiveRandomFeather::
	random 10
	switch VAR_RESULT
	case 0, EventScript_GiveRandomFeather_Pretty
	case 1, EventScript_GiveRandomFeather_Health
	case 2, EventScript_GiveRandomFeather_Muscle
	case 3, EventScript_GiveRandomFeather_Resist
	case 4, EventScript_GiveRandomFeather_Genius
	case 5, EventScript_GiveRandomFeather_Clever
	case 6, EventScript_GiveRandomFeather_Swift
	case 7, EventScript_GiveRandomFeather_Pretty
	case 8, EventScript_GiveRandomFeather_Pretty
	case 9, EventScript_GiveRandomFeather_Pretty
	releaseall
	end

EventScript_GiveRandomFeather_Pretty::
	giveitem ITEM_PRETTY_FEATHER
	releaseall
	end

EventScript_GiveRandomFeather_Health::
	giveitem ITEM_HEALTH_FEATHER
	releaseall
	end

EventScript_GiveRandomFeather_Muscle::
	giveitem ITEM_MUSCLE_FEATHER
	releaseall
	end

EventScript_GiveRandomFeather_Resist::
	giveitem ITEM_RESIST_FEATHER
	releaseall
	end

EventScript_GiveRandomFeather_Genius::
	giveitem ITEM_GENIUS_FEATHER
	releaseall
	end

EventScript_GiveRandomFeather_Clever::
	giveitem ITEM_CLEVER_FEATHER
	releaseall
	end

EventScript_GiveRandomFeather_Swift::
	giveitem ITEM_SWIFT_FEATHER
	releaseall
	end
	
	
EventScript_GiveRandomBerry::
	random 10
	switch VAR_RESULT
	case 0, EventScript_GiveRandomBerry_Common
	case 1, EventScript_GiveRandomBerry_Common
	case 2, EventScript_GiveRandomBerry_Common
	case 3, EventScript_GiveRandomBerry_Common
	case 4, EventScript_GiveRandomBerry_Common
	case 5, EventScript_GiveRandomBerry_Common
	case 6, EventScript_GiveRandomBerry_Uncommon
	case 7, EventScript_GiveRandomBerry_Uncommon
	case 8, EventScript_GiveRandomBerry_Uncommon
	case 9, EventScript_GiveRandomBerry_Rare
	releaseall
	end
	
EventScript_GiveRandomBerry_Common::
	random 10
	switch VAR_RESULT
	case 0, EventScript_GiveRandomBerry_Cheri
	case 1, EventScript_GiveRandomBerry_Chesto
	case 2, EventScript_GiveRandomBerry_Pecha
	case 3, EventScript_GiveRandomBerry_Rawst
	case 4, EventScript_GiveRandomBerry_Aspear
	case 5, EventScript_GiveRandomBerry_Leppa
	case 6, EventScript_GiveRandomBerry_Oran
	case 7, EventScript_GiveRandomBerry_Persim
	case 8, EventScript_GiveRandomBerry_Oran
	case 9, EventScript_GiveRandomBerry_Oran
	releaseall
	end
	
EventScript_GiveRandomBerry_Uncommon::
	random 15
	switch VAR_RESULT
	case 0, EventScript_GiveRandomBerry_Lum
	case 1, EventScript_GiveRandomBerry_Sitrus
	case 2, EventScript_GiveRandomBerry_Figy
	case 3, EventScript_GiveRandomBerry_Wiki
	case 4, EventScript_GiveRandomBerry_Mago
	case 5, EventScript_GiveRandomBerry_Aguav
	case 6, EventScript_GiveRandomBerry_Iapapa
	case 7, EventScript_GiveRandomBerry_Pomeg
	case 8, EventScript_GiveRandomBerry_Kelpsy
	case 9, EventScript_GiveRandomBerry_Qualot
	case 10, EventScript_GiveRandomBerry_Hondew
	case 11, EventScript_GiveRandomBerry_Grepa
	case 12, EventScript_GiveRandomBerry_Tamato
	case 13, EventScript_GiveRandomBerry_Sitrus
	case 14, EventScript_GiveRandomBerry_Sitrus
	releaseall
	end
	
EventScript_GiveRandomBerry_Rare::
	random 25
	switch VAR_RESULT
	case 0, EventScript_GiveRandomBerry_Occa
	case 1, EventScript_GiveRandomBerry_Passho
	case 2, EventScript_GiveRandomBerry_Wacan
	case 3, EventScript_GiveRandomBerry_Rindo
	case 4, EventScript_GiveRandomBerry_Yache
	case 5, EventScript_GiveRandomBerry_Chople
	case 6, EventScript_GiveRandomBerry_Kebia
	case 7, EventScript_GiveRandomBerry_Shuca
	case 8, EventScript_GiveRandomBerry_Coba
	case 9, EventScript_GiveRandomBerry_Payapa
	case 10, EventScript_GiveRandomBerry_Tanga
	case 11, EventScript_GiveRandomBerry_Charti
	case 12, EventScript_GiveRandomBerry_Kasib
	case 13, EventScript_GiveRandomBerry_Haban
	case 14, EventScript_GiveRandomBerry_Colbur
	case 15, EventScript_GiveRandomBerry_Babiri
	case 16, EventScript_GiveRandomBerry_Chilan
	case 17, EventScript_GiveRandomBerry_Roseli
	case 18, EventScript_GiveRandomBerry_Liechi
	case 19, EventScript_GiveRandomBerry_Ganlon
	case 20, EventScript_GiveRandomBerry_Salac
	case 21, EventScript_GiveRandomBerry_Petaya
	case 22, EventScript_GiveRandomBerry_Apicot
	case 23, EventScript_GiveRandomBerry_Kee
	case 24, EventScript_GiveRandomBerry_Maranga
	releaseall
	end
	
EventScript_GiveRandomBerry_Cheri::
	giveitem ITEM_CHERI_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Chesto::
	giveitem ITEM_CHESTO_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Pecha::
	giveitem ITEM_PECHA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Rawst::
	giveitem ITEM_RAWST_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Aspear::
	giveitem ITEM_ASPEAR_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Leppa::
	giveitem ITEM_LEPPA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Oran::
	giveitem ITEM_ORAN_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Persim::
	giveitem ITEM_PERSIM_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Lum::
	giveitem ITEM_LUM_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Sitrus::
	giveitem ITEM_SITRUS_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Figy::
	giveitem ITEM_FIGY_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Wiki::
	giveitem ITEM_WIKI_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Mago::
	giveitem ITEM_MAGO_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Aguav::
	giveitem ITEM_AGUAV_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Iapapa::
	giveitem ITEM_IAPAPA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Pomeg::
	giveitem ITEM_POMEG_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Kelpsy::
	giveitem ITEM_KELPSY_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Qualot::
	giveitem ITEM_QUALOT_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Hondew::
	giveitem ITEM_HONDEW_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Grepa::
	giveitem ITEM_GREPA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Tamato::
	giveitem ITEM_TAMATO_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Occa::
	giveitem ITEM_OCCA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Passho::
	giveitem ITEM_PASSHO_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Wacan::
	giveitem ITEM_WACAN_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Rindo::
	giveitem ITEM_RINDO_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Yache::
	giveitem ITEM_YACHE_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Chople::
	giveitem ITEM_CHOPLE_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Kebia::
	giveitem ITEM_KEBIA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Shuca::
	giveitem ITEM_SHUCA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Coba::
	giveitem ITEM_COBA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Payapa::
	giveitem ITEM_PAYAPA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Tanga::
	giveitem ITEM_TANGA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Charti::
	giveitem ITEM_CHARTI_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Kasib::
	giveitem ITEM_KASIB_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Haban::
	giveitem ITEM_HABAN_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Colbur::
	giveitem ITEM_COLBUR_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Babiri::
	giveitem ITEM_BABIRI_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Chilan::
	giveitem ITEM_CHILAN_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Roseli::
	giveitem ITEM_ROSELI_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Liechi::
	giveitem ITEM_LIECHI_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Ganlon::
	giveitem ITEM_GANLON_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Salac::
	giveitem ITEM_SALAC_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Petaya::
	giveitem ITEM_PETAYA_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Apicot::
	giveitem ITEM_APICOT_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Kee::
	giveitem ITEM_KEE_BERRY
	releaseall
	end

EventScript_GiveRandomBerry_Maranga::
	giveitem ITEM_MARANGA_BERRY
	releaseall
	end

