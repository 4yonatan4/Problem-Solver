#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

int main(int argc, char** argv)
{
    server_side::Server* server = new MySerialServer();
    CacheManager<string, string>* cacheManager = new FileCacheManager<string>();
    Solver<string, string>* solver = new StringReverser();
    ClientHandler* clientHandler = new MyTestClientHandler(solver, cacheManager);
    int port = stoi(argv[1]);
    server->open(port, clientHandler);
}

