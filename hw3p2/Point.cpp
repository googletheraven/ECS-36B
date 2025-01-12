#include "Point.h"

Point Point::operator+(const Point& rhs) const {

    Point newPoint(this->x + rhs.x, this->y + rhs.y);
    return newPoint;
}


Point Point::operator-(const Point& rhs) const {

    Point newPoint(this->x - rhs.x, this->y - rhs.y);
    return newPoint;
}


std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p.x << ',' << p.y << ')';  
    return os;
}


std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x;
    is >> p.y;
    return is;
}