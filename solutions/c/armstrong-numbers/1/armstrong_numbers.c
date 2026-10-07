#include "armstrong_numbers.h"
#include <stdbool.h>
#include <math.h>

bool is_armstrong_number(int candidate){
    int num = candidate;
    int digits;
    for (digits = 0; num != 0; digits++)
        num /= 10;

    num = candidate;
    int sum = 0;
    while (num != 0){
       sum += pow(num % 10, digits);
       num /= 10; 
    }

    return candidate == sum;
}
