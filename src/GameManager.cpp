#include "GameManager.hpp"

#include "bots/AliceBot.hpp"

#include <iostream>

GameManager::GameManager(Dungeon& dungeon,
        GameState& state,
        ResourceManager& res_manager,
        Logger& logger
    ) : m_dungeon(dungeon), m_state(state), m_res_manager(res_manager), m_logger(logger){}

void GameManager::attach_bot(std::unique_ptr<IBot> bot)
{
    m_bot = std::move(bot);
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
