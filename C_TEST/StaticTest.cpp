/**
 * 该静态变量存储定义对象个数
 * 该静态函数用于显示对象个数
 */
#include <conio.h>
#include <iostream>

using namespace std;
class Hero
{
private:
	int m_CurrLife;

	string m_NickName;

    static int HeroCount;
public:
	
	Hero(string name="无名英雄");

	~Hero();

	string GetName();

	int SetName(string name);

    static void GetHeroCount();

};



int Hero::HeroCount = 0;

void Hero::GetHeroCount()
{
    cout << "当前英雄数量为：" << HeroCount << endl;    
}

Hero::Hero(string name)
{
	SetName(name);
	cout << "new hero!" << m_NickName << endl;
    HeroCount++;
}

Hero::~Hero()
{
	cout << m_NickName << "is death!" << endl;
    HeroCount--;
}

string Hero::GetName()
{
	return m_NickName;
}

int Hero::SetName(string name)
{
	if(name.length() < 18 )
	{
	m_NickName = name;
	return 0;
	}
	else
	{
		return 1;
	}
	
}


int main()
{
    Hero t1,t2,t3;
    Hero::GetHeroCount();
    Hero * t4;
    Hero::GetHeroCount();
    t4 = new Hero("艾希");
    Hero::GetHeroCount();
    delete t4;
    Hero::GetHeroCount();
    
    getch();
}

