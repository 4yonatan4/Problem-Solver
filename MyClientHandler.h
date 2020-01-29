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


#define MAXSIZE  2048

//using namespace std;

class MyClientHandler : public ClientHandler {
public:
    Solver<vector<string> *, string> *solver;
    CacheManager<vector<string> *, string> *cacheManager;

    MyClientHandler(Solver<vector<string> *, string> *solver1, CacheManager<vector<string> *, string> *cacheManager1) {
        this->solver = solver1;
        this->cacheManager = cacheManager1;
    }

    virtual CacheManager<vector<string> *, string>* getClientHandler() {
        return this->cacheManager;
    }

    void handleClient(int client_socket) override {
        char buffer[MAXSIZE];
        string line;
        auto *matrix = new vector<string>();
        bool end = false;
        while (!end) {
            int valread = read(client_socket, buffer, MAXSIZE);
            if (valread < 0){
                cout << "ERROR reading from socket\n";
                break;
            }
            line = "";
            for (char c: buffer) {
                if (c == '\n') {
                    if (line == "end") {
                        end = true;
                        break;
                    }
                    matrix->push_back(line);
                    break;
                }
                if (c == EOF){
                    end = true;
                    break;
                }
                if (c != ' ') {
                    line += c;
                }
            }
        }

        string solution;
        // check if the problem is in the cache
        if (this->cacheManager->contain(matrix)) {
            solution = this->cacheManager->get(matrix);
        } else {
            solution = this->solver->solve(matrix);
            this->cacheManager->save(matrix, solution);
        }
        const char *sol = solution.c_str();
        send(client_socket, sol, strlen(sol), 0);
        cout << "Answer sent to client!\n" << endl;
    }
};

#endif //EX4_MYCLIENTHANDLER_H
