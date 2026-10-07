#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>


static char complement(char nucl){
    switch (nucl){
        case 'G':
            return 'C';
        case 'C':
            return 'G';
        case 'T':
            return 'A';
        case 'A':
            return 'U';
        default:
            return 0;
    }
}

char *to_rna(const char *dna){
    size_t len = strlen(dna);
    char* rna = malloc(len+1);

    char* out = rna;
    while (*dna != '\0'){
       *out++ = complement(*dna++); 
    }
    *out = '\0';

    return rna;
}
