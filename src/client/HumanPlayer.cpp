/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/

#include <algorithm>
#include <limits>
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"


map<BoardCoordinates, vector<BoardCoordinates> > HumanPlayer::playOneTurn() {
    //Print who it's turn to play.
    cout << getSymbol() << ": It's your move" << endl;
    //Get map of all possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves = gameLogic->getPossibleGameMoves(playerMoves,
                                                                                                     symbol);
    vector<BoardCoordinates> allMoves;
    vector<BoardCoordinates> flippedSymbols;
    map<BoardCoordinates, vector<BoardCoordinates> > playerMove;

    //For board coordinate, get its possible move and insert in to all moves vector.
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = possibleMoves.begin();
         moves != possibleMoves.end(); ++moves) {
        for (int i = 0; i < moves->second.size(); i++) {
            if (find(allMoves.begin(), allMoves.end(), moves->second[i]) == allMoves.end()) {
                allMoves.push_back(moves->second[i]);
            }
        }
    }
    //Sort vector.
    sort(allMoves.begin(), allMoves.end());
    //Check if there are no possible moves and notify player about it.
    if (allMoves.empty()) {
        cout << "No possible moves. Play passes back to the other player."
                " Press enter to continue.";
        cin.ignore();
        cout << endl;
        //Return empty map.
        return playerMove;
    }

    //Print all possible moves.
    printPossibleMoves(allMoves);
    cout << endl;
    //Get player choice.
    BoardCoordinates playerChoice = getPlayerChoice(allMoves);

    //Get flipped symbols vector.
    flippedSymbols = gameLogic->flipSymbols(possibleMoves,
                                            playerChoice, getSymbol());
    cout << endl;
    //Return them.
    playerMove.insert(pair<BoardCoordinates, vector<BoardCoordinates> >(playerChoice, flippedSymbols));
}

BoardCoordinates HumanPlayer::getPlayerChoice(vector<BoardCoordinates> possibleMoves) {

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

void HumanPlayer::printPossibleMoves(vector<BoardCoordinates> possibleMoves) {
    cout << "Your possible moves: ";
    //Print each possible move.
    for (int i = 0; i < possibleMoves.size(); i++) {
        cout << possibleMoves[i];
    }
    cout << endl;
}

void HumanPlayer::endGameFunction() {

}