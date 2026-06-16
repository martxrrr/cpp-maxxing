#include <iostream>
#define PI 3.141592625
#include "area.hpp"

void Log(int grade, float pi, std::string name = "Nigga"){
	std::cout << grade << "\n";
	std::cout << pi << "\n";
	std::cout << name << "\n";
}

constexpr bool leapYear(int year){
	if(year % 4 == 0){
		return true;
	}else{
		return false;
	}
}

struct noobStruct{
	char grade; 
	double gangsterPoints;
	int age;
};

struct OptimizedStruct{
	double gangsterPoints;
	int age;  
	char grade;
};


int main(){

	constexpr bool grade = false;
	std::cout << (grade ? "True(constexpr)" : "False(constexpr)") << "\n";

	std::cout << PI << "(macro)" << "\n";

	Log(90, 3.14159);

	bool checkYear = leapYear(2024);
	std::cout << (checkYear ? "leap year" : "Not a Leap Year") << "\n";

	calcArea shape1;

	std::cout << "Triangle: " << shape1.triangle(10.31, 20.45) << "\n";
	std::cout << "Circle: " << shape1.circle(3.14159) << "\n";
	std::cout << "Square: " << shape1.square(10.00) << "\n";

	std::cout << std::endl;
	std::cout << sizeof(noobStruct) << "\n";
	std::cout << sizeof(OptimizedStruct) << "\n";

	std::cout << std::endl;

	unsigned int bigNum = 2147483650;
	std::cout << bigNum << "\n";

	std::cout << (-1 < 1 ? "Real behaviour" : "Bad behaviour") << "\n";
	

	return 0;
}