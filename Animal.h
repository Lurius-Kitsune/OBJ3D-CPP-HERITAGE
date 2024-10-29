#pragma once
#include "Macro.h"
class Animal
{
	string name;
	int pawsCount;
	float life;

public:
	virtual void Eat(); // Virtual signifie que la fonction existe sur les classe fille !
	virtual void Sleep();
};

