/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/
#include "StandartGameLogic.h"


map<BoardCoordinates, vector<BoardCoordinates> >
StandartGameLogic::getPossibleGameMoves(vector<BoardCoordinates> playerMoves,
                                        char playerSymbol) {
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves;
    BoardCoordinates resultCoordinate;
    //For each player move, create vector of it's possible flip symbols of opponent.
    for (int i = 0; i < playerMoves.size(); i++) {
        vector<BoardCoordinates> movementsForCurrentMove;
        //Get column.
        int column = playerMoves[i].getColumn();
        //Get row.
        int row = playerMoves[i].getRow();
        //Check right possible plays.
        resultCoordinate = CheckByDirection(row, column, Right, playerSymbol);
        if ((resultCoordinate.getRow() != -1) && (resultCoordinate.getColumn() != -1)) {
            movementsForCurrentMove.push_back(resultCoordinate);
        }
        //Check left possible plays.
        resultCoordinate = CheckByDirection(row, column, Left, playerSymbol);
        if ((resultCoordinate.getRow() != -1) && (resultCoordinate.getColumn() != -1)) {
            movementsForCurrentMove.push_back(resultCoordinate);
        }
        //Check up possible plays.
        resultCoordinate = CheckByDirection(row, column, Up, playerSymbol);
        if ((resultCoordinate.getRow() != -1) && (resultCoordinate.getColumn() != -1)) {
            movementsForCurrentMove.push_back(resultCoordinate);
        }
        //Check down possible plays.
        resultCoordinate = CheckByDirection(row, column, Down, playerSymbol);
        if ((resultCoordinate.getRow() != -1) && (resultCoordinate.getColumn() != -1)) {
            movementsForCurrentMove.push_back(resultCoordinate);
        }
        //Check up left possible plays.
        resultCoordinate = CheckByDirection(row, column, UpLeft, playerSymbol);
        if ((resultCoordinate.getRow() != -1) && (resultCoordinate.getColumn() != -1)) {
            movementsForCurrentMove.push_back(resultCoordinate);
        }
        //Check down right possible plays.
        resultCoordinate = CheckByDirection(row, column, DownRight, playerSymbol);
        if ((resultCoordinate.getRow() != -1) && (resultCoordinate.getColumn() != -1)) {
            movementsForCurrentMove.push_back(resultCoordinate);
        }
        //Check up right possible plays.
        resultCoordinate = CheckByDirection(row, column, UpRight, playerSymbol);
        if ((resultCoordinate.getRow() != -1) && (resultCoordinate.getColumn() != -1)) {
            movementsForCurrentMove.push_back(resultCoordinate);
        }
        //Check down left possible plays.
        resultCoordinate = CheckByDirection(row, column, DownLeft, playerSymbol);
        if ((resultCoordinate.getRow() != -1) && (resultCoordinate.getColumn() != -1)) {
            movementsForCurrentMove.push_back(resultCoordinate);
        }
        //Sort moves.
        sort(movementsForCurrentMove.begin(), movementsForCurrentMove.end());
        //Add it to map by relevant move.
        possibleMoves[playerMoves[i]] = movementsForCurrentMove;
    }
    //Return possible moves.
    return possibleMoves;
}

vector<BoardCoordinates> StandartGameLogic::flipSymbols(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                                                        BoardCoordinates wantedChoice, char playerSymbol) {
    vector<BoardCoordinates> removePlaces;
    //For each coordinate check if player choice is in it and flip the row.
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = allChoices.begin();
         moves != allChoices.end(); ++moves) {
        //Get start coordinate.
        BoardCoordinates fromCoordinate = moves->first;
        //Get all possible moves.
        vector<BoardCoordinates> availableMoves = moves->second;
        //Check if wanted choice is in available moves.
        if (find(availableMoves.begin(), availableMoves.end(), wantedChoice) != availableMoves.end()) {
            //Flip wanted row.
            vector<BoardCoordinates> singleRow = singleRowToFlip(fromCoordinate,
                                                               wantedChoice, playerSymbol);
            flipOnBoard(singleRow, playerSymbol);
            //insert flipped row into remove places vector.
            for (int i = 0; i < singleRow.size(); ++i) {
                if (!(find(removePlaces.begin(), removePlaces.end(), singleRow[i]) != removePlaces.end())) {
                    removePlaces.push_back(singleRow[i]);
                }
            }
        }
    }
    return removePlaces;
}

vector<BoardCoordinates> StandartGameLogic::singleRowToFlip(BoardCoordinates start,
                                                          BoardCoordinates end, char playerSymbol) {
    vector<BoardCoordinates> flipCoordinates;
    //Get difference of row and col to know wanted direction.
    int rowDiff = start.getRow() - end.getRow();
    int colDiff = start.getColumn() - end.getColumn();

    int stepRow = 0, stepCol = 0, numberOfFlips = 0;

    //Set step row by the difference.
    if (rowDiff < 0) {
        stepRow = 1;
    } else if (rowDiff > 0) {
        stepRow = -1;
    }
    //Set step col by the difference.
    if (colDiff < 0) {
        stepCol = 1;
    } else if (colDiff > 0) {
        stepCol = -1;
    }

    //Check how many flips we need to do.
    if (colDiff != 0) {
        numberOfFlips = abs(colDiff);
    } else {
        numberOfFlips = abs(rowDiff);
    }

    int rowMovement = start.getRow();
    int colMovement = start.getColumn();
    int flipCounter = 0;
    //Flip symbols
    do {
        //Step by row.
        rowMovement = rowMovement + stepRow;
        //Step by column.
        colMovement = colMovement + stepCol;
        //Put symbols in wanted place on board.
        //getBoard().putSymbolOnBoard(rowMovement, colMovement, playerSymbol);
        //Remember flipped coordinates.
        flipCoordinates.push_back(BoardCoordinates(rowMovement, colMovement));
        flipCounter++;
    } while (flipCounter < numberOfFlips);
    //Return all flipped coordinates.
    return flipCoordinates;
}

BoardCoordinates StandartGameLogic::CheckByDirection(int startRow, int startColumn,
                                                     DirectionCheck direction, char playerSymbol) {
    int rowStep, columnStep, counter = 0;
    //Set by direction steps of row and column.
    switch (direction) {
        case Up: {
            rowStep = -1;
            columnStep = 0;
            break;
        }
        case Down: {
            rowStep = 1;
            columnStep = 0;
            break;
        }
        case Left: {
            rowStep = 0;
            columnStep = -1;
            break;
        }
        case Right: {
            rowStep = 0;
            columnStep = 1;
            break;
        }
        case UpLeft: {
            rowStep = -1;
            columnStep = -1;
            break;
        }
        case UpRight: {
            rowStep = -1;
            columnStep = 1;
            break;
        }
        case DownRight: {
            rowStep = 1;
            columnStep = 1;
            break;
        }
        case DownLeft: {
            rowStep = 1;
            columnStep = -1;
            break;
        }
        default: {
            rowStep = 1;
            columnStep = 1;
            break;
        }
    }

    int rowMovement = startRow + rowStep;
    int columnMovement = startColumn + columnStep;
    char currentSymbol;
    //Check if wanted row and col to check is valid.
    if (getBoard().isOnBoard(rowMovement, columnMovement)) {
        //Run on board while you see opponent symbol.
        do {
            currentSymbol = getBoard().getSymbolByPlace(rowMovement, columnMovement);
            rowMovement = rowMovement + rowStep;
            columnMovement = columnMovement + columnStep;
            counter++;
        } while (getBoard().isOnBoard(rowMovement, columnMovement)
                 && (currentSymbol != playerSymbol)
                 && (currentSymbol != ' '));
    }
    //Check if coordinate is valid and return it.
    if (getBoard().isOnBoard(rowMovement - rowStep, columnMovement - columnStep)
        && (counter > 1) && (currentSymbol == ' ')) {
        return BoardCoordinates(rowMovement - rowStep, columnMovement - columnStep);
    } else {
        //Mark that BoardCoordinate isn't valid.
        return BoardCoordinates(-1, -1);
    }

}

int StandartGameLogic::numberOfPossibleFlips(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                                             BoardCoordinates wantedChoice, char playerSymbol) {
    //Counter.
    int flipNumbers = 0;
    vector<BoardCoordinates> removePlaces;
    //For each coordinate check if player choice is in it and flip the row.
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = allChoices.begin();
         moves != allChoices.end(); ++moves) {
        //Get start coordinate.
        BoardCoordinates fromCoordinate = moves->first;
        //Get all possible moves.
        vector<BoardCoordinates> availableMoves = moves->second;
        //Check if wanted choice is in available moves.
        if (find(availableMoves.begin(), availableMoves.end(), wantedChoice) != availableMoves.end()) {
            //Flip wanted row.
            vector<BoardCoordinates> singleRow = singleRowToFlip(fromCoordinate,
                                                               wantedChoice, playerSymbol);
            flipNumbers = flipNumbers + singleRow.size();
            //insert flipped row into remove places vector.
            for (int i = 0; i < singleRow.size(); ++i) {
                if (!(find(removePlaces.begin(), removePlaces.end(), singleRow[i]) != removePlaces.end())) {
                    removePlaces.push_back(singleRow[i]);
                }
            }
        }
    }
    return flipNumbers;
}