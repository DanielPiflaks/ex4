/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#ifndef EX2_STANDARTGAMELOGIC_H
#define EX2_STANDARTGAMELOGIC_H

#include <algorithm>
#include "GameLogic.h"

class StandartGameLogic : public GameLogic {
public:
    /**
     * Constructor.
     * @param board board to play on.
     */
    StandartGameLogic(Board *board) : GameLogic(board) {};

    /**
     * Gets vector of player moves on board and player symbol,
     * and returns map of each move to it possible play.
     * @param playerMoves player options on board.
     * @param playerSymbol player symbol.
     * @return map of all possible moves.
     */
    virtual map<BoardCoordinates, vector<BoardCoordinates> > getPossibleGameMoves(vector<BoardCoordinates> playerMoves,
                                                                                  char playerSymbol);

    /**
     * Gets map of all moves, player choice to flip and flips it.
     * the function returns all flipped symbols.
     * @param allChoices map of all choices.
     * @param wantedChoice wanted choice to flip.
     * @param playerSymbol player symbol to know what not to flip.
     * @return flipped symbols.
     */
    virtual vector<BoardCoordinates> flipSymbols(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                                                 BoardCoordinates wantedChoice, char playerSymbol);


    /**
    * Gets map of all moves, player choice to flip and flips it.
    * the function returns all flipped symbols number without flip.
    * @param allChoices map of all choices.
    * @param wantedChoice wanted choice to flip.
    * @param playerSymbol player symbol to know what not to flip.
    * @return number of possible flips.
    */
    virtual int numberOfPossibleFlips(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                                      BoardCoordinates wantedChoice, char playerSymbol);

private:
    /**
     * Enum for direction check.
     */
    enum DirectionCheck {
        Right, Left, Up, Down, UpLeft, DownRight, UpRight, DownLeft
    };


    /**
     * Check possible moves by direction.
     * @param startRow row from where to look
     * @param startColumn column from where to look
     * @param direction for looking
     * @param playerSymbol player symbol to know what not to look.
     * @return possible moves.
     */
    BoardCoordinates CheckByDirection(int startRow, int startColumn,
                                      DirectionCheck direction, char playerSymbol);

    /**
     * Return single row that can be flipped.
     * @param start from where to flip.
     * @param end where to flip.
     * @param playerSymbol symbol to put instead.
     * @return all board coordinates that flipped.
     */
    vector<BoardCoordinates> singleRowToFlip(BoardCoordinates start,
                                            BoardCoordinates end, char playerSymbol);
};


#endif //EX2_STANDARTGAMELOGIC_H
