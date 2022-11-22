#include "splity.h"
#include "sendstring_dvorak.h"

enum layer_names {
	_DVORAK,
	_NUMPAD,
	_CODING
};

enum my_keycodes {
	sendit
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT(
	DV_QUOT,	LALT_T(DV_COMM),LCTL_T(DV_DOT),	DV_P, 		DV_Y, 		DV_F, 		DV_G, 		DV_C, 		DV_R, 		DV_L,
	DV_A,		DV_O,		DV_E, 		DV_U, 		DV_I, 		DV_D, 		DV_H,		DV_T, 		DV_N, 		DV_S,
	LSFT_T(DV_SCLN),DV_Q, 		DV_J, 		DV_K, 		DV_X, 		DV_B, 		DV_M, 		DV_W, 		DV_V, 		LSFT_T(DV_Z),
			KC_LGUI, 	KC_BSPC, 	MO(_CODING),	KC_ENT,     	KC_TAB,		MO(_NUMPAD),	KC_SPC,		KC_ESC
),


    [_NUMPAD] = LAYOUT(
	KC_PSLS, 	KC_7, 		KC_8, 		KC_9, 		KC_PAST, 	KC_MPLY,	KC_MPRV, 	KC_UP, 		KC_MNXT,	KC_TRNS,
	KC_LSFT, 	KC_4, 		KC_5, 		KC_6, 		KC_PPLS, 	KC_DEL, 	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_LCTL,
	KC_0, 		KC_1, 		KC_2, 		KC_3, 		KC_PMNS, 	KC_TRNS, 	KC_EXLM, 	KC_CIRC, 	KC_PERC, 	KC_TRNS,
			KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS
),

    [_CODING] = LAYOUT(
	KC_TRNS, 	DV_BSLS, 	KC_F5,		KC_GRAVE, 	DV_AT,	 	KC_TRNS, 	KC_F1, 	   	KC_F2, 		KC_F3, 		KC_F4, 
	DV_QUES, 	DV_HASH, 	DV_LPRN, 	DV_RPRN, 	DV_UNDS, 	KC_TRNS, 	KC_F5,  	KC_F6, 		KC_F7, 		KC_F8, 
	KC_LSFT,	DV_DLR, 	DV_LBRC, 	DV_RBRC, 	KC_PEQL, 	KC_TRNS, 	KC_F9, 	   	KC_F10, 	KC_F11, 	KC_F12,
			KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS,	KC_TRNS, 	KC_TRNS, 	sendit
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case sendit:
            if (record->event.pressed) {
                SEND_STRING("SIGMA 		Alphabet	Terminale\nSIGMA star 	alle moeglichen woerter\nSIGMA plus	SIGMA star ohne null\nambda		null\nL		teilmenge aller woerter\nL		formelle sprache\nP		Produktionsregeln -> Wort\nV		Nichtterminale	syntaktische Variable\n\nS -> KN\nK -> BBB\nB -> buchstabeen\nN -> ZN\nN -> Z\nZ -> ziffer\n\nV ist S K B N Z\n");
            }
            return false;
    }

    return true;
};
