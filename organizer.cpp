#include "event.h"
#include "base.h"
#include "users/users.h"
#include <vector>
#include <mariadb/conncpp.hpp>

void menu();

std::vector<users> getUsers(std::shared_ptr<sql::Statement> &statment);
void addUser(std::unique_ptr<sql::Connection> &connection, users user);

void list(std::unique_ptr<sql::Connection> &connection);
void add(std::unique_ptr<sql::Connection> &connection);
void remove(std::unique_ptr<sql::Connection> &connection);

int main(){
    try{
        sql::Driver* driver = sql::mariadb::get_driver_instance();

        //Load events

        sql::SQLString url("jdbc:mariadb://localhost:3306/organizer");
        sql::Properties properties({{"user", "lexi"}, {"password", "1408"}});

        std::unique_ptr<sql::Connection> connection(driver->connect(url, properties));

        std::vector<event> event_list;

        std::shared_ptr<sql::Statement> statment(connection->createStatement());

        std::vector<users> userList = getUsers(statment);

        std::string username;
        std::string password;
        
        if(userList.size() == 0){
            printf("New user\n");
            printf("Username: ");
            std::cin >> username;

            printf("password: ");
            std::cin >> password;

            users newUser(username, password);

            userList.push_back(newUser);

        }else{
            bool login = false;

            printf("Current user\n");

            while(!login){

                printf("Enter username: ");
                std::cin >> username;

                printf("Enter password: ");
                std::cin >> password;

                auto it = std::find_if(userList.begin(), userList.end(), [&username](users& object) {return object.getUsername() == username;});

                if(it != userList.end()){
                    if(it->checkPassword(password)){
                        login = true;
                        printf("login success\n");
                    }
                }else{
                    printf("login failed\n");
                }
                // chnage while loop for just new users
            }

            menu();

            connection->close();
        }
    }catch(sql::SQLException e){
        //Catch exception
        std::cerr << "Error printing contacts: "
         << e.what() << std::endl;
    }
}

std::vector<users> getUsers(std::shared_ptr<sql::Statement> &statment){
    try{
        std::vector<users> userList;
        
        

        std::unique_ptr<sql::ResultSet> results(statment->executeQuery("SELECT * FROM users"));

        while(results->next()){
            userList.push_back(users(std::string(results->getString(2)), std::string(results->getString(3))));
        }

        return userList;
    }catch(sql::SQLException e){
        //catch exception
        std::vector<users> userList;

        std::cerr << "Error printing contacts: "
         << e.what() << std::endl;

        return userList;
    }
}

void addUser(std::unique_ptr<sql::Connection> &connection, users user){
    try{
        std::unique_ptr<sql::PreparedStatement> statment(connection->prepareStatement("INSERT INTO USERS (user_name, user_password) VALUES (?, ?)"));

        statment->setString(1, user.getUsername());
        statment->setString(2, user.getPassword());

        statment->executeUpdate();
    }catch(sql::SQLException e){
        
    }
}

void menu(){

}

void list(std::unique_ptr<sql::Connection> &connection){
    printf("list\n");
}

void add(std::unique_ptr<sql::Connection> &connection){
    printf("add\n");

    try{
        std::string event_type;
        std::string event_start;
        std::string event_end;
        std::string event_description;

        std::unique_ptr<sql::PreparedStatement> statment(connection->prepareStatement("INSERT INTO EVENTS (event_type, event_start, event_end, event_description) VALUES (?, ?, ?, ?)"));

        statment->setString(1, event_type);
        statment->setString(2, event_start);
        statment->setString(3, event_end);
        statment->setString(4, event_description);

        statment->executeUpdate();
    }catch(sql::SQLException e){
        //catch exeption
    }
}

void remove(std::unique_ptr<sql::Connection> &connection){
    printf("remove\n");
}
