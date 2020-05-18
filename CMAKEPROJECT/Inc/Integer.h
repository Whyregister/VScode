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
            Integer(int value); 
            ~Integer();
            const Integer operator+(const int value) const;
            Integer & operator ++ ();
            const Integer   operator ++ (int n);
            Integer & operator -- ();
            const Integer   operator -- (int n);            
            friend ostream & operator<<(ostream & out ,const Integer & Int);            
            friend const istream & operator>>(istream & in ,Integer & Int);            

};



#endif 