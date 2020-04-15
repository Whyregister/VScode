#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{
    double score1[]{34,54,343,2432,4};
    double score3[]{34,54,343,2432,4};
    double score4[]{34,54,343,2432,4};
    double score5[]{34,54,343,2432,4};
    double score6[]{34,54,343,2432,4};
    double * ptr_score = score6;

    cout << *(ptr_score+15);

    //cout <<*++score;//wrong
    //cout <<*++ptr_score;//true

    getch();
    
    return 0;

}