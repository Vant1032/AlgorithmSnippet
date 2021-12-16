#ifndef _FRACTION_H
#define _FRACTION_H
#include <stdio.h>
#include <iostream>
using namespace std;
class Fraction {
  public:
    Fraction(const int &numerator, const int &denominator);
    Fraction(const Fraction &n);
    Fraction(const Fraction &&n);
    const Fraction & operator=(const Fraction &n);
    ~Fraction();
    void setNumerator(const int &a);
    void setDenominator(const int &b);
    void set(const int &a, const int &b);
    void add(const Fraction &n);
    void subtract(const Fraction &n);
    void divide(const Fraction &n);//TODO
    void muiltiply(const Fraction &n);
    double toDouble();
    friend ostream & operator<<(ostream &os, const Fraction & f);
    Fraction &operator++();
    Fraction operator++(int);
  private:
    long long numerator, denominator;
    void reduction();
    long long gcd(long long a, long long b);
};

Fraction::Fraction(const int &numerator, const int &denominator) {
  this->numerator = numerator;
  this->denominator = denominator;
  reduction();
}

inline Fraction::Fraction(const Fraction & n) {
  numerator = n.numerator;
  denominator = n.denominator;
}

inline Fraction::Fraction(const Fraction && n) {
  numerator = n.numerator;
  denominator = n.numerator;
}

inline const Fraction & Fraction::operator=(const Fraction &n) {
  numerator = n.numerator;
  denominator = n.denominator;
  return *this;
}


Fraction::~Fraction() {
}

inline void Fraction::setNumerator(const int & a) {
  numerator = a;
  reduction();
}

inline void Fraction::setDenominator(const int & b) {
  denominator = b;
  reduction();
}

inline void Fraction::set(const int & a, const int & b) {
  numerator = a;
  denominator = b;
  reduction();
}

inline void Fraction::add(const Fraction &n) {
  numerator = numerator * n.denominator + denominator * n.numerator;
  denominator = denominator * numerator;
  reduction();
}

inline void Fraction::subtract(const Fraction & n) {
  numerator = numerator * n.denominator - denominator * n.numerator;
  denominator = denominator * numerator;
  reduction();
}

inline void Fraction::divide(const Fraction & n) {
  numerator *= n.denominator;
  denominator *= n.numerator;
  reduction();
}

inline void Fraction::muiltiply(const Fraction & n) {
  numerator *= n.numerator;
  denominator *= n.denominator;
  reduction();
}

inline double Fraction::toDouble() {
  return double(numerator) / denominator;
}

inline void Fraction::reduction() {
  long long t = gcd(numerator, denominator);
  numerator /= t;
  denominator /= t;
  if (numerator < 0) {
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  } else {
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }
}

inline long long Fraction::gcd(long long a, long long b) {
  long long t;
  while ((t = a % b) != 0) {
    a = b;
    b = t;
  }
  return b;
}
ostream & operator<<(ostream &os, const Fraction & f) {
  os << f.numerator << "/" << f.denominator << endl;
  return os;
}
Fraction &Fraction::operator++(){
  numerator += denominator;
  reduction();
  return *this;
}
Fraction Fraction::operator++(int){
  Fraction tmp(*this);
  ++tmp;
  return tmp;
}
#endif
