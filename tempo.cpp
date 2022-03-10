#include "tempo.h"

void get_data_int(int* d, int* m, int* a)
{
   struct tm *tempo;
   time_t myTime;
   time (&myTime);
   tempo = localtime(&myTime);
   *d = tempo->tm_mday;
   *m = tempo->tm_mon;
   *a = tempo->tm_year + 1900;
}