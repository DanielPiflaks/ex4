//
// Created by sapirblutman on 05/12/17.
//

#include "HumanPlayerSender.h"

map<BoardCoordinates, vector<BoardCoordinates> > HumanPlayerSender::playOneTurn() {
    map<BoardCoordinates, vector<BoardCoordinates> > mapOfMoves = HumanPlayer::playOneTurn();
    //Get wanted move.
    BoardCoordinates wantedMove = mapOfMoves.begin()->first;
    //Check if wanted move is valid move on board.
    if (board->isOnBoard(wantedMove.getRow(), wantedMove.getColumn())) {
        //Send wanted move.
        client->sendMove(wantedMove);
    } else {
        //Mark to client that there is no move with 0,0.
        client->sendMove(BoardCoordinates(0, 0));
    }

    return mapOfMoves;
}

void HumanPlayerSender::endGameFunction() {
    client->sendEndGameMessage();
}