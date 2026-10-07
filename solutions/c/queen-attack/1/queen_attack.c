#include "queen_attack.h"
#include <stdbool.h>
#include <stdlib.h>

static bool valid_pos(position_t pos){
    return pos.row <= 7 && pos.column <= 7;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2){
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column)
        return INVALID_POSITION;
    if (!valid_pos(queen_1) || !valid_pos(queen_2))
        return INVALID_POSITION;

    bool diagonal = abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column);

    bool direct = (queen_1.row == queen_2.row) || (queen_1.column == queen_2.column);

    return diagonal || direct;
}
