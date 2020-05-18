#include <iostream>
#include <string.h>
using namespace std;

class XS
{
public:
	virtual void dispXM()=0;
	virtual void dispXB()=0;
	virtual void dispNL()=0;
};

class CZS:public XS
{
public:
	CZS(char * m="张三",int b=1,int n=14);
	void dispXM() override;
	void dispXB() override;
	void dispNL() override;
protected:
	char xm[9];
	int xb,nl;
};

class GZS:public XS
{
public:
	GZS(char * m="张三",int b=1,int n=17);
	void dispXM() override;
	void dispXB() override;
	void dispNL() override;
protected:
	char xm[9];
	int xb,nl;
};

class DXS:public XS
{
public:
	DXS(char * m="张三",int b=1,int n=20);
	void dispXM() override;
	void dispXB() override;
	void dispNL() override;
protected:
	char xm[9];
	int xb,nl;
};

DXS::DXS(char * m,int b,int n)
{
    strcpy(this->xm,m);
    xb = b;
    nl = n;
}

GZS::GZS(char * m,int b,int n)
{
    strcpy(this->xm,m);
    xb = b;
    nl = n;
}

CZS::CZS(char * m,int b,int n)
{
    strcpy(this->xm,m);
    xb = b;
    nl = n;
}

void CZS::dispNL()
{
    cout << this->nl <<endl;
}

void CZS::dispXB()
{
    cout << this->xb << endl;
}

void CZS::dispXM()
{
    cout << "CZS:" << this->xm << endl;
}

void GZS::dispNL()
{
    cout << this->nl <<endl;
}

void GZS::dispXB()
{
    cout << this->xb << endl;
}

void GZS::dispXM()
{
    cout << "GZS" << this->xm << endl;
}

void DXS::dispNL()
{
    cout << this->nl <<endl;
}

void DXS::dispXB()
{
    cout << this->xb << endl;
}

void DXS::dispXM()
{
    cout << "DXS:" << this->xm << endl;
}


void displayP(XS * p)
{
    p->dispXM();
    p->dispNL();
    p->dispXB();
}

void displayR(XS & p)
{
    p.dispXM();
    p.dispNL();
    p.dispXB();
}



int main()
{
	CZS czs("赵一",1,12);
	GZS gzs("钱二",0,15);
	DXS dxs("孙三",1,18);
	XS *p;//定义抽象基类的指针变量p
	p=&czs;//将初中生对象czs的地址赋给p
    displayP(p);
        p=&gzs;//将高中生对象czs的地址赋给p
    displayP(p);
        p=&dxs;//将大学生对象czs的地址赋给p
    displayP(p);
	cout<<"\n----------------------------------------\n";
	XS &r1=czs;//定义抽象基类的引用变量r1为czs的别名
	displayR(r1);
	XS &r2=gzs;//定义抽象基类的引用变量r2为czs的别名
	displayR(r2);
	XS &r3=dxs;//定义抽象基类的引用变量r3为czs的别名
	displayR(r3);
	cout<<"\n----------------------------------------\n";

    return 0;
}

