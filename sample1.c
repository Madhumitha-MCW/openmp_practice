#include <stdio.h>
#include<omp.h>
#include <time.h>

int main(int argc, char *argv[])
{
    clock_t t;
    t = clock();
    int count[8] = {0};
    int times_exec = 0;
    
    #pragma omp parallel 
    for(int i=0;i<8;i++)
    {

        printf("\nThis is a thread--> %d",omp_get_thread_num());
        count[omp_get_thread_num()]+=1; 
        times_exec++;
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    
    printf("\nfun() took %f seconds to execute \n", time_taken);

    for(int i=0;i<8;i++)
    {
        printf("%d\t", count[i]);
    }
    printf("\n times exec is: %d", times_exec);
    return 0;  
}