#include QMK_KEYBOARD_H

#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum layer_names {
    COLEMAK_DH,
    NAV,
    MEDIA,
    NUM,
    SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COLEMAK_DH] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
        LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O),
        KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
        LT(NAV, KC_SPC), KC_TAB, LT(SYM, KC_ENT), LT(NUM, KC_BSPC)),
    [NAV] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
    [MEDIA] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY),
    [NUM] = LAYOUT_split_3x5_2(
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,
        KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_0, KC_MINS, XXXXXXX, XXXXXXX),
    [SYM] = LAYOUT_split_3x5_2(
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

// https://docs.qmk.fm/features/tap_dance#example-5
enum td_keycodes {
    RSFT_RGUI_LPRN,
    RGUI_RALT_RPRN
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_TAP_SHIFTED,
    TD_SINGLE_HOLD,
} td_state_t;

static td_state_t td_state;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            if (get_mods() & MOD_MASK_SHIFT)
                return TD_SINGLE_TAP_SHIFTED;
            else
                return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    } else
        return TD_UNKNOWN;
}

void rsft_rgui_lprn_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LPRN);
            break;
        case TD_SINGLE_TAP_SHIFTED:
            register_code16(KC_LT);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RSFT) | MOD_BIT(KC_RGUI));
            break;
        default:
            break;
    }
}

void rsft_rgui_lprn_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case TD_SINGLE_TAP_SHIFTED:
            unregister_code16(KC_LT);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RSFT) | MOD_BIT(KC_RGUI));
            break;
        default:
            break;
    }
}

void rgui_ralt_rprn_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_RPRN);
            break;
        case TD_SINGLE_TAP_SHIFTED:
            register_code16(KC_GT);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RALT));
            break;
        default:
            break;
    }
}

void rgui_ralt_rprn_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_RPRN);
            break;
        case TD_SINGLE_TAP_SHIFTED:
            unregister_code16(KC_GT);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RGUI) | MOD_BIT(KC_RALT));
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [RSFT_RGUI_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rsft_rgui_lprn_finished, rsft_rgui_lprn_reset),
    [RGUI_RALT_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rgui_ralt_rprn_finished, rgui_ralt_rprn_reset),
};

const uint16_t PROGMEM media_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM esc_combo[]   = {LGUI_T(KC_S), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM copy_combo[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_D, COMBO_END};

const uint16_t PROGMEM bspc_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM del_combo[]  = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM lprn_combo[] = {RSFT_T(KC_N), RGUI_T(KC_E), COMBO_END};
const uint16_t PROGMEM rprn_combo[] = {RGUI_T(KC_E), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM lbrc_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(media_combo, MO(MEDIA)),
    COMBO(esc_combo, LSG_T(KC_ESC)),
    COMBO(copy_combo, LGUI(KC_C)),
    COMBO(paste_combo, LGUI(KC_V)),
    COMBO(bspc_combo, KC_BSPC),
    COMBO(del_combo, KC_DEL),
    COMBO(lprn_combo, TD(RSFT_RGUI_LPRN)),
    COMBO(rprn_combo, TD(RGUI_RALT_RPRN)),
    COMBO(lbrc_combo, KC_LBRC),
    COMBO(rbrc_combo, KC_RBRC),
};
