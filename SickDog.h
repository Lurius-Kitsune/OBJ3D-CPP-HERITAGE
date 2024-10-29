#pragma once
#include "Dog.h"

class SickDog : public Dog
{
	string weakness;
public:
	virtual void Introduce() override;
	virtual void Bark() override;
	virtual void Sleep() override;
};

