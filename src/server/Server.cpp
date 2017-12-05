//
// Created by danielpiflaks on 02/12/17.
//


#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include "Server.h"

#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port) : port(port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
}

void Server::start() {
    const int firstPlayerIndex = 1;
    const int secondPlayerIndex = 2;
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }

    // Start listening to incoming connections
    if (listen(serverSocket, MAX_CONNECTED_CLIENTS) < 0) {
        throw "Error listening";
    }

    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    cout << "Waiting for client connections..." << endl;
    // Accept first client.
    clientSocket1 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);

    if (clientSocket1 == -1) {
        throw "Error on accept";
    }
    cout << "First client connected" << endl;

    // Write the result back to the client
    long n = write(clientSocket1, &firstPlayerIndex, sizeof(firstPlayerIndex));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }

    // Accept first client.
    clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);

    if (clientSocket2 == -1) {
        throw "Error on accept";
    }
    cout << "Second client connected" << endl;
    // Write the result back to the client
    n = write(clientSocket2, &secondPlayerIndex, sizeof(secondPlayerIndex));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
}

void Server::notifyFirstPlayerStart() {
    const int trueParam = 1;
    long n = write(clientSocket1, &trueParam, sizeof(trueParam));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
}

void Server::sendAndReciveMoves() {
    long n;
    char move[4];
    while (true) {
        n = read(clientSocket1, &move, sizeof(move));
        if (n == -1) {
            cout << "Error reading move" << endl;
            return;
        }

        long n = write(clientSocket2, &move, sizeof(move));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }

        n = read(clientSocket2, &move, sizeof(move));
        if (n == -1) {
            cout << "Error reading move" << endl;
            return;
        }

        n = write(clientSocket1, &move, sizeof(move));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    }
}