/*
    Encapsulation Example: Bank Account
*/

#include <iostream>

class BankAccount {
private:
    /*
        Balance is sensitive information and should not be directly exposed to the outside world.
        It should only be changed through specific methods like deposit and withdraw, where we can
        implement additional checks and logic to ensure the balance is updated securely and correctly.
    */

    double balance;  // Balance is private to ensure it can only be changed through specific methods

public:
    BankAccount(double initialBalance) { /* implementation */ }
    void deposit(double amount) { /* implementation */ }
    void withdraw(double amount) { /* implementation */ }
    double getBalance() const { /* implementation */ }
};

int main() {
    // Create a bank account with an initial balance of $100
    BankAccount account(100);

    // Deposit and withdraw money using the public methods
    account.deposit(50);
    account.withdraw(30);

    // Get the current balance using the getter method
    std::cout << "Current Balance: $" << account.getBalance() << std::endl;

    return 0;
}
