#include "sum_of_multiples.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


static size_t multiples(unsigned int* output, unsigned int base, unsigned int less_than){
    unsigned int n = base; 
    unsigned int i;
    for (i = 1; i*n < less_than; i++){
       output[i-1] = i*n;
    }
    return i-1;
}

// merge b into a
static size_t append_no_dup(unsigned int* a, size_t a_len, unsigned int* b, size_t b_len){

    unsigned int* c = malloc((a_len + b_len)*sizeof(*c));
    unsigned int* cw = c;
    
    size_t ai = 0;
    size_t bi = 0;
    while (ai < a_len && bi < b_len){
        if (a[ai] < b[bi]){
            *cw++ = a[ai++];
            continue;
        }
        if (a[ai] == b[bi]){
            *cw++ = a[ai++];
            bi++;
            continue;
        }
        if (a[ai] > b[bi]){
            *cw++ = b[bi++];
            continue;
        }
    }
    while (ai < a_len){
       *cw++ = a[ai++];
    }

    while (bi < b_len){
        *cw++ = b[bi++];
    }

    size_t new_len = cw-c;
    memcpy(a, c, (new_len)*sizeof(*c));
    free(c);
    return new_len;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
        const unsigned int limit){
  
    unsigned int guess_factor = factors[0] == 0 ? 1 : factors[0];
    size_t max_single_len = (limit/guess_factor);
    size_t max_total_len = max_single_len * number_of_factors;
    unsigned int* buf = malloc(max_total_len*sizeof(*buf));
    size_t buf_len = 0;

    for (size_t i = 0; i < number_of_factors; i++){
        if (factors[i] == 0)
            continue;
        unsigned int* b = malloc(max_single_len*sizeof(*b));
        size_t b_len = multiples(b, factors[i], limit); 
        buf_len = append_no_dup(buf, buf_len, b, b_len);
        free(b);
    }
   
    unsigned int total = 0;
    for (size_t i = 0; i < buf_len; i++){
       total += buf[i];  
    }
    free(buf);

    return total;
}
