#include <iostream>
#include "Complex.h"
using std::showpos;
using std::noshowpos;
Complex::Complex(double a, double b)
{
    real = a;
    ima = b;
}

ostream & operator<<(ostream & out ,const Complex & com)
{
    
    out << noshowpos << com.real << showpos << com.ima << 'i' << std::endl;
    return out;
}

istream & operator>>(istream & inp ,Complex & com)
{
    inp >> com.real;
    inp >> com.ima;
    return inp;
}

const Complex Complex::operator+(const Complex & com)
{
    double a,b;
    a = this->real + com.real;
    b = this->ima + com.ima;
    Complex result(a,b);
    return result;
}

const Complex Complex::operator/(const Complex & com)
{
    double a,b;
    a = (real*com.real+this->ima*com.ima)/(com.real*com.real+com.ima*com.ima);
    b = (ima*com.real-this->real*com.ima)/(com.real*com.real+com.ima*com.ima);
    return Complex(a,b);
}

const Complex Complex::operator*(const Complex & com)
{
    double a,b;
    a = (real*com.real-ima*com.ima);
    b = (real*com.ima+ima*com.real);
    return Complex(a,b);
}

const Complex Complex::operator-(const Complex & com)
{
    double a,b;
    a = this->real - com.real;
    b = this->ima - com.ima;
    return Complex(a,b);
}


Complex & Complex::operator = (const Complex & com)
{
    this->real = com.real;
    this->ima = com.ima;
    return *this;
}