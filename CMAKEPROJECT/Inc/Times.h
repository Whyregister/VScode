#ifndef Times_H
#define Times_H
#include <iostream>
#include <iomanip>
using std::ostream;

class Times
{
    public:
        Times(int = 0,int = 0,int = 0);
        ~Times();

        int SetHour(int);
        int SetMinute(int);
        int SetSecond(int);
        void SetTimes(int , int , int);
        
        friend ostream & operator << (ostream & out ,const Times & Times);
        Times & operator + (int);
        

    private:
        int m_hour;
        int m_minute;
        int m_second;

};

#endif