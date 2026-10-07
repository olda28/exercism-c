#include "triangle.h"

static bool is_valid(triangle_t sides){
    return sides.a + sides.b >= sides.c
        && sides.b + sides.c >= sides.a
        && sides.a + sides.c >= sides.b
        && sides.a + sides.b + sides.c != 0;
}

static int equal_sides_count(triangle_t sides){
    return (sides.a == sides.b)
        + (sides.b == sides.c)
        + (sides.a == sides.c);
}

bool is_equilateral(triangle_t sides){
    return is_valid(sides) && equal_sides_count(sides) == 3;
}
bool is_isosceles(triangle_t sides){
    return is_valid(sides) && equal_sides_count(sides) >= 1;
}
bool is_scalene(triangle_t sides){
    return is_valid(sides) && equal_sides_count(sides) == 0;
}
