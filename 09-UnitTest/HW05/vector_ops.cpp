#include "vector_ops.hpp"
double mean(const std::vector<double> & data){
    return std::accumulate(data.begin(), data.end(), 0.0)/data.size();
}