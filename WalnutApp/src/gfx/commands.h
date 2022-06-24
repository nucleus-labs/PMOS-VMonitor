#pragma once

#define ENABLE_TUI_MODE                 0b00010001_00000001 // 0 more bytes
#define DISABLE_TUI_MODE                0b00010001_00000010 // 0 more bytes

#define TUI_SET_CURSOR_POS              0b00010011_00000011 // * more bytes    : 2 or 4 ; XY
#define TUI_GET_CURSOR_POS              0b00010001_00000100 // 0 more bytes

#define TUI_SET_TEXT_COL_RGB_24         0b00010100_00000101 // 3 more bytes    : RGB
#define TUI_SET_BACKGROUND_COL_RGB_24   0b00010100_00000110 // 3 more bytes    : RGB

#define TUI_WRITE_ASCII                 0b00010010_00000111 // 1 more bytes    : <str_len>
#define TUI_READ_LINE_ASCII             0b00010001_00001000 // 0 more bytes    ; use cursor y position

#define TUI_SET_CURSOR_BLINK_ON         0b00010001_00001001 // 0 more bytes
#define TUI_SET_CURSOR_BLINK_OFF        0b00010001_00001010 // 0 more bytes

#define TUI_GET_SIZE                    0b00010001_00001011 // 0 more bytes    ; returns 2x bytes?

#define TUI_CLEAR                       0b00010001_00001100 // 0 more bytes
#define TUI_CLEAR_LINE                  0b00010001_00001101 // 0 more bytes    ; use cursor y position

#define TUI_GET_TEXT_COL_RGB_24         0b00010001_00001110 // 0 more bytes    ; returns 3 bytes
#define TUI_GET_BACKGROUND_COL_RGB_24   0b00010001_00001111 // 0 more bytes    ; returns 3 bytes


#define GUI_