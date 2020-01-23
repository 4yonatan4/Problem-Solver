//
// Created by Efraim Paley on 1/22/20.
//

#ifndef EX4_MATRIXSOLVER_H
#define EX4_MATRIXSOLVER_H

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
#include "State.h"
#include <vector>
#include "MatrixBuilder.h"
#define MAX 50

using namespace std;
class MatrixSolver : public Solver<vector<string>*, string>
{
    Searcher<Point>* searcher;
public:
    int val;
    vector<vector<State<Point>*>>* theMatrix;
    int rows;
    State<Point*>* firstState;
    State<Point*>* goalState;
    State<Point*>* getInitalState(State<Point>* state) override;
    State<Point*>* getGoalState(State<Point>* state) override;
    State<Point*>* getAllPossibleStates(State<Point>* state) override;
    //constructor
    MatrixSolver(Searcher<Point*>* searcher)
    {
        this->searcher = searcher;
    }

    string solve(vector<string>* matrix)
    {
//        MatrixBuilder* matrixProblemToBuild = new MatrixBuilder(&matrix);
        this->theMatrix = new vector<vector<State<Point>*>>;
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
        return this->searcher->search(matrixProblemToBuild);
    }


};


#endif //EX4_MATRIXSOLVER_H
