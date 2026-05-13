#include "Logger.hpp"

Logger::Logger(const Dungeon& dungeon, const ResourceManager& res_manager) :
    m_dungeon(dungeon), m_res_manager(res_manager), m_out_stream("result.txt") {}

void Logger::logGameState(const GameState& state) const
{
    m_out_stream<<"state "<< state.current_room;
    const Room& cur_room = m_dungeon.get_room(state.current_room);

    _print_res(cur_room.resources.find(ResourceType::IRON)->second);
    _print_res(cur_room.resources.find(ResourceType::GOLD)->second);
    _print_res(cur_room.resources.find(ResourceType::GEMS)->second);
    _print_res(cur_room.resources.find(ResourceType::EXP)->second);

    m_out_stream<<'\n';
}

void Logger::_print_res(int res) const
{
    if( res > -1)
        m_out_stream<<' '<<res;
    else
        m_out_stream<<" _";
}

void Logger::logMoveAction(int move_to) const
{
    m_out_stream<<"go "<<move_to<<'\n';
}
void Logger::logCollectAction(ResourceType res) const
{
    m_out_stream<<"collect "<<m_res_manager.res_type_to_str(res)<<'\n';
}

void Logger::logGameResult(const GameState& state) const
{
    m_out_stream<<"result";
    int total_res = 0;
    
    auto collect_res = [this, &state, &total_res](ResourceType type){
        auto it = state.collected_resources.find(type);
        int res = 0;
        if(it != state.collected_resources.end())
            res = it->second;
        m_out_stream<<' '<<res;
        total_res += res * m_res_manager.get_res_value(type);
    };

    collect_res(ResourceType::IRON);
    collect_res(ResourceType::GOLD);
    collect_res(ResourceType::GEMS);
    collect_res(ResourceType::EXP);

    m_out_stream<<' '<<total_res<<'\n';
}