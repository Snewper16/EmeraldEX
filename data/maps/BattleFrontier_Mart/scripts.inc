BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_TM_BUG_BUZZ
	.2byte ITEM_TM_IRON_HEAD
	.2byte ITEM_TM_STEALTH_ROCK
	.2byte ITEM_TM_TRICK_ROOM
	.2byte ITEM_TM_GUARD_SWAP
	.2byte ITEM_TM_POWER_SWAP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_TicketGuy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EVENT_TICKETS, BattleFrontier_Mart_EventScript_TicketGuyAfterGivenTickets
	msgbox BattleFrontier_Mart_Text_TicketGuy, MSGBOX_NPC
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	giveitem ITEM_EON_TICKET
	setflag FLAG_RECEIVED_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_RECEIVED_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_EVENT_TICKETS
	release
	end

BattleFrontier_Mart_EventScript_TicketGuyAfterGivenTickets::
	msgbox BattleFrontier_Mart_Text_TicketGuyAfterGivenTickets, MSGBOX_NPC
	release
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "We came here to chaperon our\n"
	.string "grandson.\p"
	.string "But since we're here, we thought\n"
	.string "we should get some souvenirs.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Dear, what do you think of this?\n"
	.string "Wouldn't this make a nice gift?\p"
	.string "It's…PRO…TE…IN?\n"
	.string "It sounds delicious, doesn't it?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "A lot of the BATTLE FRONTIER's\n"
	.string "facilities don't allow the use of items\l"
	.string "during battles.\p"
	.string "That rule makes things tougher than\n"
	.string "they already are!$"

BattleFrontier_Mart_Text_TicketGuy:
	.string "Shhh... just take these, you'll\n"
	.string "thank me later.$"

BattleFrontier_Mart_Text_TicketGuyAfterGivenTickets:
	.string "Take those to the ferry in Lilycove City.\p"
	.string "The ferry should be able to take you\n"
	.string "to the places mentioned on these things.$"
