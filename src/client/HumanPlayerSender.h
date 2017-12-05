//
// Created by sapirblutman on 05/12/17.
//

#ifndef EX4_HUMANPLAYERSENDER_H
#define EX4_HUMANPLAYERSENDER_H


#include "HumanPlayer.h"
#include "Client.h"

class HumanPlayerSender :public HumanPlayer {
public:
    HumanPlayerSender(char symbol, Board *board, GameLogic *gameLogic, Client *client) :
            HumanPlayer(symbol, board, gameLogic) {
        this->client = client;
    };

    map<BoardCoordinates, vector<BoardCoordinates> > playOneTurn();

private:
    Client *client;
};


#endif //EX4_DANIELHARA_H
