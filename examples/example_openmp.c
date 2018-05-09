#include <stdio.h>
#include <omp.h>

int main (int argc, char *argv[]) 
{
   int nthreads, tid, my_number;

   my_number=123;

#pragma omp parallel private(nthreads, tid)
   {
      tid = omp_get_thread_num();
      if (tid == 0) {
         nthreads = omp_get_num_threads();
         printf("Number of threads = %d\n", nthreads);
      }
      printf("My number on thread %d is %d\n", tid, my_number);
   }
 
   my_number+=123;

#pragma omp parallel private(nthreads, tid)
   {
      tid = omp_get_thread_num();
      printf("Now, my number on thread %d is %d\n", tid, my_number);
   }
}
