//
// Created by Efraim Paley on 1/21/20.
//

#include "Point.h"

using namespace std;

Point::Point(int x1, int y1) : x(x1), y(y1) {

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
    double distance = y - x;
    return distance;
}

Point::~Point() {

}

