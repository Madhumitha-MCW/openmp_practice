#include <stdio.h>
#include<omp.h>
#include <time.h>

int main()
{
    #pragma omp parallel for schedule(static,1) 	
    for (int i = 0; i < 20; i++)
    {
        printf("Thread %d is running number %d\n", omp_get_thread_num(), i);
    }
    return 0;
}


//when iter_size / chunk_size is larger than the number of threads
// int main()
// {
// 	omp_set_num_threads(4);
//     #pragma omp parallel for schedule(static, 3) 	
//     for (int i = 0; i < 20; i++)
//         {
//             printf("Thread %d is running number %d\n", omp_get_thread_num(), i);
//         }
//         return 0;
// }
