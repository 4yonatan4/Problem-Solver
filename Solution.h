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
    int numOfNodesEvaluated;
public:
    void setnumOfNodesEvaluated(int num){
        this->numOfNodesEvaluated = num;
    }
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
    State<T> *s = vectorOfStates->at(0);
    finalSolution += s->nextMove;
    int i;
    for (i = 1; i < size - 1; i++) {
        s = vectorOfStates->at(i);
        std::string temp = " (" + to_string(s->getCost()) + "), " + s->nextMove;
        finalSolution += temp;
    }
    // insert the last step
    s = vectorOfStates->at(i);
    std::string temp = " (" + to_string(s->getCost()) + ")";
    finalSolution += temp;
    finalSolution += " Total nodes: " + to_string(this->numOfNodesEvaluated);
    return finalSolution;
}

#endif //EX4_SOLUTION_H
