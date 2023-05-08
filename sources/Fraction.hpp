
#ifndef FRACTION_HPP
#define FRACTION_HPP
#define INT_ADD_OVERFLOW_P(this,other)

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{

};

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // outline constructors
    Fraction();
    Fraction(int _numerator, int _denominator);
    Fraction(float flt);

    int getNumerator() const
    {
        return this->numerator;
    }

    int getDenominator() const
    {
        return this->denominator;
    }

    void setNuminator(int _numerator)
    {
        this->numerator = _numerator;
    }

    void setDenom(int _denominator)
    {
        this->denominator = _denominator;
    }

    void reduced();

    /*
    returns the greatest common divisor of the fractions
    int gcd(int num,int denom);
    */
    Fraction reduced(int numerator, int denominator) const;

    /*
    returns the least common multiplier
    */

    int my_gcd(int _numerator, int _denominator) const;

    int lcm(int denom1, int denom2) const;

    /*
    FRIEND FUNCTION - usually , functions that their first argument is not
    from the type of the class.
    functions like operator+ that takes as arguments 2 fractions shouldn't be a friend function.
    in contrast, functions of assignment, such as += have to be friend functions,
    since they return a reference, because the value of the object has changed.
    */

    // add
    const Fraction operator+(const Fraction &other) const;
    const Fraction operator+(const float &num) const;
    friend const Fraction operator+(const float &flo1, const Fraction &frac2);

    // substract
    const Fraction operator-(const Fraction &other) const;
    const Fraction operator-(const float &_float) const;
    friend const Fraction operator-(const float &flo1, const Fraction &frac2);

    // multiply
    const Fraction operator*(const Fraction &other) const;
    const Fraction operator*(const float &_float) const;
    friend const Fraction operator*(const float &flo1, const Fraction &frac2);

    // divide
    const Fraction operator/(const Fraction &other) const;
    const Fraction operator/(const float &_float) const;
    friend const Fraction operator/(const float &flo1, const Fraction &frac2);

    // comparison equality
    bool operator==(const Fraction &other) const;
    bool operator==(const float &_float) const;
    friend bool operator==(const float &float_, const Fraction &frac);

    // comparison operations (>,<,>=,<=)
    bool operator>(const Fraction &other) const;
    bool operator>(const float &float_) const;
    friend bool operator>(const float &float_, const Fraction &frac);

    bool operator<(const Fraction &other) const;
    bool operator<(const float &float_) const;
    friend bool operator<(const float &float_, const Fraction &frac);

    bool operator>=(const Fraction &other) const;
    bool operator>=(const float &float_) const;
    friend bool operator>=(const float &float_, const Fraction &frac);

    bool operator<=(const Fraction &other) const;
    bool operator<=(const float &float_) const;
    friend bool operator<=(const float &float_, const Fraction &frac);

    // prefix increment: returns the fraction after increment
    Fraction &operator++();

    // postfix increment: returns copy of the fraction - its value before increment
    Fraction operator++(int dummy_flag_for_postfix_increment);

    // prefix decrease
    Fraction &operator--()
    {
        numerator -= denominator;
        reduced();
        return *this;
    }

    // postfix decrease
    Fraction operator--(int dummy_flag_for_postfix_increment)
    {
        Fraction copy = *this;
        --(*this);
        return copy;
    }

    //----------------------------------
    // friend global IO operators
    //----------------------------------

    /*
     The << operator to print a fraction to an output stream
    in the format “numerator/denominator”.
    */
    friend std::ostream &operator<<(std::ostream &output, const Fraction &frac);

    /*
    The >> operator to read a fraction from an input stream
    by taking two integers as input.
    */

    friend std::istream &operator>>(std::istream &input, Fraction &fraction);

}; // end of class Fraction

//}; // end-namespace-ariel

#endif
