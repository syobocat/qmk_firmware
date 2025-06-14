/* Copyright 2023 Andrew Hess <handrew@duck.com>, SyoBoN <syobon@syobon.net> */

#include QMK_KEYBOARD_H

// Layer IDs.
#define LAYER_SWITCH        0
#define LAYER_STENO         1
#define LAYER_RHYTHM        2

// Layer aliases.
#define SWC LAYER_SWITCH
#define STN LAYER_STENO
#define RTM LAYER_RHYTHM

const uint16_t PROGMEM steno_combo[] = {STN_NUM, STN_ST4, STN_A, STN_U, COMBO_END};
const uint16_t PROGMEM rhythm_combo[] = {KC_G, KC_H, KC_C, KC_M, COMBO_END};
combo_t key_combos[] = {
    COMBO(steno_combo, TO(SWC)),
    COMBO(rhythm_combo, TO(SWC)),
};

// Create the actual layers.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_SWITCH] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, TO(STN), TO(RTM), XXXXXXX
    ),
    [LAYER_STENO] = LAYOUT(
        STN_RES1, STN_S1,  STN_TL,  STN_PL,  STN_HL,                    STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        STN_RES2, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_NUM, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                             STN_A,   STN_O,   STN_E,   STN_U
    ),
    [LAYER_RHYTHM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_UP,                     KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_ENT,
                                            KC_C,    KC_V,    KC_N,    KC_M
    ),

    // A blank layer commented out, just to make adding new layers a little easier.
    // [] = LAYOUT(
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    // ),
};
