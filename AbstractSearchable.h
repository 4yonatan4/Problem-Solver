//
// Created by yonatan on 22/01/2020.
//

#ifndef EX4_ABSTRACTSEARCHABLE_H
#define EX4_ABSTRACTSEARCHABLE_H

#include "Searchable.h"

template <class T>
class AbstractSearchable: public Searchable<T>{
private:
    State<T> start;
    State<T> end;
public:
    virtual  State<T> getInitialState() = 0;
    virtual bool isGoalState(State<T> state);
    virtual vector<State<T>> getAllPossibleStates(State<T> state) = 0;
    virtual string toString() = 0;
};

template <class T>
bool AbstractSearchable<T>::isGoalState(State<T> state) {
    return start.equals(state);
}

#endif //EX4_ABSTRACTSEARCHABLE_H
