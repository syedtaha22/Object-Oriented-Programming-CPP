#include "../headers/Entity.hpp"

namespace Game {

    Entity::Entity(const std::string& name, const std::string& description, int health,
        int baseAttackDamage, int baseDefense) : name(name), description(description) {

        properties[EntityProperty::HEALTH] = health;
        properties[EntityProperty::BASE_ATTACK_DAMAGE] = baseAttackDamage;
        properties[EntityProperty::BASE_DEFENSE] = baseDefense;
    }

    void Entity::setProperty(EntityProperty property, int value) {
        properties[property] = value;
    }

    int Entity::getProperty(EntityProperty property) const {
        return properties.at(property);
    }

    int& Entity::operator[](EntityProperty property) {
        return properties[property];
    }

    const std::string& Entity::getName() const {
        return name;
    }

    const std::string& Entity::getDescription() const {
        return description;
    }

} // namespace Game