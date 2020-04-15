#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ADC.h"
using namespace std;

ADC::ADC()
{
    cout << "he is a ADC!" << endl;
}

ADC::ADC(string name) : Hero(name)
{
    cout << "he is a ADC!" << endl;
}

ADC::~ADC()
{
    cout << GetName() << " delete" << endl;
}

void ADC::Move()
{
    cout << GetName() << "is esquping!" << endl;
}

void ADC::Skill(Hero & hero)
{
    cout << GetName() << "hit" << hero.GetName() << endl;
}
void ADC::Death()
{
    cout << "ADCdeath" << endl;
}