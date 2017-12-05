//
// Created by sapirblutman on 02/12/17.
//

#ifndef EX4_CLIENT_H
#define EX4_CLIENT_H

using namespace std;
#include <iostream>
#include "BoardCoordinates.h"

class Client {
public:
    Client(const char *serverIP, int serverPort);

    int connectToServer();

    void sendMove(BoardCoordinates move);

    BoardCoordinates receiveMove();

    int getStartGameNotification();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX4_CLIENT_H
