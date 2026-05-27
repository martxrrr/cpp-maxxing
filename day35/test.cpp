#include <iostream>

int main(){
	int num;
	std::cout << "Enter your number: " ;
	std::cin >> num;

	std::cout << (num % 2 == 0 ? "Even number" : "Odd number") << "\n";
}