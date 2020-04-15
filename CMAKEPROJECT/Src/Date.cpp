#include "Date.h"

using namespace std;
using std::ostream;
Date::Date(int year,int month , int day) : m_year(year),m_month(month),m_day(day)
{
    cout << "Date has been set!" << endl;
}

Date::~Date()
{
    cout << "Date has been release!" << endl;
}

int Date::SetYear(int year)
{
    m_year = year;
    m_isleap = (!(year%4) && year%100) || !(year%400);
    return 1;
}

int Date::SetMonth(int month)
{
    if ( month < 1 || month > 12)
    return 0;
    return 1;
}

int Date::SetDay(int day , int month)
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
             if(day >0 && day < 32)
             {
                 return 1;
             }
             break;
        case 4:
        case 6:
        case 9:
        case 11:
             if(day > 0 && day < 31)
             {
                 return 1;
             }
             break;
        case 2:
             if(m_isleap)
             {
                 if(day > 0 && day < 30)
                 {
                     return 1;
                 }
             }
             else
             {
                 if(day > 0 && day < 29)
                 {
                     return 1;
                 }
             }
             break;
             
    }
    return 0;
}

Date & Date::operator + (int addday)
{
    switch(m_month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
             if(m_day+addday < 32)
             {
                 m_day += addday;
             }
             else
             {
                if(m_month+1 >12)
                {
                    addday = addday + m_day - 31;
                    m_year += 1;
                    m_isleap = (!(m_year%4) && m_year%100) || !(m_year%400);
                    m_month = 1;
                    m_day = 0;
                    *this + addday;
                }
                else
                {
                    m_month += 1;
                    addday = addday + m_day - 31;
                    m_day = 0;
                    *this + addday;
                }
             }            
             break;
        case 4:
        case 6:
        case 9:
        case 11:
             if(m_day+addday < 31)
             {
                 m_day += addday;
             }
             else
             {
                if(m_month+1 >12)
                {
                    addday = addday + m_day - 30;
                    m_year += 1;
                    m_isleap = (!(m_year%4) && m_year%100) || !(m_year%400);
                    m_month = 1;
                    m_day = 0;
                    *this + addday;                    
                }
                else
                {
                    m_month += 1;
                    addday = addday + m_day - 30;
                    m_day = 0;
                    *this + addday;
                }
             }
             break;
        case 2:
             if(m_day+addday < 29+int(m_isleap))
             {
                 m_day += addday;
             }
             else
             {
                if(m_month+1 >12)
                {
                    addday = addday + m_day - 28 - int(m_isleap);
                    m_year += 1;
                    m_isleap = (!(m_year%4) && m_year%100) || !(m_year%400);
                    m_month = 1;
                    m_day = 0;
                    *this + addday;
                }
                else
                {
                    m_month += 1;
                    addday = addday + m_day - 28 - int(m_isleap);
                    m_day = 0;
                    *this + addday;
                }
             }
             break;
             
    }
    return *this;
}

ostream & operator << (ostream & out ,const Date & date)
{
    out <<setfill('0')<<setw(4)<< date.m_year;
    out <<'/';
    out <<setfill('0')<<setw(2)<< date.m_month;
    out <<'/';
    out <<setfill('0')<<setw(2)<< date.m_day;
    return out;
}

void Date::SetDate()
{
    int year , month ,day;
    cout << "输入年份：" << endl;
    cin >> year;
    cout << "输入月份：" << endl;
    cin >> month;
    cout << "输入日期：" << endl;
    cin >> day;
    if(SetYear(year)&&SetMonth(month)&&SetDay(day,month))
    {
        cout << "有效日期";
        m_year = year;
        m_month = month;
        m_day = day;
    }
    else
    {
        m_year = 0;
        m_month = 0;
        m_day = 0;
        cout << "无效日期" << endl;
    }
    
}