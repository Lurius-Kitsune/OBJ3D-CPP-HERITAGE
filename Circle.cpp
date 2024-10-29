#include "Circle.h"

Circle::Circle(const u_int& _radius, const string& _color) : Shape(_color)
{
	radius = _radius;
}

int Circle::CalcArea()
{
	return 3.14*(radius*radius);
}

int Circle::CalcPerimeter()
{
	return (radius*2)*3.14;
}

void Circle::Introduce()
{
	DISPLAY(color + "[Le cercle]", true);
	Shape::Introduce();
}
