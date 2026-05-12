#ifndef PLAYER_HPP
#define PLAYER_HPP

struct Player
{
    int cur_room_pos = 0;
    int food = 0;

    Player() = default;
    Player(int f) : food(f){}
};

#endif
