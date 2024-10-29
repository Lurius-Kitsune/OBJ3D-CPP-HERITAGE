#include "Animal.h"

Animal::Animal()
{
	name = "Margeuritte";
	pawsCount = 4;
	life = 100.0f;
}

Animal::Animal(const string& _name, const int _pawsCount, const float _life)
{
	name = _name;
	pawsCount = _pawsCount;
	life = _life;
}


void Animal::Introduce()
{
	DISPLAY("Bonjour je suis " + name + " j'ai " + to_string(pawsCount) + " patte et " + to_string(life) + " PV", true);
}


void Animal::Eat()
{
	DISPLAY("MIAM MIAM ..", true);
}

void Animal::Sleep()
{
	DISPLAY("Time to mimir zzzzz...", true);
}
