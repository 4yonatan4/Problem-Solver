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
    T state;
    int value;
    int cost = value;
    State<T> *cameFrom;
    std::string nextMove;
    explicit State(Point* point)
    {
        this->state = point;
    }

    bool equals(State<T>* other);

    int getCost() const{
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

// will be Point in matrix
template<class T>
bool State<T>::equals(State<T>* other) {
    // maybe like this ???
//    Point* p1 = this->state;
//    Point* p2 = other->state;

    Point* p1 = (Point*) this->state;
    Point* p2 = (Point*) other->state;
    return ((p1->getX() == p2->getX()) && (p1->getY() == p2->getY()));
}




#endif //EX4_STATE_H
