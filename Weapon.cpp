#include "Weapon.h"

Weapon::Weapon()
{
	name = "Unknown";
	maxAmmo = 0;
	currentAmmo = 0;
	bulletPerShot = 0;
	damagePerShot = 0;
	magazine = 0;
	maxMagazine = 0;
}

Weapon::Weapon(const string& _name, const u_int& _maxAmmo, const u_int& _bulletPerShot,
	const u_int& _damagePerShot, const u_int& _maxMagazine)
{
	name = _name;
	maxAmmo = _maxAmmo;
	currentAmmo = _maxAmmo;
	bulletPerShot = _bulletPerShot;
	damagePerShot = _damagePerShot;
	magazine = _maxMagazine;
	maxMagazine = _maxMagazine;
}


int Weapon::Shoot()
{
	if (currentAmmo <= 0)
	{
		currentAmmo -= bulletPerShot;
		return damagePerShot * (currentAmmo < bulletPerShot ? currentAmmo : bulletPerShot);
	}
	return 0;
}

void Weapon::Reload()
{
	if (magazine <= 0)
	{
		const u_int& _ammoDiff = maxAmmo - currentAmmo;
		if (_ammoDiff < magazine)
		{
			currentAmmo = magazine;
			magazine = 0;
		}
		else
		{
			currentAmmo = maxAmmo;
			magazine -= _ammoDiff;
		}
	}
	DISPLAY("I NEED MORE BULLET", true);
}

void Weapon::AddOnMagazine(const u_int& _nbAmmoFound)
{
	magazine = _nbAmmoFound + magazine >= maxMagazine ? maxMagazine : _nbAmmoFound + magazine;
}
