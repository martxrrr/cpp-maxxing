#include <iostream>

inline int getSum(int a, int b){
	return a + b;
}

int main(){


	std::cout << "Sum: " << getSum(12, 32) << std::endl;

	return 0;
}
// inline functions - the function is replaced with the function code
// like, instead of now having two parts, function definition and function call, the compiler replaces the function
// call with the function definition code
// This reduces function-call overhead and can improve performance for small
// frequently accessed functions
// If the function is too complex, the compiler just ignores it
// And it also automatically adds it for small function even if you do not explicitly tell it
