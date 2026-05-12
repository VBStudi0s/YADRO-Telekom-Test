#ifndef MAP_HPP
#define MAP_HPP

#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>

#include "Resource.hpp"

struct Room
{
    int room_number = 0;
    std::set<int> adjacent;
    std::unordered_map<ResourceType, int> resources;
    bool visited = false;
    bool collected_res = false;

    Room() = default;
    Room(int num) : room_number(num){}

    void add_adjacent(int room_num);
    void set_resource(ResourceType type, int quantity);
};

class Dungeon
{
private:
    std::map<int, Room> m_rooms;
public:
    Dungeon() = default;
    Dungeon(std::map<int, Room> rooms);

    Room& get_room(int room_num);
};

#endif
