//
// Created by danielpiflaks on 02/12/17.
//

#include "Server.h"

int main() {
    Server server(5555);
    server.start();
    server.notifyFirstPlayerStart();
    return 0;
}