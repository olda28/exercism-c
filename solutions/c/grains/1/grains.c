#include "grains.h"
#include <math.h>

uint64_t square(uint8_t index){
    return pow(2, index-1);
}
uint64_t total(void){
    int rice = 0;
    int i;
    for (i = 1; i <= 64; i++){
        rice += square(i);
    }
    return rice;
}