#include <iostream>
#include <filesystem>
#include <unordered_map>
#include <vector>
namespace fs = std::filesystem;

std::string calcHash(const std::string &fileName);
void findDuplicate(std::unordered_multimap<uintmax_t, std::string> &sizeMap);

int main(){

    std::unordered_multimap<uintmax_t, std::string> sizeMap;
    fs::path targetDir("/home/martin/Documents");


    try{
        for(const auto& entry : fs::recursive_directory_iterator(targetDir)){
            if(entry.is_regular_file()){
                sizeMap.emplace(fs::file_size(entry), entry.path().filename());
            }
        }
    }
    catch(const fs::filesystem_error &error){
        std::cout << error.what() << std::endl;
    }


    return 0;
}



void findDuplicate(std::unordered_multimap<uintmax_t, std::string> &sizeMap){

    std::unordered_multimap<std::string, std::string> hashMap;

}