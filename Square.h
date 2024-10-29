#pragma once
#include "Shape.h"

class Square : public Shape
{
	u_int side;

public :
	Square(const u_int& _side, const string& _color);
public :
	virtual int CalcArea();
	virtual int CalcPerimeter();
	virtual void Introduce();
};

