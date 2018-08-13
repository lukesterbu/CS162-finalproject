/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Bandage class definition
**********************************************************************/

#include "Bandage.hpp"

Bandage::Bandage()
{
	int heal = 15;
}

Bandage::~Bandage()
{}

void Bandage::use(Character* person)
{
	int currentHp = person.getHp();
	
	if ((currentHp + heal) > maxHp)
		person->setHp(maxHp)
	else
		person->setHp(currentHp + heal);
}
