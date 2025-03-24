// Entity base class for Player and Enemy
/*

    has name, description.


    Properties:
        - Health
        - Base attack damage
        - Base defense
        -

*/

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <unordered_map>

namespace Game {

    enum class EntityProperty {
        HEALTH,
        BASE_ATTACK_DAMAGE,
        BASE_DEFENSE
    };

    class Entity {
    protected:
        std::string name;
        std::string description;
        std::unordered_map<EntityProperty, int> properties;

    public:
        Entity(const std::string& name, const std::string& description, int health = DEFAULT_HEALTH,
            int baseAttackDamage = DEFAULT_BASE_ATTACK_DAMAGE, int baseDefense = DEFAULT_BASE_DEFENSE);

        void setProperty(EntityProperty property, int value);
        int getProperty(EntityProperty property) const;

        // virtual attack and takeDamage methods
        virtual void attack(Entity& target) = 0;
        virtual void takeDamage(int damage) = 0;

        int& operator[](EntityProperty property);

        const std::string& getName() const;
        const std::string& getDescription() const;

        // virtual destructor
        virtual ~Entity() = default;

        // default health, attack, defense values
        static const int DEFAULT_HEALTH = 100;
        static const int DEFAULT_BASE_ATTACK_DAMAGE = 10;
        static const int DEFAULT_BASE_DEFENSE = 5;
        static const int DEFAULT_MAX_HEALTH = 150;
    };

} // namespace Game

#endif // ENTITY_HPP