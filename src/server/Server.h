//
// Created by danielpiflaks on 02/12/17.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H
using namespace std;

class Server {
public:
    /**
     * Constructor.
     * @param fileName file name with port parameter.
     */
    explicit Server(const char *fileName);

    /**
     * Constructor.
     * @param port port number.
     */
    explicit Server(int port);

    /**
     * Start function to open sockets for both players.
     */
    void start();

    /**
     * Stop function to close sockets.
     */
    void stop();

    /**
     * Send message for first player that second player
     * connected to begin the game.
     */
    void notifyFirstPlayerStart();

    /**
     * receive message from socket1 and send it to socket2,
     * then receive message from socket2 and send to to socket1
     * and again the same loop.
     */
    void sendAndReceiveMoves();

private:
    int port;
    int serverSocket;

    int clientSocket1;
    int clientSocket2;

    /**
     * Set port from input parameter file.
     * @param fileName file name of parameter for port.
     */
    void setPortFromFile(const char *fileName);
};


#endif //EX4_SERVER_H
