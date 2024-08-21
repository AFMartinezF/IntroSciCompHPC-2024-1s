#include "mpi.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

/* Problem parameters */
void bandwitdh (int pid, int N);

int main(int argc, char **argv)
{
  /* MPI Variables */

  /* problem variables */
  int pid, np;
  const int N= std::atoi(argv[1]);

  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  bandwitdh(pid,N);

  /* finish */
  MPI_Finalize();

  return 0;
}

void bandwitdh(int pid, int N) {
    int tag = 0;
    double tam = 0;
    double bandwidth = 0;
    double t = 0;
    std::vector<double> v1(N, 0.0);  // Inicializa el vector con ceros

    if (pid == 0) { 
        double starttime = MPI_Wtime();

        MPI_Send(&v1[0], N, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD);
        MPI_Recv(&v1[0], N, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        double endtime = MPI_Wtime();
        t = endtime - starttime;
        tam = N * sizeof(double);  // Tamaño en bytes del mensaje
        bandwidth = tam /((t/2)*(1024*1024));  // Bandwidth en MB/s

        std::cout <<N<<"," <<bandwidth<<std::endl;
    } else if (pid == 1) {
        MPI_Recv(&v1[0], N, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&v1[0], N, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
    }
  }
