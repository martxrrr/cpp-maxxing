#include <iostream>

class Complex{
    int a;
    int b;
    public:
    Complex(int a = 0, int b = 0) : b(b), a(a) {}

    Complex operator + (const Complex& other){
        return (a + other.a, b + other.b);
    }
    void display(){
        std::cout << a << " " << b << std::endl;
    }
};

int main(){
    Complex c1(2, 3);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;

    c3.display();

    std::cout << "Hello World" << std::endl;

    return 0;
}

/*
AN OPERATOR is a symbol that we use instead of a function
e.g & - ampersand
    || - bitwise operator
    <<
    >>
    ->
    %
    +
    -
    and many more





*/