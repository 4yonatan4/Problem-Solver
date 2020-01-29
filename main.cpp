#include <iostream>
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "MyTestClientHandler.h"
#include "PriorityQueue.h"
#include "MyClientHandler.h"
#include "State.h"
#include "BestFS.h"
#include "Astar.h"
#include <string>

#define DEFAULT_PORT 5600

int main(int argc, char** argv) {
    int port = DEFAULT_PORT;
    // if the user insert another port
    if (argc > 1){
        port = stoi(argv[1]);
    }
    server_side::Server* server = new MyParallelServer();
    CacheManager<vector<string>*, string>* cacheManager = new FileCacheManager<vector<string>*,string>();
    Solver<vector<string>*,string>* solver = new MatrixSolver(new Astar<Point*>());
    ClientHandler* clientHandler = new MyClientHandler(solver, cacheManager);
    server->open(port, clientHandler);
}

