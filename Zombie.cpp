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
}

Zombie::~Zombie()
{

}
