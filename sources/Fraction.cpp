#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits.h> // for overflow test
#include <limits>
#include <cctype>
#include <cstring>
#include "Fraction.hpp"
using namespace std;
using namespace ariel;

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int _numerator,
                   int _denominator) : numerator(_numerator), denominator(_denominator)
{
    if (_denominator == 0)
    {
         __throw_invalid_argument("denominator is 0");
    }
    if (typeid(_numerator).name() != typeid(int).name() || typeid(_denominator).name() != typeid(int).name())
    {
        __throw_bad_typeid();
    }

    if (_numerator < 0 && _denominator < 0 || _denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
   
}

Fraction::Fraction(float flt)
{
    // convert from float to fraction
    int power = 1;
    // float cpy = flt;

    while (flt != (int)flt && power < 1000)
    {   // as long as the decimal value isn't 0
        // the limitation on power is because we want to have up to 3 digits beyond the desimal point
        //&& number != (int)number
        power *= 10;
        flt *= 10;
    }
    this->numerator = flt;
    this->denominator = power;


}

Fraction Fraction::reduced(int numerator, int denominator) const 
{
    int gcd = my_gcd(abs(numerator), abs(denominator));
    return Fraction(numerator /= gcd, denominator / gcd);
    // numerator /= gcd;
    // numerator /= gcd;
}

int Fraction::lcm(int denom1, int denom2) const
{
    int _lcm = (denom1 / __gcd(denom1, denom2)) * denom2;
    return _lcm;
}

// ADD
const Fraction Fraction::operator+(const Fraction &other) const
{
    //if (this. > 0 && *this > INT_MAX -1- other) {
     //   __throw_overflow_error("overflow error");
   // }
        int new_numr = (this->numerator * other.denominator) + (other.numerator * this->denominator);
        int new_denom = this->denominator * other.denominator;
        return reduced(new_numr, new_denom);
        // return Fraction(new_numr,new_denom);
   // }
   
}

const Fraction Fraction::operator+(const float &_float) const
{
    // use in the above + function
    // this is a pointer, *this is the value i.e the fraction
    return *this + Fraction(_float);

    // return Fraction(1,1);
}

const Fraction operator+(const float &float_, const Fraction &frac)
{
    return Fraction(float_) + frac;
}

// SUBSTRACT
const Fraction Fraction::operator-(const Fraction &other) const
{
    int new_numr = (this->numerator * other.denominator) - (other.numerator * this->denominator);
    int new_denom = this->denominator * other.denominator;
    return reduced(new_numr, new_denom);
    // return Fraction(new_numr,new_denom);
}
const Fraction Fraction::operator-(const float &_float) const
{
    return *this - Fraction(_float);
}

const Fraction operator-(const float &float_, const Fraction &frac)
{
    return Fraction(float_) - frac;
}

// MULTIPLY
const Fraction Fraction::operator*(const Fraction &other) const
{
    int new_numr = this->numerator * other.numerator;
    int new_denom = this->denominator * other.denominator;
    return reduced(new_numr, new_denom);
    //  return Fraction(new_numr,new_denom);
}

const Fraction Fraction::operator*(const float &_float) const
{
    return (*this) * Fraction(_float);
}

const Fraction operator*(const float &float_, const Fraction &frac)
{
    return Fraction(float_) * frac;
}

// DIVIDE
const Fraction Fraction::operator/(const Fraction &other) const
{   
    if (other.numerator == 0 )
    {
         __throw_runtime_error("can't divide by 0");
    }
    int new_numr = (this->numerator * other.denominator);
    int new_denom = other.numerator * this->denominator;
    if((new_numr/new_denom)>std::numeric_limits<int>::max()){
        throw std::overflow_error("answer is too big");
    }
    if((new_numr/new_denom)<std::numeric_limits<int>::min()){
        throw std::overflow_error("answer is too small");
    }
    return reduced(new_numr, new_denom);
    // return Fraction(new_numr,new_denom);
}
const Fraction Fraction::operator/(const float &_float) const
{
    if (_float == 0)
        __throw_runtime_error("can't divide by 0");
    return *this / Fraction(_float);
}
const Fraction operator/(const float &float_, const Fraction &frac)
{
    if (frac.numerator == 0)
    {
         __throw_runtime_error("can't divide by 0");
    }
    return Fraction(float_) / frac;
}

// EQUALITY COMPARISON
bool Fraction::operator==(const Fraction &other) const
{
    // reduce both fractions , and then compare
    Fraction frac1 = reduced(this->numerator, this->denominator);
    Fraction frac2 = reduced(other.getNumerator(), other.getDenominator());
    return frac1.numerator == frac2.numerator && frac1.denominator == frac2.denominator;
}

bool Fraction::operator==(const float &float_) const
{
    Fraction float_frac = Fraction(float_);
    return *this == float_frac;
}

bool operator==(const float &float_, const Fraction &frac)
{
    Fraction float_frac = Fraction(float_);
    return frac == float_frac;
}

// BIGGER COMPARISON
bool Fraction::operator>(const Fraction &other) const
{
    int _lcm = lcm(this->denominator, other.getDenominator());
    Fraction frac1 = Fraction(this->numerator * (_lcm / this->denominator), _lcm);
    Fraction frac2 = Fraction(other.getNumerator() * (_lcm / other.getDenominator()), _lcm);
    return frac1.numerator > frac2.numerator;
}
bool Fraction::operator>(const float &float_) const
{
    Fraction float_frac = Fraction(float_);
    return *this > float_frac;
}
bool operator>(const float &float_, const Fraction &frac)
{
    Fraction float_frac = Fraction(float_);
    return float_frac > frac;
}

// SMALLER COMPARISON
bool Fraction::operator<(const Fraction &other) const
{
    int _lcm = lcm(this->denominator, other.getDenominator());
    Fraction frac1 = Fraction(this->numerator * (_lcm / this->denominator), _lcm);
    Fraction frac2 = Fraction(other.getNumerator() * (_lcm / other.getDenominator()), _lcm);
    return frac1.numerator < frac2.numerator;
}
bool Fraction::operator<(const float &float_) const
{
    Fraction float_frac = Fraction(float_);
    return *this < float_frac;
}
bool operator<(const float &float_, const Fraction &frac)
{
    Fraction float_frac = Fraction(float_);
    return float_frac < frac;
}

// BIGGER-EQUAL COMPARISON

bool Fraction::operator>=(const Fraction &other) const
{
    int _lcm = lcm(this->denominator, other.getDenominator());
    Fraction frac1 = Fraction(this->numerator * (_lcm / this->denominator), _lcm);
    Fraction frac2 = Fraction(other.getNumerator() * (_lcm / other.getDenominator()), _lcm);
    return frac1.numerator >= frac2.numerator;
}
bool Fraction::operator>=(const float &float_) const
{
    Fraction float_frac = Fraction(float_);
    return *this >= float_frac;
}
bool operator>=(const float &float_, const Fraction &frac)
{
    Fraction float_frac = Fraction(float_);
    return float_frac >= frac;
}

// SMALLER-EQUAL COMPARISON
bool Fraction::operator<=(const Fraction &other) const
{
    int _lcm = lcm(this->denominator, other.getDenominator());
    Fraction frac1 = Fraction(this->numerator * (_lcm / this->denominator), _lcm);
    Fraction frac2 = Fraction(other.getNumerator() * (_lcm / other.getDenominator()), _lcm);
    return frac1.numerator <= frac2.numerator;
}
bool Fraction::operator<=(const float &float_) const
{
    Fraction float_frac = Fraction(float_);
    return *this <= float_frac;
}
bool operator<=(const float &float_, const Fraction &frac)
{
    Fraction float_frac = Fraction(float_);
    return float_frac <= frac;
}

// prefix
Fraction& Fraction::operator++() {
    numerator+=denominator;
    reduced();
    return *this;
}

//postfix
Fraction Fraction::operator++(int dummy_flag_for_postfix_increment) {
    Fraction copy = *this;
    ++(*this);
    return copy;
}

// print a fraction to an output stream
std::ostream &operator<<(std::ostream &output, const Fraction &frac)
{
    output << frac.numerator << '/' << frac.denominator;
    return output;
}

istream &operator>>(istream &input, Fraction &fraction)
{
    int numerator, denominator;
    //char ;
    
    input >> numerator >> denominator;

    if(denominator==0){
       throw std::runtime_error("invalid input") ; 
    }

    fraction = Fraction(numerator, denominator);

    return input;
}