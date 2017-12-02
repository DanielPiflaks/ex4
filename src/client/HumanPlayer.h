/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    /**
     * Human player constructor.
     * @param symbol player symbol
     * @param board board to play on.
     * @param gameLogic game logic to play by.
     */
    HumanPlayer(char symbol, Board *board, GameLogic *gameLogic) : Player(symbol, board, gameLogic) {};


    /**
     * Plays one turn and returns vector of board coordinates that has been flipped.
     * @return vector of board coordinates that has been flipped
     */
    virtual vector<BoardCoordinates> playOneTurn();

private:
    /**
     * Asks user for his choice between all possible moves and returns it.
     * @param possibleMoves player possible moves.
     * @return player choice to flip.
     */
    BoardCoordinates getPlayerChoice(vector<BoardCoordinates> possibleMoves);

    /**
     * Print all possible moves.
     * @param possibleMoves all player possible moves.
     */
    void printPossibleMoves(vector<BoardCoordinates> possibleMoves);
};

#endif //EX2_HUMANPLAYER_H
