#include <string>
#include <iostream>
using namespace std;
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

Rect::Rect(float length, float width)
{
	Length = new float;
	Width = new float;
	if(length >=0 && width >= 0 )
	{
		*Length = length;
		*Width = width;
	}
	else
	{
		*Length = 0;
		*Width = 0;
	}
	
}

Rect::Rect(const Rect & rect)
{
	this->Length = new float;
	this->Width = new float;
	*Length = *rect.Length;
	*Width = *rect.Width;
}

bool Rect::Set(float length, float width)
{
		if(length >=0 && width >= 0 )
	{
		*Length = length;
		*Width = width;
		return true;
	}
	else
	{
		*Length = 0;
		*Width = 0;
		return false;
	}
	
}

float Rect::Primeter() const
{
	return 2*((*Length)+(*Width));
}

float Rect::Area() const
{
	return (*Length)*(*Width);
}

Rect::~Rect()
{
	delete Length;
	delete Width;
}
int main()
{
    Rect r(3,4);
    cout << r.Area() << endl;
    cout << r.Primeter() << endl;
    return 0;
}

