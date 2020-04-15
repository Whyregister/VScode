#include <iostream>
#include <cmath>
using namespace std;

int SqurtSum(int m)
{
    int sum = 0;
    for(int i = 1 ; i <= m ; m++)
    sum += pow(i,2);

    return sum;
}

int OddSum(int m)
{
    int sum = 0;
    for ( int i = 1 ;i < m ;i+=2)
    sum += i;
    sum += m;
    return m;
}

double ReciSum(int m)
{
    double Numerator = 1,Denominator = m;
    for ( int i = m - 1 ; i >=1 ; i--)
    {
        Numerator = Denominator + Numerator * i;
        Denominator = Denominator * i;
    }

    return Numerator/Denominator;
}

int main ()
{
    cout << ReciSum(5) << endl;
    return 0;
}