/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/
#include <gtest/gtest.h>
#include "../src/Board.h"
#include "../src/Game.h"
#include "../src/MiniMaxSimulator.h"
#include "../src/StandartGameLogic.h"
#include "../src/HumanPlayer.h"
#include "../src/AIPlayer.h"

//Check that board is not changed in the simulator.
TEST(MiniMaxSimulatorTest, BoardIsntChange) {
    const int numberRows = 8;
    const int numberColumns = 8;
    //Create Board.
    Board *board = new Board(numberRows, numberColumns);
    //Create game logic.
    GameLogic *gameLogic = new StandartGameLogic(board);
    //Create simulator.
    MiniMaxSimulator *simulator = new MiniMaxSimulator(gameLogic);
    //Put symbols to start position as in game.
    gameLogic->getBoard().putSymbolOnBoard(5, 5, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 4, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 5, 'x');
    gameLogic->getBoard().putSymbolOnBoard(5, 4, 'x');

    //Create players.
    Player *humanPlayer = new HumanPlayer('x', board, gameLogic);
    Player *computerPlayer = new AIPlayer('o', board, gameLogic, simulator);

    //Put player1 symbols by its start position.
    humanPlayer->addPlayerSymbol(4, 5);
    humanPlayer->addPlayerSymbol(5, 4);

    //Put player2 symbols by its start position.
    computerPlayer->addPlayerSymbol(5, 5);
    computerPlayer->addPlayerSymbol(4, 4);

    //Set the players to simulator.
    simulator->setComputerPlayer(computerPlayer);
    simulator->setOpponent(humanPlayer);

    //Get map of possible moves of computer player.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves = gameLogic->getPossibleGameMoves(
            computerPlayer->getPlayerMoves(),
            computerPlayer->getSymbol());

    //Copy board.
    Board copyBoard = gameLogic->getBoard();
    vector<BoardCoordinates> savedMovesOfPlayer1 = humanPlayer->getPlayerMoves();
    vector<BoardCoordinates> savedMovesOfPlayer2 = computerPlayer->getPlayerMoves();

    simulator->getScoreByMove(possibleMoves, BoardCoordinates(3, 3));

    //Get board after simulator.
    Board boardAfter = gameLogic->getBoard();
    //Check if boards are equal.
    EXPECT_EQ(copyBoard, boardAfter);
    //Check if vectors are equal
    EXPECT_EQ(savedMovesOfPlayer1, humanPlayer->getPlayerMoves());
    EXPECT_EQ(savedMovesOfPlayer2, computerPlayer->getPlayerMoves());
    //Free all data.
    delete board;
    delete humanPlayer;
    delete computerPlayer;
    delete gameLogic;
}