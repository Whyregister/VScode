#include "Student.h"

Student::Student()
{
    SetDes("����˺���ʲô��û����");
    SetName("Ĭ�ϵ���");
    cout << "Ĭ�Ϲ���" << endl;
}

Student::Student(string name) : m_name(name)
{
    SetDes("����˺���ʲô��û����");
    cout << "����������" << endl;
}

Student::Student(string name,string des) : m_name(name),m_des(des)
{
    cout << "��Ϣ�ѱ���" << endl;
}
Student::~Student()

{
    cout << m_name << "���ͷ���" << endl;
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