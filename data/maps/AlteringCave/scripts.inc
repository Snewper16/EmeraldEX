AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AlteringCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	call_if_unset FLAG_DEFEATED_JIRACHI, AlteringCave_EventScript_ShowJirachi
	end

AlteringCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AlteringCave_EventScript_TryRemoveJirachi
	end

AlteringCave_EventScript_TryRemoveJirachi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_JIRACHI
	return

AlteringCave_EventScript_ShowJirachi::
	clearflag FLAG_HIDE_JIRACHI
	return

AlteringCave_EventScript_Jirachi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_JIRACHI
	setwildbattle SPECIES_JIRACHI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_EventScript_DefeatedJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AlteringCave_EventScript_RanFromJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AlteringCave_EventScript_RanFromJirachi
	setflag FLAG_DEFEATED_JIRACHI
	release
	end

AlteringCave_EventScript_DefeatedJirachi::
	setflag FLAG_DEFEATED_JIRACHI
	goto Common_EventScript_RemoveStaticPokemon
	end

AlteringCave_EventScript_RanFromJirachi::
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end
