//
// Created by sapirblutman on 05/12/17.
//

#include "HumanPlayerSender.h"

map <BoardCoordinates, vector<BoardCoordinates> > HumanPlayerSender::playOneTurn() {
    HumanPlayer::playOneTurn();
    client->sendMove();
}
