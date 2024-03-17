#include "vector_ops.hpp"
#include <numeric>
double mean(const std::vector<double> & data){
    return std::accumulate(data.begin(), data.end(), 0.0)/data.size();
}