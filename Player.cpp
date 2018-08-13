/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Player class declaration
**********************************************************************/

#include "Character.hpp"

Player::Player()
{
	atkDie = 0;
	defDie = 0;
	atkNum = 0;
	defNum = 0;
	shield = 0;
	hp = 100;
	infected = false;
	type = "Player";
}

Player::~Player()
{

}
