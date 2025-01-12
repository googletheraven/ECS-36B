//prevent include class rational more than once

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction {
private:
   int numerator;
   int denominator;
   
   int gcd(int a, int b);
   void reduce();
   
public:
   Fraction();
   Fraction(int num);
   Fraction(int num, int denom);
   
   int getNum() const;
   int getDen() const;
   
   Fraction operator+(const Fraction& other) const;
   Fraction operator-(const Fraction& other) const;
   Fraction operator*(const Fraction& other) const;
   Fraction operator/(const Fraction& other) const;
   Fraction operator-() const;
   
   bool operator==(const Fraction& other) const;
   bool operator!=(const Fraction& other) const;
   
   friend Fraction operator+(int num, const Fraction& f);
   friend Fraction operator-(int num, const Fraction& f);
   friend Fraction operator*(int num, const Fraction& f);
   friend Fraction operator/(int num, const Fraction& f);
   
   friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};

#endif