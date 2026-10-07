#include "rotational_cipher.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_lower(char c){
    return (c >= 'a' && c <= 'z');
}

static bool is_upper(char c){
    return (c >= 'A' && c <= 'Z');
}

static void safe_rot(char* c, char start, int key){
    *c = (*c - start + key) % 26 + start;
}

char *rotate(const char *text, int shift_key){
    int key = shift_key % 26; 
    size_t len = strlen(text);
    char* out = malloc(len+1);

    size_t i;
    for (i = 0; i < len; i++){
        char c = text[i];
        if (is_lower(c))
            safe_rot(&c, 'a', key);
        else if (is_upper(c))
            safe_rot(&c, 'A', key);
        
        out[i] = c;
    }
    out[i] = '\0';

    return out;
}
