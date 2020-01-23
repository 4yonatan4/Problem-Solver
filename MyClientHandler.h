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
    Solver<string, string> *solver;
    CacheManager<string, string> *cacheManager;

    MyClientHandler(Solver<string,string>* solver1, CacheManager<string, string> *cacheManager1)
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


//            int valread = read(client_socket, buffer, 1048);
//            for (char c : buffer)
//            {
//                //check if we reached end of line
//                if (c == '\n')
//                {
//                    //if end= break
//                    if (line == "end")
//                    {
//                        break;
//                    }
//                    //when we reach end of line push into vector and break, add the counter
//                    matrix.push_back(line);
//
//                    line = "";
//                    break;
//                }
//                line += c;



//                if (line == "end")
//                {
//                    if (cacheManager->contain(matrix[0])) {
//                        solution = cacheManager->get(problem);
//                        const char *sol = solution.c_str();
//                        send(client_socket , sol , strlen(sol), 0);
//                        fflush(stdout);
//                    } else {
//                        solution = solver->solve(problem);
//                        solution += "\r\n";
//                        cacheManager->save(problem, solution);
//                        const char *sol = solution.c_str();
//                        send(client_socket , sol , strlen(sol), 0);
//                        fflush(stdout);
    }

};
#endif //EX4_MYCLIENTHANDLER_H
