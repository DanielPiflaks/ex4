//
// Created by danielpiflaks on 02/12/17.
//

#include "Server.h"

int main() {
    const char * fileName = "ServerConnectionSettings.txt";
    Server serverGame(fileName);
    serverGame.start();
    serverGame.notifyFirstPlayerStart();
    serverGame.sendAndReceiveMoves();
    serverGame.stop();
    return 0;
}