/*
public - same class, derived classes, outside classes
private - same class only, not outside, not derived classes
protected - same class, derived class, not outside
Attribute - A property of object, it cannot exist independently of the object
A method is a service that can be requested from any object of the Class to affect behavior


*/


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

int main(){
    Student martin(19, 3, 90);

    martin.PrintInfo();
    std::cout << std::endl;

    martin.changeDetails(martin);
    std::cout << std::endl;

    martin.PrintInfo();

    std::cout << std::endl;

    return 0;
}