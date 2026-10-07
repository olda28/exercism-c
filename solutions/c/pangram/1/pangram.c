#include "pangram.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

static char lowercase(char c){
    if (c >= 'A' && c <= 'Z')
        return c+32;
    return c;
}

static bool is_az(char c){
    return (c >= 'a' && c <= 'z');
}

static int az_pos(char c){
    return c - 97;
}

bool is_pangram(const char *sentence){
    if (sentence == NULL)
        return false;

    int full = 67108863; // binary of 26 one's
    int actual = 0;

    while (*sentence != '\0'){
        char letter = lowercase(*sentence++);
        if (!is_az(letter))
            continue;
        actual |= 1 << az_pos(letter); 
    }
    return actual == full; 
}
