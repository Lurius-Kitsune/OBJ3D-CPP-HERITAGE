#include "GameWar.h"

GameWar::GameWar(const string& _name, const int _life, Weapon* _currentWeapon)
{
	player = new Soldier(_name, _life, _currentWeapon);
	ennemy = nullptr;
}

GameWar::GameWar(const string& _name, const int _life, Weapon* _currentWeapon, Weapon** _weapons, const u_int& _weaponsSize)
{
	player = new Soldier(_name, _life, _currentWeapon, _weapons, _weaponsSize);
	ennemy = nullptr;
}

GameWar::~GameWar()
{
	delete player;
	delete ennemy;
}

void GameWar::LaunchGame()
{
	SpawnEnnemy();
	bool _wantToQuit = false;
	do
	{
		CLEAR_SCREEN;
		DISPLAY(player->ToString(),true);
		SPACE;
		DISPLAY(ennemy->ToString(), true);
		_wantToQuit = true;
	} while (player && !_wantToQuit);
}


void GameWar::SpawnEnnemy()
{
	const string _names[] =
	{
		GREEN "Marguerite" RESET,
		BLUE "Marguerite à casquette" RESET,
		PURPLE "Patrick" RESET
	};

	Weapon** _weapons = new Weapon*[3]
	{
		new Weapon("Katrina", 1, 1, 3, 20),
		new Weapon(RED "Thomatos" RESET, 1, 1, 2, 2),
	};

	Weapon* _weapon = new Weapon("AK-47", 30, 4, 2, 300);

	ennemy = new Soldier(_names[RandomInt(2, 0)], RandomInt(100, 50), _weapon, _weapons, 3);
}


