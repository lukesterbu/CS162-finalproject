/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Gun class definition
**********************************************************************/

#include "Gun.hpp"
#include "Character.hpp"

// until everything works gun should have unlimited ammo

Gun::Gun()
{
	type = "Gun";
	gunDmg = 25;
}

Gun::~Gun()
{}

void Gun::use(Character* person)
{
	person->setDamage(gunDmg);	
}
