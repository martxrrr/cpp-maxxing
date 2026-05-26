#include <iostream>
#include <typeinfo>

typedef int32_t i4;

void swapByValue(int a, int b){ //computationally expensive, does not change the original data
	int temp = a;
	a = b;
	b = temp;

	std::cout << a << " " << b << "\n";
}

void swapByPointers(int* ptrA, int* ptrB){ //saves computing power, can modify the original data
	int temp = *ptrA;
	*ptrA = *ptrB;
	*ptrB = temp;

	std::cout << *ptrA << " " <<*ptrB << "\n";
}

void swapByReference(int &refA, int &refB){ //saves computaional power, can modify the original data
	int temp = refA;
	refA = refB;
	refB = temp;


	std::cout << refA << " " << refB << "\n";
}


int main(){

	std::cout << "Int: " << sizeof(int) << std::endl; //4 bytes
	std::cout << "bool: " << sizeof(bool) << std::endl; //1 byte
	std::cout << "Size_t: " << sizeof(size_t) << std::endl; //8 bytes
	std::cout << "Double: " << sizeof(double) << std::endl; //8 bytes
	std::cout << "Float: " << sizeof(float) << std::endl; //4 bytes
	std::cout << "long long: " << sizeof(long long) << std::endl; //8 bytes
	std::cout << "Long Int: " << sizeof(long int) << std::endl; //8 bytes

	//different sizes of integers
	std::cout << sizeof(int8_t) << std::endl; //  8-bit system (1)
	std::cout << sizeof(int16_t) << std::endl; // 16-bit (2)
	std::cout << sizeof(int32_t) << std::endl; // 32-bit (4)
	std::cout << sizeof(int64_t) << std::endl; // 64-bit (8)


	int age = 4294967295; 
	std::cout << age << std::endl;

	auto pi = 3.141592653f;
	std::cout << typeid(pi).name() << std::endl;

	// double pi2 = 3.141592653;
	// std::cout << typeid(pi2).name() << "\n";

	char grade = 'A'; // 65
	bool pass = true; // 1
	bool promoted = true; // 1 (65 + 1 + 1 = 67)

	std::cout << (grade + pass + promoted) << "\n";


	swapByValue(7, 6);

	int a = 7;
	int b = 6;
	swapByPointers(&a, &b);

	swapByReference(a, b);

	//what if you want both features of pass by value and pass by reference or pointers
	//like save computaional and optionally don't want to modify the original data
	//PASS BY CONST REFERENCE !!!!!!



	return 0;
}