#include "allergies.h"
#include <stdbool.h>

bool is_allergic_to(allergen_t idx, int flag){
    return flag & (1 << idx);
}

allergen_list_t get_allergens(int flag){
    allergen_list_t obj = { 0, { false } };

    for (int i = 0; i < ALLERGEN_COUNT; i++){
        obj.allergens[i] = flag & 1;
        obj.count += obj.allergens[i];
        flag >>= 1;
    }

    return obj; 
}

