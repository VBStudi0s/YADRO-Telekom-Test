#include "GameManager.hpp"

#include "bots/AliceBot.hpp"

#include <iostream>

GameManager::GameManager(const LoadResult& load) :
    m_dungeon(load.dungeon), m_logger(m_dungeon, m_res_manager)
{
    m_state.food = load.food;
    m_res_manager.double_resource_value(load.doubled_res);
    
}

void GameManager::attach_bot()
{
    m_bot = std::make_unique<AliceBot>(m_dungeon, m_state, m_res_manager);
}

void GameManager::simulate()
{
    bool game_running = true;
    while(game_running)
    {
        std::unique_ptr<IAction> action = m_bot->act();
        if(action == nullptr || m_state.food <= 0)
        {
            m_logger.logGameResult(m_state);
            game_running = false;
            break;
        }
        action->act(m_dungeon, m_state);
        action->acceptLogger(m_logger);
        if(m_state.current_room != 0)
            m_logger.logGameState(m_state);
    }
}