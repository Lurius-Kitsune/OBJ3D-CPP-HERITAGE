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
	do
	{
		const u_int _choice = SelectPlayerAction();
		if (_choice == -1)
		{
			break;
		}
		DoAction(_choice, player, ennemy);
		system("pause");
		DoAction(RandomInt(3, 0), ennemy, player);
	} while (player && ennemy);
}

void GameWar::DisplayGameStatus()
{
	DISPLAY(player->ToString(), true);
	SPACE;
	DISPLAY(ennemy->ToString(), true);
}


u_int GameWar::SelectPlayerAction()
{
	const string _actions[] =
	{
		player->GetCurrentWeapon() ? "Tirer" : "Coup de poing",
		"Fuir",
		"Recharger",
		"Jeter l'arme",
		"Quitter"
	};
	int _choiceIndex = 0, _actionsSize = size(_actions);
	PlayerChoice(_actions, _choiceIndex, _actionsSize);
	return _choiceIndex == _actionsSize - 1 ? -1 : _choiceIndex;
}

void GameWar::SpawnEnnemy()
{
	const string _names[] =
	{
		GREEN "Marguerite" RESET,
		BLUE "Marguerite � casquette" RESET,
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

void GameWar::DoAction(const u_int& _choice, Soldier*& _soldierTurn, Soldier*& _target)
{
	switch (_choice)
	{
	case 0:
		_soldierTurn->ShootWithWeapon(_target);
		break;
	case 1:
		DISPLAY("[Fuite]" + _soldierTurn->GetName() + " a fuit !", true);
		_soldierTurn->RunAway();
		_soldierTurn = nullptr;
		break;
	case 2:
		_soldierTurn->Reload();
		break;
	case 3:
		if (_soldierTurn->DropWeapon())
		{
			DISPLAY("OOPS J'AI GLISSER", true);
		}
		break;
	default:
		break;
	}
}

void GameWar::PlayerChoice(const string* _choices, int& _choiceIndex, const u_int& _maxChoice)
{
	bool _isChoiceMade = false;
	SPACE;
	do
	{
		u_int _input = 0;
		DisplayGameStatus();
		// Faire le choix avec des fleche du clavier et entr�e pour valider
		SPACE;
		DISPLAY("==========ACTION==========", true);
		for (u_int _i = 0; _i < _maxChoice; _i++)
		{
			if (_i == _choiceIndex)
			{
				DISPLAY(YELLOW "-> " + _choices[_i] + RESET, true);
			}
			else
			{
				DISPLAY(_choices[_i], true);
			}
		}
		DISPLAY("==========================", true);
		// Attendre une touche
		_input = _getch();

		// Si la touche est entr�e, alors _isChoiceMade = true
		switch (_input)
		{
		case 13:
			_isChoiceMade = true;
			break;
		// Si la touche est fleche du haut, alors _choiceIndex--
		case 72:
			_choiceIndex--;
			// Si _choiceIndex < 0, alors _choiceIndex = _maxChoice-1 (car tableau)
			if (_choiceIndex < 0)
			{
				_choiceIndex = _maxChoice-1;
			}
			break;
		// Si la touche est fleche du bas, alors _choiceIndex++
		case 80:
			_choiceIndex++;
			if (_choiceIndex >= _maxChoice)
			{
				_choiceIndex = 0; // on retourne en haut
			}
			break;
		default:
			break;
		}

		
	
		_kbhit();
		CLEAR_SCREEN;
	} while (!_isChoiceMade);
	
	
}



