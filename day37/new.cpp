#include <iostream>
#include <array>
#include <string>
#include <cstdint>

enum class State : uint32_t{
	Okay = 200,
	Redirect = 300,
	Not_found = 400,
	Server_error = 500

};

enum Codes{
	okay = 200,
	redirect = 300,
	notFound = 400,
	server = 500
};

int main(){

	for(int i{}; i < 5; ++i){
		std::cout << "Hello world\n";
	}

	if(double voltage{ 10 }; voltage < 0){ //only exists in the scope of the if statement
		std::cout << "What the fucka!\n";
	}else if(voltage > 5){
		std::cout << "It is actually working!\n";
	}else{
		std::cout << "Still working\n";
	}

	// std::cout << std::endl;
	// std::cout << voltage << "\n";	
	int count { 0 };
	int limit { 3 };
	do{
		std::string info { "Martin is great!" };
		std::cout << info << "\n";
		count++;
	}while(count < limit);

	for(int j { 0 }; j <= 20; ++j){
		if(j % 2 == 0){
			continue;
		}else{
			std::cout << j << " ";
		}
	}
	std::cout << "\n";

	std::string names[] = {"Martin", "Fruhler", "Stiller", "Damian", "Niggolas"};
	for(const auto& name : names){
		std::cout << name << " ";
	}
	std::cout << "\n";

	std::string text = "Hello";
	text.append("World");
	std::cout << text << "\n";

	std::string text2 = "Nigga";
	if(!text2.empty()){
		std::cout << "Shii is not empty!\n";
	}else{
		std::cout << "Add some text twin!\n";
	}

	std::array<double, 4> constants = {3.145, 9.178, 43.243, 53.526};
	for(const double& constant : constants){
		std::cout << constant << " ";
	}
	std::cout << std::endl;

	Codes code = server;
	int anotherCode = code;
	std::cout << code << "\n";
	std::cout << anotherCode << "\n";

	auto currState = static_cast<uint32_t>(State::Redirect);
	std::cout << currState << "\n";


	return 0;
}