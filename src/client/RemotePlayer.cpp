/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/

#include "RemotePlayer.h"

RemotePlayer::~RemotePlayer() {
}

map<BoardCoordinates, vector<BoardCoordinates> > RemotePlayer::playOneTurn() {
    //Print who it's turn to play.
    cout << getSymbol() << ": It's your move" << endl;
    //Get map of all possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves = gameLogic->getPossibleGameMoves(playerMoves,
                                                                                                     symbol);
    map<BoardCoordinates, vector<BoardCoordinates> > playerMove;
    vector<BoardCoordinates> flippedSymbols;
    vector<BoardCoordinates> allMoves;

    //For board coordinate, get its possible move and insert in to all moves vector.
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = possibleMoves.begin();
         moves != possibleMoves.end(); ++moves) {
        for (int i = 0; i < moves->second.size(); i++) {
            if (find(allMoves.begin(), allMoves.end(), moves->second[i]) == allMoves.end()) {
                allMoves.push_back(moves->second[i]);
            }
        }
    }

    //Check if there are no possible moves and notify player about it.
    if (allMoves.empty()) {
        cout << "No possible moves. Play passes back to the other player." << endl;

        client->sendNoPossibleMovesMessage();

        //Return empty vector.
        return playerMove;
    }

    //Get player choice.
    BoardCoordinates playerChoice = client->receiveMove();
    if (board->isOnBoard(playerChoice.getRow(), playerChoice.getColumn())) {
        //Print data massage about opponent last move.
        cout << getSymbol() << ": played" << playerChoice << endl;
    } else {
        cout << "Player has no possible moves" << endl;
    }

    //Get flipped symbols vector.
    flippedSymbols = gameLogic->flipSymbols(possibleMoves,
                                            playerChoice, getSymbol());
    cout << endl;
    //Return them.
    playerMove.insert(pair<BoardCoordinates, vector<BoardCoordinates> >(playerChoice, flippedSymbols));

}

void RemotePlayer::endGameFunction() {
    //Receive that other player can't move.
    client->receiveMove();
    client->sendEndGameMessage();
    client->disconnectServer();
    delete client;
}