#include "two_fer.h"
#include <stdio.h>
#include <stddef.h>

void two_fer(char *buffer, const char *name){
    snprintf(buffer, 100, "One for %s, one for me.", name ? name : "you");    
}
