//
// Created by Efraim Paley on 1/23/20.
//

#ifndef EX4_MATRIXBUILDER_H
#define EX4_MATRIXBUILDER_H

#include <vector>
#include "Searchable.h"
#include "State.h"
using namespace std;
template <class T>
class MatrixBuilder : public Searchable<Point*>
{
public:
    vector<vector<State<Point*>*>*>* theMatrix;
    int rows;
    State<Point*>* firstState;
    State<Point*>* goalState;
    State<Point*>* getInitialState() override;
    bool isGoalState(State<Point*>* state) override;
    vector<State<Point*>*>* getAllPossibleStates(State<Point*>* state) override;
    MatrixBuilder(vector<string>* matrix)
    {
        this->theMatrix = new vector<vector<State<Point>*>>*;
        this->rows = matrix.size() - 2;
        int i,j;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < rows; j++) {
                Point* point = new Point(i, j);
                auto* state = new State<Point>(*point);
                this->val = stoi(matrix[i][j]);
                state->value = this->val;
            }
        }


    }

};

#endif //EX4_MATRIXBUILDER_H
