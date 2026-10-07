#include "resistor_color_trio.h"
#include <math.h>
#include <stdint.h>

resistor_value_t color_code(resistor_band_t* colors){
    int zeros = colors[2];
    if (colors[1] == BLACK) // extra zero
        zeros++;

    resistor_unit_t unit = (resistor_unit_t)floor(zeros/3.0);
    int keep_zeros = zeros % 3;
    uint16_t value = (colors[0]*10 + colors[1]) * pow(10.0, keep_zeros);
    if (colors[1] == BLACK)
        value /= 10;

    resistor_value_t val = {
         value,
         unit
    };
    return val;
}

