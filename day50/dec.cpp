#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdlib>

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

    const std::string myPassword = "musiala24001";
    std::string password {};
    std::string fileName {};
    std::string currentArg;

    if(argc > 4 || argc < 4){
        std::cerr << "Invalid number of arguments!\n";
        return -1;
    }else{
        fileName = argv[1];
        for(int i = 0; i < argc; i++){
            currentArg = argv[i];
            if(currentArg == "password"){
                password = argv[i + 1];
            }
        }
    }
    
    if (myPassword == password){
        fs::path file = fileName;

        try{
            if(fs::exists(file)){
                std::string encryptedFile = file;
                std::string ext = file.extension().string();
                std::string decryptedFile = "decrypted" + ext;

                std::cout << "\n[DECRYPTING WITH CRYPTO++] decrypting file ...\n";
                if(processFile(encryptedFile, decryptedFile, myPassword, false)){
                    std::cout << "Successfully decrypted " << decryptedFile << std::endl;
                    
                    try{
                        std::string command = "xdg-open " + decryptedFile;
                        std::system(command.c_str());
                    }catch(const std::exception& e){
                        std::cerr << "Failed to open file!\n";
                        std::cerr << "Check file format and try again\n";
                        std::cerr << e.what();
                    }
                    
                    try{
                        if(fs::remove(decryptedFile)){
                            std::cout << "Decrypted file deleted successfully!\n";
                        }else{
                            std::cout << "File not found!\n";
                        }
                    }catch(const fs::filesystem_error& e){
                        std::cerr << "[ERROR] ... \n" << e.what();
                    }
                }
            }else{
                std::cerr << "File does not exist!\n";
            }
        }catch(const fs::filesystem_error& e){
                        std::cerr << "[ERROR] ... \n" << e.what();
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