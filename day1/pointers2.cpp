//MORE ABOUT POINTERS
#include <iostream>

void helloWorld(std::string name){
    std::cout << "Hello " << name << std::endl;
}

bool epsteinFunction(int age){
    if(age < 18 && age > 0){
        std::cout << "perfect age! welcome to Epstein's Island!" << std::endl;
        return true;
    }else if(age >= 18 && age <= 100){
        std::cout << "This sh!t is expired pal! " << std::endl;
        return false;
    }else{
        std::cout << "What the fuck is this age bro! " << std::endl;
        return false;
    }
}

//======================================================================
// PASSING A POINTER TO A FUNCTION AS A PARAMETER TO ANOTHER FUNCTION //
//======================================================================

int product(int a, int b){
    return a * b;
}
void printAns(int x, int y, int(*prodPointer)(int, int)){
    int result = prodPointer(x, y);
    std::cout << "Answer: " << result << std::endl;
}

int main(){
    //void pointers
    int x{5};
    void* ptrX = &x;

    std::cout << *(static_cast<int*>(ptrX)) << std::endl; //you have to type cast a void pointer

    //pointer arithmetic
    //increment, decrement - naviagating through memory addresses
    float j{5};
    float* ptrJ = &j;
    std::cout << "floating point number: " <<sizeof(float) << std::endl;
    std::cout << "Before: " <<ptrJ << std::endl;
    ptrJ+=(5 * sizeof(float)); //pointer moves through 5 times the size of float
    std::cout << "After: " << ptrJ << std::endl;

    //double pointers (pointer to another pointer)
    int var = 10;
    int* ptr1 = &var;
    int** ptr2 = &ptr1; //**

    std::cout << ptr1 << "\n";
    std::cout << ptr2 << "\n";
    std::cout << *ptr1 << "\n";
    std::cout << **ptr2 << "\n"; //dereference

    //pointers to functions
    void(*funcPtr)(std::string);
    funcPtr = helloWorld; //returnType(*pointerName)(paramType)
    (*funcPtr)("Martin"); 

    bool(*epstein)(int) = epsteinFunction; //invoking a function using the pointer name
    epstein(14);

    printAns(12, 12, product);

    return 0;
}