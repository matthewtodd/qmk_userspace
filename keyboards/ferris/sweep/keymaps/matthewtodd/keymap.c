#include QMK_KEYBOARD_H

#if __has_include("keymap.h")
#    include "keymap.h"
#endif

const uint16_t PROGMEM media_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM esc_combo[]   = {LGUI_T(KC_S), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM copy_combo[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_D, COMBO_END};

const uint16_t PROGMEM bspc_combo[]  = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM del_combo[]   = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM lprn_combo[]  = {RSFT_T(KC_N), RGUI_T(KC_E), COMBO_END};
const uint16_t PROGMEM rprn_combo[]  = {RGUI_T(KC_E), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM smash_combo[] = {RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O), COMBO_END};
const uint16_t PROGMEM lbrc_combo[]  = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM rbrc_combo[]  = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(media_combo, MO(2)),
    COMBO(esc_combo, LSG_T(KC_ESC)),
    COMBO(copy_combo, LGUI(KC_C)),
    COMBO(paste_combo, LGUI(KC_V)),
    COMBO(bspc_combo, KC_BSPC),
    COMBO(del_combo, KC_DEL),
    COMBO(lprn_combo, MT(MOD_RSFT | MOD_RGUI, KC_LPRN)),
    COMBO(rprn_combo, MT(MOD_RGUI | MOD_RALT, KC_RPRN)),
    COMBO(smash_combo, RGUI(RALT(KC_RCTL))),
    COMBO(lbrc_combo, KC_LBRC),
    COMBO(rbrc_combo, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
        LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O),
        KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
        LT(1, KC_SPC), KC_TAB, LT(4, KC_ENT), LT(3, KC_BSPC)),
    [1] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
    [2] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY),
    [3] = LAYOUT_split_3x5_2(
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,
        KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_0, KC_MINS, XXXXXXX, XXXXXXX),
    [4] = LAYOUT_split_3x5_2(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX)};

// https://docs.qmk.fm/tap_hold#chordal-hold-handedness
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x5_2(
    'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'R', 'R');
