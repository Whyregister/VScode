#include "Student.h"

Student::Student()
{
    SetDes("这个人很懒什么都没留下");
    SetName("默认地主");
    cout << "默认构造" << endl;
}

Student::Student(string name) : m_name(name)
{
    SetDes("这个人很懒什么都没留下");
    cout << "设置了名字" << endl;
}

Student::Student(string name,string des) : m_name(name),m_des(des)
{
    cout << "信息已保存" << endl;
}
Student::~Student()

{
    cout << m_name << "被释放了" << endl;
}


void Student::SetName(string name)
{
    m_name = name;
}

string Student::ShowName()
{
    return m_name;
}

void Student::SetDes(string des)
{
    m_des = des;
}

string Student::ShowDes()
{
    return m_des;
}

void Student::ShowInfor()
{
    cout << m_des <<"*" << m_name << endl;
}