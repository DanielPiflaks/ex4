//
// Created by danielpiflaks on 02/12/17.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H
using namespace std;

class Server {
public:
    Server(int port);

    void start();

    void stop();

    void notifyFirstPlayerStart();

    void sendAndReciveMoves();

private:
    int port;
    int serverSocket; // the socket's file descriptor

    int clientSocket1;
    int clientSocket2;
};


#endif //EX4_SERVER_H
