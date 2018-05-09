#include <stdio.h>
#include <mpi.h>
#include <unistd.h>

int main (int argc, char *argv[]) 
{
   MPI_Init(NULL,NULL);

   char hostname[1024];
   int world_size, world_rank, my_number;

   MPI_Comm_size(MPI_COMM_WORLD, &world_size);
   MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
   gethostname(hostname,1024);

   if (world_rank == 0) {
      printf("Number of processes = %d\n", world_size);
      my_number=123;
   }
 
   MPI_Bcast(&my_number,1,MPI_INT,0,MPI_COMM_WORLD);

   printf("My number on process %d on %s is %d\n", world_rank, hostname, my_number);
 
   if (world_rank == 0) {
      my_number+=123;
   }

   MPI_Bcast(&my_number,1,MPI_INT,0,MPI_COMM_WORLD);

   printf("Now, my number on process %d on %s is %d\n", world_rank, hostname, my_number);

   MPI_Finalize();
}
