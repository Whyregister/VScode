#include "Landowener.h"

Landowener::Landowener()
{
    cout << "默认调用" << endl;
    InitCards();
}

Landowener::Landowener(string Name):m_name(Name)
{
    cout << "命名为：" << m_name << endl;
    InitCards();
    cout << "牌堆：" << endl;
    ShowCards(vecCrads);
    
}

void Landowener::InitCards()
{
    for(int i = 0 ;i < 54 ; i++ )
    {
        vecCrads.push_back(i+1);
        vecSurplusCrads.push_back(vecCrads.at(i));
    }
    vecCurCrads.clear();
}

void Landowener::ShowCards(const vector<int> & Cards)
{
    /*for(vector<int>::const_iterator it = Cards.begin() ; it != Cards.end() ; ++it)    
    cout << *it << endl;

    for(auto card: Cards)
    cout << card <<",";*/
    copy(Cards.cbegin(),Cards.cend(),ostream_iterator<int>(cout, ", "));
    cout << endl;
}

void Landowener::TouchCards(int CardsCount)
{
    //随机生成一张剩余牌堆里存在的牌放入当前牌组
    //srand(time(NULL));
    int Num;
    for(int i = 0 ; i<= CardsCount ; i++)
    {
        Num = rand() % 54+1;
        
        if(IsContains(Num))
        {
            vecCurCrads.push_back(Num);
            DeleteCards(vecSurplusCrads,Num);
        }
        else
            i--;
    }

}

void Landowener::DeleteCards(vector<int>&deletecards, int card)
{
    /*
    //普通
    for(vector<int>::iterator iter = deletecards.begin() ; iter != deletecards.end() ; )
    {
        if(*iter == card)
            iter = deletecards.erase(iter);
        else
            ++iter;
    }*/
    //算法
    vector<int>::iterator iter;
    iter = find(deletecards.begin(),deletecards.end(),card);
    if(iter != deletecards.end())
    deletecards.erase(iter);
}


bool Landowener::IsContains(int cardNum)
{
    //1.遍历对比
    vector<int>::iterator iter = find(vecSurplusCrads.begin(),vecSurplusCrads.end(),cardNum);

    return iter != vecSurplusCrads.end();
}

void Landowener::ShowInfor()
{
    cout << m_name << ':' << endl;
    ShowCards(vecCurCrads);
    cout << "一手好牌" << endl;
    cout << "剩余牌堆：" << endl;
    ShowCards(vecSurplusCrads);
}

Landowener::~Landowener()
{

}

void Landowener::GetScore(long int score)
{
    if (score < 0)
    m_gold = 0;
    else
    m_gold = score;
}

void Landowener::SetName(string name)
{
    m_name = name;
}

string Landowener::ShowName()
{
    return m_name;
}

long int Landowener::ShowScore()
{
    return m_gold;
}

