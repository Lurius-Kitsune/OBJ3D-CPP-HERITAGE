#include "Animal.h"

void Animal::Introduce()
{
	DISPLAY("Bonjour je suis" + name + " j'ai " + to_string(pawsCount) + " patte et " + to_string(life) + " PV", true);
}

void Animal::Eat()
{
	DISPLAY("MIAM MIAM ..", true);
}

void Animal::Sleep()
{
	DISPLAY("Time to mimir zzzzz...", true);
}
