/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Zombie class declaration
**********************************************************************/

#include "Zombie.hpp"

Zombie::Zombie()
{
	damage = 10;
	range = 1;
	shield = 0;
	hp = 25;
	infected = true;
	type = "Zombie";
	letter = 'z';
	maxHp = 25;
	maxShield = 0;
	maxAmmo = 0;
	minHp = 0;
	minShield = 0;
	minAmmo = 0;
}

Zombie::~Zombie()
{

}
