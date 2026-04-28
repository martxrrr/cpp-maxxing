//CONSOLE BASED LIBRARY SIMULATOR IN C++
#include <iostream>
#include <fstream>
#include <cctype>
#include "assets/json.hpp"
using json = nlohmann::json;

class mainLibrary{
    public:
    std::string name;

    mainLibrary(){
        std::string text1 = R"(
              _                          
__      _____| | ___ ___  _ __ ___   ___ 
\ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \
 \ V  V /  __/ | (_| (_) | | | | | |  __/
  \_/\_/ \___|_|\___\___/|_| |_| |_|\___|
        )";
        std::string text2 = R"-(
 _        
| |_ ___  
| __/ _ \
| || (_) |
 \__\___/ 
        )-";
        std::string text3 = R"(
     _ _  ___   _   _  _____ 
    | | |/ / | | | / \|_   _|
 _  | | ' /| | | |/ _ \ | |  
| |_| | . \| |_| / ___ \| |  
 \___/|_|\_\\___/_/   \_\_|  
        )";
        std::string text4 = R"(
 _ _ _                          
| (_) |__  _ __ __ _ _ __ _   _ 
| | | '_ \| '__/ _` | '__| | | |
| | | |_) | | | (_| | |  | |_| |
|_|_|_.__/|_|  \__,_|_|   \__, |
                          |___/  
        )";

        std::cout << text1 << std::endl << text2 << std::endl << text3 << std::endl << text4 << std::endl;
     }

    void showMenu(){
        std::cout << "1. View available books.\n2. Borrow a book\n3. Return a book\n4. Add a book to the collection\n5. Exit the program" << std::endl;
    }
    void showBooks(){

        std::ifstream booksFile("/home/martin/programming/MAIN/C++/projects/library/assets/books.json");
        if(!booksFile.is_open()){
            std::cout << "Error opening the file! " << std::endl;
        }

        json booksJson;
        booksFile >> booksJson;

        std::cout << "\nBooks Available " << std::endl;
        std::cout << "___________________" << std::endl;
        for(auto& book : booksJson){
            std::string bookName = book["title"];
            std::string auth = book["author"];
            int id = book["ID"];
            std::cout <<  bookName << "  by  " <<  auth << "    (ID: " << id  << ")" << std::endl;
        }

    }
    void addBook(){
        std::string author, title;
        int releaseYear, bookID;

        std::cout << "Enter the following details of the book you want to add: " << std::endl;

        std::cout << "Book ID: ";
        std::cin >>  bookID;

        std::cout << "Book title: ";
        std::getline(std::cin >> std::ws, title);

        std::cout << "Book author: ";
        std::getline(std::cin >> std::ws, author);

        std::cout << "Release year: ";
        std::cin >>  releaseYear;

        nlohmann::json newBook;

        newBook["ID"] = bookID;
        newBook["title"] = title;
        newBook["author"] = author;
        newBook["releaseYear"] = releaseYear;

        json booksJson;
        std::ifstream booksFile("/home/martin/programming/MAIN/C++/projects/library/assets/books.json");
        if(booksFile.is_open() && booksFile.peek() != std::ifstream::traits_type::eof()){
            booksFile >> booksJson;
        }else{
            booksJson = json::array();
        }
        booksJson.push_back(newBook);
        std::ofstream newbooksFile("/home/martin/programming/MAIN/C++/projects/library/assets/books.json");
        newbooksFile << booksJson.dump(4);

        std::cout << "Book added successfully!";
    }
    void borrowBook(){
        json newStudentsJson;

        std::string name;
        int studentID, bookID;

        std::cout << "Enter your name: ";
        std::getline(std::cin >> std::ws, name);
        std::cout << "The book's ID: ";
        std::cin >> bookID;
        std::cout << "Your school ID: ";
        std::cin >> studentID;

        json booksJson;
        std::ifstream booksFile("/home/martin/programming/MAIN/C++/projects/library/assets/books.json");
        if(booksFile.is_open()){
            booksFile >> booksJson;
        }else{
            std::cerr << "Error opening the file! " << std::endl;
        }
        for(auto& book : booksJson){
            if(bookID == book["ID"]){
                if(book["borrowed"] == false){

                    newStudentsJson["name"] = name;
                    newStudentsJson["libraryStatus"]["booksOwing"] = bookID;
                    newStudentsJson["schoolID"] = studentID;

                    std::ifstream studentsFile("/home/martin/programming/MAIN/C++/projects/library/assets/studentsData.json");
                    json studentJson;
                    if(studentsFile.is_open() && studentsFile.peek() != std::ifstream::traits_type::eof()){
                        studentsFile >> studentJson;
                    }else{
                        studentJson = json::array();
                    }
                    studentsFile.close();

                    studentJson.push_back(newStudentsJson); //append
                    std::ofstream newBooksFile("/home/martin/programming/MAIN/C++/projects/library/assets/studentsData.json"); //overwrite
                    newBooksFile << studentJson.dump(4);

                    std::cout << "\n" <<book["title"] << " LENT SUCCESSFULLY TO " << name << std::endl;
                    
                    book["borrowed"] == true;

                }else if(book["borrowed"] == true){
                    std::cout << "The book is already borrowed! " << std::endl;
                }else{
                    std::cerr << "Error in loading the file! " << std::endl;
                }
            }
        }

    }
    void exitProgram(){
        std::string text1 = R"-(
 _____ _                 _                        _ 
|_   _| |__   __ _ _ __ | | __  _   _  ___  _   _| |
  | | | '_ \ / _` | '_ \| |/ / | | | |/ _ \| | | | |
  | | | | | | (_| | | | |   <  | |_| | (_) | |_| |_|
  |_| |_| |_|\__,_|_| |_|_|\_\  \__, |\___/ \__,_(_)
                                |___/               
        )-";
        std::string text2 = R"(
  __            
 / _| ___  _ __ 
| |_ / _ \| '__|
|  _| (_) | |   
|_|  \___/|_|   
              
        )";
        std::string text3 = R"-(
       _     _ _   _                         _ 
__   _(_)___(_) |_(_)_ __   __ _   _   _ ___| |
\ \ / / / __| | __| | '_ \ / _` | | | | / __| |
 \ V /| \__ \ | |_| | | | | (_| | | |_| \__ \_|
  \_/ |_|___/_|\__|_|_| |_|\__, |  \__,_|___(_)
                           |___/               
        )-";

        std::cout << text1 << std::endl << text2 << std::endl << text3 << std::endl;
    }
};

int main(){
    int userChoice;

    mainLibrary lib;

    lib.showMenu();
    
    do{
        std::cout << std::endl;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> userChoice;

        switch(userChoice){
            case 1:
                lib.showBooks();
                break;
            case 2:
                lib.borrowBook();
                break;
            case 3:
                std::cout << "You chose to return a book!" << std::endl;
                break;
            case 4:
                lib.addBook();
                break;
            case 5:
                std::cout << "Exiting the program..." << std::endl;
                lib.exitProgram();
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                break;
        }
    }while(userChoice != 5);

    return 0;
}