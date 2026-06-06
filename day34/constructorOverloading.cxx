#include <iostream>
#include <string>

class Room {
private:
    double length;
    double breadth;
    std::string name;

public:
    // 1. Default Constructor(done automatically by the compiler)
    Room() {
        length = 0.0;
        breadth = 0.0;
        name = "Undefined";
    }

    // 2. Parameterized Constructor (Length and Breadth only)
    Room(double l, double b) {
        length = l;
        breadth = b;
        name = "Generic Room";
    }

    // 3. Parameterized Constructor (Full details)
    Room(double l, double b, std::string n) {
        length = l;
        breadth = b;
        name = n;
    }

    // 4. Copy constructors - initializes values based on values from another object passed as a parameter
    //                        used when you want to initialize an object with values of another object
    Room(const Room& other){
        length = other.length;
        breadth = other.breadth;
        name = other.name;
    }

    void display() {
        std::cout << name << ": " << length << "x" << breadth << std::endl;
    }
};

int main() {
    // Calling different constructors
    Room r1;                    // Calls Default
    Room r2(12.5, 10.0);        // Calls Parameterized (2 args)
    Room r3(20.0, 15.0, "Gym"); // Calls Parameterized (3 args)
    Room r4(r1);                //calls the Copy constructor 

    r1.display(); // Output: Undefined: 0x0
    r2.display(); // Output: Generic Room: 12.5x10
    r3.display(); // Output: Gym: 20x15
    r4.display(); //Gets the same output as r3 

    return 0;
}