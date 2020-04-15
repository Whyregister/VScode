#include "Student.h"

Student::Student()
{
    SetDes("这个人很懒什么都没留下");
    SetName("默认地主");
    cout << "默认构造" << endl;
    InitInfor();
}

Student::Student(string name) : m_name(name)
{
    SetDes("这个人很懒什么都没留下");
    cout << "设置了名字" << endl;
    InitInfor();
}

Student::Student(string name,string des) : m_name(name),m_des(des)
{
    cout << "信息已保存" << endl;
    InitInfor();
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

void Student::AddScore(float newscore)
{
    m_Scores[m_ScoreCount] = newscore;
    m_ScoreCount++;
    float * newScores = new float[m_ScoreCount+1];
    memcpy(newScores,m_Scores,sizeof(float)*(m_ScoreCount));
    delete m_Scores;
    m_Scores = newScores;
}

float Student::GetScoreTal()
{
    float sum = 0;
    for(int i = 0 ; i < m_ScoreCount ;i++)
    sum += m_Scores[i];
    return sum;
}

Student Student::scholar(Student & stu)
{
    if(GetScoreTal() < stu.GetScoreTal())
    return stu;

    return *this;
}

void Student::InitInfor()
{
    m_Scores = new float[1];
    m_ScoreCount = 0;
    

}