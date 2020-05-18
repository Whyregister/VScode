#include <string.h>
#include <iostream>

class Employee
{
protected:
	char m_name[20];

	char m_adress[20];

	char m_postalcode[20];

	char m_city[20];

	char m_province[20];


public:
	Employee();

	int SetName(char* name);

	int SetAddress(char* address);

	int SetPostCode(char * code);

	int SetCity(char* city);

	int SetProvince(char * province);

	void Display();

};

using std::cout;
using std::endl;
Employee::Employee()
{
	strcpy(m_name,"00");
	strcpy(m_adress,"00");
	strcpy(m_city,"00");
	strcpy(m_province,"00");
	strcpy(m_postalcode,"00");
}

int Employee::SetName(char* name)
{
	if(sizeof(name) <= sizeof(m_name))
	{
		strcpy(m_name,name);
		return 1;
	}
	return 0;
}

int Employee::SetAddress(char* address)
{
	if(sizeof(address) <= sizeof(m_adress))
	{
		strcpy(m_adress,address);
		return 1;
	}
	return 0;
}

int Employee::SetPostCode(char * code)
{
	if(sizeof(code) <= sizeof(m_postalcode))
	{
		strcpy(m_postalcode,code);
		return 1;
	}
	return 0;
}

int Employee::SetCity(char* city)
{
	if(sizeof(city) <= sizeof(m_city))
	{
		strcpy(m_city,city);
		return 1;
	}
	return 0;
}

int Employee::SetProvince(char * province)
{
	if(sizeof(province) <= sizeof(m_province))
	{
		strcpy(m_province,province);
		return 1;
	}
	return 0;
}

void Employee::Display()
{
	cout << "NAME:" << m_name << endl
	<< "ADDRESS:" << m_adress << endl
	<< "CITY:" << m_city << endl
	<< "PROVINCE:" << m_province << endl
	<< "POSTALCODE:" << m_postalcode << endl;
}
int main()
{
    Employee e;
    e.SetName("jackMa");
    e.SetAddress("China");
    e.SetProvince("ZheJIang");
    e.SetCity("hangzhou");
    e.SetPostCode("123456");
    e.Display();
    return 0;
}