#include <cstdio>
#include <omp.h>

int main(void)
{
  double x = 9.0;

  int nth = omp_get_num_threads();
  int thid = omp_get_thread_num();
  std::printf("Hello world from thid: %d, out of %d .\n",
              thid, nth);

//#pragma omp parallel num_threads(4)
#pragma omp parallel private(thid, nth)
//Si no se declararn como privadas tendriamos corrupción de memoria
//Esto se puede detectar usando sanitizers: g++ -fopenmp -fsanitize=thread Private\&Shared.cpp -o private.x
  {// se generan los threads
    thid = omp_get_thread_num(); // privada, aunque tenga el mismo nombre, tipo, y no haya sido redeclarada
    nth = omp_get_num_threads(); // privada, aunque tenga el mismo nombre, tipo, y no haya sido redeclarada
    std::printf("Hello world from thid: %d, out of %d .\n",
                thid, nth);
  } // mueren los threads

  return 0;
}