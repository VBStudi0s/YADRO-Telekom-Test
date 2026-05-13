#include <iostream>

#include "GameLoader.hpp"
#include "GameManager.hpp"
#include "bots/AliceBot.hpp"

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

    LoadResult res;
    Dungeon dungeon;
    ResourceManager res_manager;
    Logger logger(dungeon, res_manager);
    try
    {
        GameLoader loader;
        res = loader.parse_and_load_game(input_file);
    }
    catch(const std::exception& e)
    {
        std::string err(e.what());
        logger.logError(err);
        return 2;
    }

    GameState state;
    state.food = res.food;
    dungeon = res.dungeon;
    res_manager.double_resource_value(res.doubled_res);

    GameManager game(dungeon, state, res_manager, logger);

    std::unique_ptr<IBot> bot = std::make_unique<AliceBot>(dungeon, state, res_manager);

    game.attach_bot(std::move(bot));
    game.simulate();

    return 0;
}
