#ifndef LANDOWENER_H
#define LANDOWENER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <time.h>

using namespace std;
class Landowener
{

        private:
                string m_name;
                long int m_gold;
                vector<int>vecCrads;
                vector<int>vecCurCrads;
                vector<int>vecSurplusCrads;
                void InitCards();
                void DeleteCards(vector<int> & ,int card);
        public:
                Landowener();
                Landowener(string Name);

                ~Landowener();

                void SetName(string);
                string ShowName();
                void GetScore(long int);
                long int ShowScore();
                
                /**显示信息*/
                void ShowInfor();
                /**摸牌*/
                void TouchCards(int Count);
                /**显示牌面*/
                void ShowCards(const vector<int> &);

                /**判断是否有这张牌*/
                bool IsContains(int cardNum);



        protected:



};

#endif // LANDOWENER_H