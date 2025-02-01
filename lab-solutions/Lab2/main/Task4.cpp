/*********************************************************************************************************
    Task 4:
        You have a class called PasswordValidator that validates the strength of a password. The
        class checks whether the password meets certain requirements, such as having numbers, upper
        and lower case letters, and ensuring it meets a minimum length.

        A User class holds a private string password. The PasswordValidator needs to validate the
        password for the User class, but it can't access the private password field directly through
        public functions.

        Your Task:
            • Implement the PasswordValidator class, which includes the following private methods:
                o bool containsNumbers(std::string): Checks if the password contains numbers.
                o bool containsUpperCaseLetter(std::string): Checks if the password contains at least
                  one uppercase letter.
                o bool containsLowerCaseLetter(std::string): Checks if the password contains at least
                  one lowercase letter.

            • The class should also have the following public method:
                o bool hasValidPassword(User& user): Checks if the password of the given User is valid
                  by calling the private validation methods. This function should validate whether the
                  password meets the necessary requirements.

            • The User class should contain:
                o A private password field.
                o A public constructor to initialize the password.

            • Since the PasswordValidator class needs to access the private password field of the User
              class, think about how this can be accomplished. You may need to use a friend function or
              another technique to allow the PasswordValidator class to directly access the password
              field in the User class.

        Restriction: The User class should not have getters to access the password field.

*********************************************************************************************************/

// Include the necessary header files
#include <iostream>
#include <string>

// Include the User class
#include "../headers/User.hpp" // Also brings in PasswordValidator.hpp

int main() {
    // Create a User object with a password
    User user("P@ssw0rd");

    // Create a PasswordValidator object
    PasswordValidator validator;

    // Check if the password is valid
    if (validator.hasValidPassword(user)) {
        std::cout << "Password is valid!" << std::endl;
    }
    else {
        std::cout << "Password is invalid!" << std::endl;
    }

    return 0; // Return 0 to indicate successful completion
}