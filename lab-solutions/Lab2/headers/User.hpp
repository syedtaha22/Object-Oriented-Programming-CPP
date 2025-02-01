#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "PasswordValidator.hpp"


// User class definition
class User {
    // Private password field
    std::string password;

public:
    // Constructor to initialize the password
    User(const std::string& pw);

    // Declare the friend function to allow PasswordValidator to access password
    friend bool PasswordValidator::hasValidPassword(User& user);
};




#endif // USER_HPP