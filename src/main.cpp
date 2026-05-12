#include <iostream>

#include "MapLoader.hpp"

void USAGE()
{
    std::cout<<"alice_bot <path to input file>\n";
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        USAGE();
        return 2;
    }
    std::string input_file(argv[1]);
    try
    {
        MapLoader map_loader;
        map_loader.parse_and_load_map(input_file);
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Error while loading map: "<< e.what() << '\n';
        return 2;
    }

    return 0;
}
