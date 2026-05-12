#ifndef MOVE_ACTION_HPP
#define MOVE_ACTION_HPP

#include "IAction.hpp"

class MoveAction : public IAction
{
    int m_move_to = 0;
public:
    MoveAction(int move_to);

    void act(Dungeon& dungeon, GameState& game_state) override;
};

#endif
