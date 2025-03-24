// handles json files.
// Has methods that take in a jsoncpp object, like for example
// Room make(const Json::Value& room) that returns a Room object.
// Item make(const Json::Value& item) that returns an Item object. (private method)
// Enemy make(const Json::Value& enemy) that returns an Enemy object. (private method)

#ifndef JSONHANDLER_HPP
#define JSONHANDLER_HPP

#include <json/json.h>

#include "Room.hpp"
#include "Item.hpp"
#include "Enemy.hpp"

namespace Game {

    class JsonHandler {
        Item getItem(const Json::Value& item);
        Enemy getEnemy(const Json::Value& enemy);
    public:
        static Room make(const Json::Value& room);

    };


} // namespace Game


#endif // JSONHANDLER_HPP