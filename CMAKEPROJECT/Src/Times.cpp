#include "Times.h"
using namespace std;

Times::Times(int hour,int minute,int second):m_hour(hour),m_minute(minute),m_second(second)
{
    cout << "Time has been set!" << endl;
}

Times::~Times()
{
    cout << "Time has been release!" << endl;
}

int Times::SetHour(int hour)
{
    if(hour >= 0 && hour < 24)
    return 1;
    else
    return 0;
}

int Times::SetMinute(int minute)
{
    if(minute >= 0 && minute <60)
    return 1;
    else
    return 0;
}

int Times::SetSecond(int second)
{
    if(second >= 0 && second < 60)
    return 1;
    else
    return 0;
}

void Times::SetTimes(int hour,int minute,int second)
{
    if(SetSecond(second)&&SetHour(hour)&&SetMinute(minute))
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
    }
    else
    {
        cout << "无效的时间。" <<endl;
    }
    
}

ostream & operator << (ostream & out ,const Times & Times)
{
    out <<setfill('0')<<setw(2)<< Times.m_hour;
    out <<':';
    out <<setfill('0')<<setw(2)<< Times.m_minute;
    out <<':';
    out <<setfill('0')<<setw(2)<< Times.m_second;
    return out;
}

Times & Times::operator + (int addsecond)
{
    if( m_second + addsecond < 60)
    {
        m_second += addsecond;
    }
    else
    {
        if(m_minute + 1 < 60)
        {
            addsecond = addsecond + m_second - 60;
            m_minute += 1;
            m_second = 0;
            *this + addsecond;
        }
        else
        {
            addsecond = addsecond + m_second - 60;
            m_minute = 0;
            m_hour += 1;
            m_second = 0;

            *this + addsecond;
        }
    }
    
}