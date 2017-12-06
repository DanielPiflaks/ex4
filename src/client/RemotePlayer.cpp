//
// Created by sapirblutman on 02/12/17.
//

#include "RemotePlayer.h"


map<BoardCoordinates, vector<BoardCoordinates> > RemotePlayer::playOneTurn() {
    //Get map of all possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves = gameLogic->getPossibleGameMoves(playerMoves,
                                                                                                     symbol);

    map<BoardCoordinates, vector<BoardCoordinates> > playerMove;
    vector<BoardCoordinates> flippedSymbols;


    //Check if there are no possible moves and notify player about it.
    if (possibleMoves.begin()->second.empty()) {
        cout << "No possible moves. Play passes back to the other player."
                " Press enter to continue.";

        client->sendNoPossibleMovesMessage();

        cout << endl;
        //Return empty vector.
        return playerMove;
    }

    //Get player choice.
    BoardCoordinates playerChoice = client->receiveMove();

    //Get flipped symbols vector.
    flippedSymbols = gameLogic->flipSymbols(possibleMoves,
                                            playerChoice, getSymbol());
    cout << endl;
    //Return them.
    playerMove.insert(pair<BoardCoordinates, vector<BoardCoordinates> >(playerChoice, flippedSymbols));
}


void RemotePlayer::endGameFunction(){
    client->sendEndGameMessage();
}