#include<iostream>
#include<omp.h>
#include<time.h>

using namespace std;
// int main()
// {
//     clock_t t;
//     t = clock();

//     #pragma omp parallel for schedule(static,1) 	
//     for (int i = 0; i < 20; i++)
//     {
//         cout<<"\nThis is a thread-->"<<omp_get_thread_num();
//     }

//     t = clock() - t;
//     double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds    
//     cout<<"\nloop took "<<time_taken<<" seconds to execute"<< time_taken<<"\n";

//     return 0;
// }


//when iter_size / chunk_size is larger than the number of threads
int main()
{
    clock_t t;
    t = clock();
    omp_set_num_threads(4);
    
    #pragma omp parallel for schedule(static, 3) 	
    for (int i = 0; i < 20; i++)
    {
        cout<<"\nThis is a thread-->"<<omp_get_thread_num();
    }
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds   
    cout<<"\nloop took "<<time_taken<<" seconds to execute"<< time_taken<<"\n";
    
    return 0;
}
