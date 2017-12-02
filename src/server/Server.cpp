//
// Created by danielpiflaks on 02/12/17.
//
#include <sys/socket.h>
#include "Server.h"

Server::Server(int port) : port(port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
}

void Server::start(){
}

