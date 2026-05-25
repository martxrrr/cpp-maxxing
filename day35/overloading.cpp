/*
Return by value
Return by reference
Overloading - use of the same thing for different purposes
A function used for different purposes
Can also be called function polymorphism
Same function name but:
					  different return types
					  different number of arguments
					  arguments with accepting different data types

If the function has everything as the same -  the program won't compile
you will get a redefinition error

Ambiguity happens when you pass an argument of a type that doesn't match any the parameter and conversion can go both ways
For example, you define long square(long n) and double square(double x) but then you pass in an int, whereas int can be converted 
to either long or double, this confuses the compiler and causes an error

*/
#include <iostream>
#include <string>
#include <typeinfo>

// int add(int x, int y){
// 	std::cout << "sum (d): " << x + y << std::endl;
// 	return (x + y);
// }

// double add(int x, int y){
// 	std::cout << "sum (f): " << x + y << std::endl;
// 	return (x + y);
// }


std::string to_ascii(int integer){
	std::cout << "int func" << "\n";
	std::string ascii = std::to_string(integer);
	return ascii;
}

std::string to_ascii(float floatingnNum){
	std::cout << "float func" << "\n";
	std::string ascii = std::to_string(floatingnNum);
	return ascii;
}

int to_int(std::string text){
	int num = std::stoi(text);
	return num;
}


float to_int(std::string text){
	float num = std::stoi(text);
	return num;
}


int main(){

	// auto ans2 = add('A', 'A'); //char is promoted to int

	// std::cout << ans1 << "\n";
	// std::cout << ans2 << "\n";

	std::string text = to_ascii(12.0f);
	std::cout << text << "\n";
	std::cout << typeid(text).name() << "\n";



	return 0;
}