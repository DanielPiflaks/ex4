/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/
#include "Game.h"


Game::Game(GameParameters &gameParameters) : gameBoard(gameBoard) {
    //Get game board.
    gameBoard = gameParameters.getGameBoard();
    //Get enum who start first.
    GameParameters::StartFirstOptions startFirstOptions = gameParameters.getStartFirst();
    //Initialize players by who start first options.
    switch (startFirstOptions) {
        case GameParameters::Player1First: {
            //Get first player.
            firstPlayer = gameParameters.getPlayer1();
            //Get second player.
            secondPlayer = gameParameters.getPlayer2();
            break;
        }

        case GameParameters::Player2First: {
            //Get first player.
            firstPlayer = gameParameters.getPlayer2();
            //Get second player.
            secondPlayer = gameParameters.getPlayer1();
            break;
        }
    }
}

Game::~Game() {

}

void Game::putSymbolsStartPosition() {
    //Get number of columns.
    int numCols = gameBoard->getNumCols();
    //Get number of rows.
    int numRows = gameBoard->getNumRows();
    //Divide by 2 to put start symbols in the middle.
    int middlePlaceCol = numCols / 2;
    int middlePlaceRow = numRows / 2;

    //Put player1 symbols by its start position.
    firstPlayer->addPlayerSymbol(middlePlaceRow, middlePlaceCol + 1);
    firstPlayer->addPlayerSymbol(middlePlaceRow + 1, middlePlaceCol);

    //Put player2 symbols by its start position.
    secondPlayer->addPlayerSymbol(middlePlaceRow + 1, middlePlaceCol + 1);
    secondPlayer->addPlayerSymbol(middlePlaceRow, middlePlaceCol);
}

void Game::RunSingleGame() {
    //Set game over indicator to be 0.
    int gameOverIndicator = 0;
    map<BoardCoordinates, vector<BoardCoordinates> > mapOfLastMove;
    vector<BoardCoordinates> symbolsToUpdate;
    //Put symbols to it start position.
    putSymbolsStartPosition();

    //Set param to know who played last.
    Player *endPlayer;

    //Set game over indicator to be 0.
    gameOverIndicator = 0;
    //Game loop. ends when both players don't have any possible moves.
    while (gameOverIndicator < 2) {

        cout << "Current board:" << endl;
        cout << endl;
        //Draw game board.
        gameBoard->drawBoard();

        //Play one turn.
        mapOfLastMove = firstPlayer->playOneTurn();
        //Check if map of moves is not empty.
        if (!mapOfLastMove.empty()) {
            //Extract the vector of cell to update from map.
            symbolsToUpdate = mapOfLastMove.begin()->second;

            //Check if there is any symbols to updated.
            if (symbolsToUpdate.empty()) {
                //If not, that means that player didn't have any move.
                gameOverIndicator++;
                endPlayer = secondPlayer;
            } else {
                //Set game over indicator to be 0.
                gameOverIndicator = 0;
                //Update first player of his new symbols.
                firstPlayer->updatePlayerSymbolAdd(symbolsToUpdate);
                //Update second player of symbols that he lost.
                secondPlayer->updatePlayerSymbolRemoved(symbolsToUpdate);
            }
        } else {
            gameOverIndicator++;
            endPlayer = secondPlayer;
        }

        if (gameOverIndicator == 2) {
            break;
        }

        cout << "Current board:" << endl;
        cout << endl;
        //Draws game board.
        gameBoard->drawBoard();
        //Play one turn.
        mapOfLastMove = secondPlayer->playOneTurn();
        //Check if map of moves is not empty.
        if (!mapOfLastMove.empty()) {
            //Extract the vector of cell to update from map.
            symbolsToUpdate = mapOfLastMove.begin()->second;
            //Check if any symbols updated.
            if (symbolsToUpdate.empty()) {
                //If not, that means that player didn't have any move.
                gameOverIndicator++;
                endPlayer = firstPlayer;
            } else {
                //Set game over indicator to be 0.
                gameOverIndicator = 0;
                //Update second player of his new symbols.
                secondPlayer->updatePlayerSymbolAdd(symbolsToUpdate);
                //Update first player of symbols that he lost.
                firstPlayer->updatePlayerSymbolRemoved(symbolsToUpdate);
            }
        } else {
            gameOverIndicator++;
            endPlayer = firstPlayer;
        }
    }
    //Notice server that game ended.
    endPlayer->endGameFunction();
    //Print player 1 score.
    cout << "Player " << firstPlayer->getSymbol() << " score is:" << firstPlayer->getScore() << endl;
    //Print player 2 score.
    cout << "Player " << secondPlayer->getSymbol() << " score is:" << secondPlayer->getScore() << endl;

    cout << "Game result is:";
    //Check who won and print the result.
    if (firstPlayer->getScore() > secondPlayer->getScore()) {
        cout << "Player " << firstPlayer->getSymbol() << " wins!" << endl;
    } else if (firstPlayer->getScore() < secondPlayer->getScore()) {
        cout << "Player " << secondPlayer->getSymbol() << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}


