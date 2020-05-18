#ifndef MYCLASS_H
#define MYCLASS_H
#include <iostream>
using std::endl;
using std::cout;

 class Myclass 
{
public:
    Myclass (int = 0,int = 0);
    void copy(const Myclass & );
    friend void copyFriend(Myclass &,const Myclass &);
    void print( );
private:
    int x,y;
};

void Myclass::copy(const Myclass & t)
{
    this->x = t.x;
    this->y = t.y;
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
 

void copyFriend(Myclass & dest,const Myclass & ori)
{
    dest.x = ori.x;
    dest.y = ori.y;
}
#endif

int main()
{
    Myclass m1;
    Myclass m2(2,3),m3(3,4);
    m1.copy(m2);
    m1.print();
    
    copyFriend(m1,m3);
    m3.print();
    return 0;
}

