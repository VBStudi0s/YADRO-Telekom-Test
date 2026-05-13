#ifndef COLLECT_ACTION_HPP
#define COLLECT_ACTION_HPP

#include "IAction.hpp"
#include "Resource.hpp"

class CollectAction : public IAction
{
    int m_room = 0;
    ResourceType m_res;
public:
    CollectAction(int room_num, ResourceType res);

    void act(Dungeon& dungeon, GameState& game_state) override;
};

#endif
