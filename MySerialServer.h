//
// Created by yonatan on 14/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer : public server_side::Server {

    virtual void open(int port, ClientHandler clientHandler);

    virtual void stop();
};


#endif //EX4_MYSERIALSERVER_H
