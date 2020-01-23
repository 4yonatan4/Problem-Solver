//
// Created by yonatan on 22/01/2020.
//

#ifndef EX4_PRIORITYQUEUE_H
#define EX4_PRIORITYQUEUE_H

#include "State.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


template<class T>
class PriorityQueue {
public:
    int *numOfNodesEvaluated;
    priority_queue<State<T> *, vector<State<T> *>, typename State<T>::costComparator> *queue;

    PriorityQueue(int *numOfNodesEvaluated1) {
        queue = new priority_queue<State<T> *, vector<State<T> *>, typename State<T>::costComparator>();
        numOfNodesEvaluated = numOfNodesEvaluated1;
    }

    bool contain(State<T> *s);

    void updateKey(State<T> *s);

    void pop() {
        *numOfNodesEvaluated += 1;
        queue->pop();
    }

    State<T> *top() {
        return queue->top();
    }

    bool empty() {
        return queue->empty();
    }

    void push(State<T> *s) {
        queue->push(s);
    }


};

template<class T>
/*
     * check if the queue contain specific State
     */
bool PriorityQueue<T>::contain(State<T> *s) {
    auto *temp = new vector<State<T> *>();
    // pop every State, and check if equal to s.
    // if it is, return true
    while (!queue->empty()) {
        State<T> *curr = queue->top();
        queue->pop();
        temp->push_back(curr);
        if (s->equals(curr)) {
            // get back all State to the queue
            int size = temp->size();
            for (int i = 0; i < size; ++i) {
                queue->push(temp[i]);
            }
            return true;
        }
    }
    // the queue not contain s
    // get back all State to the queue
    int size = temp->size();
    for (int i = 0; i < size; ++i) {
        queue->push(temp[i]);
    }
    return false;
}

/*
 * update key - get out all element until s, and pushed them back
 */
template<class T>
void PriorityQueue<T>::updateKey(State<T> *s) {
    auto *temp = new vector<State<T> *>();
    // pop every State, and check if equal to s.
    // if it is, return true
    while (!queue->empty()) {
        State<T> *curr = queue->top();
        queue->pop();
        temp->push_back(curr);
        if (s->equals(curr)) {
            // get back all State to the queue, include s himself
            int size = temp->size();
            for (int i = 0; i < size; ++i) {
                queue->push(temp[i]);
            }
            return;
        }
    }
}


#endif //EX4_PRIORITYQUEUE_H
