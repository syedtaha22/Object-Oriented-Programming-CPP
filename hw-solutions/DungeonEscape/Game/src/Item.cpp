#include "../headers/Item.hpp"


namespace Game {

    Item::Item(const std::string& name, const std::string& description, ItemType itemType,
        int attackDamage, int defense, int healthPoints, int keyType) : name(name),
        description(description), itemType(itemType) {

        properties[ItemProperty::ATTACK_BONUS] = attackDamage;
        properties[ItemProperty::DEFENSE_BONUS] = defense;
        properties[ItemProperty::HEALTH_POINTS] = healthPoints;
        properties[ItemProperty::KEY_TYPE] = keyType;
    }

    void Item::setProperty(ItemProperty property, int value) {
        properties[property] = value;
    }

    int Item::getProperty(ItemProperty property) const {
        return properties.at(property);
    }

    void Item::setName(const std::string& name) {
        this->name = name;
    }

    void Item::setDescription(const std::string& description) {
        this->description = description;
    }

    const std::string& Item::getName() const {
        return name;
    }

    const std::string& Item::getDescription() const {
        return description;
    }

    ItemType Item::getType() const {
        return itemType;
    }

    Item Item::Weapon(const std::string& name, const std::string& description, int attackBonus) {
        return Item(name, description, ItemType::WEAPON, attackBonus, 0, 0, 0);
    }

    Item Item::Armor(const std::string& name, const std::string& description, int defenseBonus) {
        return Item(name, description, ItemType::ARMOR, 0, defenseBonus, 0, 0);
    }

    Item Item::Consumable(const std::string& name, const std::string& description, int healthPoints) {
        return Item(name, description, ItemType::CONSUMABLE, 0, 0, healthPoints, 0);
    }

    Item Item::Key(const std::string& name, const std::string& description, int keyType) {
        return Item(name, description, ItemType::KEY, 0, 0, 0, keyType);
    }

}