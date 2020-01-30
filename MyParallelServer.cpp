//
// Created by yonatan on 28/01/2020.
//

#include "MyParallelServer.h"
#include "MatrixSolver.h"
#include <iostream>
#include "Astar.h"
#include "MyClientHandler.h"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>


static bool run = true;

void MyParallelServer::open(int port, ClientHandler *clientHandler) {
    this->openServer(port, clientHandler);
}

void MyParallelServer::stop() {
    run = false;
}

int MyParallelServer::openServer(int port, ClientHandler *clientHandler) {
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    struct timeval tv;
    tv.tv_sec = 120;
    // Forcefully attaching socket
    if (setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO,
                   &tv, sizeof(tv))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    //the actual bind command
    if (::bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }
    bool firstClient = true;
    while (run) {
        //making socket listen to the port
        if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
            std::cerr << "Error during listening command" << std::endl;
            return -3;
        } else {
            std::cout << "Server is now listening ..." << std::endl;
        }

        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                   (socklen_t *) &address);
        if (errno == EWOULDBLOCK) {
            std::cerr << "Time Out" << std::endl;
            return -8;
        }
        if (client_socket == -1) {
            std::cerr << "Error accepting client" << std::endl;
            return -4;
        }
        // check if firstClient
        if (firstClient) {
            thread newClient(MyParallelServer::openNewClientThread, clientHandler, client_socket);
            newClient.detach();
            firstClient = false;
        } else {
            // open new thread to take care of the current client
            // make deep copy to:
            // solver, clientHandler
            // the cache will be shared, so need to use mutex in every method of the cache

            // 1. make deep copy to solver
            Solver<vector<string> *, string> *newSolver = new MatrixSolver(new Astar<Point *>());
            ClientHandler *newClientHandler = new MyClientHandler(newSolver, clientHandler->getClientHandler());
            // open new Thread
            thread newClient(MyParallelServer::openNewClientThread, newClientHandler, client_socket);
            newClient.detach();
        }
    }
    close(socketfd);//closing the listening socket
    return 0;
}

int MyParallelServer::openNewClientThread(ClientHandler *newClientHandler, int client_socket) {
//    std::mutex mutex;
//    std::lock_guard<std::mutex> guard(mutex);
    newClientHandler->handleClient(client_socket);
    return 0;
}
