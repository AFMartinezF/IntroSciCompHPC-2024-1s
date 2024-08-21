#include <iostream>

int main(void)
{
    const int M = 2500; //7000*7000*10
    const int N = 500;//500*500*1000
    double data[M][N] = {{0.0}};

    std::cout << data[M/2][N/2] << std::endl;

    return 0;
}