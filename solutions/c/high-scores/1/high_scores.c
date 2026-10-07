#include "high_scores.h"
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
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
   return *(int*)b - *(int*)a; 
}
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
   const size_t bytesize = scores_len*sizeof(int32_t);
   int32_t *sorted = malloc(bytesize);
   memcpy(sorted, scores, bytesize);
   
   qsort(sorted, scores_len, sizeof(int32_t), comp);
   memcpy(output, sorted, sizeof(int32_t)*3);
   free(sorted);
   return scores_len > 3 ? 3 : scores_len;
}
