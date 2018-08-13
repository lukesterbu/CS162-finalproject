/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Shield class definition
**********************************************************************/

#include "Shield.hpp"

Shield::Shield()
{
	shield = 50;
}

Shield::~Shield()
{

}

void Shield::use(Character* person)
{
	person->setShield(shield);
}
