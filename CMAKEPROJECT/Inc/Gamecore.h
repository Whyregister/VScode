#ifndef GAMECORE_H
#define GAMECORE_H
#include "Hero.h"
#include <iostream>

class Gamecore
{
private:
	int attribute0;

	int attribute1;

public:
	void Move(Hero & hero);

	void Skill(Hero & hero);

	Gamecore();

	~Gamecore();
};
#endif
