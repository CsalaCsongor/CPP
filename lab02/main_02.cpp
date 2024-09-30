#include <iostream>
#include "Point.h"
using namespace std;
int main() {
    Point p(1, 1);
    Point p1(4, 5);

    std::cout << "Tavolsag: " << Point::diistance(p, p1) << std::endl;

    Point point;
    point.testIsSquare("input.txt");
    return 0;
}
