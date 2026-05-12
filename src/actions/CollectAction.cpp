#include "actions/CollectAction.hpp"

CollectAction::CollectAction(int room_num, ResourceType res) : m_room(room_num), m_res(res){}

void CollectAction::act(Dungeon& dungeon, GameState& game_state)
{
    Room& room = dungeon.get_room(m_room);
    game_state.collected_resources[m_res] += room.resources[m_res];
    room.resources[m_res] = -1;
    if(room.collected_res)
        game_state.food--;
    room.collected_res = true;
}
