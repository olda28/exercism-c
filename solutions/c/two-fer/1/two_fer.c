#include "two_fer.h"
#include <stdio.h>
#include <stddef.h>

static const char* noname = "you";
void two_fer(char *buffer, const char *name){
    const char* who;
    if (name == NULL){
        who = noname;
    } else {
        who = name;
    }

    snprintf(buffer, 100, "One for %s, one for me.", who);    
}
