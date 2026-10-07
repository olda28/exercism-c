#include "resistor_color.h"
#include <stdint.h>

uint16_t color_code(resistor_band_t code){
    return code;
}

const resistor_band_t* colors(){
    static resistor_band_t values[10];

    for (int i = 0; i < 10; i++){
        values[i] = i;
    }

    return values;
}
