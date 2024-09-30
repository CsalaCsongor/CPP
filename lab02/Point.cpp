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

 double Point::dist2(const Point& a, const Point& b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool Point::isSquare(Point p1, Point p2, Point p3, Point p4) {
    int d[6] = { dist2(p1, p2), dist2(p1, p3), dist2(p1, p4), dist2(p2, p3), dist2(p2, p4), dist2(p3, p4) };
    std::sort(d, d + 6);
    return d[0] > 0 && d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5];
}

void Point::testIsSquare(const char * filename)
{
std::ifstream inputFile(filename);
if(!inputFile)
    std::cerr<<"Error Opening the File." << std::endl;

Point A, B, C, D;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        if(iss >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y)
            if(isSquare(A, B, C, D)){
                A.print();
                B.print();
                C.print();
                D.print();
                std::cout << "Pontok negyzetet alkotnak." << std::endl;
            }
        else
            {
                A.print();
                B.print();
                C.print();
                D.print();
                std::cout << "Pontok NEM negyzetet alkotnak." << std::endl;
            }

    }

    inputFile.close();
}


