#ifndef MAP_LOADER_HPP
#define MAP_LOADER_HPP

#include <string>

class MapLoader
{
public:
    MapLoader() = default;

    void parse_and_load_map(const std::string& path);
};

#endif
