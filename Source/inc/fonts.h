//
// Created by lsc on 23-5-20.
//

#ifndef AIR32_LED_FONTS_H
#define AIR32_LED_FONTS_H
/* vim: set ai et ts=4 sw=4: */

#include <stdint.h>

typedef struct {
    const uint8_t width;
    uint8_t height;
    const uint16_t *data;
} FontDef;


extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;

#endif //AIR32_LED_FONTS_H
