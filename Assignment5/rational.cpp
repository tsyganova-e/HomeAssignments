/*
 * Elena Tsyganova
 * st142266@student.spbu.ru
 * Assignment3
 */

#include "rational.h"
#include "gcd.h"

#include <stdexcept>
#include <iostream>

void Rational::normalize()
{
    if (den == 0)
    {
        std::cout << "Denominator cannot be equal to 0. The fraction is replaced with 0/1";
        num = 0;
        den = 1;
    }
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
    long g = gcd(num, den);
    if (g != 0)
    {
        num /= g;
        den /= g;
    }
}

Rational::Rational(long n, long d) : num(n), den(d)
{
    normalize();
}

Rational Rational::operator+(const Rational& other) const
{
    return Rational(num * other.den + other.num * den, den * other.den);
}

Rational Rational::operator-(const Rational& other) const
{
    return Rational(num * other.den - other.num * den, den * other.den);
}

Rational Rational::operator*(const Rational& other) const
{
    return Rational(num * other.num, den * other.den);
}

Rational Rational::operator/(const Rational& other) const
{
    if (other.num == 0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return Rational(num * other.den, den * other.num);
}


std::ostream& operator<<(std::ostream& os, const Rational& r)
{
    if (r.den == 1)
        os << r.num;
    else
        os << r.num << '/' << r.den;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r)
{
    long n, d = 1;
    is >> n;
    if (is.peek() == '/')
    {
        is.ignore();
        is >> d;
    }
    r = Rational(n, d);
    return is;
}
