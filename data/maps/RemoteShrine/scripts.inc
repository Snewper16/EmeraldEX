RemoteShrine_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, RemoteShrine_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, RemoteShrine_OnTransition
	.byte 0

RemoteShrine_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, RemoteShrine_EventScript_TryRemoveRegigigas
	end

RemoteShrine_EventScript_TryRemoveRegigigas::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

RemoteShrine_OnTransition:
	setflag FLAG_LANDMARK_REMOTE_SHRINE
	call_if_unset FLAG_DEFEATED_REGIGIGAS, RemoteShrine_EventScript_ShowRegigigas
	end

RemoteShrine_EventScript_ShowRegigigas::
	clearflag FLAG_HIDE_REGIGIGAS
	return

RemoteShrine_EventScript_Regigigas::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RemoteShrine_EventScript_DefeatedRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RemoteShrine_EventScript_RanFromRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RemoteShrine_EventScript_RanFromRegigigas
	setflag FLAG_DEFEATED_REGIGIGAS
	release
	end

RemoteShrine_EventScript_DefeatedRegigigas::
	setflag FLAG_DEFEATED_REGIGIGAS
	goto Common_EventScript_RemoveStaticPokemon
	end

RemoteShrine_EventScript_RanFromRegigigas::
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end
