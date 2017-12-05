/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#ifndef EX2_GAMECREATOR_H
#define EX2_GAMECREATOR_H

#include "Board.h"
#include "Player.h"
#include "GameLogic.h"

#define PORT 5555

class GameParameters {
public:
    const char* IP = "10.0.0.49";
    //const char* IP = "127.0.0.1";
    /**
     * Enum of player options type.
     */
    enum PlayerOptions {
        HumanPlayerOp, AIPlayerOp, RemotePlayerOp
    };

    /**
     * Enum of Game logic options.
     */
    enum GameLogicOptions {
        StandartGame
    };

    /**
     * Enum Start first options.
     */
    enum StartFirstOptions {
        Player1First, Player2First
    };

    /**
     * Game parameter constructor. sets default parameters to start first to be player1, and
     * the game to be standart game logic.
     * @param player1Type what type player 1 is.
     * @param player1Symbol what symbol will represent player 1.
     * @param player2Type what type player 2 is.
     * @param player2Symbol what symbol will represent player 2.
     * @param numRows board number of rows,
     * @param numColumns board number of columns.
     * @param startFirst who start first. by default its player1.
     * @param gameLogicOption what game logic to play. by default its standart game logic.
     */
    GameParameters(PlayerOptions player1Type, char player1Symbol, PlayerOptions player2Type, char player2Symbol,
                   int numRows, int numColumns, StartFirstOptions startFirst = Player1First,
                   GameLogicOptions gameLogicOption = StandartGame);

    /**
     * Game parameter destructor.
     */
    ~GameParameters();

    /**
     *
     * @return Returns game board.
     */
    Board *getGameBoard();

    /**
     *
     * @return Returns player1.
     */
    Player *getPlayer1() const;

    /**
     *
     * @return Returns player2.
     */
    Player *getPlayer2() const;

    /**
     * Returns who start first.
     * @return who start first.
     */
    StartFirstOptions getStartFirst() const;

private:
    Board *gameBoard;
    StartFirstOptions startFirst;
    GameLogic *gameLogic;
    Player *player1;
    Player *player2;
};

#endif //EX2_GAMECREATOR_H
