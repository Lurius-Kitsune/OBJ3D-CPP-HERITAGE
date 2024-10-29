#pragma once
#include "Macro.h"
class Animal
{
	string name;

protected:
	int pawsCount;
	float life;

public:
	virtual void Introduce();
	virtual void Eat(); // Virtual signifie que la fonction existe sur les classe fille !
	virtual void Sleep();
};

