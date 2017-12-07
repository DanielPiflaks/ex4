//
// Created by sapirblutman on 05/12/17.
//

#include "HumanPlayerSender.h"

map<BoardCoordinates, vector<BoardCoordinates> > HumanPlayerSender::playOneTurn() {
    map<BoardCoordinates, vector<BoardCoordinates> > mapOfMoves = HumanPlayer::playOneTurn();
    //Send wanted move.
    client->sendMove(mapOfMoves.begin()->first);
    return mapOfMoves;
}

void HumanPlayerSender::endGameFunction() {
    //Receive that other player can't move.
    client->receiveMove();
    client->sendEndGameMessage();
    //client->disconnectServer();
}