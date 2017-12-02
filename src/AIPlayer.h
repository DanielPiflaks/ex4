/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#ifndef EX3_ALPLAYER_H
#define EX3_ALPLAYER_H


#include "Player.h"
#include "MiniMaxSimulator.h"

class AIPlayer : public Player {
public:
    /**
    * Human player constructor.
    * @param symbol player symbol
    * @param board board to play on.
    * @param gameLogic game logic to play by.
    */
    AIPlayer(char symbol, Board *board, GameLogic *gameLogic, MiniMaxSimulator *wantedSimulator)
            : Player(symbol, board,
                     gameLogic) {simulator = wantedSimulator;};

    /**
     * Destructor.
     */
    ~AIPlayer();

    /**
     * Plays one turn and returns vector of board coordinates that has been flipped.
     * @return vector of board coordinates that has been flipped
     */
    virtual vector<BoardCoordinates> playOneTurn();

private:
    MiniMaxSimulator *simulator;
};


#endif //EX3_ALPLAYER_H
