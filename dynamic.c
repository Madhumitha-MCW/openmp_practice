#include <stdio.h>
#include<omp.h>
#include <time.h>

int main()
{
    clock_t t;
    t = clock();
    #pragma omp parallel for schedule(dynamic, 1) 	
    for (int i = 0; i < 20; i++)
    {
        printf("Thread %d is running number %d\n", omp_get_thread_num(), i);
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds   
    printf("\nloop took %f seconds to execute \n", time_taken);
    return 0;
}