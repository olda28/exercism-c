#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs){
    size_t len = strlen(lhs);
    if (len != strlen(rhs))
        return -1;

   int hamming = 0;
   while (*lhs != '\0'){
        if (*lhs++ != *rhs++){
            hamming++;
        }
   }
   return hamming;
}
