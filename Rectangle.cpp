#include "Rectangle.h"

Rectangle::Rectangle(const u_int& _length, const u_int& _width, const string& _color)
	: Shape(_color)
{
	length = _length;
	width = _width;
}

int Rectangle::CalcArea()
{
	return length*width;
}

int Rectangle::CalcPerimeter()
{
	return (length+width) * 2;
}

void Rectangle::Introduce()
{
	DISPLAY(color + "[Le rectangle]", true);
	Shape::Introduce();
}
