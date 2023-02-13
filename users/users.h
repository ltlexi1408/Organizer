#ifndef USERS
#define USERS

#include "../base.h"

class users{
    public:
        users(std::string username, std::string password);
        ~users();

        std::string getUsername();
        std::string getPassword();

        bool checkPassword(std::string password);

    private:
        std::string username;
        std::string password;
};

#endif //USERS