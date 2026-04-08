//I realised that I have never taken a look at c++ string manipulations and operations
//That is what I will learn today

#include <iostream>
typedef std::string string;
#include <string>

int main(){
    std::string firstName = "Martin ";
    std::string lastName = "Wainaina";

    //string concatenation
    string fullName1 = firstName + lastName;
    std::cout << fullName1 << std::endl;

    //append() - concatenates a string to the end
    string fullName2 = firstName.append(lastName);
    std::cout << fullName2 << std::endl;

    //numbers treated as strings because of the double-quotes
    string num1 = "1";
    string num2 = "2";
    std::cout << num1+num2 << std::endl;

    //getting the length of a sring
    string text = "Hello I am Martin, a passionate programmer!";
    std::cout << "Text length: " << text.size() << std::endl; 
    std::cout << "Text length: " << text.length() << std::endl;
    
    //accessing characters in a string 
    string myString = "Martin Gooner";
    std::cout << myString[myString.length() - 1] << std::endl;
    myString[0] = 'G';
    std::cout << myString << std::endl;

    //at() - get a character in a string at a certain index
    string myString2 = "Alexey Kutepov";
    std::cout << myString2.at(1) << std::endl;

    //special characters
    // string text2 = "The greatest footballer of all time "Lionel Messi" Retires at 40!"; //an error occurs while using multiple double quotes in the same string
    string text2 = "The greatest footballer of all time \"Lionel Messi\" Retires at 40!"; //inserting double quotes
    string text3 = "He is the most successful Ballon d'or winner \'8 ballon d'ors\'"; //inserting single quotes
    string text4 = "This is a \nnew line and a \t tab"; //new line and a tab
    std::cout << text2 << std::endl;
    std::cout << text3 << std::endl;
    std::cout << text4 << std::endl;

    //user-input strings
    string bro;
    std::cout << "Enter your name: ";
    std::cin >> bro;
    std::cout << bro << std::endl; // as you may realise std::cin reads a white space as a terminating
                                    // character i.e it doesn't read beyond white space
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    string yourInfo;                                
    std::cout << "Enter your personal info: ";
    std::getline(std::cin >> std::ws, yourInfo);
    std::cout << yourInfo << std::endl;

    string array[] = {"Martin", "Zoe", "Sandra"};
    
    for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++){
        std::cout << array[i] << " " << std::endl;
    }
    
    return 0;
}