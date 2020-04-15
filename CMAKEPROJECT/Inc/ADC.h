#ifndef A_D_C_H
#define A_D_C_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Hero.h"

class ADC : public Hero
{
private:
	int m_PhysicanAttack;
public:
	ADC();
	ADC(string name);
	~ADC();
	
	void Move() override;
	void Death() override;
	void Skill(Hero &) override;

};
#endif
