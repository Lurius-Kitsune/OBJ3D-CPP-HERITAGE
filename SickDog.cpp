#include "SickDog.h"

void SickDog::Bark()
{
	Dog::Bark(); // Demarquage !
	DISPLAY("BARRK.. BWERKKK/...", true);
}

void SickDog::Sleep()
{
	DISPLAY("Je suis malade chef !", true);
}
