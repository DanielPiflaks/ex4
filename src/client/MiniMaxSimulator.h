/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#ifndef EX3_MINIMAXSIMULATOR_H
#define EX3_MINIMAXSIMULATOR_H


#include "Player.h"

class MiniMaxSimulator {
public:
    /**
     * Constructor.
     * @param gameLogic game logic.
     */
    MiniMaxSimulator(GameLogic *gameLogic);

    /**
     * Destructor.
     */
    ~MiniMaxSimulator();

    /**
     * Get score by wanted move.
     * @param allChoices possible moves.
     * @param move wanted move
     * @return max score of move.
     */
    int getScoreByMove(map<BoardCoordinates, vector<BoardCoordinates> > allChoices,
                       BoardCoordinates move);

    /**
     * Setter for computer player.
     * @param computerPlayer computer player pointer.
     */
    void setComputerPlayer(Player *computerPlayer);

    /**
     * Setter for opponent player
     * @param opponent opponent player pointer.
     */
    void setOpponent(Player *opponent);

private:
    Player *computerPlayer;
    Player *opponent;
    GameLogic *gameLogic;

    /**
     * Copy content of old board to current board.
     * @param oldBoard old board to copy from.
     * @param currentBoard board to copy to.
     */
    void copyBoardContent(Board oldBoard, Board *currentBoard);
};


#endif //EX3_MINIMAXSIMULATOR_H
