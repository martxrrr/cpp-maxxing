#include <iostream>
#include <cstdint>
#include <typeinfo>
#include <fstream>

typedef uint16_t u16;

enum class errorCodes : u16 {
        okay = 200,
        redirect = 300,
        notFound = 400 ,
        serverError = 500

};


int main(){

        errorCodes code = errorCodes::redirect;
        int test = static_cast<u16>(code);
        std::cout <<  typeid(test).name() << "\n";


        /*
        std::ofstream for WRITING TO A FILE
        If a file exists, std::ofstream ERASES it and overwrites it
        If the file doesn't exist, it is created
        */
       
        const std::string filename = "-testFile.txt";
        {
                std::ofstream file(filename);
                if(!file.is_open()){
                        std::cerr << "Error opening file : " << filename << "\n";
                        return -1;
                }

                file << "In my opinion the best way to move abroad, is to first finish my Comp Sci degree here in Kenya\n";
                file << "Maintain a very high transcript, and apply for masters\n";
                file << "Masters receive better financial aid from sponsors and you can also work \n since you have already finished your degree\n";
        }

        /*
        std::ifstream for READING FROM A FILE
        std::getline reads characters until it reaches the new line character '\n',
        it stores everything except the new line character into std::string line
        when the stream reaches End of File std::getline returns false and the while loop stops

        std::getline is used instead of '>>' because the >> operator stops at a whitespace
        which is almost not what I want
        */

        std::string anotherFile = "-csvFile.csv";

        {
                std::ifstream file(anotherFile);
                if(!file.is_open()){
                        std::cerr << "Error opening the file\n";
                        return -1;
                }

                std::string line;
                int lineCount = 1;
                while(std::getline(file, line)){
                        std::cout << line << "\n";
                        lineCount++;
                }
                std::cout << "The file has " << (lineCount - 1) << "lines\n";
        }

        /*
        MODES:
                std::ios::out - the default for std::ofstream
                std::ios::app - used with std::ofstream to append to the end of file
                std::ios::ate 
                std::ios::in - used with std::ifstream, it is the default for reading a file
                std::ios::binary - binary mode
        */

        std::string name_of_file = "csvFile.csv";
        {
                std::ofstream playersFile(name_of_file, std::ios::app);
                std::string morePlayers = "dewey,17,white";
                playersFile << "\n" << morePlayers ;
        }

        /*
        FILE STATUS CHECKS
        */
       const std::string playerFile = "csvFile.csv";
       {
                std::ofstream openFile(playerFile, std::ios::out);
                std::cout << "File is_open()" << openFile.is_open() << "\n"; //returns true if a file is open
                std::cout << "File good()" << openFile.good() << "\n"; //returns true if a file is good
                std::cout << "File bad()" << openFile.bad() << "\n"; //returns true if an irrecovarable I/O occured

                //others
                //eof(); //checks the end of file

       }



        return 0;
}