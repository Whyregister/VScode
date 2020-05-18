#include <iostream>
#include <conio.h>
using namespace std;

class A
{
    public:
    void show()
    {
        cout << "A" << endl;
    }
    private:
            int a;
};

class B:public A
{
    public:
    void show()
    {
        cout << "B" << endl;
    }
    private:
        int b;
};

void Test1(A a)
{
    a.show();
}



int main()
{
    B b;
    Test1(b);
    
    getch();
    return 0;
}