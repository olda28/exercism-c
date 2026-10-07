#include "phone_number.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *empty(char *str){
    memset(str, '0', 10);
    str[10] = '\0';
    return str;
}

bool validN(int n){
    return (n >= '2' && n <= '9');
}

char *phone_number_clean(const char *input){
   char* clean = malloc(12); // 11 digits + NUL

   const char* i = input;
   char* j = clean;

   // strip plus
   if (*i == '+') i++;

   // copy non-punctuation numbers
   for (; *i != '\0'; i++){
       if (j-clean > 10){ // > 11 chars written (want to write at idx 11);
           return empty(clean);
       }
       if (*i >= '0' && *i <= '9'){
           *j = *i;
           j++;  // Look at next 'clean' char
       }
   }

   
   int len = j-clean;
   if (len < 10) return empty(clean);
   if (len == 11){ // check & strip country code
       if (clean[0] != '1'){
           return empty(clean);
       } else {
           memmove(clean, clean+1, 10);
       }
   }
   if (!validN(clean[0]) || !validN(clean[3])){
       return empty(clean);
   }

   clean[10] = '\0';   
   return clean;
   
}

