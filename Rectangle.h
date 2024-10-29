#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
	u_int length;
	u_int width;

public:
	Rectangle(const u_int& _length, const u_int& _width, const string& _color);
public:
	virtual int CalcArea();
	virtual int CalcPerimeter();
	virtual void Introduce();
};

