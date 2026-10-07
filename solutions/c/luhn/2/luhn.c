#include "luhn.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

static bool is_ascii_digit(char c){
    return (c >= '0' && c <= '9');
}

static int deascii(char c){
    return c - '0';
}

static size_t strip_validate_spaces(char* input){
    char* r = input;
    char* w = input;
    while (*r != '\0'){
        char c = *r++;
        if (c == ' ') // skip spaces
            continue;
        if (!is_ascii_digit(c)){ // allow only ascii 0-9
            return 0;
        }
        *w++ = c; 
    }
    *w = '\0';
    return w-input; // new length
}

static int luhn_sum(const char* input, size_t len){
    int sum = 0;
    const char* r = input+len-1;
    for (size_t i = 0; i < len; i++){
        int digit = deascii(*r--);
        if (i % 2 == 1){
            digit = (digit * 2);
            if (digit > 9)
                digit -= 9;
        }
        sum += digit;
    }
    return sum;
}

bool luhn(const char *num){
    size_t len = strlen(num);
    char* buf = malloc(len+1);
    memcpy(buf, num, len+1);

    size_t clean_len = strip_validate_spaces(buf); // malloc
    if (clean_len <= 1){
        free(buf);
        return false;
    }

    int sum = luhn_sum(buf, clean_len);
    free(buf);

    return sum % 10 == 0;
}
