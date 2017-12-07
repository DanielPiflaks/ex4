/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/

#ifndef EX4_HUMANPLAYERSENDER_H
#define EX4_HUMANPLAYERSENDER_H


#include "HumanPlayer.h"
#include "Client.h"

/**
 * Constructor, implement the human player class constructor and in addition-
 * set the member of client.
 */
class HumanPlayerSender : public HumanPlayer {
public:
    HumanPlayerSender(char symbol, Board *board, GameLogic *gameLogic, Client *client) :
            HumanPlayer(symbol, board, gameLogic) {
        this->client = client;
    };

    /**
     * Destructor.
     */
    ~HumanPlayerSender();

    /**
     * This class is derived from human player class, so the implementation of this function is same,
     * with addition of sending this player last move to server.
     * @return vector of board coordinates that has been flipped.
     */
    map<BoardCoordinates, vector<BoardCoordinates> > playOneTurn();

    /**
     * Receive from server that opponent can't play, send back to server
     * that this player can't play, and disconnect from socket.
     */
    virtual void endGameFunction();

private:
    Client *client;
};


#endif //EX4_DANIELHARA_H
