#ifndef BFS_HPP
#define BFS_HPP

#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <deque>

#include "Dungeon.hpp"

class BFS
{
    const Dungeon& m_dungeon;

    std::deque<int> m_queue;
    std::unordered_set<int> m_visited;
    std::unordered_map<int, int> m_parent;
public:
    BFS(const Dungeon& dungeon);

    std::vector<int> build_path(
        int start_room, 
        std::function<bool(const Room&)> end_predicate, 
        std::function<bool(const Room&)> path_predicate  = [](const Room& r){ return true; }
    );
private:
    std::vector<int> reconstruct_path(int start_room, int end_room);
};

#endif