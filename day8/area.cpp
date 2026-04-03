//inside this source file you now define the functions that you declared inside the header file

#include <iostream>
#include "area.hpp"

double Area::Circle(double radius){
    return 3.14159 * radius * radius;
}

double Area::Rectangle(double length, double height){
    return length * height;
}
double Area::Triangle(double base, double height){
    return 0.5 * base * height;
}
double Area::Square(double length){
    return length * length;
}
