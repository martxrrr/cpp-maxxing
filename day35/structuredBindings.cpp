//Structured-bindings
//Allows you to unpack objects into individual variables

struct Player{
	std::string name;
	int health;
	double maxStrength;
};

#include <iostream>
#include <map>

int main(){


	//unpacking tuples and pairs
	std::map<std::string, int> info = {{"Martin", 19}};

	auto[iterator, success] = info.insert({"Bob", 21});


	//unpacking arrays
	double coords[3] = {4.1, 6.7, 6.9};
	auto[x, y, z] = coords;

	std::cout << "X: " << x << "\n";
	std::cout << "Y: " << y << "\n";
	std::cout << "Z: " << z << "\n";

	//unpacking structs
	Player villain = {"Hulk", 100, 67.67};
	auto[name, health, maxStrength] = villain; // name = Hulk, health = 100, maxStrength = 67.67

	//implementing it the way I have above, it is creating copies of the elements
	//other ways

	//creates const copies
	Player hero = {"Superman", 101, 10000};
	const auto[name, health, maxStrength] = hero;

	//creates referennces to the original objects
	Player neutral = {"Green Lantern", 98, 1000};
	auto&[name, health, maxStrength] = neutral;

	//creates const references to the original objects
	Player ngga = {"Batman", 99, 1200};
	const auto&[name, health, maxStrength] = ngga;


	//looping through items
	std::map<int, double> studentInfo = {{24001, 80}};
	studentInfo.emplace_back(24002, 81);
	studentInfo.emplace_back(24003, 78);
	studentInfo.emplace_back(24004, 71);

	for(const auto& [studentID, points] : studentInfo){
		std::cout << "ADM: " << studentID << " GRADE: " << points << std::endl;
	}


	return 0;
}

//RULES
/*
You must provide full name for the elements in the objects
The number of identifiers in the bracket must be equal to the number of elements in the the object
Structured-bindings are resolved at compile time

*/