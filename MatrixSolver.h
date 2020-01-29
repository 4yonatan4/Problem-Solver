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

public:
    Searcher<Point*>* searcher;
    //constructor
    MatrixSolver(Searcher<Point*>* searcher)
    {
        this->searcher = searcher;
    }

    string solve(vector<string>* matrix) override
    {
        auto* matrixProblemToBuild = new MatrixBuilder<Point*>(matrix);
        Solution<Point*>* solution = this->searcher->search(matrixProblemToBuild);
        if (solution != nullptr){
            return solution->getSolution();
        }
        return "Path Not Found!";
    }


};


#endif //EX4_MATRIXSOLVER_H
