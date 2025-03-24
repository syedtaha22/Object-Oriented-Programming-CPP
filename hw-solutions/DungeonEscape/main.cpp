#include <iostream>

#include "Game/core.hpp"
#include "Utils/Printer.hpp"
#include "MemoryTracker.hpp"

int main() {
    {
        Game::Interface game("Player", "A brave adventurer", "dungeon.json");
        Game::Interface::Menu();
        game.hold();

        Utils::Printer::ClearScreen();

        while (!game.gameIsOver()) {
            game.displayCurrentRoom();
            game.fightEnemies();

            while (!game.playerHasMoved()) game.promptUser();
        }
    }

    std::cout << "Memory Report:\n";
    MemoryTracker::report();

    return 0;
}
