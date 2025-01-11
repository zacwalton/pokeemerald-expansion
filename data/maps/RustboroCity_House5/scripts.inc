RustboroCity_House5_MapScripts::
	.byte 0

RustboroCity_House5_EventScript_Camper::
	msgbox RustboroCity_House5_Text_Camper, MSGBOX_NPC
	end

RustboroCity_House5_Text_Camper:
	.string "This place used to be a forest.\n"
	.string "Now it's concrete houses.\p"
	.string "What people gain, wildlife often lose...\n"
	.string "Yet here I am living here. Go figure.$"

RustboroCity_House5_EventScript_Picnicker::
	msgbox RustboroCity_House5_Text_Picnicker, MSGBOX_NPC
	end
	
RustboroCity_House5_Text_Picnicker:
	.string "Rustboro still uses artesan techniques\n"
	.string "to clear the trees for housing.\p"
	.string "By avoiding heavy industry, Hoenn\n"
	.string "preserves a deeper balance with nature.$"