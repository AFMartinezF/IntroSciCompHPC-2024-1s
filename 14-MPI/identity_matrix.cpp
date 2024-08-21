#include <iostream>
#include <vector>
#include <mpi.h>

std::vector<int> identityRows(int N, int init_row, int final_row);
void identityMpi(int N, int pid, int np);

int main(int argc, char **argv) {
    const int N = std::stoi(argv[1]);

    MPI_Init(&argc, &argv);
    int pid=0, np=0;
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    identityMpi(N, pid, np);

    MPI_Finalize();

    return 0;
}

std::vector<int> identityRows(int N, int init_row, int final_row){
    //Crear la matriz que contendra un trozo de la matriz identidad completa
    int size = final_row - init_row;
    std::vector<int> rows(size*N,0);

    //Llenar con unos donde corresponda
    int j = init_row;
    for (int i=0; i<size; ++i){
	rows[i*N+j] = 1;
	j++;
    }

    return rows;
}

void identityMpi(int N, int pid, int np){
    //Definir donde empieza y termina cada trozo de matriz
    int Nlocal = N/np;
    int init_local = pid*Nlocal;
    int final_local = init_local + Nlocal;
    auto identity_local =  identityRows(N, init_local, final_local); //auto hace que el compilador deduzca el tipo de dato usado

    int tag = 0;
    if (pid == 0) {
        //Imprimir los datos del proceso 0
        for (int i = 0; i < Nlocal; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << identity_local[i * N + j] << " ";
            }
            std::cout << std::endl;
        }

        for(int ipid = 1; ipid < np; ipid++) {
	    //Recibir los datos de los demas procesos
	    std::vector<int> recv_rows(Nlocal*N);
            MPI_Recv(recv_rows.data(), recv_rows.size(), MPI_INT, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	    //Imprimir los datos
	    for (int i = 0; i < Nlocal; ++i) {
                for (int j = 0; j < N; ++j) {
                     std::cout << recv_rows[i * N + j] << " ";
                     }
                std::cout << std::endl;
                }
	    }
        } else {
       //Enviar el trozo de matriz al pid 0
       MPI_Send(identity_local.data(), identity_local.size(), MPI_INT, 0, tag, MPI_COMM_WORLD);
      }
}
