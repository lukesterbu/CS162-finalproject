/***********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Character class definition
***********************************************************************/

#include "Character.hpp"

using std::string;

Character::Character()
{
	atkDie = 0;
	defDie = 0;
	atkNum = 0;
	defNum = 0;
	shield = 0;
	hp = 0;
	type = "Character";
}

Character::~Character()
{}

int Character::attack()
{
	int attack = 0;
	for (int i = 0; i < atkDie; i++)
	{
		attack += rand() % (atkNum - 1 + 1) + 1;
	}
	return attack;
}
// Calculates damage done
int Character::defense(int attack)
{
	int defense = 0;
	int difference = 0;
	for (int i = 0; i < defDie; i++)
	{
		defense += rand() % (defNum - 1 + 1) + 1;
	}
	if ((defense + shield) >= attack)
		difference = 0;
	else
		difference = attack - defense - shield;
	
	setHp(difference);
	
	return defense;
}

int Character::getShield()
{
	return shield;
}
// Doesn't let strength go below 0
void Character::setHp(int difference)
{
	if (hp - difference < 0)
		hp = 0;
	else 
		hp -= difference;
}

int Character::getHp()
{
	return hp;
}

string Character::getType()
{
	return type;
}
