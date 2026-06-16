#include <iostream>
#include "area.hpp"

double calcArea::triangle(double base, double height){
	return (0.5 * base * height);
}
double calcArea::circle(double radius){
	return (3.14159 * radius * radius);
}
double calcArea::square(double length){
	return (length * length);
}