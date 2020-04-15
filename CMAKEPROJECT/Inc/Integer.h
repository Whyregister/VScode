#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
using namespace std;

class Integer
{
    private:

            int m_num;

    public:
            Integer();
            Integer(istream in);    
            Integer(int value); 
            ~Integer();
            int GetNum() const;
            const Integer operator+(const int value) const;

            friend const Integer operator+(int value,const Integer & Int);
            friend ostream & operator<<(ostream & out ,const Integer & Int);            
            friend const istream & operator>>(istream & in ,Integer & Int);            

};



#endif 