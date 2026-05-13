#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "GameState.hpp"
#include "Resource.hpp"
#include "Dungeon.hpp"

class Logger
{
    const Dungeon& m_dungeon;
    const ResourceManager& m_res_manager;
public:
    Logger(const Dungeon& dungeon, const ResourceManager& res_manager);

    void logGameState(const GameState& state) const;
    void logGameResult(const GameState& state) const;
    void logMoveAction(int move_to) const;
    void logCollectAction(ResourceType res) const;

private:
    void _print_res(int res) const;
};

#endif