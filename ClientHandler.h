//
// Created by yonatan on 15/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <iostream>

using namespace std;
/*
 * ClientHandler interface
 */
class ClientHandler {
public:
    virtual void handleClient(istream in, ostream out) = 0;
};

#endif //EX4_CLIENTHANDLER_H
