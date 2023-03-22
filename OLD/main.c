#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "pgcd.h"

int my_rand()
{
    int upper = 65535;
    int lower = 1;
    return (rand() % (upper - lower + 1)) + lower;
}

int main()
{
    srand(time(NULL));
    clock_t begin, end, debut_test, fin_test;
    debut_test = clock();
    double time_spent;
    int round = 65535;

    #pragma omp for
    for (int i = 1; i < 65535; i++)
    {
        if (i % 1000 == 0)
            begin = clock();
    
        for (int j = 1; j < round; j++)
        {
            assert(PGCD(i, j) == pgcd_google(i, j));
        }
        if (i % 1000 == 0)
        {
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("i:%d || time/assert=%fµs\n", i, time_spent / round * 1000 * 1000);
        }
    }
    fin_test = clock();
    time_spent = (double)(fin_test - debut_test) / CLOCKS_PER_SEC;
    printf("temps test total=%fs\n", time_spent);
    return 0;
}