#ifndef MAP_LOADER_HPP
#define MAP_LOADER_HPP

#include <string>
#include <map>

#include "Dungeon.hpp"
#include "Player.hpp"

struct LoadResult
{
    Dungeon dungeon;
    int food;
    ResourceType doubled_res;

    LoadResult() = default;
    LoadResult(const Dungeon& dung, int f, ResourceType res) :
        dungeon(dung), food(f), doubled_res(res){}
};

class GameLoader
{
    std::map<int, Room> m_rooms;
public:
    GameLoader() = default;

    LoadResult parse_and_load_game(const std::string& path);
};

#endif
