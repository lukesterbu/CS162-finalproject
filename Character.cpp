/***********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description: Abstract class Character definition
***********************************************************************/

#include "Character.hpp"

using std::cout;
using std::endl;
using std::string;

Character::Character()
{
	atkDie = 0;
	defDie = 0;
	atkNum = 0;
	defNum = 0;
	armor = 0;
	strength = 0;
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
	if ((defense + armor) >= attack)
		difference = 0;
	else
		difference = attack - defense - armor;
	
	setStrength(difference);
	
	return defense;
}

int Character::getArmor()
{
	return armor;
}
// Doesn't let strength go below 0
void Character::setStrength(int difference)
{
	if (strength - difference < 0)
		strength = 0;
	else 
		strength -= difference;
}

int Character::getStrength()
{
	return strength;
}

string Character::getType()
{
	return type;
}
