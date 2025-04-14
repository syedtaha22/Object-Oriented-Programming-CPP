#include <iostream>

class Constants {
public:
    static const int MAX_USERS = 100;
    virtual void show() = 0;
};

class Server : public Constants {
public:
    void show() override {
        std::cout << "Server can handle up to " << MAX_USERS << " users." << std::endl;
    }
};

int main() {
    Server s;
    s.show();
    return 0;
}
