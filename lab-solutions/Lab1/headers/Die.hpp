#ifndef DIE_HPP
#define DIE_HPP

class Die {
    int sides;
    int rolls;
    static int totalDice;
    static bool seeded;
public:

    Die(int _sides); // Constructor

    int roll(); // Roll the die

    int getSides() const; // Get the number of sides

    int getRolls() const; // Get the number of rolls

    static int getTotalDice(); // Get the total number of dice created

    ~Die(); // Destructor
};

#endif // DIE_HPP