//
// Created by yonatan on 15/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <iostream>
#include <vector>
#include "CacheManager.h"

using namespace std;

/*
 * ClientHandler interface
 */
class ClientHandler {
public:
    virtual void handleClient(int client_socket) = 0;

    virtual CacheManager<vector<string> *, string>* getClientHandler() = 0;
};

#endif //EX4_CLIENTHANDLER_H
