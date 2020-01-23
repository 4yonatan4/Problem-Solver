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
template <class T>
class MatrixSolver : public Solver<vector<string>*, string>
{
    Searcher<Point>* searcher;
public:
    //constructor
    MatrixSolver(Searcher<Point>* searcher)
    {
        this->searcher = searcher;
    }

    string solve(vector<string> matrix)
    {
        MatrixBuilder<Point*>* matrixProblemToBuild = new MatrixBuilder<Point*>(&matrix);
        return this->searcher->search(matrixProblemToBuild);
    }


};


#endif //EX4_MATRIXSOLVER_H
