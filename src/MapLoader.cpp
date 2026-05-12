#include "MapLoader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>

void MapLoader::parse_and_load_map(const std::string& path)
{
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
    if(!sstream.eof() || num_of_rooms <= 0)
        throw std::runtime_error("Invalid input file line: " + line);
    std::cout<<"Number of rooms: "<<num_of_rooms<<'\n';    // write

    // parsing all rooms
    for(int i=0; i<=num_of_rooms; i++)
    {
        std::getline(file_stream, line);
        sstream = std::stringstream(line);

        int room_num = 0;
        if(!(sstream >> room_num))
            throw std::runtime_error("Unable to read room number in line: " + line);
        std::cout<<"Room number "<<room_num<<'\n';

        // read adjacent rooms
        std::string adjacents_str;
        sstream >> adjacents_str;
        std::replace(adjacents_str.begin(), adjacents_str.end(), ',', ' ');
        std::stringstream adj_stream(adjacents_str);
        std::vector<int> adj_vec;
        int adj = 0;
        while(adj_stream >> adj)
        {
            adj_vec.push_back(adj);
            std::cout<<"Adj: "<<adj<<'\n';
        }
        if(!adj_stream.eof())
        throw std::runtime_error("Error in reading line: " + line);

        // read resources
        int good = 0;
        for(int i=0; i<4; i++)
        {
            if(!(sstream>>good))
                throw std::runtime_error("Error in reading line: " + line);
            std::cout<<"Resource: "<<good<<'\n';
        }
        if(!sstream.eof())
            throw std::runtime_error("error in reading line: " + line);
    }

    // reading food and doubled resource
    std::getline(file_stream, line);
    sstream = std::stringstream(line);

    int food = 0;
    if(!(sstream >> food))
        throw std::runtime_error("error in reading line: " + line);

    std::cout<<"Food: "<<food<<'\n';
    std::string doubled_resource;
    if(!(sstream >> doubled_resource))
        throw std::runtime_error("error in reading line: " + line);

    // TODO: fix this
    if(doubled_resource == "iron")
        std::cout<<"Doubled: "<<doubled_resource<<'\n';
    else if(doubled_resource == "gold")
        std::cout<<"Doubled: "<<doubled_resource<<'\n';
    else if (doubled_resource == "gems")
        std::cout<<"Doubled: "<<doubled_resource<<'\n';
    else if (doubled_resource == "exp")
        std::cout<<"Doubled: "<<doubled_resource<<'\n';
    else
        throw std::runtime_error("error in reading line: " + line);
    if(!sstream.eof())
            throw std::runtime_error("error in reading line: " + line);
}
