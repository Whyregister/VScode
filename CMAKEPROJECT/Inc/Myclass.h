#ifndef MYCLASS_H
#define MYCLASS_H
#include <iostream>

using std::endl;
using std::cout;

 class Myclass 
{
public:
    Myclass (int ,int );
    friend void copy(Myclass &,const Myclass &);
    void print( );
private:
    int x,y;
};

void copy(Myclass & dest,const Myclass & ori)
{
    dest.x = ori.x;
    dest.y = ori.y;
}

Myclass::Myclass(int a,int b)
{
    this->x = a;
    this->y = b;
}

void Myclass::print()
{
    cout << "x = " << this->x << endl;
    cout << "y = " << this->y << endl;
}
 

#endif