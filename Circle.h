#pragma once
#include "Shape.h"
class Circle : public Shape
{
	u_int radius;

public:
	Circle(const u_int& _radius, const string& _color);
public:
	virtual int CalcArea();
	virtual int CalcPerimeter();
	virtual void Introduce();
};

