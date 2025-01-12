#include "Fraction.h"

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num) : numerator(num), denominator(1) {}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
   if (denom == 0) {
       throw std::invalid_argument("zero denominator");
   }
   reduce();
}

int Fraction::getNum() const {
   return numerator;
}

int Fraction::getDen() const {
   return denominator;
}

int Fraction::gcd(int a, int b) {
   return b == 0 ? a : gcd(b, a % b);
}

void Fraction::reduce() {
   int divisor = gcd(numerator, denominator);
   numerator /= divisor;
   denominator /= divisor;
   if (denominator < 0){
        denominator = denominator * -1;
        numerator = numerator * -1;
   }
}

Fraction Fraction::operator+(const Fraction& other) const {
   int num = numerator * other.denominator + other.numerator * denominator;
   int denom = denominator * other.denominator;
   return Fraction(num, denom);
}

Fraction Fraction::operator-(const Fraction& other) const {
   int num = numerator * other.denominator - other.numerator * denominator;
   int denom = denominator * other.denominator;
   return Fraction(num, denom);
}

Fraction Fraction::operator*(const Fraction& other) const {
   int num = numerator * other.numerator;
   int denom = denominator * other.denominator;
   return Fraction(num, denom);
}

Fraction Fraction::operator/(const Fraction& other) const {
   if (other.numerator == 0) {
       throw std::invalid_argument("zero denominator");
   }
   int num = numerator * other.denominator;
   int denom = denominator * other.numerator;
   return Fraction(num, denom);
}

Fraction Fraction::operator-() const {
   return Fraction(-numerator, denominator);
}

bool Fraction::operator==(const Fraction& other) const {
   return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
   return !(*this == other);
}

Fraction operator+(int num, const Fraction& f) {
   return Fraction(num) + f;
}

Fraction operator-(int num, const Fraction& f) {
   return Fraction(num) - f;
}

Fraction operator*(int num, const Fraction& f) {
   return Fraction(num) * f;
}

Fraction operator/(int num, const Fraction& f) {
   return Fraction(num) / f;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
   os << f.getNum() << "/" << f.getDen();
   return os;
}