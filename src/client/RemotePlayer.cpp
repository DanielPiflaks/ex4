//
// Created by sapirblutman on 02/12/17.
//

#include <limits>
#include "RemotePlayer.h"


map<BoardCoordinates, vector<BoardCoordinates> > RemotePlayer::playOneTurn() {
    //Get map of all possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves = gameLogic->getPossibleGameMoves(playerMoves,
                                                                                                     symbol);

    map<BoardCoordinates, vector<BoardCoordinates> > playerMove;
    vector<BoardCoordinates> flippedSymbols;


    //Check if there are no possible moves and notify player about it.
    if (possibleMoves.begin()->second.empty()) {
        char dummy;
        cout << "No possible moves. Play passes back to the other player."
                " Press enter to continue.";

        cin.get(dummy);

        /*********************************
         * CHangggeeebn
         */


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


BoardCoordinates RemotePlayer::getPlayerChoice(vector<BoardCoordinates> possibleMoves) {

    int row, column;
    bool validChoice = false;

    //While player choice isn't valid, try to get it.
    do {
        cout << "Please enter your move row col:";
        cin >> row >> column;
        //Ignore \n.
        cin.ignore();

        if (!board->isOnBoard(row, column)) {
            cout << "Choice is out of board! Please choose valid row and column" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        //Check if choice is possible move.
        for (int i = 0; i < possibleMoves.size(); i++) {
            if ((row == possibleMoves[i].getRow()) && (column == possibleMoves[i].getColumn())) {
                validChoice = true;
                break;
            }
        }

        if (!validChoice) {
            cout << "No such move exist in your option.Please Select valid one." << endl;
            printPossibleMoves(possibleMoves);
        }

    } while (((row > board->getNumRows()) || (column > board->getNumCols())) || (!validChoice));
    //Return player choice.
    return BoardCoordinates(row, column);
}

void RemotePlayer::printPossibleMoves(vector<BoardCoordinates> possibleMoves) {
    cout << "Your possible moves: ";
    //Print each possible move.
    for (int i = 0; i < possibleMoves.size(); i++) {
        cout << possibleMoves[i];
    }
    cout << endl;
}
