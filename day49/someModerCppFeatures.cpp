#include <iostream>
#include <typeinfo>
#include <optional>
#include <variant>
#include <map>

//How to securely handle "Data Not Found" without MAGIC NUMBERS
std::optional<int> findAgeByName(const std::string &name){
	if(name == "Martin"){
		return 20;
	}else if(name == "Sharline"){
		return 19;
	}

	else{
		//Instead of -1, we return 'nullopt' (no value)!
		return std::nullopt;
	}
}

//STRUCTURED BINDINGS
std::map<std::string, double> getStudentScores(){
	return {
		{"Martin", 90.0},
		{"Wycliffe", 95.0},
		{"Sharline", 60.0},
		{"Natalie", 83.0},
		{"Alvin", 99.0}
	};
}


void printStudentScores(const std::map<std::string, double> &scoreMap){
	std::cout << "========= [STUDENT SCORES] =========\n";
	for(const auto&[name, score] : scoreMap){
		std::cout << name << " -> " << score << "\n";
	}
}

int main(){

	auto x = {1, 2, 3, 4, 5};
	std::cout << typeid(x).name() << std::endl;

	auto age = findAgeByName("Martin");
	if(age.has_value()){
		std::cout << "Age : " << age.value() << std::endl;
	}else{
		// std::cout << "PERSON DOES NOT EXIST!\n";
		std::cout << "Age : " << age.value() << std::endl;
	}

	std::variant<int, std::string> diagnosticResult;
	diagnosticResult = 300;
	std::cout << "Result : " << std::get<int>(diagnosticResult) << "\n";

	diagnosticResult = "Very Good";
	std::cout << "Result : " << std::get<std::string>(diagnosticResult) << "\n";

	auto studentScores = getStudentScores();
	printStudentScores(studentScores);

	return 0;
}
