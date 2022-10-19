#pragma once
#include "config_common.h"

#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER Lucas_Engel
#define PRODUCT      splity_mate

#define MATRIX_ROWS 8
#define MATRIX_COLS 5
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1 }

#define DIODE_DIRECTION COL2ROW

#define SPLIT_USB_DETECT
#define FORCE_NKRO
#define UNICODE_SELECTED_MODES UC_LNX
#define EE_HANDS
#define COMBO_COUNT 3
