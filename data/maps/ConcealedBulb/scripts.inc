ConcealedBulb_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ConcealedBulb_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ConcealedBulb_OnTransition
	.byte 0

ConcealedBulb_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ConcealedBulb_EventScript_TryRemoveRegieleki
	end

ConcealedBulb_EventScript_TryRemoveRegieleki::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

ConcealedBulb_OnTransition:
	setflag FLAG_LANDMARK_CONCEALED_BULB
	call_if_unset FLAG_DEFEATED_REGIELEKI, ConcealedBulb_EventScript_ShowRegieleki
	end

ConcealedBulb_EventScript_ShowRegieleki::
	clearflag FLAG_HIDE_REGIELEKI
	return

ConcealedBulb_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ConcealedBulb_EventScript_DefeatedRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ConcealedBulb_EventScript_RanFromRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ConcealedBulb_EventScript_RanFromRegieleki
	setflag FLAG_DEFEATED_REGIELEKI
	release
	end

ConcealedBulb_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

ConcealedBulb_EventScript_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end
