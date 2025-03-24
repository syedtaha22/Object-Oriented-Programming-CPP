#include "../headers/Room.hpp"

#include <iostream>

namespace Game {

    Room::Room(const std::string& name, const std::string& description) :
        name(name), description(description) {

    }

    void Room::addItem(const Item& item) {
        this->item = item;
    }

    void Room::addEnemy(const Enemy& enemy) {
        enemies.enqueue(enemy);
    }

    const std::string& Room::getName() const {
        return name;
    }

    const std::string& Room::getDescription() const {
        return description;
    }

    Item Room::explore() {
        Item i = item;
        item = Item(); // Room no longer has an item, but it has rocks
        return i;
    }

    Enemy Room::getEnemy() {
        return enemies.dequeue();
    }

    bool Room::hasEnemies() const {
        return !enemies.isEmpty();
    }

} // namespace Game