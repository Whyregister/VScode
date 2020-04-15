#include "Mystring.h"
using std:: ostream;
using std:: istream;
using std:: cout;
Mystring::Mystring()
{
    m_String = new char[1];
    m_String[0] = '\0'; 
    m_StrLen = 0; 
    cout << &m_String  << '\n';
}

Mystring::Mystring(const char * str)
{
    if(!str)    return;
    m_StrLen = strlen(str);
    m_String = new char[m_StrLen+1];
    strcpy(m_String,str);
}

Mystring::Mystring(const Mystring & str)
{
    m_StrLen = strlen(str.m_String);
    m_String = new char[m_StrLen+1];
    strcpy(m_String,str.m_String);

}

Mystring::~Mystring()
{
    delete m_String;
}

ostream & operator << ( ostream & out ,const Mystring & str)
{
    out << str.m_String << '\n';
    out << "长度为：" << str.m_StrLen << '\n';

    printf("%p",str.m_String);

    return out;
}

istream & operator >> ( istream & in ,const Mystring & str)
{
    in >> str.m_String;
    cout<< "长度为" << str.m_StrLen;
    return in;
}

const Mystring & Mystring::operator=(const Mystring & str)
{
    if(this == &str)  return *this;
    
    delete m_String;
    
    this->m_StrLen = str.m_StrLen;
    
    m_String = new char[this->m_StrLen+1];
    
    strcpy(m_String,str.m_String);
    
    return *this;
}