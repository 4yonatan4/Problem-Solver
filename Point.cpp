//
// Created by Efraim Paley on 1/21/20.
//

#include "Point.h"

using namespace std;

Point::Point(double x, double y) : x(x), y(y)
{

}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::distance(const Point &p) const
{
    double distance = y-x;
    return distance;
}

Point::~Point() {
    // TODO Auto-generated destructor stub
}

