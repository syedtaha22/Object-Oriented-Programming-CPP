// Enemy Class. Inherits from Entity
// Has additional properties:
/*
    - Agression (int)
    - Loot (Item)
*/

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include "Item.hpp"

namespace Game {

    class Enemy : public Entity {
        int agression;
        Item loot;

    public:
        Enemy(const std::string& name, const std::string& description, const Item& loot,
            int health = DEFAULT_HEALTH, int baseAttackDamage = DEFAULT_BASE_ATTACK_DAMAGE,
            int baseDefense = DEFAULT_BASE_DEFENSE, int agression = 0);

        void attack(Entity& target) override;
        void takeDamage(int damage) override;

        int getAgression() const;
        const Item& getLoot() const;
    };

} // namespace Game



#endif // ENEMY_HPP