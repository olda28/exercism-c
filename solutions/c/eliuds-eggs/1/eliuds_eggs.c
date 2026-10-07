#include "eliuds_eggs.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int egg_count(unsigned int display){
    int count = 0;
    unsigned int digit;
    
    int shiftby = 0;
    do {
       digit = display >> shiftby++; 
       count += digit & 1;
    } while (digit != 0);
    return count;
}

