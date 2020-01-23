//
// Created by Efraim Paley on 1/21/20.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H


#include "State.h"
#include <vector>
#include <string>


using namespace std;

/*
 * Searchable interface
 */

template <class T>
class Searchable
{
public:
    virtual  State<T> getInitialState() = 0;
    virtual bool isGoalState(State<T> state) = 0;
    virtual vector<State<T>> getAllPossibleStates(State<T> state) = 0;
    virtual string toString() = 0;

};


#endif //EX4_SEARCHABLE_H
