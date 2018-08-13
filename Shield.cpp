/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Shield class definition
**********************************************************************/

#include "Shield.hpp"

Shield::Shield()
{
	type = "Shield";
	shield = 50;
}

Shield::~Shield()
{
	delete (*this);
}
// Uses a shield to increase character's shield
void Shield::use(Character* person)
{
	int currentShield = person.getShield();
	
	if ((currentShield + shield) >= person.getMaxShield())
		person->setShield(person.getMaxShield());
	else
		person->setShield(currentShield + shield);
}
