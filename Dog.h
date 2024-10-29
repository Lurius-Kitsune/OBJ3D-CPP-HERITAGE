#pragma once
#include "Animal.h"

class Dog : public Animal // Heritage fait !
{


public:
	virtual void Eat() override;
	void Bark();
};

