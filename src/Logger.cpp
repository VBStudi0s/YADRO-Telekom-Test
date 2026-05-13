#include "Logger.hpp"

#include <iostream>

Logger::Logger(const Dungeon& dungeon, const ResourceManager& res_manager) :
    m_dungeon(dungeon), m_res_manager(res_manager) {}

void Logger::logGameState(const GameState& state) const
{
    std::cout<<"state "<< state.current_room;
    const Room& cur_room = m_dungeon.get_room(state.current_room);

    _print_res(cur_room.resources.find(ResourceType::IRON)->second);
    _print_res(cur_room.resources.find(ResourceType::GOLD)->second);
    _print_res(cur_room.resources.find(ResourceType::GEMS)->second);
    _print_res(cur_room.resources.find(ResourceType::EXP)->second);

    std::cout<<'\n';
}

void Logger::_print_res(int res) const
{
    if( res > -1)
        std::cout<<' '<<res;
    else
        std::cout<<" _";
}

void Logger::logMoveAction(int move_to) const
{
    std::cout<<"go "<<move_to<<'\n';
}
void Logger::logCollectAction(ResourceType res) const
{
    std::cout<<"collect "<<m_res_manager.res_type_to_str(res)<<'\n';
}

void Logger::logGameResult(const GameState& state) const
{
    std::cout<<"result";
    int total_res = 0;
    
    auto collect_res = [this, &state, &total_res](ResourceType type){
        auto it = state.collected_resources.find(type);
        int res = 0;
        if(it != state.collected_resources.end())
            res = it->second;
        std::cout<<' '<<res;
        total_res += res * m_res_manager.get_res_value(type);
    };

    collect_res(ResourceType::IRON);
    collect_res(ResourceType::GOLD);
    collect_res(ResourceType::GEMS);
    collect_res(ResourceType::EXP);

    std::cout<<' '<<total_res<<'\n';
}