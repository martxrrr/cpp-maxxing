// Today I decided to look at stuff that I do see in other people's c++ code and I do not know what they mean.
// reason why I am doing this? sfml SUCKS 🤬, I still haven't found a way to configure the settings to run sfml 3.0
// and not sfml 2.6 coz I have both installed, I want to learn sfml 3 coz that's what the documentation have and it's just better

#include <iostream>
#include <typeinfo>

//give nick-names to data types
typedef std::string string;

//constexpr functions - functions evaluated at compile time
//can also be evaluated at runtime if they are called into a non-constexpr variable
//but a constexpr variable can not call a non-constexpr function
constexpr double area(double &radius){
    return radius * radius * 3.14159;
}

//a struct is a user defined data type used for organizing related data together, regardless of the data type
struct Gooner{
    string name = "Martin Wainaina";
    int age = 19;
    long goonCount = 3467676767;
    double bodyCount = 17.5;
};


int main(){
    //constexpr is used to create compile-time constants i.e values are evaluated at compile-time rather than runtime
    // which saves the cpu time when the program is running 
    constexpr double rad = 12.56;
    std::cout << "Area: " << rad << std::endl;

    string name = "Martin";
    std::cout << name << std::endl;

    //accessing a struct
    Gooner martin;
    std::cout << "Name: " << martin.name << std::endl;
    std::cout << "Age: " << martin.age << std::endl;
    std::cout << "Goon count 🥵" << martin.goonCount << "\n";
    std::cout << "Body Count: " << martin.bodyCount << std::endl;

    //auto - used when the user doesn't want to explicitly say the data type,
    // the compiler automatically deduces the data type, hence the variable must be initialized

    auto student = "Martin Wainaina";
    auto grade = 99;
    auto halfLife = 12.5645;

    return 0;
}