#ifndef DET_H
#define DET_H
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename T>
class Det
{
    public:
        Det():N(0)
        {

        }

        ~Det()
        {

        }
        int InvertNums(int n);

        void Swap(int des , int obj);
        void GetFullPermu(int des , int obj);
        T Cacul();

        template <typename T2>
        friend istream & operator >> (istream & in ,Det<T2> & D);
        template <typename T3>
        friend ostream & operator << (ostream & out,Det<T3> & D);
        
        const int Factor(int n);

    private:
        T det[10][10];
        T  D;
        int org[10];
        short int  Full_Permutation[100][10];
        int order;
        int N;

};

template <typename T>
istream & operator >> (istream & in, Det<T> & D)
{
    cout << "行列式阶数：" ;
    in >> D.order;
    
    for ( int i = 0 ; i < D.order ; i++ )   D.org[i] = i;
    /**生成随机数列*/
    D.GetFullPermu(0,D.order);

    cout << "输入行列式：" << endl;
    for ( int i = 0; i < D.order ; i++)
    for ( int j = 0; j < D.order ; j++)
    {
        in >> D.det[i][j];
    }

    return in;
}

template <typename T>
ostream & operator << (ostream & out , Det<T> & D)
{
    
    for ( int i = 0 ;i < D.order ; i++)
    {
        out << left << setw(4) << '|';
        for ( int j = 0 ; j < D.order ; j++)
        {
            out <<  setw(4) << D.det[i][j] ; 
        }
        out << left << setw(4) << '|';
        if(i == D.order-1)
        out << setw(4) << '=' << D.Cacul() << endl;
        else
        {
            out << endl;
        }
        
    }
    return out;
    
}


template <typename T>
const int Det<T>::Factor(int n)
{
    int f = 1;
    while(n)
    {
        f *=  n--;
    }
    return f;
}

template <typename T>
void Det<T>::GetFullPermu(int beg , int end)
{
    if ( beg == end)
    {
        for( int i = 0 ; i < order ; i++)  Full_Permutation[N][i] = org[i];
        N++;
    }
    else
    {
        for ( int i = beg ; i < end; i++)
        {
            Swap(beg , i);
            GetFullPermu(beg+1,end);
            Swap(beg , i);
        }
    }
}

template <typename T>
void Det<T>::Swap(int des ,int obj)
{
    int temp;
    temp = org[des];
    org[des] = org[obj];
    org[obj] = temp;
}

template <typename T>
int Det<T>::InvertNums(int n)
{
    int tem = 0;
    for(int i = 0 ; i < order-1; i++)
    {
        for(int j = i; j < order-1; j++)
        {
            if(Full_Permutation[n][i] > Full_Permutation[n][j+1])
            tem++;
        }
    }
    return tem;
}

template <typename T>
T Det<T>::Cacul()
{
    T sum = 0;
    T m=1;
    int times = Factor(order);
    for(int i = 0 ; i < times ;i++)
    {
        for ( int j = 0 ; j < order ; j++)
        {
            m *= det[j][Full_Permutation[i][j]];
        }
        sum += (pow(-1,InvertNums(i))*m);
        m = 1;
    }
    return sum;

}

#endif 