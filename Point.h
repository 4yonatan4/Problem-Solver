//
// Created by Efraim Paley on 1/21/20.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H

class Point {
public:
    /**
     * Constructor and destructor
     */
    Point(double x, double y);
    virtual ~Point();

    /**
     * Get the x value
     */
    double getX() const;

    /**
     * Get the y value
     */
    double getY() const;

    /**
     * Return the distance between Points
     */
    double distance(const Point &p) const;

private:
    double x;
    double y;
};

#endif //EX4_POINT_H
