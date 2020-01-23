//
// Created by yonatan on 21/01/2020.
//

#ifndef EX4_SOLUTION_H
#define EX4_SOLUTION_H

#include "State.h"
#include <vector>
#include <string>

template <class T>
class Solution{
private:
    std::vector<State<T>*>* vectorOfStates;
public:
    Solution(){
        vectorOfStates = new std::vector<State<T>*>();
    }
    virtual ~Solution(){
        delete vectorOfStates;
    };
    std::vector<State<T>*>* getVectorOfStates (){
        return vectorOfStates;
    }
    // print the solution
    void printSolution();
};

template <class T>
void Solution<T>::printSolution() {
    std::string finalSolution = "";
    // loop in vector
    // print every direction + (cost)
    for(State<T>* s : vectorOfStates){
        std::string temp = s->nextMove + " (" + to_string(s->getCost()) + "), ";
        finalSolution += temp;
    }
}

#endif //EX4_SOLUTION_H
