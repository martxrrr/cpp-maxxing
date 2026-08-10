#include <iostream>
#include <string>

template <typename T>
constexpr bool is_lvalue(T&){
    return true;
}

template <typename T>
constexpr bool is_lvalue(T&&){
    return false;
}

#define PRINTVAL(expr){ std::cout <<  #expr << " is an " << (is_lvalue(expr) ? "lvalue" : "rvalue"); }

int getValue(){
    return 10;
}

//accepts both rvalues and lvalues
int setValue(const int& i){
    std::cout << i << std::endl;
    return i;
}
//accepts lvalues only
int setValue(int& i){
    std::cout << i << std::endl;
    return i;
}

//an rvalue reference
void stringFunc(std::string&& name){
    std::cout << "[rvalue reference] " << name << "\n";
}

//accepts both rvalues and lvalues
void stringFunc(const std::string& name){
    std::cout << "[rvalue reference] " << name << "\n";
}

int main(){
    int i = 15;
    int j = 12;

    std::cout << getValue() << "\n";

    std::cout << getValue() << "\n";
    setValue(i);
    setValue(10);


    std::string firstName = "Martin";
    std::string lastName = "Wainaina";

    std::string fullName = firstName + lastName;

    stringFunc(fullName); //this code cannot work for the rvalue-reference-only function
    stringFunc(firstName + lastName);

    PRINTVAL(5);                    // rvalue
    PRINTVAL(getValue());            // rvalue
    int x { 5 };
    PRINTVAL(x);                     // lvalue
    PRINTVAL(std::string {"Hello"}); // rvalue
    PRINTVAL("Hello");               // lvalue
    PRINTVAL(++x);                   // lvalue
    PRINTVAL(x++);                   // rvalue

    //C-style string literals are lvalues and not rvalues
    //They have the properties of lvalues : addressability
    
    //This is completely valid C++
    const char (*p)[6] = &"hello";
    std::cout << p << std::endl;

    return 0;
}