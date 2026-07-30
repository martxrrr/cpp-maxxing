#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
  
int main(){
    

    //constructing paths with operator "/"
    fs::path base = "/home/martin";
    fs::path fullPath = base / "Downloads" / "music" / "song.mp3";

    std::cout << "Full path : " << fullPath << "\n";                // parent + filename
    std::cout << "Parent : " << fullPath.parent_path() << "\n";     // /home/martin/Downloads/music
    std::cout << "File name : " << fullPath.filename() << "\n";     //song.mp3
    std::cout << "Stem : " << fullPath.stem() << "\n";              //song
    std::cout << "Extension : " << fullPath.extension() << "\n";    //.mp3 
    

    //replace file extension
    fs::path backup = fullPath;
    backup.replace_extension(".mp4");
    std::cout << backup << "\n";

    //creating pathsa
    fs::path rel = fs::path("src") / "module_01" / "main.cpp";
    std::cout << rel << "\n";

    fs::path customPath = fs::path("/home/martin/Videos/music");
    std::cout << customPath << "\n";
    
    std::cout << (fs::exists(customPath) ? "Directory Found " : "Directory not Found") << "\n";

    //create a temporary directory path
    fs::path testDir = fs::temp_directory_path() / "test_directory";
    if(fs::exists(testDir)){
        std::cout << "Temporary Directory Successfully created " << "\n";
        
        //remove a directory
        fs::remove_all(testDir);
    }
    if(!fs::exists(testDir)){
            std::cout << "Directory Removed Successfully " << "\n";
    }

    //creating directories recursively (mkdir -p)
    fs::create_directories(testDir / "level_one" / "level_two");
  
    //check existence and type
    std::cout << "testDir exists ? " << (fs::exists(testDir) ? "Yes" : "No") << std::endl;
    std::cout << "testDir is a directory ? " << (fs::is_directory(testDir) ? "Yes" : "No") << std::endl;
    std::cout << "testDir is a regular file ? " << (fs::is_regular_file(testDir) ? "Yes" : "No") << std::endl;
    

    //file size in bytes
    fs::path file = "/home/martin/Downloads/backup.txt";
    std::cout << "File size : " << fs::file_size(file) << " bytes" << std::endl;
 
    //directory iteration
    fs::path dir = "/home/martin/Documents";
    for(const auto& entry : fs::directory_iterator(dir)){
        std::cout << "    " << (entry.is_directory() ? "[DIR]" : "[FILE]") << " " << entry.path().filename().string() << "\n";
    }

    //copying file
    fs::path src = "/home/martin/Downloads/backup.txt";
    fs::path dest = "/home/martin/Downloads/backup1.txt";
    fs::copy_file(src, dest);
    if(fs::is_regular_file(dest)){
      std::cout << "File copied successfully!" << std::endl;
    }

    //renaming a file
    fs::path oldName = "/home/martin/Downloads/backup1.txt";
    fs::path newName = "/home/martin/Downloads/backup2.txt";
    fs::rename(oldName, newName);
    
    
    return 0;
}
