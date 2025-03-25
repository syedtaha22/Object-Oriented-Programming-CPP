#include <iostream>

#include "Game/core.hpp"
#include "Utils/Printer.hpp"

int main() {
    Game::Interface game("Player", "A brave adventurer", "test.json");
    Game::Interface::Menu();
    game.hold();

    Utils::Printer::ClearScreen();

    while (!game.gameIsOver()) {
        game.displayCurrentRoom();
        game.fightEnemies();
        while (!game.playerHasMoved()) game.promptUser();
    }

    return 0;
}
