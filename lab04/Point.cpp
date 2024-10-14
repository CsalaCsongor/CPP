#include "Point.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print() const {
    std::cout << "Point(" << x << "," << y << ")" << std::endl;
}

 double Point::distanceTo(const Point& b){
    double dx = this->getX() - b.getX();
    double dy = this->getY() - b.getY();
    return sqrt(dx * dx - dy * dy);
}





