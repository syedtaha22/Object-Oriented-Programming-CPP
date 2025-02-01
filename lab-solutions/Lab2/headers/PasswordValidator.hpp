#ifndef PASSWORD_VALIDATOR_HPP
#define PASSWORD_VALIDATOR_HPP


#include <string>

// Forward declaration of User class
class User;

// PasswordValidator class definition
class PasswordValidator {
    // Private methods to validate the password
    bool containsNumbers(std::string password);
    bool containsUpperCaseLetter(std::string password);
    bool containsLowerCaseLetter(std::string password);

public:
    // Method to check if the password is valid
    bool hasValidPassword(User& user);

};





#endif // PASSWORD_VALIDATOR_HPP