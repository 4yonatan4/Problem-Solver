//
// Created by yonatan on 21/01/2020.
//

#ifndef EX4_ABSTRACTSEARCHER_H
#define EX4_ABSTRACTSEARCHER_H

#include "Searcher.h"

template<class T>
class AbstractSearcher : public Searcher<T> {
protected:
    int* numOfNodesEvaluated;
public:
    virtual Solution<T>*search(Searchable<T>* searchable) = 0;

    virtual int getNumOfNodesEvaluated(){
        return numOfNodesEvaluated;
    }
};

#endif //EX4_ABSTRACTSEARCHER_H
