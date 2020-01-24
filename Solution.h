//
// Created by yonatan on 21/01/2020.
//

#ifndef EX4_SOLUTION_H
#define EX4_SOLUTION_H

#include "State.h"
#include <vector>
#include <string>

template<class T>
class Solution {
private:
    std::vector<State<T> *> *vectorOfStates;
public:
    Solution() {
        vectorOfStates = new std::vector<State<T> *>();
    }

    virtual ~Solution() {
        delete vectorOfStates;
    };

    std::vector<State<T> *> *getVectorOfStates() {
        return vectorOfStates;
    }

    // print the solution
    string createSolution();

    string getSolution() {
        return this->createSolution();
    }
};

template<class T>
string Solution<T>::createSolution() {
    std::string finalSolution;
    // loop in vector
    // print every direction + (cost)
    int size = vectorOfStates->size();
    for (int i = 0; i < size; i++) {
        State<T> *s = vectorOfStates->at(i);
        std::string temp = s->nextMove + " (" + to_string(s->getCost()) + "), ";
        finalSolution += temp;
    }
    return finalSolution;
}

#endif //EX4_SOLUTION_H
