#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "GameState.hpp"
#include "Dungeon.hpp"
#include "bots/IBot.hpp"
#include "Logger.hpp"
#include "GameLoader.hpp"

class GameManager
{
    Dungeon m_dungeon;
    GameState m_state;
    ResourceManager m_res_manager;
    Logger m_logger;
    std::unique_ptr<IBot> m_bot;
public:
    GameManager(const LoadResult& load);

    void attach_bot();      // think about this

    void simulate();
};

#endif