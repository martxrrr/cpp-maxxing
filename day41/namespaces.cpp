#include <iostream>

namespace Student{
        std::string name { "Martin" };
        int age { 19 };

        void getInfo(){
                std::cout << "Name : " << name << "\n";
                std::cout << "Age : " << age << "\n";
        }
};

namespace Teacher{
        std::string name { "Sylvia" };
        int age { 25 };

        void getInfo(){
                std::cout << "Name : " << name << "\n";
                std::cout << "Age : " << age << "\n";
        }
};

void readCensor(){
        static int count = 0;
        ++count;
        std::cout << "Meter read : " << count << "\n";
}


int fact(int n){
        if(n <= 1){
                return 1;
        }
        return n * fact(n - 1);
}

int main(){

        // Student::getInfo();
        // Teacher::getInfo();

        fact(6);


        return 0;
}

/*
Namespaces and recursion

Namespaces prevent naming collisions - a variable declared inside a scope (defined by { }), is invisible outside the scope
In large codebases, this is very important as it prevents pollution and naming collisions

Recursion means a function calling itself, without a proper base case, the stack overflows
For deeply recursive algorithms, use iterative solutions or tail-call optimization hints

Global scope variables:
        Declared outside all functions
        Initialized to Zero and not garbage values
        They live out throughout the program, they are not detroyed even when they are unused

Within a translation unit, objects are initialized in the order in which they are defined, if A is defined before B then
A will be initialized before B

Across Translation Units (different .cpp files of the same program) - The initialization order is unspecified
If value A is in file1.cpp and variable B is in file2.cpp, variable B may be initialized before variable A by the compiler depending on the link order
This uncertainty leades to the Static Order Initialization Fiasco, where one global depends on another global from another file

Namespaces - group related code together under a unique name to prevent naming collisions

Static local variable:
        a function-local static variable has these properties:
                1. It is only visible to the function only, i,e LOCAL variable for the function
                2. It has static lifetime, that is, it lives throughout the program's memory

*/