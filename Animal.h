#pragma once
#include "Macro.h"

class Animal
{
	string name;

protected:
	int pawsCount;
	float life;

public: 
	string GetName() const
	{
		return name;
	}

public:
	Animal();
	Animal(const string& _name, const int _pawsCount, const float _life);

protected:
	virtual void Introduce();
public:
	virtual void Eat(); // Virtual signifie que la fonction existe sur les classe fille !
	virtual void Sleep();
};

