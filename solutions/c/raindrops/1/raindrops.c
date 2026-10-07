#include "raindrops.h"
#include <string.h>
#include <stdio.h>

void convert(char result[], int drops){
    snprintf(result, 16, "%d", drops);
    if (drops % 3 == 0){
        strncpy(result, "Pling", 6);
        result += 5;
    }
    if (drops % 5 == 0){
        strncpy(result, "Plang", 6);
        result += 5;
    }
    if (drops % 7 == 0){
        strncpy(result, "Plong", 6);
        result += 5;
    }
}
