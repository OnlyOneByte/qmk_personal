#include QMK_KEYBOARD_H

// --- Bongo Cat Animation ---
#define BONGO_WIDTH 64
#define BONGO_HEIGHT 64
#define BONGO_BYTES (BONGO_WIDTH * BONGO_HEIGHT / 8) // Should be 512

// --- Define Number of Frames ---
#define NUM_IDLE_FRAMES 3
#define NUM_TAP_FRAMES 2

// References:
// - https://github.com/j-dags/qmk_firmware/blob/master/keyboards/kyria/keymaps/jdags/keymap.c#L196
// - https://github.com/pedker/OLED-BongoCat-Revision/blob/main/bongo.h
// - https://jlamch.net/MXChipWelcome/

// Idle Frames Data (Array of frames)
static const char PROGMEM idle_frames[NUM_IDLE_FRAMES][BONGO_BYTES] = {
    {
        // 'idle3', 64x64px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xf0, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0,
        0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff,
        0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe,
        0xfe, 0xfc, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f,
        0x7f, 0x7f, 0x78, 0xf8, 0xf8, 0xf8, 0xfc, 0xff, 0xe7, 0xe7, 0xe7, 0xe7, 0xc7, 0xcf, 0xcf, 0xcf,
        0xdf, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xc3, 0xc1, 0xc3, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00,
        0xe0, 0xe0, 0xe3, 0xe3, 0xe3, 0xe3, 0xc3, 0xc3, 0x41, 0xc1, 0xc1, 0xc0, 0xc8, 0x8c, 0x8c, 0x8c,
        0x8c, 0x8c, 0x8c, 0x9c, 0x9c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x19, 0x39, 0x31, 0x31, 0x31, 0x31,
        0x31, 0x33, 0x73, 0x73, 0x63, 0x63, 0x03, 0x01, 0x20, 0x78, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f,
        0x3f, 0x1f, 0x1f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x9f, 0x9f, 0x1f, 0x1f, 0x1e, 0x10, 0x00,
        0x66, 0x22, 0x88, 0xcc, 0xcd, 0xcd, 0xdd, 0xdc, 0xdc, 0xd9, 0x99, 0x0b, 0x03, 0x93, 0xbb, 0xbb,
        0xbb, 0x93, 0x03, 0x27, 0x37, 0x77, 0x77, 0x77, 0x67, 0x27, 0x0f, 0x4f, 0x6e, 0xee, 0x6e, 0x6e,
        0x8e, 0xce, 0xde, 0xde, 0xcc, 0xc4, 0xdc, 0x9c, 0x9c, 0xbc, 0xbc, 0x38, 0x38, 0xb8, 0x38, 0x18,
        0x08, 0x78, 0x79, 0x71, 0x31, 0x91, 0xf1, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x06, 0x06, 0x0e, 0x0e, 0x0e, 0x0c, 0x0c, 0x8d, 0x8d, 0x9d, 0xdc, 0xfc, 0xfd, 0x79, 0x39, 0x3b,
        0x39, 0x38, 0x3a, 0x3b, 0x33, 0x33, 0x37, 0x37, 0x73, 0x71, 0x74, 0x76, 0x66, 0x66, 0x66, 0xe2,
        0xe8, 0xec, 0xec, 0xcc, 0xcd, 0xdd, 0xdd, 0xdd, 0xdd, 0x99, 0x80, 0x90, 0x99, 0xbb, 0x9b, 0xcb,
        0xe3, 0xf1, 0x3c, 0x1e, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x03, 0x03, 0x03, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    {
        // 'idle2', 64x64px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
        0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xf8, 0xf8,
        0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff,
        0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f,
        0x7f, 0x7f, 0x7c, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xf1, 0xf3, 0xf3, 0xf3, 0xe3, 0xe7, 0xe7, 0xe7,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xe0, 0xe0, 0xe1, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00,
        0xe0, 0xe0, 0xe3, 0xe3, 0xe3, 0xe3, 0xc3, 0xc3, 0x43, 0xc1, 0xc1, 0xc0, 0xc8, 0xcc, 0x8c, 0x8c,
        0x8c, 0x8c, 0x8c, 0x9c, 0x9c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x19, 0x39, 0x31, 0x31, 0x31, 0x31,
        0x31, 0x33, 0x73, 0x73, 0x63, 0x63, 0x03, 0x03, 0x20, 0x78, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f,
        0x3f, 0x1f, 0x1f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x9f, 0x9f, 0x1f, 0x1f, 0x1e, 0x10, 0x00,
        0x66, 0x22, 0x88, 0xcc, 0xcd, 0xcd, 0xdd, 0xdc, 0xdc, 0xd9, 0x99, 0x4b, 0x03, 0x93, 0xbb, 0xbb,
        0xbb, 0x93, 0x03, 0x27, 0x37, 0x77, 0x77, 0x77, 0x67, 0x27, 0x0f, 0x4f, 0x6f, 0xee, 0x6e, 0x6e,
        0x8e, 0xce, 0xce, 0xde, 0xcc, 0xc4, 0xd4, 0x9c, 0x9c, 0x9c, 0xbc, 0x3c, 0x38, 0xb8, 0x38, 0x18,
        0x08, 0x78, 0x79, 0x71, 0x31, 0x91, 0xf1, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x06, 0x06, 0x0e, 0x0e, 0x0e, 0x0c, 0x0c, 0x8c, 0x8d, 0x9d, 0xdc, 0xfc, 0xfd, 0x79, 0x39, 0x1b,
        0x19, 0x38, 0x3a, 0x3b, 0x33, 0x33, 0x33, 0x37, 0x73, 0x71, 0x74, 0x76, 0x66, 0x66, 0x66, 0xe2,
        0xe8, 0xec, 0xec, 0xcc, 0xcd, 0xdd, 0xdd, 0xdd, 0xdd, 0x99, 0xc0, 0x90, 0x99, 0xbb, 0x9b, 0xcb,
        0xe3, 0xf3, 0x7c, 0x1e, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x03, 0x03, 0x03, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    {
        // 'idle1', 64x64px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
        0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf8, 0xf8,
        0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff,
        0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f,
        0x7f, 0x7f, 0x7c, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xf1, 0xf7, 0xf7, 0xf3, 0xe3, 0xe7, 0xcf, 0xcf,
        0xef, 0xe7, 0xff, 0xff, 0xff, 0xe1, 0xe0, 0xe0, 0xe1, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00,
        0xe0, 0xe0, 0xe3, 0xe3, 0xe3, 0xe3, 0xc3, 0xc3, 0x43, 0xc1, 0xc1, 0xc0, 0xc8, 0xcc, 0x8c, 0x8c,
        0x8c, 0x8c, 0x8c, 0x9c, 0x9c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x19, 0x39, 0x31, 0x31, 0x31, 0x31,
        0x31, 0x33, 0x73, 0x73, 0x63, 0x63, 0x03, 0x03, 0x20, 0x78, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f,
        0x3f, 0x1f, 0x1f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x9f, 0x9f, 0x1f, 0x1f, 0x1e, 0x10, 0x00,
        0x66, 0x22, 0x88, 0xcc, 0xcd, 0xcd, 0xdd, 0xdc, 0xdc, 0xd9, 0x99, 0x0b, 0x03, 0x93, 0xbb, 0xbb,
        0xbb, 0x93, 0x03, 0x27, 0x37, 0x77, 0x77, 0x77, 0x67, 0x27, 0x0f, 0x4f, 0x6f, 0xee, 0x6e, 0x6e,
        0x8e, 0xce, 0xde, 0xde, 0xcc, 0xc4, 0xd4, 0x9c, 0x9c, 0xbc, 0xbc, 0x3c, 0x38, 0xb8, 0x38, 0x18,
        0x08, 0x78, 0x79, 0x71, 0x31, 0x91, 0xf1, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x06, 0x06, 0x0e, 0x0e, 0x0e, 0x0c, 0x0c, 0x8d, 0x8d, 0x9d, 0xdc, 0xfc, 0xfd, 0x79, 0x39, 0x1b,
        0x19, 0x38, 0x3a, 0x3b, 0x33, 0x33, 0x37, 0x37, 0x73, 0x71, 0x74, 0x76, 0x66, 0x66, 0x66, 0xe2,
        0xe8, 0xec, 0xec, 0xcc, 0xcd, 0xdd, 0xdd, 0xdd, 0xdd, 0x99, 0xc0, 0x90, 0x99, 0xbb, 0x9b, 0xcb,
        0xe3, 0xf3, 0x7c, 0x1e, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }
};

// Tapping Frames Data (Array of frames)
static const char PROGMEM tap_frames[NUM_TAP_FRAMES][BONGO_BYTES] = {
    {
        // 'tap_left', 64x64px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
        0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8,
        0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff,
        0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f,
        0x3e, 0x3e, 0x3e, 0x7e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0xe0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f,
        0x7f, 0x7f, 0x7c, 0x7c, 0xfc, 0xfc, 0xff, 0xff, 0xf1, 0xf3, 0xf3, 0xf3, 0xe3, 0xe7, 0xe7, 0xe7,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xe0, 0xe0, 0xe1, 0xf3, 0xff, 0x03, 0x00, 0x00, 0xfc, 0xff,
        0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xc1, 0x03, 0x0f, 0x3f, 0xfc, 0xf8, 0xe0, 0xc0, 0x00, 0x00, 0x00,
        0xe0, 0xe1, 0xe3, 0xe3, 0xe3, 0xe3, 0xc3, 0xc3, 0x43, 0xc1, 0xc1, 0xc0, 0xc8, 0xcc, 0x8c, 0x8c,
        0x8c, 0x8c, 0x8c, 0x9c, 0x9c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x39, 0x39, 0x31, 0x31, 0x31,
        0x31, 0x31, 0x73, 0x73, 0x63, 0x63, 0x63, 0x63, 0x63, 0xe3, 0xe7, 0xe0, 0xc0, 0xc0, 0xc7, 0xc7,
        0xc7, 0xcf, 0xcf, 0x8f, 0x8f, 0x8f, 0x8f, 0x88, 0x98, 0x9f, 0x9f, 0x1f, 0x1f, 0x1e, 0x10, 0x00,
        0x66, 0x22, 0x88, 0xcc, 0xcd, 0xcd, 0xdd, 0xdc, 0xdc, 0xd9, 0x99, 0x4b, 0x03, 0x93, 0xbb, 0xbb,
        0xbb, 0x93, 0x03, 0x27, 0x37, 0x77, 0x77, 0x77, 0x67, 0x27, 0x0f, 0x4f, 0x6f, 0xee, 0x6e, 0x6e,
        0x8e, 0xce, 0xce, 0xde, 0xcc, 0xc4, 0xd4, 0x9c, 0x9c, 0x9c, 0xbc, 0x3c, 0x38, 0xb8, 0x38, 0x18,
        0x08, 0x79, 0x79, 0x71, 0x31, 0x91, 0xf1, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x06, 0x06, 0x0e, 0x0e, 0x0e, 0x0c, 0x0c, 0x8d, 0x8d, 0x9d, 0xdc, 0xfc, 0xfd, 0x79, 0x39, 0x1b,
        0x19, 0x38, 0x3a, 0x3b, 0x33, 0x33, 0x37, 0x37, 0x73, 0x71, 0x74, 0x76, 0x66, 0x66, 0x66, 0xe2,
        0xe8, 0xec, 0xec, 0xcc, 0xcd, 0xdd, 0xdd, 0xdd, 0xdd, 0x99, 0xc0, 0x90, 0x99, 0xbb, 0x9b, 0xcb,
        0xe3, 0xf3, 0x7c, 0x1e, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x03, 0x03, 0x03, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    {
        // 'tap_right', 64x64px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
        0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xf8, 0xf8,
        0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff,
        0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x83, 0x0f, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
        0x7f, 0x7f, 0x7c, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xf1, 0xf3, 0xf3, 0xf3, 0xe3, 0xe7, 0xe7, 0xe7,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xe0, 0xe0, 0xe1, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00,
        0xe3, 0xe3, 0xe3, 0xe3, 0xe7, 0xe6, 0xc6, 0xc6, 0x46, 0xc6, 0xc6, 0xc6, 0xce, 0xce, 0x8e, 0x8c,
        0x8c, 0x8c, 0x8c, 0x9c, 0x9c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x19, 0x39, 0x31, 0x31, 0x31, 0x31,
        0x31, 0x33, 0x73, 0x73, 0x63, 0x23, 0x03, 0x03, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0x7f, 0x3f, 0x1f, 0x1f, 0x1f, 0x9f, 0x9f, 0x9f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1e, 0x10, 0x00,
        0x66, 0x22, 0x88, 0xcc, 0xcd, 0xcd, 0xdd, 0xdc, 0xdc, 0xd9, 0x99, 0x4b, 0x03, 0x93, 0xbb, 0xbb,
        0xbb, 0x93, 0x03, 0x27, 0x37, 0x77, 0x77, 0x77, 0x67, 0x27, 0x0f, 0x4f, 0x6f, 0xee, 0x6e, 0x6e,
        0x8e, 0xce, 0xce, 0xde, 0xcc, 0xc4, 0xd0, 0x90, 0x91, 0x93, 0xb3, 0x33, 0x33, 0xb1, 0x31, 0x18,
        0x08, 0x78, 0x78, 0x71, 0x31, 0x91, 0xf1, 0x01, 0x03, 0x03, 0x83, 0x03, 0x33, 0x73, 0xe3, 0xe3,
        0x06, 0x06, 0x0e, 0x0e, 0x0e, 0x0c, 0x0c, 0x8d, 0x8d, 0x9d, 0xdc, 0xfc, 0xfd, 0x79, 0x39, 0x1b,
        0x19, 0x38, 0x3a, 0x3b, 0x33, 0x33, 0x37, 0x37, 0x73, 0x71, 0x74, 0x76, 0x66, 0x66, 0x66, 0xe2,
        0xe8, 0xec, 0xec, 0xcc, 0xcd, 0xdd, 0xdd, 0xdd, 0xdd, 0x99, 0xc0, 0x90, 0x99, 0xbb, 0x9b, 0xcb,
        0xe3, 0xf3, 0x7c, 0x1e, 0x0f, 0x07, 0x01, 0x00, 0x60, 0x7c, 0x7f, 0x7f, 0x7e, 0x78, 0x30, 0x20,
        0x03, 0x03, 0x03, 0x03, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    }
};

// --- Animation State ---
static uint32_t bongo_timer = 0;
static uint8_t  current_idle_frame = 0; // Index for idle_frames array
static uint8_t  current_tap_frame = 0;  // Index for tap_frames array
static bool     current_tapping_state = false;
static bool     last_tapping_state = false;

// --- Animation Parameters ---
#define BONGO_TAP_ANIMATION_INTERVAL 100 // ms between tapping frames
#define BONGO_IDLE_ANIMATION_INTERVAL 250 // ms between idle frames
#define BONGO_WPM_THRESHOLD 20       // WPM threshold

// --- Function to Draw Bongo Cat ---
static void render_bongo_cat(void) {
    const char *frame_data; // Pointer to the current frame's data
    uint16_t current_wpm = get_current_wpm();
    current_tapping_state = (current_wpm >= BONGO_WPM_THRESHOLD);

    // Reset timer and set initial frame index when state changes
    if (current_tapping_state != last_tapping_state) {
        bongo_timer = timer_read32();
        if (current_tapping_state) {
            current_tap_frame = 0; // Start at the first tap frame
        } else {
            current_idle_frame = 0; // Start at the first idle frame
        }
        last_tapping_state = current_tapping_state;
    }

    // --- Animation Logic & Frame Selection ---
    if (current_tapping_state) {
        // Tapping State
        if (timer_elapsed32(bongo_timer) > BONGO_TAP_ANIMATION_INTERVAL) {
            bongo_timer = timer_read32();
            // Advance tap frame index, looping using modulo
            current_tap_frame = (current_tap_frame + 1) % NUM_TAP_FRAMES;
        }
        // Select the current tap frame from the array
        frame_data = tap_frames[current_tap_frame];
    } else {
        // Idle State
        if (timer_elapsed32(bongo_timer) > BONGO_IDLE_ANIMATION_INTERVAL) {
            bongo_timer = timer_read32();
            // Advance idle frame index, looping using modulo
            current_idle_frame = (current_idle_frame + 1) % NUM_IDLE_FRAMES;
        }
        // Select the current idle frame from the array
        frame_data = idle_frames[current_idle_frame];
    }

    // --- Draw Frame ---
    oled_set_cursor(0, 8); // Draw on lower half (starts row 8*8=64)
    oled_write_raw_P(frame_data, BONGO_BYTES);
}


static void render_logo(void) {
    static const char PROGMEM sofle_pico_logo[] = {0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0x70, 0xf0, 0xf0, 0xe0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xfc, 0x3c, 0x3c, 0x3c, 0x7c, 0xf8, 0xf8, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7c, 0x78, 0xf8, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0x3c, 0x1c, 0x1e, 0x1e, 0x3c, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0x1c, 0x1c, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfc, 0xce, 0xce, 0xce, 0xdc, 0xfc, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1e, 0x1e, 0x1e, 0x3c, 0x3c, 0x3c, 0x3e, 0x1f, 0x1f, 0x0f, 0x07, 0x01, 0x00, 0x01, 0x07,
                                                   0x0f, 0x1f, 0x1e, 0x3c, 0x3c, 0x3c, 0x1e, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x3c, 0x38, 0x38, 0x3c, 0x1c, 0x1c, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x06, 0x06, 0x06, 0x0e, 0x9e, 0xfc, 0xf8, 0x00, 0x00, 0x8e, 0x8e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0x83, 0x01, 0x01, 0x01, 0x83, 0x83, 0x00, 0x00, 0x7e, 0xff, 0xc7, 0x83, 0x01, 0x01, 0x01,
                                                   0x83, 0xff, 0xff, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc3, 0xe3, 0xe0, 0xe0, 0xe0, 0xf0, 0x70, 0x70, 0x70, 0x70, 0x30, 0x33, 0x73, 0xe0, 0x60, 0xe0, 0xe0, 0xc0, 0xc1, 0x83, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x70, 0x30, 0x70, 0x70, 0x70, 0x70, 0x70, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0xff, 0xf8, 0xd0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x20, 0x20, 0x40, 0xc0, 0x80, 0x00, 0x01, 0x87, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xff, 0xff, 0x03, 0x01, 0x00, 0x80, 0xc0, 0x40, 0x20, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
                                                   0xf0, 0xf8, 0x7f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1c, 0x1c, 0x38, 0x78, 0x60, 0x60, 0x60, 0x60, 0x60, 0x70, 0x38, 0x39, 0xdf, 0xef, 0xf7, 0x7b, 0x39, 0x1c, 0x1c, 0x0e, 0x0e, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0e, 0x0e, 0x1e, 0x1c, 0x3c, 0x79, 0xfb, 0xf7, 0xef, 0x9f, 0x38, 0x30, 0x70, 0x60, 0x60, 0x60, 0x60, 0x70, 0x38, 0x3c, 0x1c, 0x0f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfc, 0x7e, 0x7f, 0xff, 0xff, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0xff, 0x7f, 0x7f, 0x3f, 0x7c, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   0x00, 0x00, 0x7f, 0xff, 0x81, 0x00, 0x00, 0x00, 0x00, 0x01, 0xcf, 0xff, 0xfe, 0x7c, 0x78, 0x78, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x78, 0x78, 0x7c, 0xfe, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0e, 0x1e, 0x3f, 0x7f, 0xf1, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe1, 0xf3, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03,
                                                   0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    oled_write_raw_P(sofle_pico_logo, sizeof(sofle_pico_logo));
}
