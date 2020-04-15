#include "Calendar.h"

Calendar::Calendar(int year ,int month ,int day, int hour ,int minute ,int second) : m_date(year,month,day) ,m_time(hour,minute,second)
{
    cout << "Calendar has been set!" << endl;
}

Calendar::~Calendar()
{
    cout << "Calendar have been release!" << endl;
}

void Calendar::ShowCalendar()
{
    cout << m_date << endl;
    cout << m_time << endl;
    cout << isleap << endl;
}
