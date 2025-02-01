
// Include the header file for the PasswordValidator class
#include "../headers/User.hpp" // Also brings in PasswordValidator.hpp

// Private methods to validate the password
bool PasswordValidator::containsNumbers(std::string password) {
    for (char ch : password) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

bool PasswordValidator::containsUpperCaseLetter(std::string password) {
    for (char ch : password) {
        if (isupper(ch)) {
            return true;
        }
    }
    return false;
}

bool PasswordValidator::containsLowerCaseLetter(std::string password) {
    for (char ch : password) {
        if (islower(ch)) {
            return true;
        }
    }
    return false;
}


// Method to check if the password is valid
bool PasswordValidator::hasValidPassword(User& user) {
    const std::string& password = user.password;

    // Validate the password using PasswordValidator's methods
    bool isValid = containsNumbers(password) &&
        containsUpperCaseLetter(password) &&
        containsLowerCaseLetter(password);

    return isValid;
}

