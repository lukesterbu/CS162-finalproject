/***********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Character class definition
***********************************************************************/

#include "Character.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

Character::Character()
{
	damage = 0;
	shield = 0;
	hp = 0;
	type = "Character";
	letter = ' ';
	maxHp = 0;
	maxShield = 0;
	minHp = 0;
	minShield = 0;
}

Character::~Character()
{}

int Character::attack(Character* other)
{
	// calls defense function
	other->defense(this->damage);
	cout << this->type << " attacked the " << other->type 
	<< "." << endl;
	cout << "The " << other->type << " now has " << other->hp 
	<< " hp." << endl;
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

Character* Character::move(Character*** board, int rows, int cols)
{}
// used if gun is found
void Character::setDamage(int damage)
{
	this->damage = damage;
}

int Character::getDamage()
{
	return damage;
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

char Character::getLetter()
{
	return letter;
}

int Character::getMaxHp()
{
	return maxHp;
}

int Character::getMaxShield()
{
	return maxShield;
}

int Character::getMoveRow()
{
	return moveRow;
}

int Character::getMoveCol()
{
	return moveCol;
}

void Character::addToBag(Items* item)
{}

bool Character::isBagFull()
{}

bool Character::openBag()
{}		
