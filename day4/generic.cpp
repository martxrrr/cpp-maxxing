//I realised that POINTERS is a wide concept and they just need practice to be good at them
// like actually using them in a real program is the best way to understand them well
//so i decided to move to ther concepts since pointers are pretty much the same with just some differences


//=======================
// GENERIC PROGRAMMING //
//=======================

// allow passing in a data type as a param to a function, method or class for code reusability
//i.e one function works for all data types including the user-defined data types


#include <iostream>
template <typename T> //T acts as the data type



T max(T x, T y){
    return (x > y) ? x : y;
}

int main(){

    std::cout << max<int>(12, 123) << std::endl;
    std::cout << max<double>(11.123, 11.1234) << std::endl;
    std::cout << max<char>('m', 's') << std::endl;


    return 0;
}