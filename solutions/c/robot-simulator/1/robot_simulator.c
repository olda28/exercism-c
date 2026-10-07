#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_position_t pos = { x, y };
    return (robot_status_t){ direction, pos };
}
void robot_move(robot_status_t *robot, const char *commands){
    int sign;
    while (*commands != '\0'){
        switch (*commands++){
            case 'R':
                robot->direction++;
                if (robot->direction == DIRECTION_MAX)
                    robot->direction = DIRECTION_NORTH;
                break;
            case 'L':
                if (robot->direction == DIRECTION_NORTH)
                    robot->direction = DIRECTION_MAX;
                robot->direction--;
                break;
            case 'A':
                sign = robot->direction >= 2 ? -1 : 1;
                if (robot->direction % 2 == 0){
                    robot->position.y += sign;
                } else {
                    robot->position.x += sign;
                }
                break;
        }
    } 
}
