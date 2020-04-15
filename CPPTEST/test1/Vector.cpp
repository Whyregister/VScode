#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
    //定义
    vector<string> vecString = {"刘备","关羽","张飞"};
    //获取迭代对象
    vector<string> ::iterator itString;
    //插入
    vecString.push_back("阿斗");
    //输入
    cin >> vecString[0];
    //排序
    sort(vecString.begin(),vecString.end());
    //输出
    for (itString = vecString.begin(); itString != vecString.end() ; ++itString)
    cout << *itString << endl;
    return 0;
}