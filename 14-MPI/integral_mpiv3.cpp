#include <mpi.h>
#include <cstdio>
#include <string>

/* Problem parameters */
double f(double x);
double integral_serial(double xmin, double xmax, double n);
double integral_mpi(double xmin, double xmax, double n, int pid, int np);

int main(int argc, char **argv)
{
  if(argc != 4){
  printf("Error debe ingresar tres argumentos: npoints, xmin, xmax");
  return 1;
  }
  const int numberRects = std::stoi(argv[1]);
  const double lowerLimit = std::stod(argv[2]);
  const double upperLimit = std::stod(argv[3]);

  MPI_Init(&argc, &argv);
  int pid = 0, np = 0;
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);

  //double integral = integral_serial(lowerLimit, upperLimit, numberRects);
  double integral = integral_mpi(lowerLimit, upperLimit, numberRects, pid, np);

  //printf("The area from %lf to %lf is : %lf\n", lowerLimit, upperLimit, integral);

  MPI_Finalize();
  return 0;
}

double f(double x) {
  return x*x;
}

double integral_serial(double xmin, double xmax, double n)
{
  double area = 0.0;
  double width = (xmax - xmin)/n;

  for (int i = 0; i < n; ++i) {
    double at = xmin + i*width + width/2.0; // center in the middle
    double heigth = f(at);
    area = area + width*heigth;
  }
  return area;
}

double integral_mpi(double xmin, double xmax, double n, int pid, int np)
{

  // Dividir el dominio 
  int Nlocal = n/np;
  double Llocal = (xmax - xmin)/np;
  double xmin_local = xmin + pid*Llocal;  
  double xmax_local = xmin_local + Llocal;
  double Ilocal = integral_serial(xmin_local, xmax_local, Nlocal);
  //printf("The area from %lf to %lf is : %lf\n", xmin_local, xmax_local, Ilocal);

  int tag = 0;
  
  if (0 == pid) {
    // recibir los datos parciales de los demas
    double Itotal = Ilocal;
    // acumularlos/recibir de los demas 
    for(int ipid = 1; ipid < np; ipid++) {
      // recibir: mpi
      double Itmp = 0;
      MPI_Recv(&Itmp, 1, MPI_DOUBLE, ipid, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      Itotal += Itmp;
    }
    // imprimir el valor total
    printf("The area from %lf to %lf is : %lf\n", xmin, xmax, Itotal);
  } else {
    // enviar mi suma parcial al pid 0
    MPI_Send(&Ilocal, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
  }
  
  return Ilocal;
}
