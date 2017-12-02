/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#ifndef BOARD_H
#define BOARD_H

using namespace std;

#include <iostream>
#include <vector>
#include "BoardCoordinates.h"

class Board {
public:

    //Constructor.
    Board(int numRows, int numCols);

    //Copy constructor.
    Board(const Board &oldBoard);

    //Destructor.
    ~Board();

    //Draws board.
    void drawBoard() const;

    //Take symbol and put it on board in wanted row and column.
    void putSymbolOnBoard(int row, int column, char symbol);

    //Returns true if row and column is
    bool isOnBoard(int row, int column) const;

    //Returns symbol that is in input row and column place.
    char getSymbolByPlace(int row, int column) const;

    //Returns board number of rows.
    int getNumRows() const;

    //Returns board number of column.
    int getNumCols() const;

    //Overload == operator.
    bool operator==(const Board &board) const;

private:
    int numRows;
    int numCols;
    char **boardMatrix;

    //Frees allocated board matrix.
    void freeBoardMatrix();
};

#endif //BOARD_H

