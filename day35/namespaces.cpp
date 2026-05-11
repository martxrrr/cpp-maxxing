/*
A namepsace provides scope that allows you to declare or define names inside of it for the
purpose of disambiguation.
A name declared within a scope region is different from any identical name declared in another scope
Namespaces may only contain declaratoions and definitions, executable statements are only allowed if they are part of a definition
Global namespace
In C++, any name that is not defined inside a class, function, or a namespace is considered to be part of an implicitly-defined namespace called the global namespace 

*/



#include <iostream>

void printInfo(char* name){
	int age = 19;
	std::cout << name << std::endl;
	std::cout << age << std::endl;
	int CalcGoonCount(int sexDrive){
		std::cout << "Enter your sex drive in hours: " ;
		int goonCount = (sexDrive * 100) % 2;
		std::cout << goonCount << std::endl;

		return goonCount;
	}

	std::cout << "Gooned: " << CalcGoonCount(6767) << " times" << std::endl;
}

void showInfo(char* name){
	int age = 19;
	std::cout << name << std::endl;
	std::cout << age << std::endl;

	double CalcGoonCount(int sexDrive){
		std::cout << "Enter your sex drive in hours: " ;
		int goonCount = (sexDrive * 100) % 2;
		std::cout << goonCount << std::endl;

		return goonCount;
	}

	std::cout << "Gooned " << CalcGoonCount(6767) << " times" << std::endl;
}

int main(){



	return 0;
}