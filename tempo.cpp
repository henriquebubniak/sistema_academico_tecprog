#include "tempo.h"

void get_data_int(int* d, int* m, int* a)
{
    time_t myTime = time(NULL);
    char* tempo;
    tempo = ctime(&myTime);
    switch (tempo[4])
    {
    case 'J':
        if (tempo[5] == 'a')
            *m = 1;
        else if (tempo[6] == 'n')
            *m = 6;
        else 
            *m = 7;
        break;
    case 'F':
        *m = 2;
        break;
    case 'M':
        if(tempo[6] == 'r')
            *m = 3;
        else
            *m = 5;
        break;
    case 'A':
        if (tempo[5] == 'p')
            *m = 4;
        else
            *m = 8;
        break;
    case 'S':
        *m = 9;
        break;
    case 'O':
        *m = 10;
        break;
    case 'N':
        *m = 11;
        break;
    case 'D':
        *m = 12;
        break;
    
    default:
        *m = 1;
        break;
    }
    *d = (tempo[8]-48)*10 + tempo[9]-48;
    *a = (tempo[20]-48)*1000 + (tempo[21]-48)*100 + (tempo[22]-48)*10 + tempo[23]-48;
}