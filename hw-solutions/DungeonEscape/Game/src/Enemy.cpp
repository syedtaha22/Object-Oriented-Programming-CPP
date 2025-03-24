#include "../headers/Enemy.hpp"

namespace Game {

    Enemy::Enemy(const std::string& name, const std::string& description, const Item& loot,
        int health, int baseAttackDamage, int baseDefense, int agression) :
        Entity(name, description, health, baseAttackDamage, baseDefense), agression(agression), loot(loot) {
    }

    void Enemy::attack(Entity& target) {
        int damage = getProperty(EntityProperty::BASE_ATTACK_DAMAGE) + agression;
        target.takeDamage(damage);
    }

    void Enemy::takeDamage(int damage) {
        int health = getProperty(EntityProperty::HEALTH);
        health -= damage;
        if (health < 0) health = 0;
        properties[EntityProperty::HEALTH] = health;
    }

    int Enemy::getAgression() const {
        return agression;
    }

    const Item& Enemy::getLoot() const {
        return loot;
    }

} // namespace Game