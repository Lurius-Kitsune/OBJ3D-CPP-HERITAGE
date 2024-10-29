#include "SickDog.h"

SickDog::SickDog()
{
	weakness = "Thomas";
}

SickDog::SickDog(const string& _name, const int _pawsCount, const float _life, 
	const double _barkPower, const string& _weakness) : Dog(_name, _life, _barkPower)
{
	pawsCount = _pawsCount;
	weakness = _weakness;
}


void SickDog::Introduce()
{
	pawsCount = 3;
	life = 3.00f;
	barkPower = 0.00;
	Dog::Introduce();
	DISPLAY("Ma faiblesse est " + weakness, true)
}

void SickDog::Bark()
{
	Dog::Bark(); // Demarquage !
	DISPLAY("BARRK.. BWERKKK/...", true);
}

void SickDog::Sleep()
{
	DISPLAY("Je suis malade chef !", true);
}
