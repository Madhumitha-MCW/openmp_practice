#include<iostream>
#include<omp.h>
#include<time.h>

using namespace std; 

int main(int argc, char *argv[])
{
    clock_t t;
    t = clock();
    int count[8] = {0};
    int times_exec = 0;
    
    #pragma omp parallel 
    for(int i=0;i<8;i++)
    {

        cout<<"\nThis is a thread-->"<<omp_get_thread_num();
        count[omp_get_thread_num()]+=1; 
        times_exec++;
    }
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout<<"\nfun() took "<<time_taken<<" seconds to execute"<< time_taken<<"\n";

    for(int i=0;i<8;i++)
    {
        cout<<count[i]<<"\t";
    }
    
    cout<<"\ntimes exec is:"<<times_exec;
    
    return 0;  
}