#include "difference_of_squares.h"
#include <math.h>

unsigned int sum_of_squares(unsigned int number){
    unsigned int i;
    int total = 0;
    for (i = 1; i <= number; i++){
        total += pow(i, 2);
    }
    return total;
}
unsigned int square_of_sum(unsigned int number){
    unsigned int i;
    int sum = 0;
    for (i = 1; i <= number; i++){
        sum += i;
    }
    return pow(sum, 2);
}
unsigned int difference_of_squares(unsigned int number){
    return square_of_sum(number) - sum_of_squares(number);
}