/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;

int main()
{
    Fraction a(5, 3), b(14, 21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a + b << endl;
    cout << "a-b" << a - b << endl;
    cout << "a/b" << a / b << endl;
    cout << "a*b" << a * b << endl;
    cout << "2.3*b" << 2.3 * b << endl;
    cout << "a+2.421" << a + 2.421 << endl;
    Fraction c = a + b - 1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1)
        cout << " a is bigger than 1.1" << endl;
    else
        cout << " a is smaller than 1.1" << endl;

    // char ch2 = ' ';
    // if (isspace(ch2))
    //     cout << "ch2 is a space" << endl;
    // istringstream is("6 8 3 0"); 
    // int numerator, denominator;
    // char wspace;

    // is >> numerator>>denominator ;
    // cout<<numerator<<endl;
    // //cout<<wspace<<endl;
    // cout<<"hello"<<denominator<<"bye"<<endl;
    // if(wspace== '\f')
    //     cout << "ch2 is a space" << endl;

    std::stringstream ss_zero_denominator("6 8 3 0");
   // ss_zero_denominator.str("6 8 3 0");
    // Fraction frac2, frac3,frac4;
    // ss_zero_denominator >> frac2>>frac3 ;
    // cout<<frac2<<frac3;
    // cout<<frac3<<endl;
    
}
