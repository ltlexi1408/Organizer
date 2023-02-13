#include "users.h"

users::users(std::string username, std::string password){
    this->username = username;
    this->password = password;
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
    return (password == this->password);
}
