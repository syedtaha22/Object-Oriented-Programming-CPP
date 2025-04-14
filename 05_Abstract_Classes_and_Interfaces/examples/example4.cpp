#include <iostream>

class PaymentMethod {
public:
    virtual void pay(float amount) = 0;
};

class CreditCard : public PaymentMethod {
public:
    void pay(float amount) override {
        std::cout << "Paid $" << amount << " with credit card." << std::endl;
    }
};

class PayPal : public PaymentMethod {
public:
    void pay(float amount) override {
        std::cout << "Paid $" << amount << " using PayPal." << std::endl;
    }
};

int main() {
    PaymentMethod* payment;

    CreditCard cc;
    payment = &cc;
    payment->pay(100.0f);

    PayPal pp;
    payment = &pp;
    payment->pay(50.0f);

    return 0;
}
