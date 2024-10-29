#pragma once
#include "Soldier.h"
class GameWar
{
	Soldier* player;
	Soldier* ennemy;

public:
	GameWar() = default;

	GameWar(const string& _name, const int _life, Weapon* _currentWeapon);
	GameWar(const string& _name, const int _life, Weapon* _currentWeapon,
		Weapon** _weapons, const u_int& _weaponsSize);

public: 
	void LaunchGame();


private: 
	void SpawnEnnemy();
};

