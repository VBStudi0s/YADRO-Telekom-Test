#include "Dungeon.hpp"

void Room::add_adjacent(int room_num)
{
    adjacent.insert(room_num);
}

void Room::set_resource(ResourceType type, int quantity)
{
    resources[type] = quantity;
}

Dungeon::Dungeon(std::map<int, Room> rooms) : m_rooms(rooms)
{
}

