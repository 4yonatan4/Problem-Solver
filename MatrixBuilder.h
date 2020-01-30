//
// Created by Efraim Paley on 1/23/20.
//

#ifndef EX4_MATRIXBUILDER_H
#define EX4_MATRIXBUILDER_H

#include <vector>
#include "Searchable.h"
#include "State.h"

using namespace std;

template<class T>
class MatrixBuilder : public Searchable<Point *> {
public:
    vector<vector<State<Point *> *> *> *theMatrix;
    int rows, columns;
    State<Point *> *firstState;
    State<Point *> *goalState;

    State<Point *> *getGoalState() override {
        return this->goalState;
    }


    string toString() override { return nullptr; };

    MatrixBuilder(vector<string> *matrix) {
        this->theMatrix = new vector<vector<State<Point *> *> *>;
        int size = matrix->size();
        int enter = size - 2;
        int exit = size - 1;
        this->rows = size - 2;
        // calculate the number of columns
        calculateColumns(matrix);
        // create new matrix of state with the values that we get from the client
        createTheMatrix(matrix);
        // create enter State
        string enterLine = matrix->at(enter);
        Point *enterPoint = new Point(enterLine);
        this->firstState = theMatrix->at(enterPoint->getX())->at(enterPoint->getY());

        // create goal State
        string exitLine = matrix->at(exit);
        Point *exitPoint = new Point(exitLine);
        this->goalState = theMatrix->at(exitPoint->getX())->at(exitPoint->getY());
    }


    State<Point *> *getInitialState() override {
        return this->firstState;
    }

    bool isGoalState(State<Point *> *state) override {
        return state->equals(goalState);
    }

    void calculateColumns(vector<string> *matrix) {
        string line = matrix->at(0);
        int count = 0;
        for (char c: line) {
            if (c == ',') {
                count++;
            }
        }
        this->columns = count + 1;
    }


    void createTheMatrix(vector<string> *matrix) {
        int i, j, count = 0;
        string line;
        for (i = 0; i < rows; i++) {
            count = 0;
            line = matrix->at(i);
            theMatrix->push_back(new vector<State<Point *> *>());
            for (j = 0; j < columns; j++) {
                string temp;
                while (line[count] != ',') {
                    temp += line[count];
                    count++;
                    if (line[count] == '\0') {
                        break;
                    }
                }
                Point *point = new Point(i, j);
                auto *state = new State<Point *>(point);
                state->value = stoi(temp);
                state->cost = state->value;
                theMatrix->at(i)->push_back(state);
                count++;
            }
        }
    }


    vector<State<Point *> *> *getAllPossibleStates(State<Point *> *state) override {
        vector<State<Point *> *> *possibleStatesVector = new vector<State<Point *> *>;
//x(i)= rows
        int x = state->state->getX();
//y(j) = columns
        int y = state->state->getY();
        // left
        if (y != 0) {
            if (this->theMatrix->at(x)->at(y - 1)->value != -1)
                possibleStatesVector->push_back(this->theMatrix->at(x)->at(y - 1));
        }
        // right
        if (y != this->columns - 1) {
            if (this->theMatrix->at(x)->at(y + 1)->value != -1)
                possibleStatesVector->push_back(this->theMatrix->at(x)->at(y + 1));
        }
        // up
        if (x != 0) {
            if (this->theMatrix->at(x - 1)->at(y)->value != -1)
                possibleStatesVector->push_back(this->theMatrix->at(x - 1)->at(y));
        }
        // down
        if (x != this->rows - 1) {
            if (this->theMatrix->at(x + 1)->at(y)->value != -1)
                possibleStatesVector->push_back(this->theMatrix->at(x + 1)->at(y));
        }
        return possibleStatesVector;
    }

};


#endif //EX4_MATRIXBUILDER_H
