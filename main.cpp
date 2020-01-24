#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "PriorityQueue.h"
#include "MyClientHandler.h"
#include "State.h"
#include "BestFS.h"
#include <string>


int main(int argc, char** argv)
{
    server_side::Server* server = new MySerialServer();
    CacheManager<vector<string>*, string>* cacheManager = new FileCacheManager<vector<string>*,string>();
    Solver<vector<string>*,string>* solver = new MatrixSolver(new BestFS<Point*>());
    ClientHandler* clientHandler = new MyClientHandler(solver, cacheManager);
    int port = stoi(argv[1]);
    server->open(port, clientHandler);
}

