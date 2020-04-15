#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstring>
using std:: ostream;
using std:: istream;

class Mystring
{
    private:
        char * m_String;
        int m_StrLen;

    public:
        Mystring();

        Mystring(const char * str);

        Mystring(const Mystring & str);

        ~Mystring();
        const Mystring & operator=(const Mystring & str);
        friend ostream & operator << (ostream & out ,const Mystring & str); 
        friend istream & operator >> (istream & out ,const Mystring & str); 

    protected:

};

#endif