#include "actions/MoveAction.hpp"

#include <iostream>

MoveAction::MoveAction(int move_to) : m_move_to(move_to){}

void MoveAction::act(Dungeon& dungeon, GameState& game_state)
{
    game_state.current_room = m_move_to;
    dungeon.get_room(m_move_to).visited = true;
    game_state.food--;

    std::cout<<"Go to "<<m_move_to<<'\n';
}
