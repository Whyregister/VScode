#ifndef GALON_H
#define GALON_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Warrior.h"
using namespace std;

class Galon : public Warrior
{
private:
	string word[10];

public:
	void Move() override;
	void Death() override;

	void Skill();

	Galon();

	~Galon();

	void Taking();

};

#endif
