//
// Created by yonatan on 15/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H
/*
 * Cache Manager interface
 */
template <class P, class S>
class CacheManager{
public:
    // contain
    // get problem and return if we already got the solution
    bool contain (P problem) = 0;
    // save solution to a specific problem
    int save(P problem, S solution) = 0;
    // get
    S get(P problem) = 0;

    // ????
    // replace/update to a new solution
    // full
};
#endif //EX4_CACHEMANAGER_H
