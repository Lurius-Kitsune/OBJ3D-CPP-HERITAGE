#pragma once
#include "Animal.h"

class Dog : public Animal // Heritage fait !
{
	double barkPower;

public:
	virtual void Eat() override;
	virtual void Bark();
};

