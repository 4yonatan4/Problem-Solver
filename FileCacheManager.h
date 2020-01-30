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
#include <mutex>
#include "CacheManager.h"

using namespace std;

template<class P, class S>
class FileCacheManager : public CacheManager<vector<string> *, string> {
public:
    //std::mutex mutex;
    // get problem and return if we already got the solution
    bool contain(vector<string> *problem) override {
        // lock the fuction. will unlock in the end of the function.
        std::lock_guard<std::mutex> guard(mutex);
        string str = hashName(problem);
        ifstream inputStream(str, ios::binary);
        return (!inputStream.fail());
    }

    // save solution to a specific problem
    void save(vector<string> *problem, string solution) override {
        // lock the fuction. will unlock in the end of the function.
        std::lock_guard<std::mutex> guard(mutex);
        // make uniqe name of the problem
        string str = hashName(problem);
        // open the output stream
        ofstream outputStream(str, ios::binary);
        // update the file
        outputStream << solution << endl;
        // close the output stream
        outputStream.close();
    }

    // get
    string get(vector<string> *problem) override {
        // lock the fuction. will unlock in the end of the function.
        std::lock_guard<std::mutex> guard(mutex);
        // make uniqe name of the problem
        string str = hashName(problem);
        // try to open the file = search the solution in the files
        ifstream inputStream;
        inputStream.open(str, ios::binary);
        // found the file
        if (inputStream.is_open()) {
            string solution{};
            getline(inputStream, solution);
            inputStream.close();
            return solution;
        } else { // fail = file not found.
            cout << "file not found" << endl;
            return nullptr;
        }
    }

    string hashName(vector<string> *problem) {
        // lock the fuction. will unlock in the end of the function.
        std::lock_guard<std::mutex> guard(mutex);
        string hashProblem;
        for (string s : *problem) {
            hashProblem += s;
        }
        hash<string> hash1;
        size_t hash = hash1(hashProblem);
        hashProblem = to_string(hash) + ".txt";
        return hashProblem;
    }
};

#endif //EX4_FILECACHEMANAGER_H
