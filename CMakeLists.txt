cmake_minimum_required(VERSION 3.22)

project(alice_bot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(alice_bot
    src/main.cpp
    src/GameLoader.cpp
    src/Dungeon.cpp
    src/Resource.cpp
    src/BFS.cpp
    src/actions/CollectAction.cpp
    src/actions/MoveAction.cpp
    src/bots/AliceBot.cpp
    src/GameManager.cpp
    src/Logger.cpp
)

target_include_directories(alice_bot PRIVATE include)
