#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;
int main(){

    //bit shift right (>>)
    unsigned int a = 4;
    a >>= 2; //divides(integer division, no remainders) the number by 2^n, where n is the number of places specified
    cout << "Right shift: " << a << endl;

    //bits shift left (<<)
    unsigned int b = 5;
    b <<= 3; //multiplies the number by 2^n, where n is the number of places specified
    cout << "Left shift: " << b << endl;

    //&(and)
    unsigned int c = 10; // 0000 1010
    unsigned int d = 12; // 0000 1100
    int res = c & d;     // 0000 1000
    cout << "c & d: " << res << endl;

    // |(or)
    unsigned int e = 24; //0001 1000
    unsigned int f = 35; //0010 0011
    int results = e | f; //0011 1011
    cout << "e | f: " << results << endl;

    // ~(not)
    unsigned int g = 37; // 0010 0101
    unsigned int h = ~g; // 1101 1010
    cout << "~g: " << h << endl;

    //^ (xor)
    unsigned int i = 27;// 0001 1011
    unsigned int j = 67;// 0100 0011
    int k = i ^ j;      // 0101 1000 =
    cout << "i ^ j: " << k << endl;



    return 0;
}

/*
 * bitwise operators
 * & (and) - becomes 1 when both are 1, otherwise it gives out 0
 * | (or) - becomes 1 when either of the bits is 1, otherwise it gives out 0 i.e only 0 when both are 0
 * ~ (not) - it flips the bits, 0 becomes 1 and 1 becomes 0
 * ^ (xor) - becomes 1 when the bits are different, otherwise it gives out 0
 * >> (shift right) - shifts the bits to the right the specified number of positions
 * << (shift left) - shifts the bits to the left the specified number of positions
 */
