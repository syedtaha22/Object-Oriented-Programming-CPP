// Dungeon class.
/*

    A is basically a doubly linked list of rooms. A dungeon has a player and a current room.
*/

#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <string>

#include "Player.hpp"
#include "Room.hpp"
#include "../../DataStructures/List.hpp"

namespace Game {

    class Dungeon {
        DataStructures::List<Room> rooms;
        DataStructures::Node<Room>* currentRoom;

        bool gameOver;

    public:
        Dungeon(const std::string& dungeonFile = "dungeon.json");

        bool isLastRoom() const;
        bool isFirstRoom() const;

        bool movePlayer(const char direction);

        Room& getCurrentRoom();
    };

} // namespace Game


#endif // DUNGEON_HPP