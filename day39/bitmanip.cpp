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



        [[maybe_unused]] constexpr int ishungry      { 0 };
        [[maybe_unused]] constexpr int ishappy       { 1 };
        [[maybe_unused]] constexpr int isavailable   { 2 };
        [[maybe_unused]] constexpr int issuccessful  { 3 };
        [[maybe_unused]] constexpr int isgay         { 4 };
        [[maybe_unused]] constexpr int isblack       { 5 };
        [[maybe_unused]] constexpr int isbeautiful   { 6 };
        [[maybe_unused]] constexpr int issleeping    { 7 };

        std::bitset<8> mood { 0b000'0000 };
        mood.set(ishappy);
        mood.set(isbeautiful);
        mood.set(isgay);
        mood.set(issuccessful);

        std::cout << ((mood.test(ishappy)) ? "Happy Boy" : "Sad Boy") << "\n";
        std::cout << ((mood.test(isbeautiful)) ? "Beautiful boy" : "Not a beautiful boy") << "\n";
        std::cout << ((mood.test(isgay)) ? "He's a true gay man" : "Straight boy") << "\n";

        mood.flip(issuccessful);
        std::cout << ((mood.test(issuccessful)) ? "A happy, beautiful, successful gay man" : "He's a broke aaahh") << "\n";
        

        std::cout << mood.size() << "\n";
        std::cout << mood.count() << "\n";      
        std::cout << ((mood.all()) ? "All bits are true" : "Not all bits are true") << "\n";
        std::cout << ((mood.any()) ? "At least one bit is true" : "No bit is true") << "\n";
        std::cout << ((mood.none()) ? "All bits are false" : "Not all bits are false") << "\n";


        //variable initialization
        //the maybe unused tells the compiler that we have decalred and initialized a variable and we may not use it
        //since some compilers generate errors when a variable is declared but not used, this prevents
        //the compiler from coming up with such errors
        [[maybe_unused]] constexpr double pi { 3.141592625 };

        std::cout << sizeof(size_t) << "\n";

        std::bitset<2> random { 0b00 };
        std::cout << sizeof(random) << "\n";




        return 0;
}

/*
std::bitset functions:
        1. set() - turns a bit on..it does nothing if the bit is already on
        2. reset() - turns a bit off..it does nothing if the bit is already off
        3. test() - query whether a bit is on or off
        4. flip() - flips a bit value 1 to 0 and vice versa
std::bitset is optimized for speed not memory savings, because the size of std::bitset is the number of bytes needed to hold the bits
            rounded up to the nearest 4-bytes (on 32-bit systems) or 8-bytes(on 64-bit systems)

*/