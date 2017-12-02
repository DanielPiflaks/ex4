/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/
#include <gtest/gtest.h>
#include "../src/Board.h"

//Check that copy constructor of board works.
TEST(BoardTest, CopyConstructorCheck) {
    const int boardRow = 4;
    const int boardColumn = 4;
    //Create first board.
    Board firstBoard(boardRow, boardColumn);
    //Put random symbols on board.
    firstBoard.putSymbolOnBoard(3, 2, 'x');
    firstBoard.putSymbolOnBoard(1, 1, 'o');
    //Copy board to board.
    Board copyBoard = firstBoard;
    //Check that boards are equal.
    EXPECT_EQ(copyBoard, firstBoard);
}
//Check that we can't go to invalid place in board.
TEST(BoardTest, NotValidPlaceCheck) {
    const int boardRow = 4;
    const int boardColumn = 4;
    //Create board.
    Board boardToCheck(boardRow, boardColumn);

    //Check that negative negative isn't working.
    EXPECT_FALSE(boardToCheck.isOnBoard(-1, -1));
    //Check that positive negative isn't working.
    EXPECT_FALSE(boardToCheck.isOnBoard(314, -1));
    //Check that negative positive isn't working.
    EXPECT_FALSE(boardToCheck.isOnBoard(-34, 34));
    //We want that boar will be inside of the matrix, without 0 0
    EXPECT_FALSE(boardToCheck.isOnBoard(0, 0));

    //Check that On board is working.
    EXPECT_TRUE(boardToCheck.isOnBoard(2, 2));
    //Check Boarders
    EXPECT_TRUE(boardToCheck.isOnBoard(4, 4));
    EXPECT_TRUE(boardToCheck.isOnBoard(1, 1));

    //Check that get symbols isn't working in not current place.
    EXPECT_ANY_THROW(boardToCheck.getSymbolByPlace(-1, -1));
}