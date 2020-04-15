#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Hero.h"
using namespace std;
Hero::Hero()
{
	cout << "new hero! withoutname" << endl;
}

Hero::Hero(string name)
{
	SetName(name);
	cout << "new hero!" << m_NickName << endl;
}

Hero::~Hero()
{
	cout << m_NickName << "is death!" << endl;
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

void Hero::Move()
{
	cout << "HeroMoving!" << endl;
	cout << this << endl;
}

void Hero::Death()
{
	cout << "Hero death!" << endl;
}
