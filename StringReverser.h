//
// Created by Efraim Paley on 1/19/20.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H
#include <string>
#include "Solver.h"
class StringReverser : public Solver<std::string,std::string>
{
public:
    std::string solve(std::string problem) override;

};


#endif //EX4_STRINGREVERSER_H
