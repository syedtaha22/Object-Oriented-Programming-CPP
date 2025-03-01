/*****************************************************************************************************
    Task 2:
        Create four abstract classes IWaterBreather, IEggLayer, IMilkProvider, and IFlyer.
            • IWaterBreather should have the waterBreathing() method
            • IEggLayer should have the laysEggs() method
            • IMilkProvider should have the givesMilk() method
            • IFlyer should have the flies() method
        Create an Amphibian abstract class that implements the IWaterBreather and IEggLayer
        classes. Create a Birds abstract class that implements the IEggLayer and IFlyer classes.

        Create a Mammal abstract class that implements the IMilkProvider class.
        Now create a concrete class Platypus that inherits from Mammal but implements the IEggLayer
        class. Also, create another concrete class Bat that inherits from Mammal and implements the
        IFlyer class.

        Finally, create a Chimera concrete class that implements all four abstract classes.

        Suppose you want to add all of these animals in one linked list, how will you do that? What
        methods will you be able to call if you are successful?

        Consider how to create a linked list with a common base class or interface
*****************************************************************************************************/

#include <iostream>

class IWaterBreather {
public:
    virtual void waterBreathing() = 0;
    virtual ~IWaterBreather() {}
};

class IEggLayer {
public:
    virtual void laysEggs() = 0;
    virtual ~IEggLayer() {}
};

class IMilkProvider {
public:
    virtual void givesMilk() = 0;
    virtual ~IMilkProvider() {}
};

class IFlyer {
public:
    virtual void flies() = 0;
    virtual ~IFlyer() {}
};

class Animal : public IWaterBreather, public IEggLayer, public IMilkProvider, public IFlyer {
public:
    virtual ~Animal() {}
};


class Amphibian : public IWaterBreather, public IEggLayer {
public:
    virtual ~Amphibian() {}
    // Common amphibian functions
};

class Birds : public IEggLayer, public IFlyer {
public:
    virtual ~Birds() {}
    // Common bird functions
};

class Mammal : public IMilkProvider {
public:
    virtual ~Mammal() {}
    // Common mammal functions
};

class Platypus : public Mammal, public IEggLayer {
public:
    void givesMilk() override {
        std::cout << "Platypus gives milk" << std::endl;
    }
    void laysEggs() override {
        std::cout << "Platypus lays eggs" << std::endl;
    }

};

class Bat : public Mammal, public IFlyer {
public:
    void givesMilk() override {
        std::cout << "Bat gives milk" << std::endl;
    }
    void flies() override {
        std::cout << "Bat flies" << std::endl;
    }

};

class Chimera : public IWaterBreather, public IEggLayer, public IMilkProvider, public IFlyer {
public:
    void waterBreathing() override {
        std::cout << "Chimera breathes water" << std::endl;
    }
    void laysEggs() override {
        std::cout << "Chimera lays eggs" << std::endl;
    }
    void givesMilk() override {
        std::cout << "Chimera gives milk" << std::endl;
    }
    void flies() override {
        std::cout << "Chimera flies" << std::endl;
    }

};

int main() {
    Platypus platypus;
    platypus.givesMilk();
    platypus.laysEggs();

    Bat bat;
    bat.givesMilk();
    bat.flies();

    Chimera chimera;
    chimera.waterBreathing();
    chimera.laysEggs();
    chimera.givesMilk();
    chimera.flies();

    return 0;
}