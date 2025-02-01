#include "../headers/User.hpp" // Also brings in PasswordValidator.hpp 

User::User(const std::string& pw) : password(pw) {} // Constructor to initialize the password