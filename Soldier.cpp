#include "Soldier.h"

Soldier::Soldier(const string& _name, const int _life,Weapon* _currentWeapon)
{
	name = _name;
	life = _life;
	currentWeapon = _currentWeapon;
	weapons = nullptr;
	weaponsSize = 0;
}

Soldier::Soldier(const string& _name, const int _life, Weapon* _currentWeapon,
	Weapon** _weapons, const u_int& _weaponsSize)
	: Soldier(_name, _life, _currentWeapon)
{
	weapons = _weapons;
	weaponsSize = _weaponsSize;
}

Soldier::~Soldier()
{
	for (u_int _i = 0; _i < weaponsSize; _i++)
	{
		delete weapons[_i];
	}

	delete currentWeapon;
	delete[] weapons;
}


bool Soldier::ShootWithWeapon(Soldier*& _receiver)
{
	return _receiver->ReceiveDamage(this, currentWeapon->Shoot());
}

bool Soldier::ReceiveDamage(Soldier* _attacker, const float _damage)
{
	life -= _damage;
	if (life <= 0)
	{
		Death(_attacker);
		return true;
	}
	return false;
}

void Soldier::AddWeapon(Weapon* _weapon)
{
	if (_weapon)
	{
		Weapon** _tempWeapons = new Weapon * [weaponsSize + 1];
		for (u_int _i = 0; _i < weaponsSize; _i++)
		{
			_tempWeapons[_i] = weapons[_i];
		}

		_tempWeapons[weaponsSize] = _weapon;
		delete weapons;
		weapons = _tempWeapons;
		weaponsSize++;
	}
}

void Soldier::SetCurrentWeapon(const u_int& _weaponIndex)
{
	if (IsValidWeaponIndex(_weaponIndex))
	{
		Weapon** _tempWeapons = new Weapon * [weaponsSize - 1];
		bool _isSkipped = false;
		for (u_int _i = 0; _i < weaponsSize; _i++)
		{
			if (_i == _weaponIndex)
			{
				currentWeapon = weapons[_i];
				_isSkipped = true;
				continue;
			}
			_tempWeapons[_i - _isSkipped] = weapons[_i];
		}

		delete weapons;
		weapons = _tempWeapons;
		weaponsSize--;
	}
}

void Soldier::Death(Soldier*& _attacker)
{
	_attacker->AddWeapon(DropWeapon());
	delete this;
}

Weapon* Soldier::RunAway()
{
	return DropWeapon();
}

Weapon* Soldier::DropWeapon()
{
	if (RandomInt(10, 1) > 7)
	{
		Weapon* _weapon = currentWeapon;
		currentWeapon = nullptr;
		return _weapon;
	}
	return nullptr;
}

string Soldier::ToString() const
{
	const string _ammoShow = to_string(currentWeapon->GetCurrentAmmo()) + "/" + to_string(currentWeapon->GetMaxAmmo());
	
	return "[" + name + "] \n" +
		GREEN + "\t[HP] " + to_string(life) + RESET + "\n" +
		"\t[Weapon] " + currentWeapon->GetName() + " " + _ammoShow ;
}


bool Soldier::IsValidWeaponIndex(const u_int _weaponIndex)
{
	return _weaponIndex >= 0 && _weaponIndex < weaponsSize;
}