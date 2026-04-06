//A little project on dynamic memory allocation of arrays
//just a small one coz I had a busy week, from tomorrow we gotta go back to work as usual and lock in 😤
#include <iostream>
#include <string>

class Student{
    public:
    std::string name;
    int age;
    Student(std::string name, int age){
        this->age = age;
        this->name = name;
    }
    void display(){
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "-----------------------------------";
    }
};

int main(){
    int count;
    std::cout << "Enter the number of students to record: ";
    std::cin >> count;
    Student* studentList = (Student*) operator new[](count * sizeof(Student));

    for(int i = 0; i < count; i++){
        std::string name;
        int age;

        std::cout << "Enter student's name: ";
        std::cin >> name;
        std::cout << "Enter student's age: ";
        std::cin >> age;

        new(&studentList[i]) Student(name, age);
    }
    std::cout << "=====================================" << std::endl;
    std::cout << "       STUDENT DATABASE              " << std::endl;
    std::cout << "=====================================" << std::endl;

    for(int i = 0; i < count; i++){
        studentList[i].display();
    }
    delete[] studentList;

    return 0;
}