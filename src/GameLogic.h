/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/
#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H

using namespace std;

#include <iostream>
#include <vector>
#include <map>
#include "Board.h"

class GameLogic {
public:
    /**
     * Game logic constructor.
     * @param board board to play on.
     */
    GameLogic(Board *board);

    /**
     * Game logic copy constructor.
     * @param gameLogic game logic to copy.
     */
    GameLogic(GameLogic *gameLogic);

    /**
     * Game logic destructor
     */
    ~GameLogic();

    /**
     *
     * @return Returns board that game logic holds.
     */
    Board &getBoard();


    /**
     * Gets vector of player moves on board and player symbol,
     * and returns map of each move to it possible play.
     * @param playerMoves player options on board.
     * @param playerSymbol player symbol.
     * @return map of all possible moves.
     */
    virtual map<BoardCoordinates, vector<BoardCoordinates> > getPossibleGameMoves(vector<BoardCoordinates> playerMoves,
                                                                                  char playerSymbol) = 0;

    /**
    * Gets map of all moves, player choice to flip and flips it.
    * the function returns all flipped symbols.
    * @param allChoices map of all choices.
    * @param wantedChoice wanted choice to flip.
    * @param playerSymbol player symbol to know what not to flip.
    * @return flipped symbols.
    */
    virtual vector<BoardCoordinates> flipSymbols(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                                                 BoardCoordinates wantedChoice, char playerSymbol) = 0;


    /**
    * Gets map of all moves, player choice to flip and flips it.
    * the function returns all flipped symbols number without flip.
    * @param allChoices map of all choices.
    * @param wantedChoice wanted choice to flip.
    * @param playerSymbol player symbol to know what not to flip.
    * @return number of possible flips.
    */
    virtual int numberOfPossibleFlips(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                                                 BoardCoordinates wantedChoice, char playerSymbol) = 0;

private:
    Board *board;
protected:
    void flipOnBoard(vector<BoardCoordinates> coordinatesToFlip, char symbol);
};


#endif //EX2_GAMELOGIC_H
