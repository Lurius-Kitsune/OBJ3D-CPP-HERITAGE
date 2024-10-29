#pragma once
#include "Dog.h"

class SickDog : public Dog
{

public:
	virtual void Bark() override;
	virtual void Sleep() override;
};

