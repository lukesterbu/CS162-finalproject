/***********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Character class definition
***********************************************************************/

#include "Character.hpp"

using std::string;

Character::Character()
{
	damage = 0;
	range = 0;
	shield = 0;
	hp = 0;
	infected = false;
	type = "Character";
	maxHp = 0;
	maxShield = 0;
	maxAmmo = 0;
	minHp = 0;
	minShield = 0;
	minAmmo = 0;
}

Character::~Character()
{}

int Character::attack()
{
	
}
// Calculates damage done
int Character::defense()
{
	
}
// Doesn't let shield go below min or above max
void Character::setShield(int shield)
{
	if (shield >= maxShield)
		this->shield = maxShield;
	else if (shield <= minShield)
		this->shield = minShield;
	else
		this->shield = shield;
}

int Character::getShield()
{
	return shield;
}
// Doesn't let hp go below min or above max
void Character::setHp(int hp)
{
	if (hp >= maxHp)
		this->hp = maxShield;
	else if (hp <= minHp)
		this->hp = minHp;
	else
		this->hp = hp;
}

int Character::getHp()
{
	return hp;
}

string Character::getType()
{
	return type;
}
