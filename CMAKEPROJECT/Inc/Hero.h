#ifndef HERO_H
#define HERO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
using std::string;

class Hero
{
private:
	int m_MaxLife;

	int m_CurrLife;

	string m_NickName;

	int m_x;

	int m_y;

public:
	Hero();
	
	Hero(string name);

	virtual ~Hero();
	virtual void Move() = 0;
	virtual void Death() = 0;
	virtual void Skill(Hero &) = 0;

	string GetName();

	int SetName(string name);

};

#endif
