#include "collatz_conjecture.h"
#include <stdio.h>

int steps(int start){
    if (start <= 0) return -1;
    int i;
    for (i = 0; start != 1; i++){
        printf("%d", start);
        if (start % 2 == 0){
            start = start / 2;
        } else {
            start = start*3 + 1;
        }
    }
    return i;
}