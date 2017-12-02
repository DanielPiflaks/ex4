/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/
#include <gtest/gtest.h>
#include "../src/GameLogic.h"
#include "../src/StandartGameLogic.h"
#include "../src/HumanPlayer.h"


TEST(GameLogicTest, PossibleMovesCheck) {
    const int numRows = 8;
    const int numColumns = 8;
    //Create new board.
    Board *board = new Board(numRows, numColumns);
    //Create game logic to check.
    GameLogic *gameLogic = new StandartGameLogic(board);
    //Put symbols to start position as in game.
    gameLogic->getBoard().putSymbolOnBoard(5, 5, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 4, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 5, 'x');
    gameLogic->getBoard().putSymbolOnBoard(5, 4, 'x');

    //Create players.
    Player *humanPlayer1 = new HumanPlayer('x', board, gameLogic);
    Player *humanPlayer2 = new HumanPlayer('o', board, gameLogic);

    //Put player1 symbols by its start position.
    humanPlayer1->addPlayerSymbol(4, 5);
    humanPlayer1->addPlayerSymbol(5, 4);

    //Put player2 symbols by its start position.
    humanPlayer2->addPlayerSymbol(5, 5);
    humanPlayer2->addPlayerSymbol(4, 4);

    //Get possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves =
            gameLogic->getPossibleGameMoves(humanPlayer1->getPlayerMoves(), humanPlayer1->getSymbol());

    //Create vector of expected from moves.
    vector<BoardCoordinates> expectedFromMoves;
    expectedFromMoves.push_back(BoardCoordinates(4, 5));
    expectedFromMoves.push_back(BoardCoordinates(5, 4));
    //Create vector of from moves
    vector<BoardCoordinates> fromMoves;
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = possibleMoves.begin();
         moves != possibleMoves.end(); ++moves) {
        BoardCoordinates fromMove = moves->first;
        fromMoves.push_back(fromMove);
    }

    EXPECT_EQ(fromMoves, expectedFromMoves);

    //Create expect moves for first position.
    vector<BoardCoordinates> expectedMove1;
    //Add expected moves to vector.
    expectedMove1.push_back(BoardCoordinates(4, 3));
    expectedMove1.push_back(BoardCoordinates(6, 5));

    //Create expect moves for first position.
    vector<BoardCoordinates> expectedMove2;
    //Add expected moves to vector.
    expectedMove2.push_back(BoardCoordinates(3, 4));
    expectedMove2.push_back(BoardCoordinates(5, 6));

    //For board coordinate, get its possible move and insert in to all moves vector.
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = possibleMoves.begin();
         moves != possibleMoves.end(); ++moves) {
        BoardCoordinates fromMove = moves->first;
        vector<BoardCoordinates> movesForSinglePosition;
        for (int i = 0; i < moves->second.size(); i++) {
            movesForSinglePosition.push_back(moves->second[i]);
        }
        //Check for first from move.
        if (fromMove == BoardCoordinates(4, 5)) {
            EXPECT_EQ(expectedMove1, movesForSinglePosition);
        }
        //Check for second from move.
        if (fromMove == BoardCoordinates(5, 4)) {
            EXPECT_EQ(expectedMove2, movesForSinglePosition);
        }
    }
    //free all objects.
    delete board;
    delete humanPlayer1;
    delete humanPlayer2;
    delete gameLogic;
}

TEST(GameLogicTest, NotRecognizeCheck) {
    const int numRows = 8;
    const int numColumns = 8;
    //Create new board.
    Board *board = new Board(numRows, numColumns);
    //Create game logic to check.
    GameLogic *gameLogic = new StandartGameLogic(board);
    //Put symbols to start position as in game.
    gameLogic->getBoard().putSymbolOnBoard(5, 5, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 4, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 5, 'x');
    gameLogic->getBoard().putSymbolOnBoard(5, 4, 'x');

    //Create players.
    Player *humanPlayer1 = new HumanPlayer('x', board, gameLogic);
    Player *humanPlayer2 = new HumanPlayer('o', board, gameLogic);

    //Put player1 symbols by its start position.
    humanPlayer1->addPlayerSymbol(4, 5);
    humanPlayer1->addPlayerSymbol(5, 4);

    //Put player2 symbols by its start position.
    humanPlayer2->addPlayerSymbol(5, 5);
    humanPlayer2->addPlayerSymbol(4, 4);

    //Get possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves =
            gameLogic->getPossibleGameMoves(humanPlayer1->getPlayerMoves(), humanPlayer1->getSymbol());

    //Create vector of expected from moves.
    vector<BoardCoordinates> expectedFromMoves;
    expectedFromMoves.push_back(BoardCoordinates(4, 5));
    expectedFromMoves.push_back(BoardCoordinates(5, 4));

    //Add random symbol and to check that it's not checked.
    gameLogic->getBoard().putSymbolOnBoard(7, 8, 'x');
    humanPlayer1->addPlayerSymbol(7, 8);

    //Create vector of from moves
    vector<BoardCoordinates> fromMoves;
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = possibleMoves.begin();
         moves != possibleMoves.end(); ++moves) {
        BoardCoordinates fromMove = moves->first;
        fromMoves.push_back(fromMove);
    }

    EXPECT_EQ(fromMoves, expectedFromMoves);

    //Add random symbol and to check that it's not checked.
    gameLogic->getBoard().putSymbolOnBoard(1, 1, 'o');
    humanPlayer1->addPlayerSymbol(1, 1);

    //Create vector of from moves
    fromMoves.empty();
    for (map<BoardCoordinates, vector<BoardCoordinates> >::iterator moves = possibleMoves.begin();
         moves != possibleMoves.end(); ++moves) {
        BoardCoordinates fromMove = moves->first;
        if (find(fromMoves.begin(), fromMoves.end(), moves->first) == fromMoves.end()) {
            fromMoves.push_back(fromMove);
        }
    }
    //Check that all from moves as expected.
    EXPECT_EQ(fromMoves, expectedFromMoves);
    //free all objects.
    delete board;
    delete humanPlayer1;
    delete humanPlayer2;
    delete gameLogic;
}

TEST(GameLogicTest, CheckNumberOfPossibleMoves) {
    const int numRows = 8;
    const int numColumns = 8;
    //Create new board.
    Board *board = new Board(numRows, numColumns);
    //Create game logic to check.
    GameLogic *gameLogic = new StandartGameLogic(board);
    //Put symbols to start position as in game.
    gameLogic->getBoard().putSymbolOnBoard(5, 5, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 4, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 5, 'x');
    gameLogic->getBoard().putSymbolOnBoard(5, 4, 'x');

    //Create players.
    Player *humanPlayer1 = new HumanPlayer('x', board, gameLogic);
    Player *humanPlayer2 = new HumanPlayer('o', board, gameLogic);

    //Put player1 symbols by its start position.
    humanPlayer1->addPlayerSymbol(4, 5);
    humanPlayer1->addPlayerSymbol(5, 4);

    //Put player2 symbols by its start position.
    humanPlayer2->addPlayerSymbol(5, 5);
    humanPlayer2->addPlayerSymbol(4, 4);

    //Get possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves =
            gameLogic->getPossibleGameMoves(humanPlayer1->getPlayerMoves(), humanPlayer1->getSymbol());

    int numberOfMoves = gameLogic->numberOfPossibleFlips(possibleMoves, BoardCoordinates(3, 4),
                                                         humanPlayer1->getSymbol());
    //Check that all from moves as expected.
    EXPECT_EQ(numberOfMoves, 2);
    //Free all objects.
    delete board;
    delete humanPlayer1;
    delete humanPlayer2;
    delete gameLogic;
}

//Checks that if board is full there are no possible moves.
TEST(GameLogicTest, NoPossibleMovesCheck) {
    const int numRows = 8;
    const int numColumns = 8;
    //Create new board.
    Board *board = new Board(numRows, numColumns);
    //Create game logic to check.
    GameLogic *gameLogic = new StandartGameLogic(board);

    //Create players.
    Player *humanPlayer1 = new HumanPlayer('x', board, gameLogic);

    //Put symbols on every cell.
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            gameLogic->getBoard().putSymbolOnBoard(i + 1, j + 1, 'x');
            humanPlayer1->addPlayerSymbol(i + 1, j + 1);
        }
    }

    //Get possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves =
            gameLogic->getPossibleGameMoves(humanPlayer1->getPlayerMoves(), humanPlayer1->getSymbol());

    int numberOfMoves = gameLogic->numberOfPossibleFlips(possibleMoves, BoardCoordinates(3, 4),
                                                         humanPlayer1->getSymbol());
    //Check that there are no possible.
    EXPECT_EQ(numberOfMoves, 0);
    //Free all objects.
    delete board;
    delete humanPlayer1;
    delete gameLogic;
}

//Check that logic flips right.
TEST(GameLogicTest, CheckFlippedCorrect) {
    const int numRows = 8;
    const int numColumns = 8;
    //Create new board.
    Board *board = new Board(numRows, numColumns);
    //Create game logic to check.
    GameLogic *gameLogic = new StandartGameLogic(board);
    //Put symbols to start position as in game.
    gameLogic->getBoard().putSymbolOnBoard(5, 5, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 4, 'o');
    gameLogic->getBoard().putSymbolOnBoard(4, 5, 'x');
    gameLogic->getBoard().putSymbolOnBoard(5, 4, 'x');

    //Create players.
    Player *humanPlayer1 = new HumanPlayer('x', board, gameLogic);
    Player *humanPlayer2 = new HumanPlayer('o', board, gameLogic);

    //Put player1 symbols by its start position.
    humanPlayer1->addPlayerSymbol(4, 5);
    humanPlayer1->addPlayerSymbol(5, 4);

    //Put player2 symbols by its start position.
    humanPlayer2->addPlayerSymbol(5, 5);
    humanPlayer2->addPlayerSymbol(4, 4);

    //Get possible moves.
    map<BoardCoordinates, vector<BoardCoordinates> > possibleMoves =
            gameLogic->getPossibleGameMoves(humanPlayer1->getPlayerMoves(), humanPlayer1->getSymbol());

    //Get flipped coordinates.
    vector<BoardCoordinates> flippedCoord = gameLogic->flipSymbols(possibleMoves, BoardCoordinates(3, 4),
                                                                   humanPlayer1->getSymbol());
    //Set expected flipped coordinates as set move.
    vector<BoardCoordinates> expectedFlippedCoord;
    expectedFlippedCoord.push_back(BoardCoordinates(4, 4));
    expectedFlippedCoord.push_back(BoardCoordinates(3, 4));
    //Check that all coordinates as expected.
    EXPECT_EQ(flippedCoord, expectedFlippedCoord);
    //Free all objects.
    delete board;
    delete humanPlayer1;
    delete humanPlayer2;
    delete gameLogic;
}