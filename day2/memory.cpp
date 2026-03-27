//STACK VS HEAP MEMORY
//STACK - memory from where declaration of variables and functions is allocated from
//        safer, automatic deallocation of memory, temporary allocation coz it freed after program runs, faster coz it happens automatically

//HEAP - memory from where we perform dynamic memory allocation
//       less safe, slower, larger, manual deallocation, accessed by multiple threads

//dynamic memory allocation - useful when size of required memory is not known at compile time
#include <iostream>
#include <memory>
class Car{
public:
    std::string name;
    void print(){
        std::cout << "This is a " << name << std::endl;
    }
    Car(std::string name){
        this->name = name;
    }
};


int main(){
    
    int *array = new int[5]; //dynamic memory allocation for arrays
    array[0] = 12;
    array[1] = 13;
    array[2] = 14;
    for(int i = 0; i < 3; i++){
        std::cout << array[i] << std::endl;
    }
    delete[] array; //manually free the memory to avoid memory leaks

    //use case
    int sub;
    std::cout << "How many subjects do you study: ";
    std::cin >> sub;
    int *grades = new int[sub]; //allocate memory for the array during runtime
    std::cout << "Enter your grades\n ";
    for(int i = 0; i < sub; i++){
        std::cout << ">>";
        std::cin >> grades[i];
    }

    for(int i = 0; i < sub; i++){
        std::cout << grades[i] <<  " ";
    }
    delete[] grades;

    //memory leaks
    int* newPtr = new int(10);

    newPtr = new int(20); //allocated another memory, with the same ptr name while still having another memory
    delete newPtr; //freeing one of the memory while leaving the other one hanging and no way to access it

    //memory allocation and classes
    Car *car1 = new Car("Volkswagen");
    car1->print();
    
    (*car1).name = "Mercedes Benz";
    (*car1).print();
    
    //arrow funcions
    car1->name = "Bayerische Motoren Werke";
    car1->print();

    //memory not enough?
    try{
        double *bigArray = new double[99999999999999]; //a ridiculously large number :)
    }
    catch(std::bad_alloc& error){ //catching the std::bad_alloc error which comes up when memory allocation fails
        std::cout << "Bad allocation happened " << error.what() << std::endl;
    }

    //alternative of above
    double *veryBig = new(std::nothrow) double[99999999999999]; //do not throw an error, just return null if the process fails
    if(veryBig == NULL){
        std::cout << "Even worse brochacho!" << std::endl;
    }else{
        std::cout << "Memory allocated successfully" << std::endl;
    }

    return 0;
}