#pragma once
#include "Macro.h"
class Shape
{
protected:
	string color;
public:
	Shape();

	Shape(const string& _color);

protected:
	virtual int CalcArea() = 0;
	virtual int CalcPerimeter() = 0;
	virtual void Introduce();
};

