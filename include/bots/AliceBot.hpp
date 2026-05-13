#ifndef ALICE_BOT_HPP
#define ALICE_BOT_HPP

#include "IBot.hpp"
#include "Dungeon.hpp"
#include "GameState.hpp"
#include "BFS.hpp"
#include "Resource.hpp"

class AliceBot : public IBot
{
    const Dungeon& m_dungeon;
    const GameState& m_game_state;
    const ResourceManager& m_res_manager;
    BFS m_path_finder;

    int m_food_treshold = 0;
public:
    AliceBot(const Dungeon& dungeon, const GameState& game_state, const ResourceManager& res_manager);

    std::unique_ptr<IAction> act() override;
private:

    std::unique_ptr<IAction> _explore_stage_act();
    std::unique_ptr<IAction> _return_stage_act();

    ResourceType _get_most_valuable_res(const Room& room);
    bool _room_has_resources(const Room& room);
};

#endif
