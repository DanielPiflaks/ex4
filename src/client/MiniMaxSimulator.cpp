/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/

#include "MiniMaxSimulator.h"

MiniMaxSimulator::MiniMaxSimulator(GameLogic *gameLogic) : gameLogic(gameLogic) {}


MiniMaxSimulator::~MiniMaxSimulator() {

}

int MiniMaxSimulator::getScoreByMove(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                                     BoardCoordinates move) {
    //Save board to return to first board.
    Board savedBoard = gameLogic->getBoard();
    //Get flipped symbols vector.
    vector<BoardCoordinates> flippedSymbols = gameLogic->flipSymbols(allChoices,
                                                                     move, computerPlayer->getSymbol());

    //Update removed symbol for opponent.
    opponent->updatePlayerSymbolRemoved(flippedSymbols);
    //Update added symbols for computer player.
    computerPlayer->updatePlayerSymbolAdd(flippedSymbols);
    //Get scores.
    int scoreOpponent = opponent->getScore();
    int scoreComputer = computerPlayer->getScore();
    //Get opponent possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > opponentPossibleMoves = gameLogic->getPossibleGameMoves(
            opponent->getPlayerMoves(),
            opponent->getSymbol());

    int max = 0;
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = opponentPossibleMoves.begin();
         moves != opponentPossibleMoves.end(); ++moves) {
        for (int i = 0; i < moves->second.size(); i++) {
            BoardCoordinates singleMove = moves->second[i];
            //Get number of possible flips.
            int numberOfPossibleFlips = gameLogic->numberOfPossibleFlips(opponentPossibleMoves,
                                                                         singleMove,
                                                                         opponent->getSymbol());
            //Get score of opponent after change.
            int scoreOpponentAfterChange = scoreOpponent + numberOfPossibleFlips;
            //Get computer score after change.
            int scoreComputerAfterChange = scoreComputer - numberOfPossibleFlips + 1;
            //Calc delta.
            int delta = scoreOpponentAfterChange - scoreComputerAfterChange;
            //Check if delta is bigget then max param and update max.
            if (delta > max) {
                max = delta;
            }
        }
    }
    //Set back all flipped symbols.
    computerPlayer->updatePlayerSymbolRemoved(flippedSymbols);

    //Remove move.
    flippedSymbols.erase(remove(flippedSymbols.begin(), flippedSymbols.end(), move),
                         flippedSymbols.end());

    opponent->updatePlayerSymbolAdd(flippedSymbols);

    //Copy board to be as saved board.
    copyBoardContent(savedBoard, &gameLogic->getBoard());
    //Return max score for game.
    return max;
}

void MiniMaxSimulator::setComputerPlayer(Player *computerPlayer) {
    MiniMaxSimulator::computerPlayer = computerPlayer;
}

void MiniMaxSimulator::setOpponent(Player *opponent) {
    MiniMaxSimulator::opponent = opponent;
}

void MiniMaxSimulator::copyBoardContent(Board oldBoard, Board *currentBoard) {
    //Copy board content from old to current.
    for (int i = 0; i < oldBoard.getNumRows(); ++i) {
        for (int j = 0; j < oldBoard.getNumCols(); ++j) {
            currentBoard->putSymbolOnBoard(i + 1, j + 1, oldBoard.getSymbolByPlace(i + 1, j + 1));
        }
    }
}