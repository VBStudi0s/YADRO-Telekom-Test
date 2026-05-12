#ifndef IACTION_HPP
#define IACTION_HPP

#include "Dungeon.hpp"
#include "GameState.hpp"

class IAction
{
public:
    virtual void act(Dungeon& dungeon, GameState& game_state) = 0;

    virtual ~IAction() = default;
};

#endif
