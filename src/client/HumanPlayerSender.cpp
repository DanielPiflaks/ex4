/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/

#include "HumanPlayerSender.h"

HumanPlayerSender::~HumanPlayerSender() {
}

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
    client->disconnectServer();
    delete client;
}