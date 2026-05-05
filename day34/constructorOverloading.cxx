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

    void display() {
        std::cout << name << ": " << length << "x" << breadth << std::endl;
    }
};

int main() {
    // Calling different constructors
    Room r1;                    // Calls Default
    Room r2(12.5, 10.0);        // Calls Parameterized (2 args)
    Room r3(20.0, 15.0, "Gym"); // Calls Parameterized (3 args)

    r1.display(); // Output: Undefined: 0x0
    r2.display(); // Output: Generic Room: 12.5x10
    r3.display(); // Output: Gym: 20x15

    return 0;
}