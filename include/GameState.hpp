#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "Resource.hpp"
#include <unordered_map>

struct GameState
{
    int current_room = 0;
    int food = 0;
    std::unordered_map<ResourceType, int> collected_resources;
};

#endif
