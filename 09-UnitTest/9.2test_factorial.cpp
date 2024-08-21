#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//Ejecutar con g++ 9.2test_factorial.cpp 9.2factorial.cpp -o 9.2test_factorial.x -l Catch2Main -l Catch2 
#include "catch2/catch_test_macros.hpp"
#include "factorial.h"

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( factorial(0) == 1 );
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
}