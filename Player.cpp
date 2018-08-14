/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Player class declaration
**********************************************************************/

#include "Player.hpp"

Player::Player()
{
	damage = 5;
	range = 1;
	shield = 0;
	hp = 100;
	infected = false;
	type = "Player";
	letter = '*';
	maxHp = 100;
	maxShield = 100;
	maxAmmo = 1000;
	minHp = 0;
	minShield = 0;
	minAmmo = 0;
}

Player::~Player()
{

}

// maybe pass board object here
void Player::move()
{
	
}
