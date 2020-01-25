//
// Created by Efraim Paley on 1/21/20.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H

#include <string>
class Point {
public:
    /**
     * Constructor and destructor
     */
    Point(int x, int y);
    Point(std::string line);
    virtual ~Point();

    /**
     * Get the x value
     */
    int getX() const;

    /**
     * Get the y value
     */
    int getY() const;

    /**
     * Return the distance between Points
     */
    int distance(const Point &p) const;

private:
    int x;
    int y;
};

#endif //EX4_POINT_H
