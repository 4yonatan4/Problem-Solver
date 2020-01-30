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
    MatrixSolver(Searcher<Point*>* searcher1)
    {
        this->searcher = searcher1;
    }

    string solve(vector<string>* matrix) override
    {
        //build the matrix
        auto* matrixProblemToBuild = new MatrixBuilder<Point*>(matrix);
        //find the solution
        Solution<Point*>* solution = this->searcher->search(matrixProblemToBuild);
        //put solution into string
        if (solution != nullptr){
            return solution->getSolution();
        }
        return "Path Not Found!";
    }


};


#endif //EX4_MATRIXSOLVER_H
