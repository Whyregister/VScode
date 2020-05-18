#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

class Times
{
    public:
        Times(int = 0,int = 0,int = 0);
        ~Times();

        int SetHour(int);
        int SetMinute(int);
        int SetSecond(int);
        void SetTimes(int , int , int);
        
        //friend ostream & operator << (ostream & out ,const Times & Times);
        void GetTime();
        void Secondgo(int);
        //Times & operator + (int);
        

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
        cout << "wrong time!" <<endl;
    }
    
}

void Times::GetTime()
{
    cout <<setfill('0')<<setw(2)<< m_hour;
    cout <<':';
    cout <<setfill('0')<<setw(2)<< m_minute;
    cout <<':';
    cout <<setfill('0')<<setw(2)<< m_second;
}

void Times::Secondgo(int addsecond)
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
            Secondgo(addsecond);
        }
        else
        {
            addsecond = addsecond + m_second - 60;
            m_minute = 0;
            m_hour += 1;
            m_second = 0;
            Secondgo(addsecond);
        }
    }
    
}
int main()
{
    Times t(12,12,12);
    while(1)
    {
        t.GetTime();
        t.Secondgo(1);
        Sleep(5);
        system("cls");
    }
}