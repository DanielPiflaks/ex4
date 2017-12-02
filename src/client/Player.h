/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
using namespace std;

#include <iostream>
#include <algorithm>
#include "Board.h"
#include "GameLogic.h"

class Player {
public:
    /**
     * Player constructor.
     * @param symbol
     * @param board
     * @param gameLogic
     */
    Player(char symbol, Board *board, GameLogic *gameLogic);

    /**
     * Player destructor.
     */
    virtual ~Player();

    /**
     * Virtual function that plays ones turn for player.
     * @return flipped board coordinates vector.
     */
    virtual vector<BoardCoordinates> playOneTurn() = 0;

    /**
     * Add player symbol to board.
     * @param row row where to add.
     * @param column column where to add.
     */
    void addPlayerSymbol(int row, int column);

    /**
     * Gets remove coordinates and remove it from player moves vector.
     * @param removeCoordinates coordinates to remove.
     */
    void updatePlayerSymbolRemoved(vector<BoardCoordinates> removeCoordinates);

    /**
     * Gets add coordinates and add it to player moves vector.
     * @param addCoordinates coordinates to add.
     */
    void updatePlayerSymbolAdd(vector<BoardCoordinates> addCoordinates);

    /**
     * Getter
     * @return Returns player symbol.
     */
    char getSymbol() const;

    /**
     * Getter
     * @return Return player score(how many symbols on board).
     */
    int getScore() const;

    vector<BoardCoordinates> getPlayerMoves();

protected:
    char symbol;
    Board *board;
    vector<BoardCoordinates> playerMoves;
    GameLogic *gameLogic;
};


#endif //EX2_PLAYER_H
