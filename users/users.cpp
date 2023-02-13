#include "users.h"

users::users(std::string username, std::string password){
    this->username = username;
    this->password = hashPassword(password);
}

users::~users(){

}


std::string users::getUsername(){
    return username;
}

std::string users::getPassword(){
    return password;
}

bool users::checkPassword(std::string password){
    return (hashPassword(password) == this->password);
}

std::string users::hashPassword(std::string password){
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}
