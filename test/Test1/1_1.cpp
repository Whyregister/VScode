#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

class Date
{
    public:
        Date(int = 0, int = 0, int = 0);
        ~Date();
        void Daygo(int);
        void GetDate();
        int SetYear(int );
        int SetMonth(int );
        int SetDay(int , int );
        void SetDate();

    private:
        int m_year;
        int m_month;
        int m_day;
        bool m_isleap;
};

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

void Date::Daygo(int addday)
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
                    this->Daygo(addday);
                }
                else
                {
                    m_month += 1;
                    addday = addday + m_day - 31;
                    m_day = 0;
                    this->Daygo(addday);
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
                    this->Daygo(addday);                    
                }
                else
                {
                    m_month += 1;
                    addday = addday + m_day - 30;
                    m_day = 0;
                    this->Daygo(addday);
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
                    this->Daygo(addday);
                }
                else
                {
                    m_month += 1;
                    addday = addday + m_day - 28 - int(m_isleap);
                    m_day = 0;
                    this->Daygo(addday);
                }
             }
             break;
             
    }
}

void Date::GetDate()
{
    cout <<setfill('0')<<setw(4)<< m_year;
    cout <<'/';
    cout <<setfill('0')<<setw(2)<< m_month;
    cout <<'/';
    cout <<setfill('0')<<setw(2)<< m_day;
}

void Date::SetDate()
{
    int year , month ,day;
    cout << "input the year:" ;
    cin >> year;
    cout << "input the month:" << endl;
    cin >> month;
    cout << "input the day:" << endl;
    cin >> day;
    if(SetYear(year)&&SetMonth(month)&&SetDay(day,month))
    {
        cout << "success!";
        m_year = year;
        m_month = month;
        m_day = day;
    }
    else
    {
        m_year = 0;
        m_month = 0;
        m_day = 0;
        cout << "wrong input!" << endl;
    }
    
}
int main()
{
    Date date(2000,2,29);
    date.Daygo(1);
    date.GetDate();
    return 0;
}