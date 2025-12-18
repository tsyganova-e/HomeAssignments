/*
 * Elena Tsyganova
 * st142266@student.spbu.ru
 * Assignment3
 */

#include "gcd.h"

long gcd(long a, long b)
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b != 0)
    {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
