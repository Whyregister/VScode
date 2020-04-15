#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <iomanip>

using namespace std;

class Date
{
    public:
        Date(int = 0, int = 0, int = 0);
        ~Date();

        Date & operator + (int);
        friend ostream & operator << (ostream & out ,const Date & Date);
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


#endif
