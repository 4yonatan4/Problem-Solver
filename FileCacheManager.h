//
// Created by yonatan on 15/01/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H


#include <unordered_map>
#include <fstream>
#include "CacheManager.h"

using namespace std;

template<class S>

class FileCacheManager : public CacheManager<string, S> {
public:
    // get problem and return if we already got the solution
    bool contain(string problem) override {
        string str = problem + ".txt";
        ifstream inputStream(str, ios::binary);
        return (!inputStream.fail());
    }

    // save solution to a specific problem
    void save(string problem, S solution) override {
        // make uniqe name of the problem
        string str = problem + ".txt";
        // open the output stream
        ofstream outputStream(str, ios::binary);
        // update the file
        outputStream.write((char *) &solution, solution.size());
        // close the output stream
        outputStream.close();
        }

    // get
    S get(string problem) override {
        // make uniqe name of the problem
        string str = problem + ".txt";
        // try to open the file = search the solution in the files
        ifstream inputStream(str, ios::binary);
        // not fail = found, fail = not found.
        if (inputStream.fail()) {
            return NULL;
        } else { // found the file
            S solution;
            inputStream.read((char *) &solution, sizeof(solution));
            inputStream.close();
            return solution;
        }
    }
};

#endif //EX4_FILECACHEMANAGER_H
