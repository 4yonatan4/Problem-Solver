//
// Created by Efraim Paley on 1/19/20.
//

#include "StringReverser.h"


std::string StringReverser::solve(std::string problem) {
    int i;
    int size = problem.length();
    for (i = 0; i < (size / 2); i++) {
        std::swap(problem[i], problem[size - i - 1]);
    }
    return problem;
}
