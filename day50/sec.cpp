#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

//crypto++ includes
#include <cryptopp/sha.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
#include <cryptopp/cryptlib.h>

namespace fs = std::filesystem;


void deriveKey(const std::string& password, CryptoPP::SecByteBlock& key)
{
    CryptoPP::SHA256 hash; //initialize the sha256 algorithm
    hash.Update(reinterpret_cast<const CryptoPP::byte*>(password.data()), password.size()); //pass in the data you want to hash and its size
    hash.Final(key); //pack the hashed data into the special container named key
}

bool processFile(const std::string& inputFile, 
                 const std::string& outputFile, 
                 const std::string& password, 
                 bool encrypt){
    try{
        CryptoPP::SecByteBlock key(CryptoPP::AES::MAX_KEYLENGTH); //prepare the special container which stores the password. Exactly 32-bytes which is good for the algorithm
        deriveKey(password, key); //hash the password and put it in the special container
        CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; //set up and IV


        if(encrypt){
            CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption enc;
            enc.SetKeyWithIV(key, key.size(), iv);


            //here we create kinda like a pipeline, open a stream of the input file-> pass it to the encryption context -> pass the encypted file to the output file
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

int main(){
    std::string secretFile = "/home/martin/secret.jpeg";
    std::string encryptedFile = "/home/martin/encrypted.jpeg";
    std::string decryptedFile = "/home/martin/decrypted.jpeg";
    std::string myPassword = "_Martin42@";

    // std::ofstream(secretFile) << "This is a test file for encryption";

    std::cout << "[ENCRYPTION WITH CRYPTO++] encrypting file ...\n";
    if(processFile(secretFile, encryptedFile, myPassword, true)){
        std::cout << "File successfully encrypted to " << encryptedFile << std::endl;
    }

    try{
        if(fs::remove(secretFile)){
            std::cout << "File deleted successfully!\n";
        }else{
            std::cout << "File not found!\n";
        }
    }catch(const fs::filesystem_error& e){
        std::cerr << "[ERROR] ... \n" << e.what();
    }

    int trials = 0;
    do{
        std::string userInput;
        std::cout << "\nEnter password to decrypt file " << encryptedFile << " : ";
        std::cin >> userInput;
        if (userInput == myPassword){
            std::cout << "\n[DECRYPTING WITH CRYPTO++] decrypting file ...\n";
            if(processFile(encryptedFile, decryptedFile, myPassword, false)){
                std::cout << "File successfully decrypted to " << decryptedFile << std::endl;

                try{
                    if(fs::remove(encryptedFile)){
                        std::cout << "Encrypted file deleted successfully!\n";
                    }else{
                        std::cout << "File not found!\n";
                    }
                }catch(const fs::filesystem_error& e){
                    std::cerr << "[ERROR] ... \n" << e.what();
                }
                break;
            }
        }else{
            std::cout << "Wrong password!\n";
            trials += 1;
        }
    }while(trials < 3);

    return 0;
}