//Ejecutar con sanitizers 
//g++ -g -fsanitize=address,leak,undefined 9.1Example.cpp -o d.out

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
  // declare variables
  const int N = 10;
  double * array;
  //reserve memory
  array = new double [N];
  // initialise array
  for (int ii = 0; ii < N; ++ii) {
    array[ii] = 2*(++ii); // != 2*(ii++) ?
  //array[ii] = 2*(ii); //
  }
  // print some values
  int idx = 2;
  std::cout << array[idx] << std::endl;
  idx = 10;
  //idx = 9;
  std::cout << array[idx] << std::endl; // compiles, but ...

  // free memory
  //delete [] array;

  return EXIT_SUCCESS;
}