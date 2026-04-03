//I learnt that working with larger projects, you may need to split you code into different files and call them in the main file
//That is what I decided to take a look at today, then continue with SFML later

//Header files - contains declarations e.g function prtotypes, class definitions, global  constants
//have a .h or .hpp 

//Header guards - used in the header files to make sure the header files are only included once
//including more than once may cause errors

#include <iostream> //This is what I am talking about, these include files
#include "area.hpp"

int main(){

    Area area;
    std::cout << "Area of a Circle: " << area.Circle(23) << std::endl;
    std::cout << "Area of a Triangle: " << area.Triangle(10, 15) << std::endl;
    std::cout << "Area of a Square: " << area.Square(20) << std::endl;
    std::cout << "Area of a Rectangle: " << area.Rectangle(12, 90) << std::endl;

    return 0;
}