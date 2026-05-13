#ifndef ALICE_BOT_HPP
#define ALICE_BOT_HPP

#include "IBot.hpp"
#include "Dungeon.hpp"
#include "GameState.hpp"
#include "BFS.hpp"
#include "Resource.hpp"

class AliceBot : public IBot
{
    Dungeon& m_dungeon;
    GameState& m_game_state;
    ResourceManager& m_res_manager;
    BFS m_path_finder;

    int m_food_treshold = 0;
public:
    AliceBot(Dungeon& dungeon, GameState& game_state, ResourceManager& res_manager);

    std::unique_ptr<IAction> act() override;
private:

    std::unique_ptr<IAction> _explore_stage_act();
    std::unique_ptr<IAction> _return_stage_act();

    ResourceType _get_most_valuable_res(const Room& room);
    bool _room_has_resources(const Room& room);
};

#endif