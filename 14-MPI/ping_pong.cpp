#include "mpi.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

/* Problem parameters */
void ping_pong (int pid);

int main(int argc, char **argv)
{
  /* MPI Variables */

  /* problem variables */
  int pid, np;

  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  ping_pong(pid);

  /* finish */
  MPI_Finalize();

  return 0;
}

  void ping_pong(int pid){
    MPI_Status status;
    int M=10;
    int tag=0;
    int message = 0;
    for (int m=0; m<M; m++) {
      if (pid == 0) {
        MPI_Send(&message, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
        MPI_Recv(&message, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
	std::cout << "Modified message for iteration "<<m<<" : " << message << std::endl;
      }
      else if (pid == 1) {
        MPI_Recv(&message, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
        message += 99;
        MPI_Send(&message, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
      }
    }
  }
