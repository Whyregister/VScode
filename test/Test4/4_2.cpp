#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

class Times
{
    public:
        Times(int = 0,int = 0,int = 0);
        ~Times();
        
        void SetTimes(int , int , int);       
        void Display();
        void operator + (int);
        void operator - (int);

    private:
        int m_hour;
        int m_minute;
        int m_second;

};


Times::Times(int hour,int minute,int second):m_hour(hour),m_minute(minute),m_second(second)
{
    cout << "Time has been set!" << endl;
}

Times::~Times()
{
    cout << "Time has been release!" << endl;
}



void Times::SetTimes(int hour,int minute,int second)
{


    if(hour < 0 || hour > 24)
    return;

    if(minute < 0 || minute >= 60)
    return;

    if(second < 0 || second >= 60)
    return;

    m_hour = hour;
    m_minute = minute;
    m_second = second;
    
}

void Times::Display()
{
    cout <<setfill('0')<<setw(2)<< m_hour;
    cout <<':';
    cout <<setfill('0')<<setw(2)<< m_minute;
    cout <<':';
    cout <<setfill('0')<<setw(2)<< m_second;
}

void Times::operator + (int addsecond)
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



void Times::operator - (int addsecond)
{
    if( m_second - addsecond >= 0)
    {
        m_second -= addsecond;
    }
    else
    {
        if(m_minute - 1 >= 0)
        {
            addsecond = addsecond + m_second - 60;
            m_minute -= 1;
            m_second = 0;
            *this - addsecond;
        }
        else
        {
            addsecond = addsecond + m_second - 60;
            m_minute = 0;
            m_hour -= 1;
            m_second = 0;

            *this - addsecond;
        }
    }
    
}
    
int main()
{
    Times t(12,12,12);
    while(1)
    {
        t-1;
        t.Display();
        system("cls");
    }
}