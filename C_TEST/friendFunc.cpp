/**
 * Watcher监视器类
 * 可以利用其中窥探其它类数据
 */
#include <iostream>
#include <conio.h>
using namespace std;
class Pos;
class Student;
class Watcher;

class Student
{    
private:
    string m_name;
    int m_number;
    friend Watcher;
public:
    Student(string name = "无",int number = 0) { m_name = name,m_number = number;}    
};

class Pos
{
private:
    int m_x;
    int m_y;
    friend Watcher;
public:
    Pos(int x = 0, int y = 0) { m_x = x, m_y = y; }
};

class Watcher
{
public:
    void ShowInfor(const Student & stu) { cout << stu.m_name << endl << stu.m_number << endl;}
    void ShowInfor(const Pos & point) {cout << '(' << point.m_x << ',' << point.m_y <<')'<< endl;}
};

int main()
{
    Watcher w;
    Student stu;
    Pos p;

    w.ShowInfor(stu);
    w.ShowInfor(p);

    getch();
}

