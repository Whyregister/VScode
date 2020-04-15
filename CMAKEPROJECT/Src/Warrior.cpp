#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Warrior.h"
using namespace std;
Warrior::Warrior()
{
    cout << "new warrior! withoutname" << endl;
}

Warrior::Warrior(string name)  :Hero(name)
{
    cout << "new warrior! havename" << endl;
}

Warrior::~Warrior()
{
    cout << GetName() <<  " delete" << endl;
}

void Warrior::Move()
{
    cout << "WarriorMoving!" << endl;
}

void Warrior::Skill(Hero & hero)
{
    cout << GetName() << "hit" << hero.GetName() << endl;
}

void Warrior::Death()
{
    cout << "warrior die!" << endl;
}