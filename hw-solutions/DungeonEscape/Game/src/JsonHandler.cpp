/*

{
    "rooms": [
        {
            "id": <integer>,
            "name": "<string>",
            "description": "<string>",
            "item": {
                "name": "<string>",
                "description": "<string>",
                "type": "<char>",
                "properties": {
                    "<string>": <integer>
                }
            } or null,
            "enemies": [
                {
                    "name": "<string>",
                    "description": "<string>",
                    "health": <integer>,
                    "base_attack_damage": <integer>,
                    "base_defense": <integer>,
                    "aggression": <integer>,
                    "loot": {
                        "name": "<string>",
                        "description": "<string>",
                        "type": "<char>",
                        "properties": {
                            "<string>": <integer>
                        }
                    }
                }
            ]
        }
    ]
}


for item type:
    - Weapon: 'W'
    - Armor: 'A'
    - Consumable: 'C'
    - Key: 'K'
    - Rock: 'R' or null


*/


#include "../headers/JsonHandler.hpp"


namespace Game {

    Item JsonHandler::getItem(const Json::Value& item) {
        if (item.isNull()) return Item();
        char type = item["type"].asString()[0];

        switch (type) {
        case 'W':
            return Item::Weapon(item["name"].asString(), item["description"].asString(),
                item["properties"]["attack_bonus"].asInt());
        case 'A':
            return Item::Armor(item["name"].asString(), item["description"].asString(),
                item["properties"]["defense_bonus"].asInt());
        case 'C':
            return Item::Consumable(item["name"].asString(), item["description"].asString(),
                item["properties"]["heal_amount"].asInt());
        case 'K':
            return Item::Key(item["name"].asString(), item["description"].asString(),
                item["properties"]["key_type"].asInt());
        case 'R':
            return Item(); // Rock
        default:
            throw std::runtime_error("Invalid item type");
        }
    }

    Enemy JsonHandler::getEnemy(const Json::Value& enemy) {
        Item item = getItem(enemy["loot"]);

        return Enemy(enemy["name"].asString(), enemy["description"].asString(), item,
            enemy["health"].asInt(), enemy["base_attack_damage"].asInt(),
            enemy["base_defense"].asInt(), enemy["aggression"].asInt());
    }

    Room JsonHandler::make(const Json::Value& room) {
        Room newRoom(room["name"].asString(), room["description"].asString());
        JsonHandler handler;

        newRoom.addItem(handler.getItem(room["item"]));
        for (const auto& enemy : room["enemies"]) {
            newRoom.addEnemy(handler.getEnemy(enemy));
        }

        return newRoom;
    }


} // namespace Game