/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/

#ifndef EX4_REMOTEPLAYER_H
#define EX4_REMOTEPLAYER_H


#include "Player.h"
#include "Client.h"

class RemotePlayer : public Player {
public:
    /**
     * Human player constructor we extend of client setting.
     * @param symbol player symbol.
     * @param board board to play on.
     * @param gameLogic game logic to play by.
     * @param client client.
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
     * Receive opponent last move and update this player board.
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
