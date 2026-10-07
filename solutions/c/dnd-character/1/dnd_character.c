#include "dnd_character.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


int ability(void){
    srand(time(NULL));
    int sum = 0;

    int smallest = 6;
    for (int i = 0; i < 4; i++){
        int n = (rand() % 6) + 1;
        sum += n;
        if (n < smallest)
            smallest = n;
    }
    sum -= smallest;
    return sum;
}

    
int modifier(int score){
    return floor((score - 10)/2.0F);
}

dnd_character_t make_dnd_character(void){
    int constitution = ability();
    dnd_character_t dnd = { ability(), ability(), constitution, ability(), ability(), ability(), 10+modifier(constitution) }; 
    return dnd;
}
