#include <iostream>
#include <vector>
#include <mpi.h>

std::vector<int> identityRows(int N, int init_row, int final_row);
void identityMpi(int N, int pid, int np);

int main(int argc, char **argv) {
    int N = 6;

    MPI_Init(&argc, &argv);
    int pid=0, np =0;
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
//    auto identity =  identityRows(N, init_row, final_row);//auto hace que el compilador deduzca el tipo de dato usado
    identityMpi(N, pid, np);

    MPI_Finalize();

    return 0;
}

std::vector<int> identityRows(int N, int init_row, int final_row){
    int size = final_row - init_row;
    std::vector<int> rows(size*N,0);

    int j = init_row;
    for (int i=0; i<size; ++i){
	rows[i*N+j] = 1;
	j++;
    }

    return rows;
}

void identityMpi(int N, int pid, int np){
    int Nlocal = N/np;
    int init_local = pid*Nlocal;
    int final_local = init_local + Nlocal;
//    std::cout<<"final_local: "<<final_local<<std::endl;
    auto identity_local =  identityRows(N, init_local, final_local);

    int tag = 0;

    if (pid == 0) {
        //imprimir los datos propios
        for (int i = 0; i < Nlocal; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << identity_local[i * N + j] << " ";
            }
            std::cout << std::endl;
        }

        // acumularlos/recibir de los demas

        for(int ipid = 1; ipid < np; ipid++) {
        // recibir: mpi
	    std::vector<int> recv_rows(Nlocal*N);
            MPI_Recv(recv_rows.data(), recv_rows.size(), MPI_INT, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	    for (int i = 0; i < Nlocal; ++i) {
                for (int j = 0; j < N; ++j) {
                     std::cout << recv_rows[i * N + j] << " ";
                }
                std::cout << std::endl;
            }
       }
       // imprimir el valor total
       } else {
       // enviar mi suma parcial al pid 0
       MPI_Send(identity_local.data(), identity_local.size(), MPI_INT, 0, tag, MPI_COMM_WORLD);
      }
}
