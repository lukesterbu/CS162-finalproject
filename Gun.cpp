/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Gun class definition
**********************************************************************/

#include "Gun.hpp"
#include "Character.hpp"

Gun::Gun()
{
	gunDmg = 25;
}

Gun::~Gun()
{}

void Gun::use(Character* person)
{
	person->setDamage(gunDmg);	
}
