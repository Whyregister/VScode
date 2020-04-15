#include <iostream>
#include <conio.h>

using namespace std;
int & sum();
void test();

int main ()
{
    int & rel_num = sum();
    test();                                                                                         
    cout << "result = " << rel_num << endl ;
     
    getch();
    
    return 0;

}

	int & sum ()
	{
        int num = 857;
        
        int & rel_num = num;
        
        return rel_num;
	}

	void test ()
    {
       int x = 14354;
       
       int y = 453;
        
       int v = 5443;
        
       int ds = 3432;
        
       int dfd = 34;
    }