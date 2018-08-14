/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Ammo class definition
**********************************************************************/

#include "Ammo.hpp"

Ammo::Ammo()
{
	type = "Ammo";
}

Ammo::~Ammo()
{
	delete this;
}

void Ammo::use(Character* person)
{
	
}
