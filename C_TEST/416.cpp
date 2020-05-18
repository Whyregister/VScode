#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
/*
*访问控制属性私有，公有，保护
*/

/**定义英雄类*/
using namespace std;

class Hero
{
//私有
private:
	int m_MaxLife;

	int m_CurrLife;

	string m_NickName;

	int m_x;

	int m_y;
//公有
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

//保护属性只在继承中体现区别；

//继承自英雄的战士类
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
Warrior::Warrior()
{
    cout << "new warrior! withoutname" << endl;
}

Warrior::Warrior(string name) :Hero(name)
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
//公有继承，则基类里的访问属性在子类体现一致

//什么情况下定义不要给出实参？
//1.无显示定义构造
//2.显示定义构造但是无参构造
//3.存在参数的显示构造但是都有默认参数
//例如：
class Hero
{
//私有
private:
	int m_MaxLife;

	int m_CurrLife;

	string m_NickName;

	int m_x;

	int m_y;
//公有
public:
	Hero();
	
	Hero(string name = "【电脑】");

	virtual ~Hero();

	virtual void Move() = 0;
	virtual void Death() = 0;
	virtual void Skill(Hero &) = 0;

	string GetName();

	int SetName(string name);

};

//派生类构造函数调用顺序
//由上至下：
//例如：
/**英雄类*/
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



/**继承自英雄的战士类*/
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
Warrior::Warrior()
{
    cout << "new warrior! withoutname" << endl;
}

Warrior::Warrior(string name) :Hero(name)
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

/**继承自战士的一个英雄盖伦*/
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
//结果为
/**
 * new Hero1
 * new warrior
 * new Galon
 */
//何时可以不显示调用构造函数
/**1.无常量
 * 2.无引用
 * 3.无成员类
 * */

//菱形继承
//如一个英雄凯尔，即继承战士类，又继承ADC类

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

/**继承自英雄的战士类*/
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

void Warrior::Death()
{
    cout << "warrior die!" << endl;
}

/**ADC类*/
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

/**英雄Kaer*/

//继承自战士
class Kaer : public Warrior
{
private:
	string word[10];

public:
	void Move() override;
	void Death() override;

	void Skill();

	Kaer();

	~Kaer();

	void Taking();

};


//继承自ADC
class Kaer : public ADC
{
private:
	string word[10];

public:
	void Move() override;
	void Death() override;

	void Skill();

	Kaer();

	~Kaer();

	void Taking();

};


//类的实现
void Kaer::Move()
{
    cout << "KaerMoving!" << endl;
}

void Kaer::Skill()
{
     cout << "zheng yi shen pan!" << endl;
}

Kaer::Kaer() : Warrior("Kaer")
{
    cout << "new Kaer!" << endl;
}

Kaer::~Kaer()
{
}

void Kaer::Death()
{
    cout << "Kaer Death!" << endl;
}

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
Warrior::Warrior()
{
    cout << "new warrior! withoutname" << endl;
}

Warrior::Warrior(string name) :Hero(name)
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

//此时存在错误

//解决方案，虚基类

//继承自战士
class Kaer :virtual public Warrior
{
private:
	string word[10];

public:
	void Move() override;
	void Death() override;

	void Skill();

	Kaer();

	~Kaer();

	void Taking();

};


//继承自ADC
class Kaer :virtual public ADC
{
private:
	string word[10];

public:
	void Move() override;
	void Death() override;

	void Skill();

	Kaer();

	~Kaer();

	void Taking();

};
