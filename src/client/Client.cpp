//
// Created by sapirblutman on 02/12/17.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include <unistd.h>
#include "Client.h"

Client::Client(const char *serverIP, int serverPort) :
        serverIP(serverIP), serverPort(serverPort), clientSocket(0) {}

int Client::connectToServer() {
    //Create socket point.
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }

    //Create structure for the server address.
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(serverIP);
    //Convert values between host and network byte orders.
    serverAddress.sin_port = htons(serverPort);

    //Establish connection with TCP server.
    if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;

    int numberOfPlayer;
    int readParam = read(clientSocket, &numberOfPlayer, sizeof(numberOfPlayer));
    if (readParam == -1){
        throw "Error reading result from socket";
    }
    return numberOfPlayer;
}

int Client::sendMove(int row, int col) {
    //Write the move coordinate to the socket.
    int check = write(clientSocket, &row, sizeof(row));
    if (check == -1) {
        throw "Error writing row coordinate";
    }
    check = write(clientSocket, &col, sizeof(col));
    if (check == -1) {
        throw "Error writing column coordinate";
    }
}

int Client::getStartGameNotification(){
    int startParamNotify;
    int readParam = read(clientSocket, &startParamNotify, sizeof(startParamNotify));
    if (readParam == -1){
        throw "Error reading result from socket";
    }
    return startParamNotify;
}
