//
// Created by Efraim Paley on 1/28/20.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H
#include "State.h"
#include "AbstractSearcher.h"
#include <queue>
#include <stack>
#include <vector>
#include <iostream>

template<class T>
class DFS : public AbstractSearcher<T>
{
private:
    stack<State<T> *> *DFSStack;
    int numOfNodesEvaluated = 0;
public:
    DFS<T>()

    {
        DFSStack = new stack<State<T> *>;
        this->numOfNodesEvaluated = 0;
    }

    virtual Solution<T> *search(Searchable<T> *searchable);

    Solution<T> *backTrace(State<T> *goalState, State<T> *initState);

    string checkDirection(State<T> *s1, State<T> *cameFrom1);
};

template<class T>
Solution<T>* DFS<T>::search(Searchable<T> *searchable)
{
    State<T> *node = searchable->getInitialState();
    //set color to grey
    node->setColor('g');
    DFSStack->push(node);
    while (!(DFSStack->empty()))
    {
        DFSStack->pop();
        //if we hit a wall
        if (node->getCost() == -1)
        {
            //set the node to black
            node->setColor('b');
            //update the node
            node = DFSStack->top();
            continue;
        }
        //check all the neighbors
        vector<State<T> *> *successors = searchable->getAllPossibleStates(node);
        int size = successors->size();
        for (int i = 0; i < size; i++)
        {
            State<T> *s = successors->at(i);
            // if we didnt visit the neighbor s yet and its not a wall
            if (s->getColor() == 'w')
            {
                //set color to grey
                s->setColor('g');
                s->cameFrom = node;
                s->cost += node->getCost();
                DFSStack->push(s);
            }

        }
        this->numOfNodesEvaluated += 1;
        //once we finish checking all the neighbors of the node- change to black
        node->setColor('b');
        //update the node
        node = DFSStack->top();
        if (searchable->isGoalState(node))
        {
            // backtrace, return the solution - path, according to the output text that we get
            Solution<T> *solution = backTrace(node, searchable->getInitialState());
            solution->setnumOfNodesEvaluated(this->numOfNodesEvaluated);
            return solution;
        }

    }

}

template<class T>
Solution<T>* DFS<T>::backTrace(State<T> *goalState, State<T> *initState) {
    // create empty Solution - vector of states
    auto *solution = new Solution<Point*>();
    // start from the goal, and check his cameFrom
    State<T> *s = goalState;
    // go back until the beginning
    // calculate for every node is next Move
    // insert to the solution from the end to beginning
    while (!(s->equals(initState))) {
        // insert the state to the beginning of the vector
        solution->getVectorOfStates()->insert(solution->getVectorOfStates()->begin(), s);
        // calculate for every node is next Move
        string direction = checkDirection(s, s->cameFrom);
        s->cameFrom->nextMove = direction;
        // go back in the trace
        s = s->cameFrom;
    }
    solution->getVectorOfStates()->insert(solution->getVectorOfStates()->begin(), s);
    return solution;
}


template<class T>
string DFS<T>::checkDirection(State<T> *s1, State<T> *cameFrom1) {
    Point* s = s1->state;
    Point* cameFrom = cameFrom1->state;
    // x values equals
    if (s->getX() == cameFrom->getX()) {
        // Left
        if (s->getY() < cameFrom->getY()) {
            return "Left";
        } else { // Right
            return "Right";
        }
    }
    // y values equals
    if (s->getY() == cameFrom->getY()) {
        // Down
        if (s->getX() < cameFrom->getX()) {
            return "Up";
        } else { // Up
            return "Down";
        }
    }
    return "undefined move";
}
//ggg
#endif //EX4_DFS_H
