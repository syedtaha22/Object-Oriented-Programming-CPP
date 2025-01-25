/*******************************************************************************************
    Task 6:
        You’ve been hired by a board game company that’s working on their next big
        release, Roll to Glory. The game revolves around a variety of unique dice
        that players use to progress through challenges, collect resources, and
        compete against each other. Each type of dice plays a critical role in the
        mechanics of the game. For instance:

            • A 6-sided dice is used for basic movement.
            • A 10-sided dice determines the success of special actions.
            • A 20-sided dice is reserved for epic battles and rare events.

        Your task is to design a customizable dice roller to help the developers test
        and balance their game mechanics. Here's what the system needs to do:

            1. Players should be able to create dice with any number of sides, from
               the standard 6-sided dice to more exotic ones (e.g., 15-sided, 100-sided).
            2. Once a dice is created, players can roll it multiple times and view the
               outcomes.
            3. Players should be able to check the number of sides on any dice they’ve
               created.
            4. Players should be able to check how many dice have been created so far
               during the session.

        The goal is to develop a system that allows the game designers to experiment with
        different types of dice effortlessly.
*******************************************************************************************/

// Include the necessary header files
#include <iostream>

#include "../headers/Die.hpp" // Include the Die class

int main() {
    // Create a 6-sided die
    Die d6(6);

    // Create a 10-sided die
    Die d10(10);

    // Create a 20-sided die
    Die d20(20);

    // Roll the 6-sided
    std::cout << "Rolling the 6-sided die: " << d6.roll() << std::endl;

    // Roll the 10-sided
    std::cout << "Rolling the 10-sided die: " << d10.roll() << std::endl;

    // Roll the 20-sided
    std::cout << "Rolling the 20-sided die: " << d20.roll() << std::endl;

    // Get the number of sides of the 6-sided die
    std::cout << "Number of sides of the 6-sided die: " << d6.getSides() << std::endl;

    // Get the total number of dice created
    std::cout << "Total number of dice created: " << Die::getTotalDice() << std::endl;

    return 0;
}
