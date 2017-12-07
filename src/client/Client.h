/******************************************
Student name: Daniel Piflaks and Sapir Blutman
Student ID: Daniel : 311322986 Sapir : 203312905
Course Exercise Group: 05
Exercise name: Ex4
******************************************/

#ifndef EX4_CLIENT_H
#define EX4_CLIENT_H

using namespace std;

#include <iostream>
#include "BoardCoordinates.h"

class Client {
public:
    /**
     * Client constructor if given file name,extract from file: IP, port.
     * @param fileName given file name.
     */
    explicit Client(const char *fileName);

    /**
     * Client constructor if given IP and port number.
     * @param serverIP server IP.
     * @param serverPort port number.
     */
    Client(const char *serverIP, int serverPort);

    ~Client();

    /**
     * Connect to existing socket that compatible to IP and port.
     * After connecting- read the client's player number.
     * @return 1 is client is first, 2 if second.
     */
    int connectToServer();

    /**
     * Closing socket from server.
     */
    void disconnectServer();

    /**
     *If there isn't any possible move(=>given move= (0,0)) then write to socket appropriate massage,
     * else- write the move coordinate.
     * @param move the client latest move (will be (0, 0) if there isn't one).
     */
    void sendMove(BoardCoordinates move);

    /**
     * Create and send to socket massage in order to notify
     * the server that the game ended.
     */
    void sendEndGameMessage();

    /**
     * Create and send to socket massage in order to notify
     * the other player that this player has no moves.
     */
    void sendNoPossibleMovesMessage();

    /**
    *Read massage from socket about other player latest move.
    * If massage state that there isn't move- return neutral coordinate (0,0).
     * Else, convert the massage into coordinate.
     * @return neutral coordinate or suitable one, depending on the massage.
    */
    BoardCoordinates receiveMove();

    /**
     * After the 1st client connect to socket the server waits for 2nd client.
     * After both connected then server sends to socket 1, in order that 1st client
     * will read it and will notify to start the game.
     * @return 1 if both client connected.
     */
    int getStartGameNotification();

    /**
     * Open file, read from it IP address and port.
     * @param fileName the name of file that we will read IP and port from.
     */
    void setIpAndPortFromFile(const char *fileName);

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX4_CLIENT_H
