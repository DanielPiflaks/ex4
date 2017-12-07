/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/

#include <iostream>
#include <cstdlib>
#include "Server.h"

int main() {
    //Name of file with port and IP data.
    const char *fileName = "ServerConnectionSettings.txt";
    try {
        Server serverGame(fileName);
        serverGame.start();
        serverGame.notifyFirstPlayerStart();
        serverGame.sendAndReceiveMoves();
        serverGame.stop();

    } catch (const char *msg) {
        //If something went wrong print the reason.
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }

    return 0;
}