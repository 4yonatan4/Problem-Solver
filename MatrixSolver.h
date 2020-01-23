//
// Created by Efraim Paley on 1/22/20.
//

#ifndef EX4_MATRIXSOLVER_H
#define EX4_MATRIXSOLVER_H

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
#include <vector>

using namespace std;
class MatrixSolver : public Solver<vector<string>, string>
{
public:
    vector<string> matrix;
    int rows;
    Searcher<vector<string>> searcher
    MatrixSolver(Searcher s );

};


#endif //EX4_MATRIXSOLVER_H
