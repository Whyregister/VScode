#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "Galon.h"

using std::cout;
using std::endl;

void Galon::Move()
{
    cout << "GalonMoving!" << endl;
}

void Galon::Skill()
{
     cout << "zheng yi shen pan!" << endl;
}

Galon::Galon() : Warrior("Galon")
{
    cout << "new Galon!" << endl;
}

Galon::~Galon()
{
}

void Galon::Death()
{
    cout << "Galon Death!" << endl;
}