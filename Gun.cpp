/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Gun class definition
**********************************************************************/

#include "Gun.hpp"
#include "Character.hpp"

Gun::Gun()
{
	type = "Gun";
	gunDmg = 25;
}

Gun::~Gun()
{
	delete this;
}

bool Gun::use(Character* person)
{
	person->setDamage(gunDmg);	
}
