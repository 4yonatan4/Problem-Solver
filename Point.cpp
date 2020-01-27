//
// Created by Efraim Paley on 1/21/20.
//

#include "Point.h"
#include <cmath>

using namespace std;

Point::Point(int x, int y) : x(x), y(y) {

}

Point::Point(std::string line) {
    int foundComma = line.find(',');
    string x1 = line.substr(0, foundComma);
    string y1 = line.substr(foundComma + 1);
    this->x = stoi(x1);
    this->y = stoi(y1);
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

int Point::distance(const Point &p) const {
    return sqrt((pow(this->getY() - p.getY(), 2)) + (pow(this->getX() - p.getX(), 2)));
}

Point::~Point() {

}

