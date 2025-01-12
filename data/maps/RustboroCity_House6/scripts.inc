RustboroCity_House6_MapScripts::
	.byte 0

RustboroCity_House5_EventScript_Collector::
	lock
	faceplayer
	goto_if_set FLAG_RECIEVED_LIFE_ORB_RUSTBORO, RustboroCity_House6_LifeOrb_Given
	msgbox RustboroCity_House6_Text_LifeOrb, MSGBOX_DEFAULT
	giveitem ITEM_LIFE_ORB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECIEVED_LIFE_ORB_RUSTBORO
	release
	end

RustboroCity_House6_LifeOrb_Given::
	msgbox RustboroCity_House6__Text_LifeOrb_Given, MSGBOX_DEFAULT
	release
	end

RustboroCity_House6_Text_LifeOrb:
	.string "Do you like rocks?\p"
	.string "This one doesn't quite fit my collection.\n"
	.string "Take it if you like.$"

RustboroCity_House6__Text_LifeOrb_Given:
	.string "I love rocks.\n"
	.string "So much history preserved in them.$"

