#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string.h>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

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
#endif
