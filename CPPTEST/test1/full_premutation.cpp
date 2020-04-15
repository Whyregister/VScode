#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;
int NN = 0;
int pum[50][50];

void Swap(int * Array , int des , int obj)
{
    int temp;
    temp = Array[des];
    Array[des] = Array[obj];
    Array[obj] = temp;
}

int nixushu(int n,int jieshu)
{
    int tem = 0;
    for(int i = 0 ; i < jieshu-1; i++)
    {
        for(int j = i; j < jieshu-1; j++)
        {
            if(pum[n][i] > pum[n][j+1])
            tem++;
        }
    }
    return tem;
}

int Jiechen(int n)
{
    int jiechen = 1;
    while(n)
    {
        jiechen *= n;
        n--;
    }
    return jiechen;
}

void output(int n)
{
    for (int j=0;j<Jiechen(n);j++)
    {

    for (int i = 0 ; i < n ; i++)
    {
        cout << pum[j][i];
    }
    cout << '\t' << nixushu(j,n)<< '\n';

    }
}

void input(int * Array , int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        pum[NN][i] = Array[i];
    }
}

void Premutation(int * Array , int beg , int end)
{
    if(beg == end )
    {
        input(Array, end+1);
        NN += 1;
    }
    else
    {
        for (int i = beg ; i <=end ; i++)
        {
            Swap(Array , beg , i);
            Premutation(Array , beg+1 ,end);
            Swap(Array , beg, i);
        }
    }
    

}


int main ()
{
    int n;
    cout << "几阶行列式：" ;
    cin >> n;
    const int N = n;
    int array[N];
    int hang[N][N];
    for ( int i =0 ; i < N ; i++)
    {
        array[i] = i;
    }

    Premutation(array , 0 , n-1);

    //output(n);

    cout << "输入行列式" ;
    for(int i = 0;i < N ;i ++)
    {
        for (int j = 0 ; j < N ;j++)
        {
            cin >> hang[i][j];
        }
        cout << endl;
    }
    int sum=0;
    int m=1;
    for (int i = 0 ;i < Jiechen(n) ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            m*=hang[j][pum[i][j]];
        }
        sum+=(pow(-1,nixushu(i,n))*m);
        m=1;
    }
    cout << "D = " <<sum;
    getch();
    return 0;
}