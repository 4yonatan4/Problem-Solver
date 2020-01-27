cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(ex4 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.h CacheManager.h FileCacheManager.h Solver.h StringReverser.cpp StringReverser.h
        Searchable.h State.h BestFS.h Searcher.h AbstractSearchable.h AbstractSearcher.h PriorityQueue.h Solution.h Point.cpp
        MyClientHandler.h Astar.h PriorityQueueHeuristic.h)