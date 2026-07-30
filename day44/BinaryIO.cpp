#include <iostream>
#include <cstdint>
#include <iomanip>


#pragma pack(push, 1) //packed struct for binary serialization
struct sensoRecord{

    uint32_t sensorID;
    float temperature;
    float pressure;
    uint64_t timestamp;
};
#pragma pack(pop)


int main(){



    return 0;
}


/*
 Binary I/O in C++ reads and writes raw memory bytes directly to and from a storage target without applying text transformations or formatting.

 reinterpret_cast is a low-level C++ cast operator that reinterprets the underlying bit pattern of an object as a different type without changing the data itself.  
 It primarily serves as a compile-time directive that instructs the compiler to treat an expression as if it had a different type, 
 often bypassing standard type safety checks. 
 Mostly used in Binary file I/O, network packet parsing, hardware register access.

*/
