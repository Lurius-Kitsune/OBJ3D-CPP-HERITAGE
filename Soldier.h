#pragma once
#include "Weapon.h"
#include "Random.h"
class Soldier
{
	string name;
	float life;
	Weapon* currentWeapon;
	Weapon** weapons;
	u_int weaponsSize;


public:
	Soldier() = default;

	Soldier(const string& _name, const int _life, Weapon* _currentWeapon);
	Soldier(const string& _name, const int _life, Weapon* _currentWeapon, Weapon** _weapons, const u_int& _weaponsSize);
	~Soldier();
public:
	bool ShootWithWeapon(Soldier*& _receiver);
	bool ReceiveDamage(Soldier* _attacker, const float _damage);
	void AddWeapon(Weapon* _weapon);
	void SetCurrentWeapon(const u_int& _weaponIndex);
	Weapon* RunAway();
	Weapon* DropWeapon();

	string ToString()const;
private:
	void Death(Soldier*& _attacker);
	bool IsValidWeaponIndex(const u_int _weaponIndex);
};

