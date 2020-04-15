#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include "Date.h"
#include "Times.h"
using std::string;

class Calendar
{
    private:
        string isleap;
        Date m_date;
        Times m_time;

    public:
        Calendar(int = 0,int = 0 ,int = 0 ,int = 0,int = 0,int = 0 );
        ~Calendar();

        void ShowTime();
        void ShowDate();
        void ShowCalendar();

};

#endif