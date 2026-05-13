#include "bots/AliceBot.hpp"

#include "actions/MoveAction.hpp"
#include "actions/CollectAction.hpp"

#include <iostream>

AliceBot::AliceBot(Dungeon& dungeon, GameState& game_state, ResourceManager& res_manager) :
    m_dungeon(dungeon), m_game_state(game_state), m_res_manager(res_manager),  m_path_finder(m_dungeon)
{
    m_food_treshold = m_game_state.food / 2;
}

std::unique_ptr<IAction> AliceBot::act()
{
    if(m_game_state.food > m_food_treshold)
        return _explore_stage_act();
    return _return_stage_act();
}

std::unique_ptr<IAction> AliceBot::_explore_stage_act()
{
    std::cout<<"Explore stage\n";

    Room& cur_coom = m_dungeon.get_room(m_game_state.current_room);
    if(m_game_state.current_room != 0 && !cur_coom.collected_res && _room_has_resources(cur_coom))
        return std::make_unique<CollectAction>(m_game_state.current_room, _get_most_valuable_res(cur_coom));

    // move to the next unvisited room
    auto path = m_path_finder.build_path(m_game_state.current_room, [](const Room& r){ return !r.visited; });
    if(path.size() == 0)
        return _return_stage_act();
    int next_room = path.front();
    return std::make_unique<MoveAction>(next_room);
}

std::unique_ptr<IAction> AliceBot::_return_stage_act()
{
    std::cout<<"return stage\n";
    std::cout<<"Current room: "<<m_game_state.current_room<<'\n';

    // find path to the start room (go only through visited)
    auto path = m_path_finder.build_path(
        m_game_state.current_room,
        [](const Room& r){ return r.room_number == 0; },
        [](const Room& r){ return r.visited; }
    );
    if(path.size() == 0 || m_game_state.current_room == 0)
        return nullptr;
    Room& cur_coom = m_dungeon.get_room(m_game_state.current_room);
    if(path.size() > m_game_state.food && _room_has_resources(cur_coom)) // has extra food, collect res
        return std::make_unique<CollectAction>(m_game_state.current_room, _get_most_valuable_res(cur_coom));
    return std::make_unique<MoveAction>(path.front());
}

ResourceType AliceBot::_get_most_valuable_res(const Room& room)
{
    auto res_sorted = m_res_manager.get_resource_value_sorted();
    for(const auto& p: res_sorted)
        if(room.resources.count(p.first) > 0)
            return room.resources.find(p.first)->first;
}

bool AliceBot::_room_has_resources(const Room& room)
{
    for(const auto& p: room.resources)
        if(p.second > 0)
            return true;
    return false;
}