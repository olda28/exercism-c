#include "high_scores.h"
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int32_t latest(const int32_t *scores, size_t scores_len){
   return scores[scores_len-1]; 
}
int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t highest = 0;
    for (size_t i = 0; i < scores_len; i++){
        if (scores[i] > highest)
            highest = scores[i];
    }
    return highest;
}

static int comp(const void *a, const void *b){
    int32_t x = *(const int32_t*)a;
    int32_t y = *(const int32_t*)b;

    if (x > y)
        return -1;
    if (x < y)
        return 1;
    return 0;
}
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
   size_t count = scores_len > 3 ? 3 : scores_len;
   const size_t bytesize = scores_len*sizeof(int32_t);
   int32_t *sorted = malloc(bytesize);
   memcpy(sorted, scores, bytesize);
   
   qsort(sorted, scores_len, sizeof(int32_t), comp);
   memcpy(output, sorted, sizeof(int32_t)*count);
   free(sorted);

   return count; 
}
