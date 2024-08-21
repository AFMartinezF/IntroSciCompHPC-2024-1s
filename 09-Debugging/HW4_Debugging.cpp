//Indentation improved for better readability
#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);

int main (int argc, char **argv){
    int ii, jj;
    ii =  0; //Testing foo function with a value that causses a division by zero
    jj = -1;
    std::cout<<foo(ii, jj)<<std::endl;
    std::cout<<foo(jj, ii)<<std::endl;
    std::cout<<baz(25.9)<<std::endl;
    ii =  1;//Testing foo function with values that do not cause a division by zero
    std::cout<<foo(ii, jj)<<std::endl;
    std::cout<<foo(jj, ii)<<std::endl;
    std::cout<<baz(-25.9)<<std::endl; //Testing baz function with a negative value
    return EXIT_SUCCESS;
}

int foo(int a, int b){//Return aritmetic operation between a and b, only if if there is no division by zero 
    if (a == 0 || b == 0 || bar(a,b)==0) {//Manejo de la división por cero 
        std::cout<<"Error: División by zero"<<std::endl;
        return 0;
    }
    return a/b + b/bar(a, b) + b/a; //HW4_Debugging.cpp:23:33: runtime error: division by zero
}

int bar(int a, int b){ //Return 2a - b if a is positive, otherwise return  -b
    unsigned int c = a;
    return c + a - b;
}

double baz(double x){ //Return the square root of x if x is positive, otherwise return the square root of -x
    double v = -x; //Moved this line to the top and changed the sign
    if (x < 0) return std::sqrt(v); //Changed < instead of = 
    return std::sqrt(x); //Added ;   
}