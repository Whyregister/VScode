#include <iostream>
#include <iomanip>
using namespace std;

double WeightCalc(const double body_height)
{
    return body_height - 100;
}


int main ()
{
    double body_height,body_weight;
    double Standard_weight;
    cout << "请输入身高(单位:cm)、体重（单位：kg） ：";
    cin >> body_height >> body_weight;
    cout << setw(8);
    cout << "标准体重为" << (Standard_weight=WeightCalc(body_height)) << "kg" << endl;
    if(body_weight > 1.2 * Standard_weight)
    cout << "超重" << endl;
    else    if (body_weight < 0.8*Standard_weight)
    cout << "超轻" << endl;
    else
    {
    cout << "正常" << endl;
    }
    
            
    return 0;

}