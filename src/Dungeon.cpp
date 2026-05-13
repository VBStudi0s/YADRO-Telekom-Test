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
    m_rooms[0].visited = true;
}

Room& Dungeon::get_room(int room_num)
{
    return m_rooms.find(room_num)->second;
}

const Room& Dungeon::get_room(int room_num) const
{
    return m_rooms.find(room_num)->second;
}
