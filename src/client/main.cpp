/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/
#include <limits>
#include "GameParameters.h"
#include "Game.h"

int main() {
    //Set size of game board.
    const int numberRows = 4;
    const int numberColumns = 4;

    //Create bool parameter for while loop to get player wanted player.
    bool waitingForInput = true;
    GameParameters::PlayerOptions player2Type;
    int input;
    while (waitingForInput) {
        //Print menu for user.
        cout << "choose your opponent:" << endl;
        cout << "1. a human local player" << endl << "2. an AI player" << endl;
        cout << "3. a remote player" << endl;
        cin >> input;
        if (input == 1) {
            //If input is 1, then the game is against local human player.
            player2Type = GameParameters::HumanPlayerOp;
            waitingForInput = false;
        } else if (input == 2) {
            //If input is 2, then the game is against AI player.
            player2Type = GameParameters::AIPlayerOp;
            waitingForInput = false;
        } else if (input == 3) {
            //If input is 3, then the game is against remote player.
            player2Type = GameParameters::RemotePlayerOp;
            waitingForInput = false;
        }
        //Clear not valid input.
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    //Create game parameters.
    GameParameters gameParameters(GameParameters::HumanPlayerOp, 'x',
                                  GameParameters::PlayerOptions(player2Type), 'o',
                                  numberRows, numberColumns);
    //Create game with those parameters.
    Game game(gameParameters);
    //Run single game.
    game.RunSingleGame();

    return 0;
}