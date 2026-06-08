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

class Number{

    int value;
public:
    Number(int v){
        value = v;
    }

    void show(){
        std::cout << "Value: " << value << "\n";
    }
    void operator++(){
        value++;
    }
};

int main(){
    Complex c1(2, 3);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;

    c3.display();

    std::cout << "Hello World" << std::endl;

    Number a(5);

    std::cout << "Before increment: " << "\n";
    a.show();

    std::cout << "After increment: " << "\n";
    a++;
    a.show();

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

rules:
    1. You can only overload existing operators
    2. Operator precedence can not change
    3. Number of operands remain the same, unary and binary
advs:
    1. improves code readability
    2. makes code intuitive
    3. makes classes behave like built in types
    4. simplifies complex expression

unary:
    1. works on one operand like ++a, a++, --a, a--
    2. 



*/