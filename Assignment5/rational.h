/*
 * Elena Tsyganova
 * st142266@student.spbu.ru
 * Assignment3
 */
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
private:
    long num;
    long den;

    void normalize();

public:
    Rational(long n = 0, long d = 1);

    long numerator() const
    {
        return num;
    }
    long denominator() const
    {
        return den;
    }

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
};

#endif // RATIONAL_H
