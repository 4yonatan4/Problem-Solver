//
// Created by Efraim Paley on 1/21/20.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

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
#include <mutex>
#include "State.h"
#include <vector>


#define MAXSIZE = 1024

using namespace std;
class myClientHandler : public ClientHandler
{
    void handleClient(int client_socket)  {
        char buffer[1024];
        int valread = read(client_socket, buffer, 1024);
        string str;
        vector <vector<State<double>>> matrix;
        while (strcmp(buffer, "end") != 0)
        {
            for (int i = 0; i < 1024; i++)
            {
                if (buffer[i] == '\n')
                {
                    buffer[i] = '\0';
                    break;
                }
            }
            string problem(buffer)
            while (getline(buffer, 1024))


                // search the solution in the cache
            string problem(buffer);
            string solution;
            // if in the cache, return the solution

            valread = read(client_socket, buffer, 1024);
        }
    }

};


#endif //EX4_MYCLIENTHANDLER_H
