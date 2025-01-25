#include <cstdlib>
#include <ctime>

#include "../headers/Die.hpp"

// Initialize the static member variable
int Die::totalDice = 0;
bool Die::seeded = false;

// Constructor to initialize the number of sides
Die::Die(int _sides) : sides(_sides), rolls(0) {
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    totalDice++;
}

// Method to roll the die
int Die::roll() {
    rolls++;
    return rand() % sides + 1;
}

// Method to get the number of sides
int Die::getSides() const {
    return sides;
}

// Method to get the number of rolls
int Die::getRolls() const {
    return rolls;
}

// Method to get the total number of dice created
int Die::getTotalDice() {
    return totalDice;
}

// Destructor to decrement the total number of dice
Die::~Die() {
    totalDice--;
}

