#include "GameLoader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>

LoadResult GameLoader::parse_and_load_game(const std::string& path)
{
    m_rooms.clear();
    std::ifstream file_stream(path);
    if(!file_stream)
        throw std::runtime_error("Unable to open file: " + path);

    // preparing parsing stuff
    std::string line;
    std::stringstream sstream;
    std::getline(file_stream, line);

    // parsing first line (number of rooms)
    sstream = std::stringstream(line);
    int num_of_rooms = 0;
    sstream >> num_of_rooms;
    if(!sstream.eof() || num_of_rooms <= 0 || num_of_rooms > 255)
        throw std::runtime_error("Invalid input file line: " + line);

    // parsing all rooms
    for(int i=0; i<=num_of_rooms; i++)
    {
        std::getline(file_stream, line);
        sstream = std::stringstream(line);

        int room_num = 0;
        if(!(sstream >> room_num) || room_num < 0 || room_num > num_of_rooms)
            throw std::runtime_error("Unable to read room number in line: " + line);
        m_rooms[room_num] = Room(room_num);

        // read adjacent rooms
        std::string adjacents_str;
        sstream >> adjacents_str;
        std::replace(adjacents_str.begin(), adjacents_str.end(), ',', ' ');
        std::stringstream adj_stream(adjacents_str);
        std::vector<int> adj_vec;
        int adj = 0;
        while(adj_stream >> adj)
        {
            if(adj < 0 || adj > num_of_rooms || adj == room_num)
                throw std::runtime_error("Error in reading line: " + line);
            adj_vec.push_back(adj);
            m_rooms[room_num].add_adjacent(adj);
            if(m_rooms.find(adj) != m_rooms.end())      // symmetrically for safety
                m_rooms[adj].add_adjacent(m_rooms[room_num].room_number);
        }
        if(!adj_stream.eof())
            throw std::runtime_error("Error in reading line: " + line);

        // read resources
        auto read_res = [this, &line, &sstream, &room_num](ResourceType type){
            int good = 0;
            if(!(sstream>>good) || good < 0 || good > 255)
                throw std::runtime_error("Error in reading line: " + line);
                m_rooms[room_num].set_resource(type, good);
            };

        read_res(ResourceType::IRON);
        read_res(ResourceType::GOLD);
        read_res(ResourceType::GEMS);
        read_res(ResourceType::EXP);

        if(!sstream.eof())
            throw std::runtime_error("error in reading line: " + line);
    }

    Dungeon dungeon(m_rooms);

    // reading food and doubled resource
    std::getline(file_stream, line);
    sstream = std::stringstream(line);

    int food = 0;
    if(!(sstream >> food) || food < 2 || food > 255)
        throw std::runtime_error("error in reading line: " + line);

    std::string doubled_resource;
    if(!(sstream >> doubled_resource))
        throw std::runtime_error("error in reading line: " + line);

    ResourceManager r_manager;
    if(!r_manager.is_valid_resource(doubled_resource))
        throw std::runtime_error("error in reading line: " + line);
    if(!sstream.eof())
            throw std::runtime_error("error in reading line: " + line);
    return LoadResult(dungeon, food, r_manager.str_to_res_type(doubled_resource));
}
