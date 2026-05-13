#include "BFS.hpp"

#include <iostream>

BFS::BFS(const Dungeon& dungeon) : m_dungeon(dungeon) {}

std::vector<int> BFS::build_path(int start_room, std::function<bool(const Room&)> end_predicate, std::function<bool(const Room&)> path_predicate)
{
    m_visited = { start_room };
    m_queue = { start_room };
    m_parent = {};
    while(!m_queue.empty())
    {
        int current = m_queue.front();
        m_queue.pop_front();

        const Room& cur_room = m_dungeon.get_room(current);
        if(end_predicate(cur_room))
            return reconstruct_path(start_room, current);
        for(const int adj: cur_room.adjacent)
        {
            if(m_visited.count(adj) == 0 && path_predicate(m_dungeon.get_room(adj)))
            {
                m_visited.insert(adj);
                m_parent[adj] = current;
                m_queue.push_back(adj);
            }
        }
    }

    return {};
}

std::vector<int> BFS::reconstruct_path(int start_room, int end_room)
{
    std::vector<int> path;
    int curr = end_room;

    while(curr != start_room)
    {
        path.push_back(curr);
        curr = m_parent[curr];
    }
    std::reverse(path.begin(), path.end());
    return path;
}