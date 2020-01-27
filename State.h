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
    int heuristic;
    State<T> *cameFrom;
    std::string nextMove;

    explicit State(Point *point) {
        this->state = point;
    }

    bool equals(State<T> *other);

    int getCost() const {
        return this->cost;
    }

    void setHeuristic(State<Point*>* goalState){
        Point* p1 = (Point *) this->state;
        Point* p2 = (Point*) goalState->state;
        this->heuristic = p1->distance(*p2) + this->getCost();
    }

    // To compare two cost
    class costComparator {
    public:
        int operator()(const State<T> *s1, const State<T> *s2) {
            return s1->getCost() > s2->getCost();
        }
    };

    class HeuristicComparator {
    public:
        int operator()(const State<T> *s1, const State<T> *s2) {
            return s1->heuristic > s2->heuristic;
        }
    };
};

// will be Point in matrix
template<class T>
bool State<T>::equals(State<T> *other) {
    Point *p1 = (Point *) this->state;
    Point *p2 = (Point *) other->state;
    return ((p1->getX() == p2->getX()) && (p1->getY() == p2->getY()));
}


#endif //EX4_STATE_H
