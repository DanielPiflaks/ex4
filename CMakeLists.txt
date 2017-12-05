cmake_minimum_required(VERSION 3.8)
project(ex4)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES_CLIENT src/client/Board.cpp src/client/Board.h src/client/Player.h src/client/HumanPlayer.h src/client/HumanPlayer.cpp src/client/Player.cpp src/client/Game.h src/client/Game.cpp src/client/GameParameters.cpp src/client/GameParameters.h src/client/BoardCoordinates.cpp src/client/BoardCoordinates.h src/client/GameLogic.cpp src/client/GameLogic.h src/client/StandartGameLogic.cpp src/client/StandartGameLogic.h src/client/AIPlayer.h src/client/AIPlayer.cpp src/client/MiniMaxSimulator.cpp src/client/MiniMaxSimulator.h src/client/RemotePlayer.cpp src/client/RemotePlayer.h src/client/Client.cpp src/client/Client.h src/client/HumanPlayerSender.cpp src/client/HumanPlayerSender.h)
set(TESTS_FILES tests/MiniMaxSimulatorTest.cpp tests/BoardTest.cpp tests/GameLogicTest.cpp)
set(SOURCE_FILES_SERVER  src/server/Server.cpp src/server/Server.h)

add_executable(ex4_server ${SOURCE_FILES_SERVER} src/server/main_server.cpp)
add_executable(ex4_client ${SOURCE_FILES_CLIENT} src/client/main.cpp)
add_executable(tests ${SOURCE_FILES_CLIENT} ${TESTS_FILES} tests/gtest_main.cpp)

target_link_libraries(tests gtest gtest_main pthread)
add_test(ex4 ex4)