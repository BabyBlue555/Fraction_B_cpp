
#ifndef FRACTION_HPP
#define FRACTION_HPP
#define INT_ADD_OVERFLOW_P(this, other)

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
    /*
    * @brief default constructor
    */
    Fraction();

    /*
     * @brief constructor that takes two ints and builds a Fraction
     * @param _numerator The numerator of the fraction.
     * @param _denominator The denominator of the fraction.
     */
    Fraction(int _numerator, int _denominator);

    /*
     * @brief constructor that converts a float to Fraction
     * @param flt The float we want to convert
     */
    Fraction(float flt);

    /*
     * @brief getter of numerator 
     * @return the numerator of a Fraction
     */
    int getNumerator() const
    {
        return this->numerator;
    }

    /*
    * @brief getter of denominator
    * @return the denominator of a Fraction
    */
    int getDenominator() const
    {
        return this->denominator;
    }

    /*
    * @brief setter of numerator
    * @param the numerator of the Fraction
    */    
    void setNuminator(int _numerator)
    {
        this->numerator = _numerator;
    }

    /*
    * @brief setter of denominator
    * @param the denominator of the Fraction
    */    
    void setDenom(int _denominator)
    {
        this->denominator = _denominator;
    }


    void reduced();

    /*
    * @param numerator the numerator of the Fraction
    * @param denominator the denominator of the Fraction
    * @return the reduced form of the fraction of these params
    */
    Fraction reduced(int numerator, int denominator) const;

    /*
    * @param _numerator numerator of fraction
    * @param _denominator denominator of fraction
    * @return int the least common multiplier
    */
    int my_gcd(int _numerator, int _denominator) const;

    /*
    * @param denom1 denominator of first fraction 
    * @param denom2 denominator of second fraction 
    * @return int the least common multiplier of the denominators
    */
    int lcm(int denom1, int denom2) const;

    /*
    FRIEND FUNCTION - usually , functions that their first argument is not
    from the type of the class.
    functions like operator+ that takes as arguments 2 fractions shouldn't be a friend function.
    in contrast, functions of assignment, such as += have to be friend functions,
    since they return a reference, because the value of the object has changed.
    */

    // add

    /*
    * @brief adds two fractions 
    * @param other The fraction to add
    * @return const Fraction The result of the addition
    */
    const Fraction operator+(const Fraction& other) const;

    /*
    * @brief adds two fractions 
    * @param other The fraction to add
    * @return const Fraction The result of the addition
    */
    const Fraction operator+(const float& num) const;
    friend const Fraction operator+(const float& _float, const Fraction& frac);

    // substract
    const Fraction operator-(const Fraction& other) const;
    const Fraction operator-(const float& _float) const;
    friend const Fraction operator-(const float& _float, const Fraction& frac);

    // multiply
    const Fraction operator*(const Fraction& other) const;
    const Fraction operator*(const float& _float) const;
    friend const Fraction operator*(const float& _float, const Fraction& frac);

    // divide
    const Fraction operator/(const Fraction& other) const;
    const Fraction operator/(const float& _float) const;
    friend const Fraction operator/(const float& _float, const Fraction& frac);

    // comparison equality
    bool operator==(const Fraction& other) const;
    bool operator==(const float& _float) const;
    friend bool operator==(const float& _float, const Fraction& frac);

    // comparison operations (>,<,>=,<=)
    bool operator>(const Fraction& other) const;
    bool operator>(const float& float_) const;
    friend bool operator>(const float& float_, const Fraction& frac);

    bool operator<(const Fraction& other) const;
    bool operator<(const float& float_) const;
    friend bool operator<(const float& float_, const Fraction& frac);

    bool operator>=(const Fraction& other) const;
    bool operator>=(const float& float_) const;
    friend bool operator>=(const float& float_, const Fraction& frac);

    bool operator<=(const Fraction& other) const;
    bool operator<=(const float& float_) const;
    friend bool operator<=(const float& float_, const Fraction& frac);

    // prefix increment: returns the fraction after increment
    Fraction& operator++();

    // postfix increment: returns copy of the fraction - its value before increment
    Fraction operator++(int dummy_flag_for_postfix_increment);

    // prefix decrease
    Fraction& operator--()
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
