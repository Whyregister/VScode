#include "Integer.h"

using std::ostream;

Integer::Integer()
{

}

Integer::Integer(istream in)
{
    in >> m_num;
}

Integer::Integer(int value)
{
    m_num = value;
}
Integer::~Integer()
{

}

int Integer::GetNum() const
{
    return m_num;
}

const Integer Integer::operator+(const int value) const
{
    Integer result(this->m_num+value);
    return result;
}

const Integer operator+(int value ,const Integer & Int)
{
    return Integer(value + Int.m_num);
}

ostream & operator<<(ostream & out ,const Integer & Int)
{
    out << "值为:" << Int.m_num;
    return out;
}

const istream & operator>>(istream & in , Integer & Int)
{
    in >> Int.m_num;
    Int.m_num += 1; 
    return in;
}