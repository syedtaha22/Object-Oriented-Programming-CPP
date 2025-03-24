#include <stdexcept>
#include <iostream>

#include "../headers/Player.hpp"

namespace Game {

    Player::Player(const std::string& name, const std::string& description) :
        Entity(name, description, DEFAULT_HEALTH, DEFAULT_BASE_ATTACK_DAMAGE, DEFAULT_BASE_DEFENSE) {

        inventory.push_back(Item::Weapon("Fists", "Your fists", 0));
        inventory.push_back(Item::Armor("Clothes", "Your clothes", 0));
        equippedWeapon = 0;
        equippedArmor = 1;
    }

    void Player::attack(Entity& target) {
        int damage = getProperty(EntityProperty::BASE_ATTACK_DAMAGE)
            + inventory[equippedWeapon].getProperty(ItemProperty::ATTACK_BONUS);
        target.takeDamage(damage);
    }

    void Player::takeDamage(int damage) {
        int defense = getProperty(EntityProperty::BASE_DEFENSE)
            + inventory[equippedArmor].getProperty(ItemProperty::DEFENSE_BONUS);

        int health = getProperty(EntityProperty::HEALTH);
        int damageTaken = damage - defense;
        if (damageTaken > 0) {
            health -= damageTaken;
            if (health < 0) health = 0; // health cannot be negative
            properties[EntityProperty::HEALTH] = health;
        }
    }

    bool Player::equipWeapon(int weaponIndex) {
        if (weaponIndex < 0 || weaponIndex >= inventory.getSize()) {
            std::cout << "There's no item at that index\n";
            return false;
        }

        if (inventory[weaponIndex].getType() != ItemType::WEAPON) {
            std::cout << "This item is not a weapon\n";
            return false;
        }
        equippedWeapon = weaponIndex;
        return true;
    }

    bool Player::equipArmor(int armorIndex) {
        if (armorIndex < 0 || armorIndex >= inventory.getSize()) {
            std::cout << "There's no item at that index\n";
            return false;
        }

        if (inventory[armorIndex].getType() != ItemType::ARMOR) {
            std::cout << "This item is not armor\n";
            return false;
        }
        equippedArmor = armorIndex;
        return true;
    }

    bool Player::useConsumable(int consumableIndex) {
        if (consumableIndex < 0 || consumableIndex >= inventory.getSize()) {
            std::cout << "There's no item at that index\n";
            return false;
        }

        if (inventory[consumableIndex].getType() != ItemType::CONSUMABLE) {
            std::cout << "This item is not a consumable\n";
            return false;
        }

        int health = getProperty(EntityProperty::HEALTH);
        if (health == DEFAULT_MAX_HEALTH) {
            std::cout << "Health is already full\n";
            return false;
        }

        health += inventory[consumableIndex].getProperty(ItemProperty::HEALTH_POINTS);
        properties[EntityProperty::HEALTH] = health;

        inventory[consumableIndex].setProperty(ItemProperty::HEALTH_POINTS, 0);
        inventory[consumableIndex].setName("Empty bottle");
        inventory[consumableIndex].setDescription("An empty bottle");

        return true;
    }

    void Player::addItem(const Item& item) {
        inventory.push_back(item);
    }

    const DataStructures::Vector<Item>& Player::getInventory() const {
        return inventory;
    }

    const Item& Player::getEquippedWeapon() const {
        return inventory[equippedWeapon];
    }

    const Item& Player::getEquippedArmor() const {
        return inventory[equippedArmor];
    }


} // namespace Game