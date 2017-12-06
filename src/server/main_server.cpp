//
// Created by danielpiflaks on 02/12/17.
//

#include "Server.h"

int main() {
    Server serverGame;
    serverGame.start();
    serverGame.notifyFirstPlayerStart();
    serverGame.sendAndReciveMoves();
    return 0;
}