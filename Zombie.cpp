/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Zombie class declaration
**********************************************************************/

#include "Zombie.hpp"

Zombie::Zombie()
{
	atkDie = 0;
	defDie = 0;
	atkNum = 0;
	defNum = 0;
	shield = 0;
	hp = 25;
	infected = true;
	type = "Zombie";
	maxHp = 0;
	maxShield = 0;
	maxAmmo = 0;
	minHp = 0;
	minShield = 0;
	minAmmo = 0;
}

Zombie::~Zombie()
{

}
