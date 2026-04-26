#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <vector>
#include <openssl/evp.h>

namespace fs = std::filesystem;

std::string calcHash(const std::string &fileName);
void findDuplicate(std::unordered_multimap<uintmax_t, std::string> &sizeMap);

int main(){
    std::cout << "DUPLICATE FILE FINDER" << "\n";

    std::unordered_multimap<uintmax_t, std::string> sizeMap;
    fs::path targetDir("/home/martin/Documents/csFiles");


    try{
        for(const auto& entry : fs::recursive_directory_iterator(targetDir)){
            if(entry.is_regular_file()){
                sizeMap.emplace(fs::file_size(entry), entry.path());
            }
        }
    }
    catch(const fs::filesystem_error &error){
        std::cout << error.what() << std::endl;
    }

    findDuplicate(sizeMap);


    return 0;
}

std::string calcHash(const std::string &fileName){
    EVP_MD_CTX* contx = EVP_MD_CTX_new();
    unsigned char hash[EVP_MAX_MD_SIZE];
    const EVP_MD *alg = EVP_sha256();
    unsigned int hashLen = 0;
    EVP_DigestInit_ex(contx, alg, nullptr);
    
    std::ifstream file(fileName, std::ios::binary);
    if(!file){std::cout << "File not found!" << std::endl;}

    char buffer[4096];
    while(file.read(buffer, sizeof(buffer)) || file.gcount() > 0){
        EVP_DigestUpdate(contx, buffer, file.gcount()); //digest the file in chunks of 4KB
    }

    EVP_DigestFinal_ex(contx, hash, &hashLen);

    EVP_MD_CTX_free(contx);

    //convert to hex
    char hex[hashLen * 2+ 1];
    for(unsigned int i = 1; i < hashLen; i++){
        sprintf(&hex[i * 2], "%02x", hash[i]);
    }

    return std::string(hex);

}


void findDuplicate(std::unordered_multimap<uintmax_t, std::string> &sizeMap){

    std::unordered_multimap<std::string, std::string> hashMap;

    for(auto iter = sizeMap.begin(); iter != sizeMap.end(); ++iter){
        const int key = iter->first;
        auto range = sizeMap.equal_range(key);

        if(range.first != range.second){ //check if the key actually exists
            if(std::next(range.first) == range.second){
                continue;
            }
            else{
                for(auto rangeIter = range.first; rangeIter != range.second; ++rangeIter){
                    std::string hash = calcHash(rangeIter->second);
                    hashMap.emplace(hash, rangeIter->second);
                }
            }
        }
    }

    //print the duplicates
    for(auto dup = hashMap.begin(); dup != hashMap.end(); ++dup){
        const std::string key = dup->first;
        auto range = hashMap.equal_range(key);

        for(auto iter = range.first ; iter != range.second; ++iter){
            std::cout << "[DUPLICATE]" << range.first->second << "\n";
        }
    }
    

}