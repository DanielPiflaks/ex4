//
// Created by danielpiflaks on 02/12/17.
//

#include <iostream>
#include <cstdlib>
#include "Server.h"

int main() {
    const char *fileName = "ServerConnectionSettings.txt";
    try {
        Server serverGame(fileName);
        serverGame.start();
        serverGame.notifyFirstPlayerStart();
        serverGame.sendAndReceiveMoves();
        serverGame.stop();

    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }

    return 0;
}