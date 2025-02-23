/**************************************************************************************************
    Task 3:
        Create a class LivingBeing that has a string attribute species and a constructor
        that initializes it. Then, create two classes: Animal and Plant, both inheriting
        from LivingBeing. Each should have a constructor that initializes species.

        Next, create a class HybridOrganism that inherits from both Animal and Plant.
        Implement a constructor in HybridOrganism that initializes both base classes and
        an additional attribute, hybridName. Finally, create a display() function in
        HybridOrganism that prints all attributes.

        IntelliSense may show an ambiguity error when accessing species in HybridOrganism.
        Ignore it for now.

        In main(), instantiate a HybridOrganism object and call display(). You will encounter
        a compilation error due to ambiguity when trying to access species. Answer the following:

        1) Why does the ambiguity occur, and how does the compiler interpret the duplicate
           species members?
        2) How can you explicitly resolve this ambiguity when accessing species in HybridOrganism?
        3) What alternative design choices could prevent such issues in multiple inheritance?
**************************************************************************************************/

#include <iostream>

class LivingBeing {
protected:
    std::string species;
public:
    LivingBeing(const std::string& species) : species(species) {}
};

class Animal : public LivingBeing {
public:
    Animal(const std::string& species) : LivingBeing(species) {}
};

class Plant : public LivingBeing {
public:
    Plant(const std::string& species) : LivingBeing(species) {}
};

class HybridOrganism : public Animal, public Plant {
private:
    std::string hybridName;
public:
    HybridOrganism(const std::string& animalSpecies, const std::string& plantSpecies,
        const std::string& hybridName) : Animal(animalSpecies), Plant(plantSpecies),
        hybridName(hybridName) {
    }

    /****************************************************************************************
        1) The ambiguity occurs because the HybridOrganism class inherits from both Animal
           and Plant, which have a common base class LivingBeing with the attribute species.
           when accessing species in HybridOrganism, the compiler does not know which
           species attribute to use, as it is present in both Animal and Plant.
        2) To explicitly resolve the ambiguity, we can use the scope resolution operator ::
           to specify which base class's species attribute we want to access.
        3) Alternative design choices to prevent such issues in multiple inheritance include
              - using virtual inheritance to ensure that there is only one instance of the
                base class in the derived class hierarchy.
              - renaming the species attribute in the derived classes to avoid conflicts.
              - using composition instead of multiple inheritance to achieve the desired
                functionality.
    ****************************************************************************************/
    void display() const {
        std::cout << "Animal Species: " << Animal::species << std::endl;
        std::cout << "Plant Species: " << Plant::species << std::endl;
        std::cout << "Hybrid Name: " << hybridName << std::endl;
    }
};

int main() {
    HybridOrganism hybrid("Lion", "Rose", "LionRose"); // Creating HybridOrganism object
    hybrid.display();
    return 0;
}