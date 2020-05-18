#include "Integer.h"

using std::ostream;

Integer::Integer()
{
    m_num = 0;
}

Integer::Integer(int value)
{
    m_num = value;
}

Integer::~Integer()
{

}

const Integer Integer::operator+(const int value) const
{
    Integer result(this->m_num+value);
    return result;
}

ostream & operator<<(ostream & out ,const Integer & Int)
{
    out << Int.m_num;
    return out;
}

const istream & operator>>(istream & in , Integer & Int)
{
    in >> Int.m_num;
    return in;
}
Integer & Integer:: operator ++ ()
{
    m_num++;
    return *this;
}
const Integer   Integer:: operator ++ (int n)
{
    Integer tem(m_num);
    m_num++;
    return tem;
}

Integer & Integer:: operator -- ()
{
    m_num--;
    return *this;
}

const Integer   Integer:: operator -- (int n)
{
    Integer tem(m_num);
    m_num--;
    return tem;
}