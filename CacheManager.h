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
    virtual bool contain (P problem) = 0;
    // save solution to a specific problem
    virtual void save(P problem, S solution) = 0;
    // get
    virtual S get(P problem) = 0;
};
#endif //EX4_CACHEMANAGER_H
