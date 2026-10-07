#include "space_age.h"

static double orb_period(planet_t planet){
    switch (planet){
        case MERCURY:
            return 0.2408467;
        case VENUS:
            return 0.61519726;
        case EARTH:
            return 1.0;
        case MARS:
            return 1.8808158;
        case JUPITER:
            return 11.862615;
        case SATURN:
            return 29.447498;
        case URANUS:
            return 84.016846;
        case NEPTUNE:
            return 164.79132;
        default:
            return -1.0;
    }
}

float age(planet_t planet, int64_t seconds){
    double period = orb_period(planet);
    if (period == -1.0)
        return -1;
    double days_in_year = 365.25*period;
    double seconds_in_year = days_in_year*24*60*60;
    return seconds/seconds_in_year;
}
