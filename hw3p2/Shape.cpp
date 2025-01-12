#include <iostream>
#include <algorithm> // min(), max()

#include "Shape.h"


bool Rectangle::overlaps(const Shape& s) const {
    return s.overlaps(*this);
}


bool Rectangle::overlaps(const Rectangle& r) const{
    bool rectanglesOverlap = false;
    bool x_less = this->position.x <= r.position.x;
    bool y_less = this->position.y <= r.position.y;

    if (x_less && y_less) {
        bool invalid_y_spacing = this->position.y + this->height > r.position.y;
        bool invalid_x_spacing = this->position.x + this->width > r.position.x;
        rectanglesOverlap = invalid_x_spacing && invalid_y_spacing; 
    }
    else if (x_less && !y_less) {
        bool invalid_y_spacing = r.position.y + r.height > this->position.y;
        bool invalid_x_spacing = this->position.x + this->width > r.position.x;
        rectanglesOverlap = invalid_x_spacing && invalid_y_spacing; 
    }
    else {
        rectanglesOverlap = r.overlaps(*this);
    }
    return rectanglesOverlap;
}


bool Rectangle::overlaps(const Circle& r) const{

int x_n, y_n;

x_n = std::min(std::max(r.center.x, this->position.x), this->position.x + this->width);
y_n = std::min(std::max(r.center.y, this->position.y), this->position.y + this->height);

int squared_l2_norm =  (x_n - r.center.x) * (x_n - r.center.x) + (y_n - r.center.y) * (y_n - r.center.y);

return squared_l2_norm < (r.radius * r.radius);
}


bool Rectangle::fits_in(const Rectangle& r) const {

    int leftBoundary, lowerBoundary, rightBoundary, upperBoundary;  
    bool crossesLeft, crossesLower, crossesRight, crossesUpper, fits; 
    
    leftBoundary = r.position.x;
    lowerBoundary = r.position.y;
    rightBoundary = r.position.x + r.width;
    upperBoundary = r.position.y + r.height;

    crossesLeft = this->position.x < leftBoundary;
    crossesLower = this->position.y < lowerBoundary;
    crossesRight = this->position.x + this->width > rightBoundary; 
    crossesUpper =  this->position.y + this->height > upperBoundary;

    fits = !(crossesLeft || crossesLower || crossesRight || crossesUpper);
    
    return fits;
}


void Rectangle::draw(void) const {
    const std::string output = "<rect x=\""
                + std::to_string(position.x) + "\" y=\""
                + std::to_string(position.y) + "\" width=\""
                + std::to_string(width) + "\" height=\""
                + std::to_string(height) + "\"/>";
    std::cout << output << std::endl;
}

Rectangle::~Rectangle(void) {
    
}


bool Circle::overlaps(const Shape& s) const {
    return s.overlaps(*this);
}


bool Circle::overlaps(const Circle& r) const {
    
    int squared_l2_norm =  (this->center.x - r.center.x) * (this->center.x - r.center.x)
     + (this->center.y - r.center.y) * (this->center.y - r.center.y);
 
    return squared_l2_norm < (r.radius * r.radius);
}


bool Circle::overlaps(const Rectangle& r) const {
    return r.overlaps(*this);
}


bool Circle::fits_in(const Rectangle& r) const {

    bool a = this->center.x - radius >= r.position.x;
    bool b = this->center.y - radius >= r.position.y;
    bool c = this->center.x + radius <= r.position.x + r.width;
    bool d = this->center.y + radius <= r.position.y + r.height;

    bool fits = a && b && c && d;
    return fits;
}


void Circle::draw(void) const {
    const std::string output = "<circle cx=\""
                          + std::to_string(center.x) + "\" cy=\""
                          + std::to_string(center.y) + "\" r=\""
                          + std::to_string(radius) + "\"/>";
    std::cout << output << std::endl;
}

Circle::~Circle(void) {
    
}