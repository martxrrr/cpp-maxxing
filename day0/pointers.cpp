//DAY 0 of learning c++ (I already know the basic stuff like variable, arrays and loops)
//pointer - a special variable that holds the memory address of another variable

#include <iostream>
#include <typeinfo>

int main(){
    
    int x{5}; 
    int* pNum{&x}; //pointer
    int& ref{x}; //reference (it's like a nickname for a variable)

    ref = 6;
    std::cout << typeid(&x).name() << std::endl;

    //size of pointers
    int* age{};
    float* salary{};

    std::cout << sizeof(age) << std::endl;;
    std::cout << sizeof(salary) << std::endl;
    //all prints out 8 (because I am using a 64-bit computer(8-bytes))


    //null pointers 
    char* grade{ nullptr };

    // std::cout << *grade << std::endl; //segmentation fault (dereferencing a null pointer)
    if(grade == nullptr){
        std::cout << "This is a null pointer" << std::endl;
    }else{
        std::cout << "Pointer pointing to a valid address" << std::endl;
    }

    //pointers and const values

    int z{12};
    //read-only pointer (can not change the address where the pointer is pointing to)
    int* const zPtr{&z};

    //pointer to a read-only value
    const int w{5};
    const int q{23};
    const int* wPtr = &w;
    wPtr = &q; 

    //const pointer to a const value - (neither the value nor the pointer can change)
    const int p{21};
    const int const *pPtr{&p};
    
    //void pointer - data type pointing to is not specifies
    int shoeSize = 39;
    void* shoePtr{&shoeSize};
    std::cout << *shoePtr << std::endl; //causes error - can't be dereferenced

    return 0;
}