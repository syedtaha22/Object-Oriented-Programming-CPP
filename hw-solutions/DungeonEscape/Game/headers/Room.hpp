// Room class. 
/*

    Room has name, description

    It may have:
        - An item
        - Enemies
        Unimplemented:
            - Traps
            - Puzzles
            - NPCs
            - etc.
*/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

#include "Item.hpp" // For item
#include "Enemy.hpp" // For enemies
#include "../../DataStructures/Queue.hpp" // For qeueu of enemies

namespace Game {

    class Room {
        std::string name;
        std::string description;
        Item item;
        DataStructures::Queue<Enemy> enemies;

    public:
        Room(const std::string& name, const std::string& description);

        void addItem(const Item& item);
        void addEnemy(const Enemy& enemy);

        const std::string& getName() const;
        const std::string& getDescription() const;
        Item explore();
        Enemy getEnemy();

        bool hasEnemies() const;
    };



} // namespace Game



#endif // ROOM_HPP