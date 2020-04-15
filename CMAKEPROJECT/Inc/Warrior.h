#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Hero.h"

class Warrior : public Hero
{
private:
	int m_PhysicanAttack;


public:
	Warrior();
	Warrior(string name );
	~Warrior();

	void Move() override;
	void Death() override;
	void Skill(Hero &) override;

};


#endif
