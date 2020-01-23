//
// Created by Efraim Paley on 1/21/20.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

#include "Point.h"
#include <string>

template<class T>
class State {
public:
    // will be Point in matrix
    T state;
    double value;
    double cost = value;
    State<T> *cameFrom;
    std::string nextMove;

    bool equals(State<T> &other) {
        return ((this->point.getX() == other.point.getX()) && (this->point.getY() == other.point.getY()));
    }

    double getCost() const{
        return this->cost;
    }

    // To compare two cost
    class costComparator
    {
    public:
        int operator() (const State<T>* s1, const State<T>* s2)
        {
            return s1->getCost() > s2->getCost();
        }
    };
};




#endif //EX4_STATE_H
