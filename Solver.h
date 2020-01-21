//
// Created by Efraim Paley on 1/16/20.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
//
//Solver interface
//
template <class P, class S>
class Solver
{
public:
    virtual S solve(P problem) = 0;
};


#endif //EX4_SOLVER_H
