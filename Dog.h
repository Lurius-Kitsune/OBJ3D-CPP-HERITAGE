#pragma once
#include "Animal.h"

class Dog : public Animal // Heritage fait !
{

protected:
	double barkPower;

public:
	virtual void Introduce() override;
	virtual void Eat() override;
	virtual void Bark();
};

