//header file - declarations of functions or classes and prototypes

// #pragma once - another (modern) way of guarding the headers i.e ensuring they are only included once
#ifndef AREA_HPP
#define AREA_HPP

class Area{
public:
    int radius, length, width, base, height;

    double Circle(double radius);
    double Triangle(double base, double height);
    double Square(double length);
    double Rectangle(double length, double height); 
};

#endif