/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Bandage class definition
**********************************************************************/

#include "Bandage.hpp"

Bandage::Bandage()
{
	type = "Bandage";
	bandage = 15;
}

Bandage::~Bandage()
{
	delete this;
}
// Uses a bandage to increase character's health
void Bandage::use(Character* person)
{
	int currentHp = person->getHp();
	
	if ((currentHp + bandage) >= person->getMaxHp())
		person->setHp(person->getMaxHp());
	else
		person->setHp(currentHp + bandage);
}
