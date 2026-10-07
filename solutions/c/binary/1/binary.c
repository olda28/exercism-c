#include "binary.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

static int digit(char c){
    return c - '0';
}

int convert(const char *input){
    size_t len = 0;
    const char *r = input;
    while (*r != '\0'){
        if (digit(*r++) > 1) return INVALID;
        len++;
    }    
    
    int sum = 0;
    for (int i = len-1; i >= 0; i--){
        sum += digit(*input++) * pow(2, i); 
    }
    return sum;
}
