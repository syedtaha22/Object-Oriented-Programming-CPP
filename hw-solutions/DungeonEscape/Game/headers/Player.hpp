// Player class. Inherits from Entity.
// Has additional properties:
/*

    - Inventory (DataStructure::Vector<Item>)
    - Equipped weapon (Item)
    - Equipped armor (Item)
*/


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Item.hpp"
#include "../../DataStructures/Vector.hpp"

namespace Game {

    class Player : public Entity {
        DataStructures::Vector<Item> inventory;
        int equippedWeapon; // index in inventory
        int equippedArmor; // index in inventory

    public:
        Player(const std::string& name, const std::string& description);

        void attack(Entity& target) override;
        void takeDamage(int damage) override;

        bool equipWeapon(int weaponIndex);
        bool equipArmor(int armorIndex);
        bool useConsumable(int consumableIndex);


        void addItem(const Item& item);

        const DataStructures::Vector<Item>& getInventory() const;
        const Item& getEquippedWeapon() const;
        const Item& getEquippedArmor() const;
    };

} // namespace Game

#endif // PLAYER_HPP