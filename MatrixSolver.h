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
class MatrixSolver : public Solver<string, string>
{
    Searcher<Point>* searcher;
public:
   //constructor
    MatrixSolver(Searcher<Point>* searcher){this->searcher = searcher;};
    string  solve(vector<string> matrix, int rows);
};


#endif //EX4_MATRIXSOLVER_H
