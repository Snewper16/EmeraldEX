MastersForge_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MastersForge_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MastersForge_OnTransition
	.byte 0

MastersForge_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MastersForge_EventScript_TryRemoveRegidrago
	end

MastersForge_EventScript_TryRemoveRegidrago::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MastersForge_OnTransition:
	setflag FLAG_LANDMARK_MASTERS_FORGE
	call_if_unset FLAG_DEFEATED_REGIDRAGO, MastersForge_EventScript_ShowRegidrago
	end

MastersForge_EventScript_ShowRegidrago::
	clearflag FLAG_HIDE_REGIDRAGO
	return

MastersForge_EventScript_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MastersForge_EventScript_DefeatedRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MastersForge_EventScript_RanFromRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MastersForge_EventScript_RanFromRegidrago
	setflag FLAG_DEFEATED_REGIDRAGO
	release
	end

MastersForge_EventScript_DefeatedRegidrago::
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

MastersForge_EventScript_RanFromRegidrago::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end
