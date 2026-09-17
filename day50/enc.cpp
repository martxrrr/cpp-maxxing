#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include <cryptopp/sha.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
#include <cryptopp/cryptlib.h>

namespace fs = std::filesystem;

void deriveKey(const std::string& password, CryptoPP::SecByteBlock& key);

bool processFile(const std::string& inputFile, 
                 const std::string& outputFile, 
                 const std::string& password, 
                 bool encrypt);

int main(int argc, char* argv[]){

    const std::string myPassword = "_Martin42@";

    std::string dir        {};
    std::string password   {};
    std::string currentArg {};

    if(argc > 4 || argc < 4){
        std::cerr << "Invalid number of arguments!\n";
        return -1;
    }else{
        dir = argv[1];
        for(int i = 0; i < argc; i++){
            currentArg = argv[i];
            if(currentArg == "password"){
                password = argv[i + 1];
            }
        }
    }

    if(password == myPassword){
        fs::path targetDir(dir);
        fs::path encDir = "encDir";
        fs::path fullDir = targetDir / encDir;

        if(!fs::exists(fullDir)){
            fs::create_directories(fullDir);
        }

        try{
            for(const auto& entry : fs::recursive_directory_iterator(targetDir)){
                if(entry.is_regular_file()){

                    fs::path fullPath = fullDir / entry.path().filename();

                    std::string secretFile = entry.path();
                    std::string encryptedFile = fullPath;

                    if(processFile(secretFile, encryptedFile, myPassword, true)){
                        std::cout << "[ENCRYPTING ...] " << fullPath.filename() << std::endl;
                    }

                    try{
                        fs::remove(secretFile);
                    }catch(const fs::filesystem_error& e){
                        std::cerr << "[ERROR] \n" << e.what();
                    }

                    fs::rename(encryptedFile, secretFile);
                }
            }
            fs::remove(fullDir);
        }
        catch(const fs::filesystem_error& e){
            std::cerr << e.what() << std::endl;
        }
    }else{
        std::cerr << "Wrong password!\n";
        return -1;
    }
    
    return 0;
}

void deriveKey(const std::string& password, CryptoPP::SecByteBlock& key)
{
    CryptoPP::SHA256 hash;
    hash.Update(reinterpret_cast<const CryptoPP::byte*>(password.data()), password.size());
    hash.Final(key);
}

bool processFile(const std::string& inputFile, 
                 const std::string& outputFile, 
                 const std::string& password, 
                 bool encrypt){
    try{
        CryptoPP::SecByteBlock key(CryptoPP::AES::MAX_KEYLENGTH);
        deriveKey(password, key);
        CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

        if(encrypt){
            CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption enc;
            enc.SetKeyWithIV(key, key.size(), iv);

            CryptoPP::FileSource(inputFile.c_str(), true,
                new CryptoPP::StreamTransformationFilter(enc,
                    new CryptoPP::FileSink(outputFile.c_str()))
            );
        }else{
            CryptoPP::CBC_Mode<CryptoPP::AES>::Decryption dec;
            dec.SetKeyWithIV(key, key.size(), iv);
            CryptoPP::FileSource(inputFile.c_str(), true,
                new CryptoPP::StreamTransformationFilter(dec, 
                    new CryptoPP::FileSink(outputFile.c_str()))
            );
        }
        return true;
    }
    catch(const CryptoPP::Exception& e){
        std::cerr << "Error processing the file " << e.what();
        return false;
    }
}