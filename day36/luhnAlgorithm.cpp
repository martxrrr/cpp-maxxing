#include <iostream>

int main(){
	std::cout << "Hello, Luhn " << "\n";

	std::string cardNumber;



	return 0;
}

/*
Luhn's algorithm

	3252-5786-7845-6516-7621
	
	SET 1
	1 + 6 + 6 + 5 + 5 + 8 + 6 + 7 + 2 + 2 (every digit in an odd position (from the right))

	2 + 12 + 12 + 10 + 10 + 16 + 12 + 14 + 4 + 4 (double them, if after doubling it is greater than 9, subtract 9)
	2 + 3 + 3 + 1 + 1 + 7 + 3 + 5 + 4 + 4 = (33)

	
	SET 2
	2 + 7 + 1 + 6 + 4 + 7 + 8 + 5 + 5 + 3 (every digit in an even position (form the right))
	add them just as they are = 48

	FINAL
	48 + 33 = 81
	 81 % 10 != 0 thus number is not valid

*/