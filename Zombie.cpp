/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Zombie class declaration
**********************************************************************/

#include "Zombie.hpp"

Zombie::Zombie()
{
	damage = 15;
	shield = 0;
	hp = 25;
	type = "Zombie";
	letter = 'z';
	maxHp = 25;
	maxShield = 0;
	minHp = 0;
	minShield = 0;
}

Zombie::~Zombie()
{

}
