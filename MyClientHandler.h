//
// Created by Efraim Paley on 1/21/20.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "MySerialServer.h"
#include <iostream>
#include <string>
#include "State.h"
#include "MatrixSolver.h"
#include <vector>
#include <fstream>



#define MAXSIZE  5000

using namespace std;

class MyClientHandler : public ClientHandler
{
public:
    Solver<vector<string>*, string> *solver;
    CacheManager<vector<string>*, string> *cacheManager;

    MyClientHandler(Solver<vector<string>*,string>* solver1, CacheManager<vector<string>*, string> *cacheManager1)
    {
        this->solver = solver1;
        this->cacheManager = cacheManager1;
    }

    void handleClient(int client_socket) override
    {
        char buffer[MAXSIZE];
        int valread = read(client_socket, buffer, MAXSIZE);
        int counter = 0;
        string line = "";
        vector<string> matrix;
        int length = strlen(buffer);
        for (int i = 0; i < length; i++)
        {
            if (buffer[i] == '\n')
            {
                matrix.push_back(line);
                counter++;
                line = "";
                continue;
            }
            line += buffer[i];
        }
        int rows = counter - 3;
        string str = solver->solve(matrix);
        //fflush(stdout);
    }

};
#endif //EX4_MYCLIENTHANDLER_H
