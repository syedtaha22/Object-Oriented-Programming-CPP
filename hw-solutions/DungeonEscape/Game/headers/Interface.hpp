#ifndef INTERFACE_HPP
#define INTERFACE_HPP


#include <iostream>

#include "Dungeon.hpp"
#include "Player.hpp"

#include "../../Utils/Printer.hpp"

namespace Game {

    class Interface {
        Dungeon dungeon;
        Player player;
        Utils::Printer print;

        bool lastInputWasSuccessful;
        char lastInput;
        bool isFighting;

        bool gameOver;

        bool movePlayer(char direction);
        bool changePlayerWeapon();
        bool changePlayerArmor();
        bool usePlayerConsumable();
        bool printPlayerStats();
        bool printPlayerInventory();
        bool exploreRoom();

    public:
        Interface(const std::string& playerName, const std::string& playerDescription,
            const std::string& dungeonFile);

        bool gameIsOver() const;
        bool handleInput(char option);
        bool playerHasMoved() const;

        void displayCurrentRoom();
        void fightEnemies();
        void promptUser();
        void hold();


        Room& getCurrentRoom();

        static bool Menu(const std::string& fileName = "menu.txt");


    };


} // namespace Game


#endif // INTERFACE_HPP