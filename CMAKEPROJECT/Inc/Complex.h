#ifndef COMPLEX_H
#define COMPLEX_H
using std::ostream;
using std::istream;
class Complex
{
    public:
        Complex(double real = 0, double ima = 0);
        friend ostream & operator << (ostream & out ,const Complex & com);
        friend istream & operator >> (istream & in , Complex & com);
        const Complex operator + (const Complex & com);
        const Complex operator / (const Complex & com);
        const Complex operator * (const Complex & com);
        const Complex operator - (const Complex & com);
        Complex & operator = (const Complex & com);
        double Getreal();
        double Getima();
    private:
        double real;
        double ima;

};

#endif