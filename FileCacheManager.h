//
// Created by yonatan on 15/01/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H


#include <unordered_map>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "CacheManager.h"

using namespace std;

template <class P, class S>
class FileCacheManager : public CacheManager<vector<string>*, string> {
public:
    // get problem and return if we already got the solution
    bool contain(vector<string>* problem) override {
        string str = hashName(problem);
        ifstream inputStream(str, ios::binary);
        return (!inputStream.fail());
    }

    // save solution to a specific problem
    void save(vector<string>* problem, string solution) override {
        // make uniqe name of the problem
        string str = hashName(problem);
        // open the output stream
        ofstream outputStream(str, ios::binary);
        // update the file
        outputStream.write((char *) &solution, solution.size());
        // close the output stream
        outputStream.close();
    }

    // get
    string get(vector<string>* problem) override {
        // make uniqe name of the problem
        string str = hashName(problem);
        // try to open the file = search the solution in the files
        ifstream inputStream(str, ios::binary);
        // not fail = found, fail = not found.
        if (inputStream.fail()) {
            return nullptr;
        } else { // found the file
            string solution;
            inputStream.read((char *) &solution, solution.size());
            inputStream.close();
            return solution;
        }
    }

    string hashName(vector<string>* problem){
        string hashProblem;
        int size = problem->size();
        for(string s : *problem){
            hashProblem += s;
        }
        hash<string> hash1;
        size_t hash = hash1(hashProblem);
        hashProblem = to_string(hash) + ".txt";
        return hashProblem;
    }
};

#endif //EX4_FILECACHEMANAGER_H
