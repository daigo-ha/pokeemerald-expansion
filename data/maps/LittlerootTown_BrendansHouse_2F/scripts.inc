# 1 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_MapScripts::
# 3 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
# 4 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
# 5 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.byte 0
# 6 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 7 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnTransition:
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
# 9 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 11 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 12 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 13 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_unset FLAG_STARTER_BAG, MCRoom_EventScript_StarterBag
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
# 17 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 18 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 19 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 20 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 21 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
# 22 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 23 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 24 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	@ Odd that the MaysHouse equivalent was used below instead
# 25 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 26 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVALS_HOUSE_2F_RIVAL, 0, 2
# 27 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVALS_HOUSE_2F_RIVAL, MOVEMENT_TYPE_FACE_UP
# 28 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 29 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 30 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Ret::
# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 32 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 33 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
# 34 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 35 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
# 36 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 37 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 38 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
# 39 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 40 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 41 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 42 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnWarp:
# 43 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
# 44 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.2byte 0
# 45 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 46 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
# 47 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 48 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
# 49 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 50 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 51 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
# 52 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 53 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
# 54 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 55 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 56 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 57 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 58 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan::
# 59 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 60 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	addobject LOCALID_RIVALS_HOUSE_2F_RIVAL
# 61 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
# 62 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 63 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PIN
# 64 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_ExclamationMark
# 65 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 66 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_Delay48
# 67 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 68 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 69 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 70 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
# 71 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
# 72 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
# 73 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
# 74 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 75 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 76 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 77 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 78 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 79 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	fadedefaultbgm
# 80 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 81 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 82 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 83 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
# 84 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
# 85 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 86 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 87 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 88 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 89 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 90 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
# 91 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
# 92 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 93 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 94 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 95 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
# 96 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
# 97 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 98 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 99 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 100 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 101 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 102 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
# 103 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
# 104 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 105 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 106 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 107 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
# 108 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
# 109 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 110 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 111 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 112 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 113 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 114 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
# 115 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
# 116 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 117 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 118 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 119 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
# 120 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
# 121 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 122 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 123 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 124 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 125 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 126 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
# 127 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 128 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 129 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 130 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters:
# 131 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 132 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 133 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 134 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 135 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 136 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
# 137 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 138 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 139 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 140 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 141 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 142 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 143 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 144 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
# 145 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 146 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 147 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 148 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 149 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 150 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 151 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 152 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 153 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 154 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 155 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
# 156 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 157 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 158 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 159 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 160 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 161 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 162 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 163 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 164 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 165 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
# 166 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 167 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 168 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 169 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 170 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 171 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
# 172 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 173 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 174 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 175 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 176 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 177 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 178 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 179 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 180 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
# 181 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 182 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 183 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 184 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 185 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 186 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 187 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 188 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
# 189 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 190 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 191 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 192 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 193 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 194 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 195 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
# 196 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 197 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 198 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 199 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 200 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 201 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 202 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 203 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 204 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 205 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 206 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
# 207 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_8
# 208 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 209 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 210 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 211 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 212 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 213 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 214 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 215 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
# 216 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 217 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 218 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 219 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 220 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 221 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_down
# 222 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 223 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 224 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
# 225 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 226 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 227 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 228 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_up
# 229 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 230 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 231 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 232 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
# 233 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 234 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 235 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_faster_left
# 236 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 237 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 238 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_PC::
# 239 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 240 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 241 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
# 242 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
# 243 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 244 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 245 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
# 246 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 247 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 248 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_ON
# 249 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 250 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special BedroomPC
# 251 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitstate
# 252 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 253 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 254 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 255 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
# 256 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 257 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 258 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 259 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 260 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 261 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 262 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
# 263 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 264 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 265 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 266 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 267 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_Notebook::
# 268 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
# 269 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 270 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 271 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_GameCube::
# 272 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
# 273 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 274 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 275 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ClockIsStopped:
# 276 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The clock is stopped…\p"
# 277 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Better set it and start it!$"
# 278 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 279 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
# 280 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "MOM: {PLAYER}, how do you like your\n"
# 281 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "new room?\p"
# 282 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Good! Everything's put away neatly!\p"
# 283 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "They finished moving everything in\n"
# 284 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "downstairs, too.\p"
# 285 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "POKéMON movers are so convenient!\p"
# 286 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Oh, you should make sure that\n"
# 287 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "everything's all there on your desk.$"
# 288 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 289 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_Notebook:
# 290 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
# 291 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 1\n"
# 292 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Open the MENU with START.\p"
# 293 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "ADVENTURE RULE NO. 2\n"
# 294 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Record your progress with SAVE.\p"
# 295 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The remaining pages are blank…$"
# 296 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 297 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
Common_Text_LookCloserAtMap:
# 298 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
# 299 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "HOENN region map.$"
# 300 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 301 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ItsAGameCube:
# 302 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
# 303 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "A Game Boy Advance is connected to\n"
# 304 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "serve as the Controller.$"

MCRoom_MapScripts::
	.byte 0


MCRoom_EventScript_Starter::
# 309 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_unset FLAG_STARTER_SNIVY, MCRoom_EventScript_Starter_4
MCRoom_EventScript_Starter_3:
# 334 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Starter_Text_2, MSGBOX_DEFAULT
MCRoom_EventScript_Starter_1:
	end

MCRoom_EventScript_Starter_2:
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lock
# 311 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	message MCRoom_EventScript_Starter_Text_0
# 312 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmessage
# 313 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	multichoice 20, 5, MULTI_STARTER_CHOICE, 0
# 314 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 315 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MCRoom_EventScript_Starter_10
# 319 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MCRoom_EventScript_Starter_11
# 323 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq MCRoom_EventScript_Starter_12
# 328 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Starter_Text_1
# 329 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmessage
MCRoom_EventScript_Starter_9:
# 331 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	release
	goto MCRoom_EventScript_Starter_1

MCRoom_EventScript_Starter_4:
# 309 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_unset FLAG_STARTER_TEPIG, MCRoom_EventScript_Starter_6
	goto MCRoom_EventScript_Starter_3

MCRoom_EventScript_Starter_6:
# 309 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_unset FLAG_STARTER_OSHAWOTT, MCRoom_EventScript_Starter_2
	goto MCRoom_EventScript_Starter_3

MCRoom_EventScript_Starter_10:
# 316 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call StarterFade
# 317 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call MCRoom_EventScript_Snivy
	goto MCRoom_EventScript_Starter_9

MCRoom_EventScript_Starter_11:
# 320 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call StarterFade
# 321 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call MCRoom_EventScript_Tepig
	goto MCRoom_EventScript_Starter_9

MCRoom_EventScript_Starter_12:
# 324 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call StarterFade
# 325 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call MCRoom_EventScript_Oshawott
	goto MCRoom_EventScript_Starter_9


StarterFade::
# 340 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 341 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 20
# 342 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


MCRoom_EventScript_Snivy::
# 348 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 349 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_SNIVY, 10, 3
# 350 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Snivy_Text_0, MSGBOX_YESNO
# 351 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MCRoom_EventScript_Snivy_2
# 375 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	hidemonpic
# 376 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_NotChosen
MCRoom_EventScript_Snivy_1:
# 378 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmessage
# 379 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
	end

MCRoom_EventScript_Snivy_2:
# 352 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_SNIVY, 5, ITEM_ORAN_BERRY
# 353 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq MCRoom_EventScript_Snivy_5
# 361 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq MCRoom_EventScript_Snivy_6
# 370 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	hidemonpic
# 371 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Snivy_Text_2
	goto MCRoom_EventScript_Snivy_1

MCRoom_EventScript_Snivy_5:
# 354 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 355 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Snivy_Text_1
# 356 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject 0
# 357 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_STARTER_SNIVY
# 358 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 359 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
	goto MCRoom_EventScript_Snivy_1

MCRoom_EventScript_Snivy_6:
# 362 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 363 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Snivy_Text_1
# 364 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject 0
# 365 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_STARTER_SNIVY
# 366 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 367 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknameBoxMon
	goto MCRoom_EventScript_Snivy_1


MCRoom_EventScript_Tepig::
# 385 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 386 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_TEPIG, 10, 3
# 387 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Snivy_Text_0, MSGBOX_YESNO
# 388 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MCRoom_EventScript_Tepig_2
# 412 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	hidemonpic
# 413 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_NotChosen
MCRoom_EventScript_Tepig_1:
# 415 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmessage
# 416 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
	end

MCRoom_EventScript_Tepig_2:
# 389 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_TEPIG, 5, ITEM_ORAN_BERRY
# 390 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq MCRoom_EventScript_Tepig_5
# 398 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq MCRoom_EventScript_Tepig_6
# 407 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	hidemonpic
# 408 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Snivy_Text_2
	goto MCRoom_EventScript_Tepig_1

MCRoom_EventScript_Tepig_5:
# 391 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 392 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Tepig_Text_0
# 393 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject 1
# 394 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_STARTER_TEPIG
# 395 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 396 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
	goto MCRoom_EventScript_Tepig_1

MCRoom_EventScript_Tepig_6:
# 399 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 400 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Tepig_Text_0
# 401 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject 1
# 402 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_STARTER_TEPIG
# 403 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 404 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknameBoxMon
	goto MCRoom_EventScript_Tepig_1


MCRoom_EventScript_Oshawott::
# 422 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 423 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	showmonpic SPECIES_OSHAWOTT, 10, 3
# 424 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Snivy_Text_0, MSGBOX_YESNO
# 425 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MCRoom_EventScript_Oshawott_2
# 449 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	hidemonpic
# 450 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_NotChosen
MCRoom_EventScript_Oshawott_1:
# 452 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmessage
# 453 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
	end

MCRoom_EventScript_Oshawott_2:
# 426 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	givemon SPECIES_OSHAWOTT, 5, ITEM_ORAN_BERRY
# 427 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq MCRoom_EventScript_Oshawott_5
# 435 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq MCRoom_EventScript_Oshawott_6
# 444 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	hidemonpic
# 445 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Snivy_Text_2
	goto MCRoom_EventScript_Oshawott_1

MCRoom_EventScript_Oshawott_5:
# 428 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 429 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Oshawott_Text_0
# 430 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject 2
# 431 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_STARTER_OSHAWOTT
# 432 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 433 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknamePartyMon
	goto MCRoom_EventScript_Oshawott_1

MCRoom_EventScript_Oshawott_6:
# 436 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 437 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox MCRoom_EventScript_Oshawott_Text_0
# 438 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject 2
# 439 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_STARTER_OSHAWOTT
# 440 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 441 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call NicknameBoxMon
	goto MCRoom_EventScript_Oshawott_1


NicknamePartyMon::
# 459 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 460 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	hidemonpic
# 461 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 462 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 463 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 469 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 470 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	hidemonpic
# 471 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 474 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
	return

NicknameBoxMon_2:
# 472 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


MCRoom_EventScript_StarterBag::
# 482 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_unset FLAG_STARTER_SNIVY, MCRoom_EventScript_StarterBag_3
MCRoom_EventScript_StarterBag_2:
# 486 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_STARTER_BAG
	return

MCRoom_EventScript_StarterBag_1:
# 483 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	clearflag FLAG_STARTER_BAG
	return

MCRoom_EventScript_StarterBag_3:
# 482 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_unset FLAG_STARTER_TEPIG, MCRoom_EventScript_StarterBag_5
	goto MCRoom_EventScript_StarterBag_2

MCRoom_EventScript_StarterBag_5:
# 482 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_unset FLAG_STARTER_OSHAWOTT, MCRoom_EventScript_StarterBag_1
	goto MCRoom_EventScript_StarterBag_2


MCRoom_EventScript_Starter_Text_0:
# 311 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Which starter are you choosing?$"

MCRoom_EventScript_Starter_Text_1:
# 328 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "We are waiting...$"

MCRoom_EventScript_Starter_Text_2:
# 334 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The bag is empty.$"

MCRoom_EventScript_Snivy_Text_0:
# 350 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Are you sure?$"

MCRoom_EventScript_Snivy_Text_1:
# 355 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Snivy$"

MCRoom_EventScript_Snivy_Text_2:
# 371 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "You have no more room for this Pokemon.$"

MCRoom_EventScript_Tepig_Text_0:
# 392 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Tepig$"

MCRoom_EventScript_Oshawott_Text_0:
# 429 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Received Oshawott$"

NicknamePartyMon_Text_0:
# 459 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Do you want to give it a nickname?$"

MCRoom_NotChosen::
# 477 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "You did not choose the Pokemon$"
