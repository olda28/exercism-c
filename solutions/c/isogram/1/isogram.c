#include "isogram.h"
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

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


bool is_isogram(const char phrase[]){
    if (phrase == NULL)
        return false;
    
    int flag = 0;

    while (*phrase != '\0'){
        char letter = lowercase(*phrase++);
        if (!is_az(letter))
            continue;

        int flagbit = 1 << az_pos(letter);
        if (flagbit & flag) // already exists
            return false;
        else
            flag |= flagbit;
    }
    return true;
    
}

