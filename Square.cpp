#include "Square.h"

Square::Square(const u_int& _side, const string& _color) : Shape(_color)
{
    side = _side;
}

int Square::CalcArea()
{
    return side*side;
}

int Square::CalcPerimeter()
{
    return side*4;
}

void Square::Introduce()
{
    DISPLAY(color + "[Le caré]", true);
    Shape::Introduce();
}
