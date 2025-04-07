Harvest_WoodScript::
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_WOOD, VAR_RESULT
	releaseall
	end

Harvest_MushroomSmallScript::
    random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_TINY_MUSHROOM, VAR_RESULT
	releaseall
	end

Harvest_MushroomLargeScript::
	giveitem ITEM_BIG_MUSHROOM
    random 1
    addvar VAR_RESULT, 1
    giveitem ITEM_TINY_MUSHROOM, VAR_RESULT
	releaseall
	end
	
Harvest_MushroomBalmSmallScript::
	giveitem ITEM_BALM_MUSHROOM
	releaseall
	end

Harvest_VivichokeScript::
	giveitem ITEM_VIVICHOKE
	releaseall
	end
	
Harvest_KingsLeafScript::
	giveitem ITEM_KINGS_LEAF
	releaseall
	end

Harvest_LeekScript::
	random 20
	compare VAR_RESULT, 19
	goto_if_ge Harvest_LeekScript_GiveHerb
	call Harvest_LeekScript_GiveLeek
	releaseall
	end

Harvest_LeekScript_GiveLeek::
	giveitem ITEM_LEEK
	releaseall
	end
	
Harvest_LeekScript_GiveHerb::
	giveitem ITEM_REVIVAL_HERB
	releaseall
	end

Harvest_StoneScript::
	random 4
	switch VAR_RESULT
	case 0, Harvest_StoneScript_GiveMud
	call Harvest_StoneScript_GiveStone
	releaseall
	end

Harvest_StoneScript_GiveStone::
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_STONE, VAR_RESULT
	releaseall
	end
	
Harvest_StoneScript_GiveMud::
	random 2
    addvar VAR_RESULT, 1
    giveitem ITEM_MUD, VAR_RESULT
	releaseall
	end

	
Harvest_Resource_Collected::
	releaseall
	end
	
