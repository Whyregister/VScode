#include <iostream>
using namespace std;
int main()
{
    string student[]{"刘备","关羽","张飞","吕布"};
    string object[]{"语文","数学","英语"};
    const int row = 3;
    const int col = 4;
    int score[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << student[j] << object[i] << "为:";
            cin >> score[i][j];
        }
    }

    char g;
    cin >> g;
    switch (g)
    {
        case '1':
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        cout << student[j] << object[i] << "为:" << score[i][j]<<endl;
                    }
                }
        break;

        case '2':
                for (int i = 0; i < col; i++)
                {
                    for (int j = 0; j < row; j++)
                    {
                        cout << student[i] << object[j] << "为:" << score[j][i]<<endl;
                    }
                }
                
        break;
        default:
        break;
    }

    return 0;
}