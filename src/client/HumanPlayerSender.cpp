//
// Created by sapirblutman on 05/12/17.
//

#include "HumanPlayerSender.h"

map <BoardCoordinates, vector<BoardCoordinates> > HumanPlayerSender::playOneTurn() {
    map<BoardCoordinates, vector<BoardCoordinates> > mapOfMoves = HumanPlayer::playOneTurn();
    client->sendMove(mapOfMoves.begin()->first);
}
