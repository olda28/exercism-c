#include "phone_number.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static char *zero(char *str){
    memset(str, '0', 10);
    str[10] = '\0';
    return str;
}

static bool valid_n(int n){
    return (n >= '2' && n <= '9');
}

char *phone_number_clean(const char *input){
   char* clean = malloc(12); // 11 digits + NUL
   if (clean == NULL)
       return NULL;

   char* out = clean;

   // strip plus
   if (*input == '+')
       input++;

   // copy non-punctuation numbers
   while (*input != '\0'){
       if (*input >= '0' && *input <= '9'){
           if (out-clean > 10){ // > 11 chars written (want to write at idx 11);
               return zero(clean);
           }
           *out++ = *input;
       }
       input++;
   }

   
   size_t len = out-clean;
   if (len < 10)
       return zero(clean);

   // Check and strip country code
   if (len == 11){
       if (clean[0] != '1')
           return zero(clean);
       
       memmove(clean, clean+1, 10);
   }

   if (!valid_n(clean[0]) || !valid_n(clean[3])){
       return zero(clean);
   }

   clean[10] = '\0';   
   return clean;
   
}

