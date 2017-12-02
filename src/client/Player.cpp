/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#include "Player.h"

Player::Player(char symbol, Board *board, GameLogic *gameLogic) : symbol(symbol),
                                                                  board(board), gameLogic(gameLogic) {}

Player::~Player() {

}

char Player::getSymbol() const {
    return symbol;
};

void Player::addPlayerSymbol(int row, int column) {
    //Create new coordinate.
    BoardCoordinates newCoordinate(row, column);
    //Insert it to player moves.
    playerMoves.push_back(newCoordinate);
    //Put this symbol on board.
    board->putSymbolOnBoard(row, column, symbol);
}

void Player::updatePlayerSymbolRemoved(vector<BoardCoordinates> removeCoordinates) {
    //Remove each coordinate from vector.
    for (int i = 0; i < removeCoordinates.size(); ++i) {
        //Check if wanted coordinate is in vector and remove it.
        if (find(playerMoves.begin(), playerMoves.end(), removeCoordinates[i]) != playerMoves.end()) {
            playerMoves.erase(remove(playerMoves.begin(), playerMoves.end(), removeCoordinates[i]), playerMoves.end());
        }

    }
}

void Player::updatePlayerSymbolAdd(vector<BoardCoordinates> addCoordinates) {
    //Insert coordinates
    for (int i = 0; i < addCoordinates.size(); ++i) {
        //Check if this coordinate isn't already in vector and insert it.
        if (!(find(playerMoves.begin(), playerMoves.end(), addCoordinates[i]) != playerMoves.end())) {
            playerMoves.insert(playerMoves.end(), addCoordinates.begin(), addCoordinates.end());
        }

    }
}

int Player::getScore() const {
    return playerMoves.size();
}

vector<BoardCoordinates> Player::getPlayerMoves(){
    return playerMoves;
}