#ifndef RECT_H
#define RECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class Rect
{
protected:
	float* Length;

	float* Width;


public:
	~Rect();
	
	Rect(float length=1, float width=1);

	Rect(const Rect & rect);

	bool Set(float length=0, float width = 0);

	float Primeter() const;

	float Area() const;

};
#endif
