#include QMK_KEYBOARD_H
#include "features/achordion.h"

/**
 * Layer
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_layers.md
 */
enum layers
{
    DEFT, // Default
    NAVI, // Navigation & Mouse key
    NUMB, // Number
    FUNC, // Function
};

/**
 * Macros
 * https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
 */
enum keycodes
{
    PPY_SCR, // Ploopy nano scroll wheel
    PPY_DPI, // Ploopy nano change DPI
    PPY_RST, // Ploopy nano RESET
    SL_LINE, // Select Line
};

/**
 * Alias
 */
#define LTHUM_1 CTL_T(KC_ENT)      // Left Thumb 1
#define LTHUM_2 LT(NAVI, KC_SPC)   // Left Thumb 2
#define LTHUM_3 KC_TAB             // Left Thumb 3
#define RTHUM_3 LT(FUNC, KC_LN G1) // Right Thumb 3
#define RTHUM_2 LSFT_T(KC_BSPC)    // Right Thumb 2
#define RTHUM_1 LT(NUMB, KC_DEL)   // Right Thumb 1
#define LHOME_1 LGUI_T(KC_A)       // Left Home Row 1
#define LHOME_2 LALT_T(KC_S)       // Left Home Row 2
#define LHOME_3 LCTL_T(KC_D)       // Left Home Row 3
#define LHOME_4 LSFT_T(KC_F)       // Left Home Row 4
#define RHOME_4 LSFT_T(KC_J)       // Right Home Row 4
#define RHOME_3 LCTL_T(KC_K)       // Right Home Row 3
#define RHOME_2 LALT_T(KC_L)       // Right Home Row 2
#define RHOME_1 LGUI_T(KC_QUOT)    // Right Home Row 1
#define WN_PREV C(G(KC_LEFT))      // Window Space Prev
#define WN_NEXT C(G(KC_RGHT))      // Window Space Next
#define WN_SHOW G(KC_TAB)          // Window Space Next
#define WD_PREV C(KC_LEFT)         // Word Prev
#define WD_NEXT C(KC_RGHT)         // Word Next
#define TB_NEXT A(KC_TAB)          // Next Tab

/**
 * Key Overrides
 * https://docs.qmk.fm/#/feature_key_overrides
 */
const key_override_t comm_scln_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN); // ,;
const key_override_t dot_coln_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);   // .:
const key_override_t ques_exlm_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM); // ?!
const key_override_t mins_slsh_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_SLSH); // -/
const key_override_t plus_astr_override = ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_ASTR); // +*
const key_override_t eql_unds_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_UNDS);   // =_
const key_override_t bsls_hash_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, KC_HASH); // \#
const key_override_t at_perc_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_PERC);     // @%
const key_override_t grv_circ_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_CIRC);   // `^
const key_override_t lprn_labk_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LABK); // (<
const key_override_t rprn_rabk_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RABK); // )>
const key_override_t pipe_ampr_override = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_AMPR); // |&
const key_override_t lbrc_lcbr_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_LCBR); // [{
const key_override_t rbrc_rcbr_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_RCBR); // ]}
const key_override_t tild_dlr_override = ko_make_basic(MOD_MASK_SHIFT, KC_TILD, KC_DLR);   // ~$

const key_override_t **key_overrides = (const key_override_t *[]){
    &comm_scln_override,
    &dot_coln_override,
    &ques_exlm_override,
    &mins_slsh_override,
    &plus_astr_override,
    &eql_unds_override,
    &bsls_hash_override,
    &at_perc_override,
    &grv_circ_override,
    &lprn_labk_override,
    &rprn_rabk_override,
    &pipe_ampr_override,
    &lbrc_lcbr_override,
    &rbrc_rcbr_override,
    &tild_dlr_override,
    NULL};

/**
 * Combo keys
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
 */
const uint16_t PROGMEM mins_slsh_combo[] = {KC_W, KC_E, COMBO_END};      // w + e = -/
const uint16_t PROGMEM plus_astr_combo[] = {KC_E, KC_R, COMBO_END};      // e + r = +*
const uint16_t PROGMEM eql_unds_combo[] = {KC_W, KC_R, COMBO_END};       // w + r = =_
const uint16_t PROGMEM tab_combo[] = {LHOME_2, LHOME_3, COMBO_END};      // s + d = TAB
const uint16_t PROGMEM bspc_combo[] = {LHOME_3, LHOME_4, COMBO_END};     // d + f = BACKSPACE
const uint16_t PROGMEM esc_combo[] = {LHOME_2, LHOME_4, COMBO_END};      // s + f = ESC
const uint16_t PROGMEM bsls_hash_combo[] = {KC_X, KC_C, COMBO_END};      // x + c = \#
const uint16_t PROGMEM at_perc_combo[] = {KC_C, KC_V, COMBO_END};        // c + v = @%
const uint16_t PROGMEM grv_circ_combo[] = {KC_X, KC_V, COMBO_END};       // x + v = `^
const uint16_t PROGMEM lprn_labk_combo[] = {KC_U, KC_I, COMBO_END};      // u + i = (<
const uint16_t PROGMEM rprn_rabk_combo[] = {KC_I, KC_O, COMBO_END};      // i + o = )>
const uint16_t PROGMEM pipe_ampr_combo[] = {KC_U, KC_O, COMBO_END};      // u + o = |&
const uint16_t PROGMEM lang_combo[] = {RHOME_4, RHOME_3, COMBO_END};     // j + k = 한/영
const uint16_t PROGMEM caps_combo[] = {RHOME_3, RHOME_2, COMBO_END};     // k + l = CAPSLOCK
const uint16_t PROGMEM ppydpi_combo[] = {RHOME_4, RHOME_2, COMBO_END};   // j + l = Ploopy DPI
const uint16_t PROGMEM lbrc_lcbr_combo[] = {KC_M, KC_COMM, COMBO_END};   // m + , = [{
const uint16_t PROGMEM rbrc_rcbr_combo[] = {KC_COMM, KC_DOT, COMBO_END}; // , + . = ]}
const uint16_t PROGMEM tild_dlr_combo[] = {KC_M, KC_DOT, COMBO_END};     // m + . = ~$

combo_t key_combos[] = {
    COMBO(mins_slsh_combo, KC_MINS),
    COMBO(plus_astr_combo, KC_PLUS),
    COMBO(eql_unds_combo, KC_EQL),
    COMBO(tab_combo, KC_TAB),
    COMBO(bspc_combo, KC_BSPC),
    COMBO(esc_combo, KC_ESC),
    COMBO(bsls_hash_combo, KC_BSLS),
    COMBO(at_perc_combo, KC_AT),
    COMBO(grv_circ_combo, KC_GRV),
    COMBO(lprn_labk_combo, KC_LPRN),
    COMBO(rprn_rabk_combo, KC_RPRN),
    COMBO(pipe_ampr_combo, KC_PIPE),
    COMBO(lang_combo, KC_LNG1),
    COMBO(caps_combo, KC_CAPS),
    COMBO(ppydpi_combo, PPY_DPI),
    COMBO(lbrc_lcbr_combo, KC_LBRC),
    COMBO(rbrc_rcbr_combo, KC_RBRC),
    COMBO(tild_dlr_combo, KC_TILD),
};

/**
 * Keymaps
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [DEFT] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LHOME_1, LHOME_2, LHOME_3, LHOME_4, KC_G,    KC_H,    RHOME_4, RHOME_3, RHOME_2, RHOME_1,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES,
                          LTHUM_1, LTHUM_2, LTHUM_3, RTHUM_3, RTHUM_2, RTHUM_1
    ),

    [NAVI] = LAYOUT_split_3x5_3(
        KC_BTN4, WN_PREV, WN_SHOW, WN_NEXT, KC_BTN5, KC_PGUP, WD_PREV, KC_UP,   WD_NEXT, KC_PGDN,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, TB_NEXT, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
        PPY_SCR, KC_BTN3, KC_BTN2, KC_BTN1, PPY_DPI, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______,
                          _______, _______, QK_BOOT, _______, _______, _______
    ),

    [NUMB] = LAYOUT_split_3x5_3(
        _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______,
        _______, KC_4,    KC_5,    KC_6,    _______, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_0,    KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, QK_BOOT, _______, _______
    ),

    [FUNC] = LAYOUT_split_3x5_3(
        KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______, _______, _______, _______, _______,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______
    ),
    // clang-format on
};

/**
 * PERMISSIVE_HOLD_PER_KEY
 * https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#hold-on-other-key-press
 */
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case LHOME_1:
    case LHOME_2:
    case LHOME_3:
    case LHOME_4:
    case RHOME_1:
    case RHOME_2:
    case RHOME_3:
    case RHOME_4:
    case LTHUM_2:
        return true;
    default:
        return false;
    }
}

/**
 * HOLD_ON_OTHER_KEY_PRESS_PER_KEY
 * https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#hold-on-other-key-press
 */
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case LTHUM_1:
    case LTHUM_3:
    case RTHUM_1:
    case RTHUM_2:
    case RTHUM_3:
        return true;
    default:
        return false;
    }
}

/**
 * Custom Quantum Functions
 * https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    /**
     * Achordion
     * https://getreuer.info/posts/keyboards/achordion/index.html
     */
    if (!process_achordion(keycode, record))
    {
        return false;
    }

    /**
     * Macros
     * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md
     */
    switch (keycode)
    {
    case PPY_SCR:
        if (record->event.pressed)
        {
            SEND_STRING(SS_TAP(X_NUM) SS_TAP(X_NUM));
        }
        break;
    case PPY_DPI:
        if (record->event.pressed)
        {
            SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_SCRL));
        }
        break;
    case PPY_RST:
        if (record->event.pressed)
        {
            SEND_STRING(SS_TAP(X_NUM) SS_TAP(X_NUM) SS_TAP(X_SCRL) SS_TAP(X_SCRL));
        }
        break;
    case SL_LINE:
        if (record->event.pressed)
        {
            SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT));
        }
        break;
    }

    return true;
}

/**
 * Achordion
 * https://getreuer.info/posts/keyboards/achordion/index.html
 */
void matrix_scan_user(void)
{
    achordion_task();
}

/**
 * Achordion
 * https://getreuer.info/posts/keyboards/achordion/index.html
 */
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record)
{
    // Thumb keys exception
    switch (tap_hold_keycode)
    {
    case LTHUM_1:
    case LTHUM_2:
    case LTHUM_3:
    case RTHUM_1:
    case RTHUM_2:
    case RTHUM_3:
        return true;
    }

    switch (other_keycode)
    {
    case LTHUM_1:
    case LTHUM_2:
    case LTHUM_3:
    case RTHUM_1:
    case RTHUM_2:
    case RTHUM_3:
        return true;
    }

    // Combo keys mapping
    switch (tap_hold_keycode)
    {
    case LHOME_1:
    case LHOME_2:
    case LHOME_3:
    case LHOME_4:
        switch (other_keycode)
        {
        case KC_LPRN:
        case KC_RPRN:
        case KC_PIPE:
        case KC_LNG1:
        case KC_CAPS:
        case KC_MUTE:
        case KC_LBRC:
        case KC_RBRC:
        case KC_TILD:
            return true;
        }
    case RHOME_1:
    case RHOME_2:
    case RHOME_3:
    case RHOME_4:
        switch (other_keycode)
        {
        case KC_MINS:
        case KC_PLUS:
        case KC_EQL:
        case KC_TAB:
        case KC_BSPC:
        case KC_ESC:
        case KC_BSLS:
        case KC_AT:
        case KC_GRV:
            return true;
        }
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

/**
 * Tap-only combos are useful if any (or all) of the underlying keys are mod-tap or layer-tap keys.
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md#per-combo-timing-holding-tapping-and-key-press-order
 */
bool get_combo_must_tap(uint16_t index, combo_t *combo)
{
    return true;
}
