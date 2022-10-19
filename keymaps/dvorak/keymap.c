#include "splity.h"
#include "sendstring_dvorak.h"

enum layer_names {
	_DVORAK,
	_GAMING,
	_NUMPAD,
	_CODING,
	_FROW
};

enum combos {
	AE,
	UE,
	OE
};

enum unicode_name {
	UC_AE,
	UC_UE,
	UC_OE,
	UC_AEP,
	UC_UEP,
	UC_OEP

};

const uint32_t PROGMEM unicode_map[] = {
	[UC_AE] = 0x00E4,
	[UC_UE] = 0x00FC,
	[UC_OE] = 0x00F6,
	[UC_AEP] = 0x00C4,
	[UC_UEP] = 0x00DC,
	[UC_OEP] = 0x00D6
	
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT(
	DV_QUOT,	DV_COMM, 	DV_DOT, 	DV_P, 		DV_Y, 		DV_F, 		DV_G, 		DV_C, 		DV_R, 		DV_L,
	DV_A,		DV_O,		DV_E, 		DV_U, 		DV_I, 		DV_D, 		DV_H, 		DV_T, 		DV_N, 		DV_S,
	DV_SCLN, 	DV_Q, 		DV_J, 		DV_K, 		DV_X, 		DV_B, 		DV_M, 		DV_W, 		DV_V, 		DV_Z,
			KC_LSFT, 	KC_BSPC, 	MO(_CODING),	KC_ENT,     	LCTL_T(KC_TAB),	MO(_NUMPAD),	KC_SPC,		TO(_GAMING)
),

    [_GAMING] = LAYOUT(
	KC_TAB, 	DV_Q, 		DV_W, 		DV_E, 		DV_R, 		KC_TRNS, 	KC_BTN1,	KC_MS_U, 	KC_BTN2,	KC_BTN3,
	KC_LSFT, 	DV_A, 		DV_S, 		DV_D, 		DV_F, 		KC_TRNS, 	KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_TRNS,
	KC_LCTL, 	DV_Z, 		DV_X, 		DV_C, 		DV_V, 		KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,
			DV_1, 		KC_SPC,     	DV_2, 		DV_3, 		KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	TO(_DVORAK)
),

    [_NUMPAD] = LAYOUT(
	KC_NLCK, 	KC_P7, 		KC_P8, 		KC_P9, 		KC_EXLM, 	KC_MPLY,	KC_MPRV, 	KC_UP, 		KC_MNXT,	KC_TRNS,
	KC_P0, 		KC_P4, 		KC_P5, 		KC_P6, 		KC_CIRC, 	KC_TRNS, 	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_LSFT,
	KC_LALT, 	KC_P1, 		KC_P2, 		KC_P3, 		KC_PERC, 	KC_PSTE, 	KC_COPY, 	MO(_FROW), 	KC_UNDO, 	KC_LCTL,
			KC_PPLS,	KC_PMNS,	KC_PAST,	KC_PSLS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS
),

    [_CODING] = LAYOUT(
	KC_TRNS, 	KC_TRNS, 	DV_GRV,		DV_AT, 		KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	LALT(KC_UP), 	LALT(KC_DOWN), 	KC_TRNS,
	DV_QUES, 	DV_HASH, 	DV_LPRN, 	DV_RPRN, 	KC_TRNS, 	KC_TRNS, 	DV_UNDS, 	DV_EQL, 	DV_BSLS,	KC_F5,
	KC_LSFT,	DV_DLR, 	DV_LBRC, 	DV_RBRC, 	KC_TRNS, 	KC_TRNS, 	KC_TAB, 	KC_LALT, 	DV_AMPR, 	KC_TRNS,
			KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	LALT(KC_F4),	KC_LGUI, 	KC_DEL, 	KC_ESC
),


    [_FROW] = LAYOUT(
    	KC_F1, 	   	KC_F2, 		KC_F3, 		KC_F4, 		KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,
	KC_F5,  	KC_F6, 		KC_F7, 		KC_F8, 		KC_TRNS,   	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,
	KC_F9, 	   	KC_F10, 	KC_F11, 	KC_F12, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,
		        KC_TRNS,	KC_TRNS,      	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS
)

};

const uint16_t PROGMEM ae_combo[] = {DV_A, DV_E, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {DV_U, DV_E, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {DV_O, DV_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [AE] = COMBO(ae_combo, XP(0,3)),
    [UE] = COMBO(ue_combo, XP(1,4)),
    [OE] = COMBO(oe_combo, XP(2,5))
};

