#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value){
    size_t len = strlen(value);
    char* buf = malloc(len+1);

    size_t i;
    for (i = 0; i < len; i++){
       buf[i] = value[len-i-1]; 
    }

    return buf;
}
