// Point.h - interfész
#ifndef POINT_H
#define POINT_H
class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
    static double dist2(const Point& a, const Point& b);
    bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
    void testIsSquare(const char * filename);

};
#endif /* PONT_H */
