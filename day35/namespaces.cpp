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