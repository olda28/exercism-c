#include "perfect_numbers.h"

static int aliquot(int n){
    int sum = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0){
            sum += i;
        }
    }
    return sum;
}

kind classify_number(int n){
   if (n <= 0)
       return ERROR;

   int sum = aliquot(n);

   if (n < sum){
       return ABUNDANT_NUMBER;
   }
   if (n > sum){
       return DEFICIENT_NUMBER;
   }
   return PERFECT_NUMBER;
}
