#include <iostream>

typedef int32_t i4;

int main(){

	// std::cout << sizeof(int) << std::endl; //4 bytes
	// std::cout << sizeof(bool) << std::endl; //1 byte
	// std::cout << sizeof(size_t) << std::endl; //8 bytes
	// std::cout << sizeof(double) << std::endl; //8 bytes
	// std::cout << sizeof(float) << std::endl; //4 bytes
	// std::cout << sizeof(long long) << std::endl; //8 bytes

	// //different sizes of integers
	// std::cout << sizeof(int8_t) << std::endl; //  8-bit system (1)
	// std::cout << sizeof(int16_t) << std::endl; // 16-bit (2)
	// std::cout << sizeof(int32_t) << std::endl; // 32-bit (4)
	// std::cout << sizeof(int64_t) << std::endl; // 64-bit (8)


	int age = 4294967295; 
	std::cout << age << std::endl;



	return 0;
}