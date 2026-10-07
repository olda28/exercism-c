#include "gigasecond.h"
#include <time.h>

void gigasecond(time_t input, char *output, size_t size){
   const time_t later = input + 1000000000;
   struct tm* later_tm = gmtime(&later);
   strftime(output, size, "%F %T", later_tm);
}
