//
// Created by sapirblutman on 02/12/17.
//

#ifndef EX4_REMOTEPLAYER_H
#define EX4_REMOTEPLAYER_H


#include "Player.h"

class RemotePlayer : public Player {
public:
    /**
     * Human player constructor.
     * @param symbol player symbol
     * @param board board to play on.
     * @param gameLogic game logic to play by.
     */
    RemotePlayer(char symbol, Board *board, GameLogic *gameLogic) : Player(symbol, board, gameLogic) {};


    /**
     * Plays one turn and returns vector of board coordinates that has been flipped.
     * @return vector of board coordinates that has been flipped
     */
    virtual vector<BoardCoordinates> playOneTurn();
};


#endif //EX4_REMOTEPLAYER_H
