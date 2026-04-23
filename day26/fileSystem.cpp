#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(){
    fs::path targetDir("/home/martin/programming/MAIN/PYTHON1/Face Recognition/files/Ana.jpeg");
    fs::path target2("/home/martin/programming/MAIN/PYTHON1/Face Recognition/files");

    //check if a path exists and if it is a regular file
    if(fs::exists(targetDir) && fs::is_regular_file(targetDir)){ 
        std::cout << targetDir.stem().string() << "\n"; //file name wothout extension
        std::cout << targetDir.extension().string() << "\n"; //extension e.g .jpeg, .webp, .mp3, .mp4
        std::cout << targetDir.filename().string() << "\n"; //file full name
    }

    //check whether a path is a directory and if it exists
    if(fs::is_directory(target2) && fs::exists(target2)){
        std::cout << "Shii is a directory!" << std::endl;
    }

    //check the file size in bytes
    uintmax_t size = fs::file_size(targetDir);
    std::cout << size << std::endl;

    //creating directory/directories
    fs::path target3("/home/martin/programming/MAIN/C++/dsa");
    fs::create_directories("/home/martin/programming/MAIN/C++/dsa/trees/test");
    fs::create_directory();

    //copying a file or directory
    try{
        fs::copy_file("/home/martin/programming/MAIN/PYTHON1/Face Recognition/files/Ana.jpeg", 
                 "/home/martin/programming/MAIN/C++/dsa/Ana.jpeg",
                fs::copy_options::overwrite_existing
            ); //note some copy options, overwriting and copying recursively i.e fs::copy_options::recursive

        std::cout << "File copied successfully!" << std::endl;
    }
    catch(const std::exception& error){ std::cerr << "Error: " << error.what() << std::endl;}

    //move or rename a file (depending on the usage)
    fs::rename("/home/martin/programming/MAIN/PYTHON1/Face Recognition/files/Ana.jpeg",
               "/home/martin/programming/MAIN/PYTHON1/Face Recognition/files/Ana-de-Armas.jpeg");

    std::cout << fs::current_path() << std::endl; //current dir

    //looping through a directory
    try{
        for(const auto&entry : fs::recursive_directory_iterator("/home/martin/programming/MAIN/PYTHON1/Face Recognition")){
            if(entry.is_regular_file()){
                std::cout << entry.path().filename() << std::endl;
            }else if(entry.is_directory()){
                std::cout << "DIR: " << entry.path().filename() << std::endl;
            }
        }
    }catch(const std::exception& error){ std::cout << error.what() << std::endl;}

    return 0;
}