//Compilar con mpic++ mpi_basic.c++ -o basic.x
//Equivalente a: g++ -L/usr/lib64 -Wl,-rpath -Wl,/usr/lib64 -Wl,--enable-new-dtags -lmpi

//ejecutar con mpirun -np # ./basic.x cambiar '#' por el número de procesos a ejecutar.

#include "mpi.h"
#include <cstdio>

int main(int argc, char **argv)
{
  int processId;                 /* rank of process */
  int noProcesses;               /* number of processes */

  MPI_Init(&argc, &argv);                   /* Mandatory */
  MPI_Comm_size(MPI_COMM_WORLD, &noProcesses);
  MPI_Comm_rank(MPI_COMM_WORLD, &processId);

  std::fprintf(stdout, "Hello from process %d of %d\n", processId, noProcesses);

  MPI_Finalize();                       /* Mandatory */

  return 0;
}
