# **Dungeon Escape**  

## **Description**  
Dungeon Escape is a text-based RPG that immerses players in the depths of a mysterious and perilous dungeon. Players must navigate through a series of rooms, battling enemies, collecting weapons and armor, and using consumables to survive. Every decision—from equipping the right gear to choosing whether to fight or flee—affects the outcome of the adventure.  

The game is fully customizable via the `dungeon.json` configuration file, allowing players to define their own dungeon layout, enemies, and items. This flexibility makes the game highly replayable, with different dungeon configurations leading to unique gameplay experiences.  

---

## **Controls**  
At any point when prompted for an input (`> `), the following commands can be used:  

- **H** - View the controls menu  
- **W** - Change equipped weapon  
- **D** - Change equipped armor (D for Defense)  
- **C** - Use a consumable item (such as health potions)  
- **S** - View player statistics, including health, attack, and defense  
- **I** - Open the inventory to see collected items  
- **E** - Explore the current room, which may trigger events or encounters  
- **n** - Move to the next room (if available)  
- **p** - Move to the previous room (if available)  

The dungeon is full of hidden dangers, and survival depends on how wisely you manage your inventory, combat strategy, and movement.  

---

## **Configuration**  
The game reads its dungeon layout, enemies, and items from a `dungeon.json` file. This file allows full customization of the game world. Players can modify room descriptions, change the types of enemies encountered, and adjust item statistics to create a unique dungeon-crawling experience.  

### **General JSON Structure**  
The `dungeon.json` file follows this structure:  

```json
{
    "rooms": [
        {
            "id": 1,
            "name": "Ancient Crypt",
            "description": "A dark, humid room filled with eerie silence. Something lurks in the shadows.",
            "item": {
                "name": "Rusty Sword",
                "description": "An old blade, worn but still usable.",
                "type": "W",
                "properties": {
                    "attack_bonus": 5
                }
            },
            "enemies": [
                {
                    "name": "Skeleton Warrior",
                    "description": "A reanimated warrior, its hollow eyes glowing faintly.",
                    "health": 20,
                    "base_attack_damage": 5,
                    "base_defense": 2,
                    "aggression": 3,
                    "loot": {
                        "name": "Bone Armor",
                        "description": "Light armor crafted from old bones.",
                        "type": "A",
                        "properties": {
                            "defense_bonus": 3
                        }
                    }
                }
            ]
        }
    ]
}
```

---

## **Room Fields**  
Each room has specific attributes defining its characteristics.  

| Field         | Type             | Description                                   |
|---------------|------------------|-----------------------------------------------|
| `id`          | Integer          | Unique identifier for the room                |
| `name`        | String           | Name of the room                              |
| `description` | String           | Narrative description of the room             |
| `item`        | Object / `null`  | Item found in the room (or `null` if no item) |
| `enemies`     | Array of objects | List of enemies present in the room           |

Rooms serve as the primary environment for exploration and encounters. Some rooms may contain valuable loot, while others may be home to dangerous foes.

---

## **Enemy Fields**  
Enemies are defined within each room and determine combat encounters.  

| Field                | Type     | Description                                 |
|----------------------|----------|---------------------------------------------|
| `name`               | String   | Name of the enemy                           |
| `description`        | String   | Description of the enemy                    |
| `health`             | Integer  | Total health points of the enemy            |
| `base_attack_damage` | Integer  | The enemy's attack strength                 |
| `base_defense`       | Integer  | Defensive value that reduces damage taken   |
| `aggression`         | Integer  | Determines how frequently the enemy attacks |
| `loot`               | Object   | Item dropped upon defeat (can be `null`)    |

The `aggression` value increase the overall attack damage of the enemy. Higher aggression values indicate more aggressive enemies that attack more fiercely.

---

## **Item Fields**  
Items can be found in rooms or obtained from defeated enemies.  

| Field         | Type   | Description                                       |
|---------------|--------|---------------------------------------------------|
| `name`        | String | Name of the item                                  |
| `description` | String | A short description of the item                   |
| `type`        | Char   | `W` for weapon, `A` for armor, `C` for consumable |
| `properties`  | Object | Contains item-specific attributes                 |

### **Item Type Properties**  
- **Weapons (`"type": "W"`)**  
  - `"attack_bonus"`: Increases player's attack power.  
- **Armor (`"type": "A"`)**  
  - `"defense_bonus"`: Increases player's defense rating.  
- **Consumables (`"type": "C"`)**  
  - `"heal_amount"`: Restores the specified amount of health when used.  

Proper use of items is essential for surviving deeper dungeon levels.

---

## **Project Dependencies**  
This game relies on the `jsoncpp` library for JSON parsing.  

### **Installing jsoncpp**  
#### **MSYS2 (MinGW-w64)**  
To install `jsoncpp` using MSYS2, run:  
```sh
pacman -S mingw-w64-x86_64-jsoncpp
```
This will install the library for MinGW-w64 toolchains.  

#### **Vcpkg**  
To install `jsoncpp` using Vcpkg, run:  
```sh
vcpkg install jsoncpp
```
When compiling the game, link against `jsoncpp` by adding:  
```sh
-ljsoncpp
```
to your compiler flags.

---

## **Running the Game**  
After compiling, run the executable:  
```sh
./main.exe
```
This will automatically load `dungeon.json` and begin the adventure.  