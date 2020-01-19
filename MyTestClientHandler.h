//
// Created by yonatan on 15/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include <string>
#include "MySerialServer.h"
#include <iostream>
#include <sys/socket.h>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <string.h>

using namespace std;

/*
 * test of client Handler
 */
class MyTestClientHandler : public ClientHandler {

public:
    Solver<string, string> *solver;
    CacheManager<string, string> *cacheManager;

    MyTestClientHandler(Solver<string, string>* solver1, CacheManager<string, string>* cacheManager1) {
        this->solver = solver1;
        this->cacheManager = cacheManager1;
    }

    void handleClient(int client_socket) override {
        char buffer[1024];
        int valread = read(client_socket, buffer, 1024);
        while (strcmp(buffer, "end\r\n") != 0) {
            // search the solution in the cache
            string problem(buffer);
            string solution;
            // if in the cache, return the solution
            if (cacheManager->contain(problem)) {
                solution = cacheManager->get(problem);
                const char *sol = solution.c_str();
                send(client_socket , sol , strlen(sol), 0);
                fflush(stdout);
            } else {
                solution = solver->solve(problem);
                cacheManager->save(problem, solution);
                const char *sol = solution.c_str();
                send(client_socket , sol , strlen(sol), 0);
                fflush(stdout);
            }
            valread = read(client_socket, buffer, 1024);
        }
    }
};


#endif //EX4_MYTESTCLIENTHANDLER_H
