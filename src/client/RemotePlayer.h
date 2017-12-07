//
// Created by sapirblutman on 02/12/17.
//

#ifndef EX4_REMOTEPLAYER_H
#define EX4_REMOTEPLAYER_H


#include "Player.h"
#include "Client.h"

class RemotePlayer : public Player {
public:
    /**
     * Human player constructor.
     * @param symbol player symbol
     * @param board board to play on.
     * @param gameLogic game logic to play by.
     */
    RemotePlayer(char symbol, Board *board, GameLogic *gameLogic, Client *client) :
            Player(symbol, board, gameLogic) {
        this->client = client;
    };

    /**
     * Destructor.
     */
    ~RemotePlayer();

    /**
     * Plays one turn and returns vector of board coordinates that has been flipped.
     * @return vector of board coordinates that has been flipped
     */
    virtual map<BoardCoordinates, vector<BoardCoordinates> > playOneTurn();

    /**
     * End game behavior of player.
     */
    virtual void endGameFunction();

private:
    Client *client;
};


#endif //EX4_REMOTEPLAYER_H
