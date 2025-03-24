#include <iostream>
#include <fstream>

#include "../headers/Interface.hpp"


namespace Game {

    bool Interface::Menu(const std::string& fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.close();
        return true;
    }

    Interface::Interface(const std::string& playerName, const std::string& playerDescription,
        const std::string& dungeonFile) : dungeon(dungeonFile),
        player(playerName, playerDescription), lastInputWasSuccessful(true),
        lastInput(' '), isFighting(false), gameOver(false) {

        Utils::Printer::ClearScreen();
    }

    bool Interface::gameIsOver() const {
        return gameOver;
    }

    bool Interface::changePlayerWeapon() {
        // Title
        print("\n====================================", Utils::Color::CYAN);
        print("       WEAPON EQUIPMENT MENU       ", Utils::Color::CYAN);
        print("====================================\n", Utils::Color::CYAN);

        // Loop over the player's inventory and display weapons
        const DataStructures::Vector<Item>& inventory = player.getInventory();
        bool hasWeapons = false;

        for (size_t i = 0; i < inventory.getSize(); ++i) {
            const Item& item = inventory[i];
            if (item.getType() == ItemType::WEAPON) {
                hasWeapons = true;
                print("  [" + std::to_string(i) + "] " + item.getName(), Utils::Color::WHITE);
            }
        }

        if (!hasWeapons) {
            print("\n  No weapons available in your inventory.", Utils::Color::RED);
            return false;
        }

        print("\n------------------------------------", Utils::Color::YELLOW);



        int index;
        print("  Enter the index of the weapon you want to equip: ", Utils::Color::GREEN, false);
        std::cin >> index;
        bool equipped = player.equipWeapon(index);

        if (!equipped) return false;

        print("\n====================================", Utils::Color::CYAN);
        print("       WEAPON EQUIPPED!            ", Utils::Color::CYAN);
        print("====================================", Utils::Color::CYAN);

        print("\n  Equipped: " + inventory[index].getName(), Utils::Color::WHITE);
        print("  " + inventory[index].getDescription(), Utils::Color::YELLOW);

        return true;
    }

    bool Interface::changePlayerArmor() {
        // Title
        print("\n====================================", Utils::Color::CYAN);
        print("       ARMOR EQUIPMENT MENU        ", Utils::Color::CYAN);
        print("====================================\n", Utils::Color::CYAN);

        // Loop over the player's inventory and display armor
        const DataStructures::Vector<Item>& inventory = player.getInventory();
        bool hasArmor = false;

        for (size_t i = 0; i < inventory.getSize(); ++i) {
            const Item& item = inventory[i];
            if (item.getType() == ItemType::ARMOR) {
                hasArmor = true;
                print("  [" + std::to_string(i) + "] " + item.getName(), Utils::Color::WHITE);
            }
        }

        if (!hasArmor) {
            print("\n  No armor available in your inventory.", Utils::Color::RED);
            return false;
        }

        print("\n------------------------------------", Utils::Color::YELLOW);

        int index;
        print("  Enter the index of the armor you want to equip: ", Utils::Color::GREEN, false);
        std::cin >> index;

        bool equipped = player.equipArmor(index);

        if (!equipped) return false;

        print("\n====================================", Utils::Color::CYAN);
        print("       ARMOR EQUIPPED!             ", Utils::Color::CYAN);
        print("====================================", Utils::Color::CYAN);

        print("\n  Equipped: " + inventory[index].getName(), Utils::Color::WHITE);
        print("  " + inventory[index].getDescription(), Utils::Color::YELLOW);

        return true;
    }


    bool Interface::usePlayerConsumable() {
        // Title
        print("\n====================================", Utils::Color::CYAN);
        print("       CONSUMABLES MENU            ", Utils::Color::CYAN);
        print("====================================\n", Utils::Color::CYAN);

        // Loop over the player's inventory and display consumables
        const DataStructures::Vector<Item>& inventory = player.getInventory();
        bool hasConsumables = false;

        for (size_t i = 0; i < inventory.getSize(); ++i) {
            const Item& item = inventory[i];
            if (item.getType() == ItemType::CONSUMABLE) {
                hasConsumables = true;
                print("  [" + std::to_string(i) + "] " + item.getName()
                    + " (+" + std::to_string(item.getProperty(ItemProperty::HEALTH_POINTS)) + " HP)",
                    Utils::Color::WHITE);
            }
        }

        if (!hasConsumables) {
            print("\n  No consumables available in your inventory.", Utils::Color::RED);
            return false;
        }

        print("\n------------------------------------", Utils::Color::YELLOW);

        int index;
        print("  Enter the index of the consumable you want to use: ", Utils::Color::GREEN, false);
        std::cin >> index;

        std::string name = inventory[index].getName();
        std::string description = inventory[index].getDescription();

        bool used = player.useConsumable(index);

        if (!used) return false;

        print("\n====================================", Utils::Color::CYAN);
        print("       CONSUMABLE USED!            ", Utils::Color::CYAN);
        print("====================================", Utils::Color::CYAN);

        print("\n  Used: " + name, Utils::Color::WHITE);
        print("  " + description, Utils::Color::YELLOW);

        return true;
    }

    bool Interface::printPlayerStats() {
        // Title
        print("\n====================================", Utils::Color::CYAN);
        print("       PLAYER STATS                ", Utils::Color::CYAN);
        print("====================================\n", Utils::Color::CYAN);

        // Player name and description
        print("  Name: " + player.getName(), Utils::Color::WHITE);
        print("  Description: " + player.getDescription(), Utils::Color::WHITE);

        // Player health
        print("\n  Health: " +
            std::to_string(player.getProperty(EntityProperty::HEALTH)),
            Utils::Color::WHITE);

        // Player attack damage
        print("  Attack Damage: " +
            std::to_string(
                player.getProperty(EntityProperty::BASE_ATTACK_DAMAGE) +
                player.getEquippedWeapon().getProperty(ItemProperty::ATTACK_BONUS)
            ),
            Utils::Color::WHITE);

        // Player defense
        print("  Defense: " +
            std::to_string(
                player.getProperty(EntityProperty::BASE_DEFENSE) +
                player.getEquippedArmor().getProperty(ItemProperty::DEFENSE_BONUS)
            ),
            Utils::Color::WHITE);

        // Player equipped weapon
        const Item& equippedWeapon = player.getEquippedWeapon();
        print("\n  Equipped Weapon: " + equippedWeapon.getName(), Utils::Color::WHITE);
        print("  " + equippedWeapon.getDescription(), Utils::Color::WHITE);

        // Player equipped armor
        const Item& equippedArmor = player.getEquippedArmor();
        print("\n  Equipped Armor: " + equippedArmor.getName(), Utils::Color::WHITE);
        print("  " + equippedArmor.getDescription(), Utils::Color::WHITE);

        return true;
    }


    bool Interface::printPlayerInventory() {

        // Title
        print("\n====================================", Utils::Color::CYAN);
        print("       PLAYER INVENTORY            ", Utils::Color::CYAN);
        print("====================================\n", Utils::Color::CYAN);

        // Loop over the player's inventory and display items
        const DataStructures::Vector<Item>& inventory = player.getInventory();
        for (size_t i = 0; i < inventory.getSize(); ++i) {
            const Item& item = inventory[i];
            print("  [" + std::to_string(i) + "] " + item.getName(), Utils::Color::WHITE);
        }

        return true;
    }

    bool Interface::exploreRoom() {
        Room& currentRoom = dungeon.getCurrentRoom();
        Item item = currentRoom.explore();

        print("\n====================================", Utils::Color::CYAN);
        print("          ROOM EXPLORATION          ", Utils::Color::CYAN);
        print("====================================", Utils::Color::CYAN);

        print("\n  You look around the room carefully...", Utils::Color::WHITE);

        if (item.getType() == ItemType::ROCK) {
            // If the item is a rock, we assume the room had nothing else
            print("\n  You found a rock.", Utils::Color::MAGENTA);
            print("  Amazing. Truly a once-in-a-lifetime discovery.", Utils::Color::MAGENTA);
            print("  Maybe if you collect enough, you can start a museum.", Utils::Color::MAGENTA);
            print("\n  You decide to leave it where it is.", Utils::Color::YELLOW);
            print("\n====================================\n", Utils::Color::CYAN);
            return false;
        }

        // Normal item discovery
        print("\n  You found: " + item.getName(), Utils::Color::GREEN);
        print("  " + item.getDescription(), Utils::Color::YELLOW);

        // Add item to inventory
        player.addItem(item);
        print("\n  The item has been added to your inventory.", Utils::Color::CYAN);
        print("\n====================================\n", Utils::Color::CYAN);

        return true;
    }

    bool Interface::handleInput(char option) {
        if (option == 'n' || option == 'p') lastInputWasSuccessful = movePlayer(option);
        else if (option == 'H') lastInputWasSuccessful = Menu();
        else if (option == 'W') lastInputWasSuccessful = changePlayerWeapon();
        else if (option == 'A') lastInputWasSuccessful = changePlayerArmor();
        else if (option == 'C') lastInputWasSuccessful = usePlayerConsumable();
        else if (option == 'S') lastInputWasSuccessful = printPlayerStats();
        else if (option == 'I') lastInputWasSuccessful = printPlayerInventory();
        else if (option == 'E') lastInputWasSuccessful = exploreRoom();
        else {
            std::cout << "I don't know what to do with that" << std::endl;
            lastInputWasSuccessful = false;
        }

        return lastInputWasSuccessful;
    }

    bool Interface::movePlayer(char direction) {
        if (dungeon.getCurrentRoom().hasEnemies()) {
            print("There are enemies guarding the way!", Utils::Color::RED);
            return false;
        }


        if (dungeon.isFirstRoom() && direction == 'p') {
            print("You cannot go back there", Utils::Color::RED);
            return false;
        }

        if (dungeon.isLastRoom() && direction == 'n') {
            gameOver = true;
            return true;
        }

        return dungeon.movePlayer(direction);
    }

    void Interface::displayCurrentRoom() {
        Utils::Printer::ClearScreen();
        lastInputWasSuccessful = true;
        lastInput = ' ';


        Room& currentRoom = dungeon.getCurrentRoom();
        print(currentRoom.getName(), Utils::Color::CYAN, true, true);
        print(currentRoom.getDescription(), Utils::Color::WHITE, true, true);

        if (currentRoom.hasEnemies()) {
            print("There are enemies in this room!", Utils::Color::RED);
            print("You must defeat them before moving on.", Utils::Color::RED);

            // Print enter to continue
            print("Press Enter to continue...", Utils::Color::WHITE);
            hold();
        }
    }

    void Interface::fightEnemies() {
        Room& currentRoom = dungeon.getCurrentRoom();
        if (!currentRoom.hasEnemies()) return;

        isFighting = true;

        while (currentRoom.hasEnemies()) {
            // Prompt user before each fight

            // Type 'a' to attack
            lastInput = ' ';
            print("Type 'a' to attack when ready", Utils::Color::YELLOW);
            while (lastInput != 'a') promptUser();

            Enemy enemy = currentRoom.getEnemy();

            print("You have encountered " + enemy.getName(), Utils::Color::RED);

            while (enemy.getProperty(EntityProperty::HEALTH) > 0) {
                player.attack(enemy);

                if (enemy.getProperty(EntityProperty::HEALTH) <= 0) {
                    print("You have defeated " + enemy.getName(), Utils::Color::GREEN);
                    print("You have gained " + enemy.getLoot().getName(), Utils::Color::GREEN);
                    player.addItem(enemy.getLoot());
                    break;
                }
                else {
                    print("You have taken damage!", Utils::Color::RED);
                    enemy.attack(player);

                    if (player.getProperty(EntityProperty::HEALTH) <= 0) {
                        print("You have been defeated by " + enemy.getName(), Utils::Color::RED);
                        gameOver = true;
                        return;
                    }
                }
            }
        }

        print("All Enemies have been defeated!", Utils::Color::GREEN);
        print("You can now proceed", Utils::Color::GREEN);
        isFighting = false;
    }

    void Interface::promptUser() {
        if (gameOver) return;

        lastInput = ' ';

        if (!lastInputWasSuccessful) {
            print("> ", Utils::Color::RED, false);
        }
        else {
            print("> ", Utils::Color::GREEN, false);
        }

        std::cin >> lastInput;

        if (isFighting && lastInput == 'a') {
            lastInputWasSuccessful = true;
            return;
        }
        handleInput(lastInput);

    }

    void Interface::hold() {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }

    Room& Interface::getCurrentRoom() {
        return dungeon.getCurrentRoom();
    }

    bool Interface::playerHasMoved() const {
        return ((lastInput == 'n' || lastInput == 'p') && lastInputWasSuccessful) || gameOver;
    }

} // namespace Game