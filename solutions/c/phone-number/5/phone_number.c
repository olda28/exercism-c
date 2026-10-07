#include "phone_number.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static char *zero(char *str){
    memset(str, '0', 10);
    str[10] = '\0';
    return str;
}

static bool valid_n(char n){
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
           if (out-clean >= 11){ // (want to write at idx 11 - char 12);
               return zero(clean);
           }
           *out++ = *input;
       }
       input++;
   }

   
   size_t len = out-clean;
   if (len <= 9)
       return zero(clean);

   // Check and strip country code
   if (len == 11){
       if (clean[0] != '1')
           return zero(clean);
       
       memmove(clean, clean+1, 10);
   }
   clean[10] = '\0';   

   if (!valid_n(clean[0]) || !valid_n(clean[3])){
       return zero(clean);
   }

   return clean;
   
}

