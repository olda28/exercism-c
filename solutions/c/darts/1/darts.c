#include "darts.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t score(coordinate_t coord){
    float distance = sqrt(pow(coord.x, 2) + pow(coord.y, 2));
    if (distance > 10) {
        return 0;
    }
    if (distance > 5){
        return 1;
    }
    if (distance > 1){
        return 5;
    } else {
        return 10;
    }
}