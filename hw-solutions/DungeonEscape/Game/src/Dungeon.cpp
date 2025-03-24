/*
*/



#include "../headers/Dungeon.hpp"
#include "../headers/JsonHandler.hpp"


#include <fstream>
#include <iostream>

namespace Game {

    Dungeon::Dungeon(const std::string& dungeonFile) : gameOver(false) {
        std::ifstream file(dungeonFile);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file");
        }

        Json::Value root;
        file >> root;
        file.close();

        for (const auto& room : root["rooms"]) {
            rooms.insert(JsonHandler::make(room));
        }

        currentRoom = rooms.getHead();
    }


    bool Dungeon::isLastRoom() const {
        return currentRoom->next == nullptr;
    }

    bool Dungeon::isFirstRoom() const {
        return currentRoom->prev == nullptr;
    }

    bool Dungeon::movePlayer(const char direction) {
        if (currentRoom == nullptr) throw std::runtime_error("Current room is null");

        switch (direction) {
        case 'n': currentRoom = currentRoom->next; return true;
        case 'p': currentRoom = currentRoom->prev; return true;
        default: return false;
        }

    }

    Room& Dungeon::getCurrentRoom() {
        if (currentRoom == nullptr) {
            throw std::runtime_error("Current room is null");
        }
        return currentRoom->data;
    }


} // namespace Game