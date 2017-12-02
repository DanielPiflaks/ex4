/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#include "GameLogic.h"

GameLogic::GameLogic(GameLogic *gameLogic) {
    board = new Board(*gameLogic->board);
}

GameLogic::GameLogic(Board *board) :
        board(board) {
}

GameLogic::~GameLogic() {

}

Board &GameLogic::getBoard() {
    return *board;
}

void GameLogic::flipOnBoard(vector<BoardCoordinates> coordinatesToFlip, char symbol) {
    for (int i = 0; i < coordinatesToFlip.size(); i++) {
        board->putSymbolOnBoard(coordinatesToFlip[i].getRow(),
                                coordinatesToFlip[i].getColumn(), symbol);
    }
}