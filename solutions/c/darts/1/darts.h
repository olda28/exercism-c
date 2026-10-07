#include <stdint.h>
#ifndef DARTS_H
#define DARTS_H
typedef struct coordinate_t {
    float x;
    float y;
} coordinate_t;
uint8_t score(coordinate_t coord);
#endif
