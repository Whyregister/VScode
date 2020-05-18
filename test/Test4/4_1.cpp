#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex(double sb = 0, double xb = 0);
        void print();
        const Complex operator + (const Complex & com);
        const Complex operator / (const Complex & com);
        const Complex operator * (const Complex & com);
        const Complex operator - (const Complex & com);
        Complex & operator = (const Complex & com);
    private:
        double sb;
        double xb;
};

Complex::Complex(double a, double b)
{
    sb = a;
    xb = b;
}

void Complex::print()
{
    cout << noshowpos << sb << showpos << xb << 'i' << std::endl;
}

const Complex Complex::operator+(const Complex & com)
{
    double a,b;
    a = this->sb + com.sb;
    b = this->xb + com.xb;
    Complex result(a,b);
    return result;
}

const Complex Complex::operator/(const Complex & com)
{
    double a,b;
    a = (sb*com.sb+this->xb*com.xb)/(com.sb*com.sb+com.xb*com.xb);
    b = (xb*com.sb-this->sb*com.xb)/(com.sb*com.sb+com.xb*com.xb);
    return Complex(a,b);
}

const Complex Complex::operator*(const Complex & com)
{
    double a,b;
    a = (sb*com.sb-xb*com.xb);
    b = (sb*com.xb+xb*com.sb);
    return Complex(a,b);
}

const Complex Complex::operator-(const Complex & com)
{
    double a,b;
    a = this->sb - com.sb;
    b = this->xb - com.xb;
    return Complex(a,b);
}


Complex & Complex::operator = (const Complex & com)
{
    this->sb = com.sb;
    this->xb = com.xb;
    return *this;
}

int main()
{
    Complex com1(1,2);
    Complex com2(3,4);
    Complex com3 = com1 + com2;
    Complex com4 = com1 - com2;
    com3.print();
    com4.print();
    return 0;
}
