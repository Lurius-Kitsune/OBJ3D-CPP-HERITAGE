#include "SickDog.h"

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
