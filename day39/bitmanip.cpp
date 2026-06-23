#include <iostream>
#include <bitset>

struct Node{
        bool isLegal = true;
        int age = 10;
        double gangsterPoints = 3.14159;
        
};

struct Node2{
        int ag = 10;
        double gp = 3.14159;
        bool islegal = true;

};

int main(){

        std::cout << "Normal struct: " << sizeof(Node) << "\n";
        std::cout << "Optimized struct: " << sizeof(Node2) << "\n";


        std::bitset<8> bits { 0b0000'0101 };
        bits.set(3); //sets the 3rd bit to 1
        bits.flip(4); //flips the bit at the 4th position
        bits.reset(4); //turns the bit at the 4th position off


        std::cout << "Bits: " << bits << "\n";

        //testing
        std::cout << "5th position: " << bits.test(5) << "\n"; // returns 0 if off and 1 if on
        std::cout << "1st position: " << bits.test(0) << "\n";




        return 0;
}

/*
std::bitset functions:
        1. set() - turns a bit on..it does nothing if the bit is already on
        2. reset() - turns a bit off..it does nothing if the bit is already off
        3. test() - query whether a bit is on or off
        4. flip() - flips a bit value 1 to 0 and vice versa


*/