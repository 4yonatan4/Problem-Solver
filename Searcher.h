//
// Created by yonatan on 21/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Solution.h"
#include "Searchable.h"

template <class T>
class Searcher{
public:
    virtual Solution<T>* search(Searchable<T>* searchable) = 0;
};
#endif //EX4_SEARCHER_H
