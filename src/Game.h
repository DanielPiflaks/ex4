/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#ifndef EX2_GAME_H
#define EX2_GAME_H

using namespace std;

#include <iostream>
#include <list>
#include <vector>
#include "Player.h"
#include "GameParameters.h"
#include "BoardCoordinates.h"

class Game {
public:
    /**
     * Game constructor.
     * @param gameParameters game parameters know how to play.
     */
    Game(GameParameters &gameParameters);

    /**
     * Game destructor.
     */
    ~Game();

    /**
     * Runs single game by input game parameters.
     */
    void RunSingleGame();

    /**
     * Puts player symbols to start position.
     */
    void putSymbolsStartPosition();

private:
    Board *gameBoard;
    Player *firstPlayer;
    Player *secondPlayer;
};

#endif //EX2_GAME_H
