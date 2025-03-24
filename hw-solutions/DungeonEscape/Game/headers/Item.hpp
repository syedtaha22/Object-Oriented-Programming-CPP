// Class to represent an item in the game
/*

    Item types:
    - Weapon
    - Armor
    - Consumable
    - Key

    Item properties:
    - Name
    - Description
    - Attack damaga (Weapon)
    - Defense (Armor)
    - Health points (Consumable)
    - Key type (Key)
*/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <unordered_map>


namespace Game {

    enum class ItemType {
        WEAPON,
        ARMOR,
        CONSUMABLE,
        ROCK,
        KEY
    };

    enum class ItemProperty {
        ATTACK_BONUS,
        DEFENSE_BONUS,
        HEALTH_POINTS,
        KEY_TYPE
    };

    class Item {
        ItemType itemType;
        std::string name;
        std::string description;
        std::unordered_map<ItemProperty, int> properties;

    public:
        Item(const std::string& name = "Rock", const std::string& description = "Just a rock",
            ItemType itemType = ItemType::ROCK, int attackBonus = 0, int defenseBonus = 0,
            int healthPoints = 0, int keyType = 0);

        void setProperty(ItemProperty property, int value);
        int getProperty(ItemProperty property) const;

        void setName(const std::string& name);
        void setDescription(const std::string& description);


        const std::string& getName() const;
        const std::string& getDescription() const;
        ItemType getType() const;

        static Item Weapon(const std::string& name, const std::string& description, int attackBonus);
        static Item Armor(const std::string& name, const std::string& description, int defenseBonus);
        static Item Consumable(const std::string& name, const std::string& description, int healthPoints);
        static Item Key(const std::string& name, const std::string& description, int keyType);
    };

} // namespace Game


#endif // ITEM_HPP