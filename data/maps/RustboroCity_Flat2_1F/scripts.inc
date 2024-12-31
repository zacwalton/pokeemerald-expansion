RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_Woman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Delcatty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DELCATTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Delcatty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "There was a time when these apartments\n"
	.string "were given to Devon employees.\p"
	.string "How times have changed.$"

RustboroCity_Flat2_1F_Text_Delcatty:
	.string "Delcatty: Gyaaaah!$"

