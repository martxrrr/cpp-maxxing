#include <iostream>

class Student{
private:
    int age;
    int gangsterPoints;
    int grade;

public:
    Student(int miaka, int gp, int grade) : age(miaka), gangsterPoints(gp), grade(grade) {}
    void PrintInfo();

    void showDanger(){
        int dangerLevel = age * gangsterPoints;
        std::cout << "Danger Level: " << dangerLevel << "\n";
    }
    void changeDetails(Student &student){
        student.grade += 10;
        student.age += 10;
        student.gangsterPoints += 10;
        std::cout << "Change by value: " << "\n";
        std::cout << "Age: " << student.age << "\n";
        std::cout << "Gangster Points: " << student.gangsterPoints << "\n";
        std::cout << "Grade: " << student.grade << "\n";
    }

};

void Student::PrintInfo(){
        std::cout << "Age: " << age << "\n";
        std::cout << "Gangster Points: " << gangsterPoints << "\n";
        std::cout << "Grade: " << grade << "\n";
    }

void class1(){
    Student martin(19, 3, 90);

    martin.PrintInfo();
    std::cout << std::endl;

    martin.changeDetails(martin);
    std::cout << std::endl;

    martin.PrintInfo();

    std::cout << std::endl;
}



class Animal{
public:
    std::string talk;
    int legs;

    Animal(){
        this->talk = "meow";
        this->legs = 4;
    }

    Animal(Animal animal){
        talk = animal.talk;
        legs = animal.legs;
    }

};


int main(){

    Animal cat;
    std::cout << cat.talk << "\n";
    std::cout << cat.legs << "\n";

    Animal snake(cat);
    std::cout << snake.talk << "\n";
    std::cout << snake.legs << "\n";

    

    return 0;
}

/*

Animal(std::string language, int legs){
        this->talk = language;
        this->legs = legs;
    }


public - same class, derived classes, outside classes
private - same class only, not outside, not derived classes
protected - same class, derived class, not outside
Attribute - A property of object, it cannot exist independently of the object
A method is a service that can be requested from any object of the Class to affect behavior


Constructor - a special member function that initializes the data members of the class
              it has the same name as the class
              has no return type
              invoked automatically whenever a new object is created
              cannot be inherited
              cannot be virtual


Types of constructors:
    1. Default contructor - takes no parameters
    2. Parametized constructors - takes params when declared and arguments when an object is being created
    3. Copy Constructors - takes another object as a constructor
    

*/