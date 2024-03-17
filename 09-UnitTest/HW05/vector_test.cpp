#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch_test_macros.hpp"
#include "vector_ops.hpp"
#include <numeric>

TEST_CASE( "Mean of a vector is computed", "[mean]" ) {
    std::vector<double> x1(10, 0.0);
    REQUIRE(mean(x1) - 0.0 <= 1e-3);

    std::vector<double> x2(10, 5.0);
    REQUIRE(mean(x2) - 5.0 <= 1e-3);

    std::vector<double> x3(10, -5.0);
    REQUIRE(mean(x3) + 5.0 <= 1e-3);

    std::vector<double> x4(101); 
    x4.resize(101);
    std::iota(x4.begin(), x4.end(), 0); 
    REQUIRE(mean(x4) - 50.0 <= 1e-3);

    std::vector<double> x5(101); 
    x5.resize(101);
    std::iota(x5.begin(), x5.end(), 100.0); 
    REQUIRE(mean(x5) - 150.0 <= 1e-3);    
}