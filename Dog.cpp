#include "Dog.h"

Dog::Dog()
{
	barkPower = 4.00;
}

Dog::Dog(const string& _name, const float _life, 
	const double _barkPower) : Animal(_name, 4, _life)
{
	barkPower = _barkPower;
}


void Dog::Introduce()
{
	Animal::Introduce();
	DISPLAY(barkPower, true);
}

void Dog::Eat()
{
	DISPLAY("MIAM MIAM croquette ..", true);
}

void Dog::Sleep()
{
	DISPLAY("Time to mimir home zzzzz...", true);
}

void Dog::Bark()
{
	DISPLAY("I DONT LIKE YU, I'm now going to bark at you, BARK BARK BARK BARK", true);
}
