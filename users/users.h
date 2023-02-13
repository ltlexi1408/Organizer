#ifndef USERS
#define USERS

#include "../base.h"
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

class users{
    public:
        users(std::string username, std::string password);
        ~users();

        std::string getUsername();
        std::string getPassword();

        bool checkPassword(std::string password);
        std::string hashPassword(std::string password);

    private:
        std::string username;
        std::string password;
};

#endif //USERS