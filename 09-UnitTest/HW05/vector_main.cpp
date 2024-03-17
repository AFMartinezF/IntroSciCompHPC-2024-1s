#include "vector_ops.hpp"
#include <iostream>
#include <numeric>

int main(int argc, char **argv) {
    const int N = std::atoi(argv[1]);
    std::vector<double> x;
    x.resize(N);
    std::iota(x.begin(), x.end(), 0.0); // see: https://en.cppreference.com/w/cpp/algorithm/iota
    std::cout << mean(x) << "\n";
}