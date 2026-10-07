#include "resistor_color_trio.h"
#include <stdint.h>
#include <math.h>

resistor_value_t color_code(resistor_band_t* colors){
    int multiplier = colors[2];
    if (colors[1] == BLACK) // extra zero
        multiplier++;

    resistor_unit_t unit = multiplier/3; // truncates aka floor when 3 instead of 3.0
    int keep_multiplier = multiplier % 3;
    uint16_t value = (colors[0]*10 + colors[1]) * pow(10.0, keep_multiplier);
    if (colors[1] == BLACK)
        value /= 10; // remove extra zero from value

    return (resistor_value_t){ value, unit };
}

