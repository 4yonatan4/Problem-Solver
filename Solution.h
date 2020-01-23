//
// Created by yonatan on 21/01/2020.
//

#ifndef EX4_SOLUTION_H
#define EX4_SOLUTION_H

#include "State.h"
#include <vector>

template <class T>
class Solution{
private:
    std::vector<State<T>*>* vectorOfStates;
public:
    Solution(){
        vectorOfStates = new std::vector<State<T>*>();
    }
    std::vector<State<T>>* getVectorOfStates (){
        return vectorOfStates;
    }
    // print the solution
    void printSolution();
};

template <class T>
void Solution<T>::printSolution() {
    // loop in vector
    // print every direction + (cost)
}

#endif //EX4_SOLUTION_H
