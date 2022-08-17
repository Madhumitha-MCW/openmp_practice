#include <stdio.h>
#include<omp.h>

int main(int argc, char *argv[])
{
  #pragma omp parallel
  printf("This is a thread.\n   %d",omp_get_thread_num());
  return 0;
}
