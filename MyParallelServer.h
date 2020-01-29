//
// Created by yonatan on 28/01/2020.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H

#include "Server.h"

class MyParallelServer : public server_side::Server {

    virtual void open(int port, ClientHandler *clientHandler);

    virtual void stop();

    int openServer(int port, ClientHandler *clientHandler);

    static int openNewClientThread(ClientHandler* newClientHandler, int client_socket);

};


#endif //EX4_MYPARALLELSERVER_H
