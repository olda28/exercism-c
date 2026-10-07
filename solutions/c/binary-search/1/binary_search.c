#include "binary_search.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

const int *binary_search(int value, const int *arr, size_t length){
    if (length == 0)
        return NULL;

    int idx; 
    int first = 0;
    int last = length-1;
    do {
        idx = (first+last)/2;
        if (arr[idx] == value)
            return arr+idx;
        if (arr[idx] > value)
            last = idx-1;
        if (arr[idx] < value)
            first = idx+1;
    } while (last >= first);
    return NULL;
}
