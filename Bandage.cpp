/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Bandage class definition
**********************************************************************/

#include "Bandage.hpp"

#include <iostream>

using std::cout;
using std::endl;

Bandage::Bandage()
{
	type = "Bandage";
	bandage = 5;
}

Bandage::~Bandage()
{
	delete this;
}
// Uses a bandage to increase character's health
// Returns true if able to use
bool Bandage::use(Character* person)
{
	int currentHp = person->getHp();
	
	if (currentHp >= person->getMaxHp())
	{
		cout << "Your health was already full!" << endl;
		return false;
	}
	else if ((currentHp + bandage) >= person->getMaxHp())
	{
		person->setHp(person->getMaxHp());
		cout << "Your health is now full!" << endl;
		return true;
	}
	else
	{	
		person->setHp(currentHp + bandage);
		return true;
	}
}
