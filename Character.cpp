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
	// incorporate range and damage here
}
// Calculates damage done
int Character::defense(int attack)
{
	int overShield = 0;
	// check shield and then hp
	if (attack > shield)
	{
		overShield = attack - shield;
		setShield(minShield);
	}
	else if (attack <= shield)
		setShield(shield - attack);
	
	// apply remainder to hp
	setHp(hp - overShield);
}

int Character::move()
{
	
}
// used if gun is found
void Character::setDamage(int damage)
{
	this->damage = damage;
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
