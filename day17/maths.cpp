//I realised that in the near future I will need to use more advanced math function like trig, hyperbolic or exponential functions
//so today I explored the cmath library

#include <iostream>
#include <cmath>
#include <numbers>

int main(){
    const double pi = 3.14159;
    double degree = 90;
    float angle = degree * (pi / 180);

    //NOTE: Angle is in radians, not degrees
    std::cout << sin(angle) << std::endl;
    std::cout << cos(angle) << std::endl;
    std::cout << tan(angle) << std::endl;

    //inverse trig functions
    std::cout << asin(angle) << std::endl;
    std::cout << acos(angle) << std::endl;
    std::cout << atan(angle) << std::endl;

    //exponetial and logarithmic functions
    double num = 12;
    std::cout << exp(num) << std::endl; //returns e^x
    std::cout << log(num) << std::endl; //natural log i.e base e
    std::cout << log10(num) << std::endl; //log to base 10
    std::cout << log2(num) << std::endl; //log to base 2
    
    double base = 6;
    double power = 7;
    std::cout << pow(base, power) << std::endl; //6^7 

    std::cout << sqrt(10000) << std::endl; //square root
    std::cout << cbrt(10000) << std::endl; //cube root

    double x{3};
    double y{4};
    std::cout << hypot(x, y) << std::endl; //returns the hypotenuse from the sides 3 and 4 

    double val{-67};
    std::cout << abs(val) << std::endl; //gets the absolute value of a number

    float nm{2};
    float dm{3};
    std::cout << fmod(nm, dm) << std::endl; //gets the floating remainder of x/y

    //rounding
    float flt{2.3};
    std::cout << ceil(flt) << std::endl; //round up
    std::cout << floor(flt) << std::endl; //round down
    std::cout << round(flt) << std::endl; //normal rounding off
    std::cout << trunc(flt) << std::endl; //truncate, just cutting off the floating point numbers

    //checking
    int nan = 2;
    std::cout << isnan(nan) << std::endl; //returns true if a number is not a number
    std::cout << isinf(nan) << std::endl; //returns true if a number is infinite, else returns false

    //for advanced physics and calculus
    //hyperbolic functions
    double hyper{67.67};
    std::cout << sinh(hyper) << std::endl;
    std::cout << cosh(hyper) << std::endl;
    std::cout << tanh(hyper) << std::endl;

    std::cout << asinh(hyper) << std::endl;
    std::cout << asinh(hyper) << std::endl;
    std::cout << asinh(hyper) << std::endl;

    //the <numbers> library also offers a set of mathematical constants
    std::numbers::pi; //the value of pi
    std::numbers::e; //euler's number 
    std::numbers::phi; //golden ratio phi
    std::numbers::log2e; //log of e to base 2
    std::numbers::log10e; //log of e to base 10

    return 0;
}