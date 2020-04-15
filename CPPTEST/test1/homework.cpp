#include <iostream>
#include <iomanip>
using namespace std;

double WeightCalc(const double body_height)
{
    return body_height - 100;
}


int main ()
{
    double body_height;
    cout << "请输入身高(单位:cm) ：";
    cin >> body_height;

    cout << setw(8);
    cout << "标准体重为" << WeightCalc(body_height) << "kg" << endl;
        
    return 0;

}