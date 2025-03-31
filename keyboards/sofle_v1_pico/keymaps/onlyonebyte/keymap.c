// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later
// Modified by Angelo Yang (@OnlyOneByte)

#include QMK_KEYBOARD_H
#include "oled_assets.c" // includes layers.h

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { KC_QWERTY = SAFE_RANGE, KC_PRVWD, KC_NXTWD, KC_LSTRT, KC_LEND, KC_DLINE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
        /*
        * QWERTY
        * ,-----------------------------------------.                    ,-----------------------------------------.
        * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
        * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
        * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
        * `-----------------------------------------/       /     \      \-----------------------------------------'
        *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
        *            |      |      |      |      |/       /         \      \ |      |      |      |      |
        *            `----------------------------------'           '------''---------------------------'
        */

        [_QWERTY] = LAYOUT(
        KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
        KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
        KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                        KC_LGUI,KC_LALT,KC_LCTL, MO(_LOWER), KC_ENT,      KC_SPC,  MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
        ),
        /* LOWER
        * ,-----------------------------------------.                    ,-----------------------------------------.
        * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
        * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
        * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
        * `-----------------------------------------/       /     \      \-----------------------------------------'
        *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
        *            |      |      |      |      |/       /         \      \ |      |      |      |      |
        *            `----------------------------------'           '------''---------------------------'
        */
        [_LOWER] = LAYOUT(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                            _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
        ),
        /* RAISE
        * ,----------------------------------------.                    ,-----------------------------------------.
        * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
        * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
        * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
        * `-----------------------------------------/       /     \      \-----------------------------------------'
        *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
        *            |      |      |      |      |/       /         \      \ |      |      |      |      |
        *            `----------------------------------'           '------''---------------------------'
        */
        [_RAISE] = LAYOUT(
        _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
        _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_DEL,
        _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
        _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                                _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
        ),
        /* ADJUST
        * ,-----------------------------------------.                    ,-----------------------------------------.
        * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | QK_BOOT|    |QWERTY||      |      |                          |      |      |      |      |      |      |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
        * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
        * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
        * `-----------------------------------------/       /     \      \-----------------------------------------'
        *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
        *            |      |      |      |      |/       /         \      \ |      |      |      |      |
        *            `----------------------------------'           '------''---------------------------'
        */
        [_ADJUST] = LAYOUT(
        XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT  , XXXXXXX,KC_QWERTY, XXXXXXX,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
        XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
        )
    // clang-format on
};

#ifdef OLED_ENABLE

static void render_status(void) {
    /* Print current mode */
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("MODES:"), false);
    oled_write_P(PSTR("\n"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("- MAC"), false);
    } else {
        oled_write_ln_P(PSTR("- WIN"), false);
    }

    // Base Layer
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("- Qwerty"), false);
            break;
        default:
            oled_write_P(PSTR("- Undefined"), false);
    }

    // Which Layer Currently
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("- Base"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("- Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("- Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("- Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("- Undefined"), false);
    }

    // Caps state
    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CAPSLOCK"), led_usb_state.caps_lock);
}

uint16_t startup_timer;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_90;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        /* Renders the current keyboard state (layer, lock, caps, scroll, etc) */
        render_status();
    } else {
        render_logo();
    }
    return false;
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [1] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}, [2] = {ENCODER_CCW_CW(_______, _______)}, [3] = {ENCODER_CCW_CW(_______, _______)}, [4] = {ENCODER_CCW_CW(_______, _______)},
};
#endif
