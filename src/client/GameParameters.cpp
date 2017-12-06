/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex3
******************************************/

#include <fstream>
#include "Board.h"
#include "Player.h"
#include "GameParameters.h"
#include "HumanPlayer.h"
#include "RemotePlayer.h"
#include "StandartGameLogic.h"
#include "MiniMaxSimulator.h"
#include "AIPlayer.h"
#include "HumanPlayerSender.h"

GameParameters::GameParameters(PlayerOptions player1Type, char player1Symbol, PlayerOptions player2Type,
                               char player2Symbol,
                               int numRows, int numColumns, StartFirstOptions startFirst,
                               GameLogicOptions gameLogicOption)
        : gameBoard(gameBoard), startFirst(startFirst) {
    //Create new game board.
    gameBoard = new Board(numRows, numColumns);

    //Create game logic by input.
    switch (gameLogicOption) {
        case StandartGame: {
            gameLogic = new StandartGameLogic(gameBoard);
            break;
        }
    }

    Client *client;
    if ((player1Type == RemotePlayerOp) || (player2Type == RemotePlayerOp)) {
        setIpAndPortFromFile();
        client = new Client(ip, port);
        int startFirstParam = client->connectToServer();
        if (startFirstParam == 1) {
            player1Type = HumanPlayerSenderOp;
            player2Type = RemotePlayerOp;

            cout << "Waiting for other player to join..." << endl;
            int getStartGame = client->getStartGameNotification();
            if (getStartGame != 1) {
                throw "Not valid start game notification";
            }
        }
        if (startFirstParam == 2) {
            player2Type = HumanPlayerSenderOp;
            player1Type = RemotePlayerOp;
        }

    }

    //Create 2 simulator in case that one of players is computer.
    MiniMaxSimulator *simulatorPlayer1 = new MiniMaxSimulator(gameLogic);
    MiniMaxSimulator *simulatorPlayer2 = new MiniMaxSimulator(gameLogic);

    //Create player 1 by it's symbol and type.
    switch (player1Type) {
        case HumanPlayerOp: {
            player1 = new HumanPlayer(player1Symbol, gameBoard, gameLogic);
            break;
        }
        case AIPlayerOp: {
            player1 = new AIPlayer(player1Symbol, gameBoard, gameLogic, simulatorPlayer1);
            break;
        }
        case RemotePlayerOp: {
            player1 = new RemotePlayer(player1Symbol, gameBoard, gameLogic, client);
            break;
        }
        case HumanPlayerSenderOp: {
            player1 = new HumanPlayerSender(player1Symbol, gameBoard, gameLogic, client);
            break;
        }
        default:
            break;
    }

    //Create player 2 by it's symbol and type.
    switch (player2Type) {
        case HumanPlayerOp: {
            player2 = new HumanPlayer(player2Symbol, gameBoard, gameLogic);
            break;
        }
        case AIPlayerOp: {
            player2 = new AIPlayer(player2Symbol, gameBoard, gameLogic, simulatorPlayer2);
            break;
        }
        case RemotePlayerOp: {
            player2 = new RemotePlayer(player2Symbol, gameBoard, gameLogic, client);
            break;
        }
        case HumanPlayerSenderOp: {
            player2 = new HumanPlayerSender(player2Symbol, gameBoard, gameLogic, client);
            break;
        }
        default:
            break;
    }

    //Check if first player is computer player
    if (player1Type == AIPlayerOp) {
        //Set players for simulators.
        simulatorPlayer1->setOpponent(player2);
        simulatorPlayer1->setComputerPlayer(player1);
    } else {
        //If not, delete the simulator.
        delete simulatorPlayer1;
    }
    //Check if second player is computer player
    if (player2Type == AIPlayerOp) {
        //Set players for simulators.
        simulatorPlayer2->setOpponent(player1);
        simulatorPlayer2->setComputerPlayer(player2);
    } else {
        //If not, delete the simulator.
        simulatorPlayer2;
    }

}


Board *GameParameters::getGameBoard() {
    return gameBoard;
}


Player *GameParameters::getPlayer2() const {
    return player2;
}

GameParameters::StartFirstOptions GameParameters::getStartFirst() const {
    return startFirst;
}

Player *GameParameters::getPlayer1() const {
    return player1;
}

GameParameters::~GameParameters() {
    delete gameBoard;
    delete gameLogic;
    delete player1;
    delete player2;
}

void GameParameters::setIpAndPortFromFile() {
    //Set const sub string as expected.
    const string ipSubString = "IP:";
    const string portSubString = "PORT:";
    //Set const comment char symbol.
    const char commentChar = '#';
    //Set file name.
    const char *fileName = "ClientConnectionSettings.txt";
    string singleLine, stringPort;
    ifstream inFile;
    //Open file.
    inFile.open(fileName);
    //Check if file opened.
    if (inFile.is_open()) {
        //Check if file is empty.
        if (!inFile.eof()) {
            //Get next line.
            getline(inFile, singleLine);
        }
        //Get all lines until we get to end of file.
        while (!inFile.eof()) {
            //Check if line is not comment line.
            if (singleLine.find(commentChar) != 0) {
                //Check if line contains ip sub string.
                if (singleLine.find(ipSubString) == 0) {
                    ip = (singleLine.substr(ipSubString.length(), singleLine.length())).c_str();
                    //Check if line contains port sub string.
                } else if (singleLine.find(portSubString) == 0) {
                    stringPort = singleLine.substr(portSubString.length(), singleLine.length());
                    //Convert string to int.
                    sscanf(stringPort.c_str(), "%d", &port);
                }
            }
            //Get next line.
            getline(inFile, singleLine);
        }
        //Close file when there is no more lines to read.
        inFile.close();
    } else {
        //Throw exception when we can't open file.
        throw "Can't open settings file!";
    }
}