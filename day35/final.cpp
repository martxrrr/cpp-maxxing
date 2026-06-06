/*
destructors and friend functions
*/

#include <iostream>

class Teacher{
private:
	int age = 21;
	std::string location = "Witeithie";
public:
	std::string subject;
	char grade;

	Teacher(std::string sub, char grade) : subject(sub), grade(grade) {}

	void PrintInfo(){
		std::cout << "I teach " << subject << "\n";
		std::cout << "I attained grade " << grade << "\n";
		std::cout << "I am " << age << " years old!" << "\n";
		std::cout << "I live in " << location << "\n";
	}
};


int main(){

	Teacher kevin("Maths", 'A');
	kevin.PrintInfo();


	return 0;
}