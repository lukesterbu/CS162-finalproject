/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Player class declaration
**********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include "Items.hpp"

#include <vector>

class Player : public Character
{
	private:
		int maxHp;
		int maxShield;
		int maxAmmo;
		int minHp;
		int minShield;
		int minAmmo;
		std::vector<Items*> backpack;
	public:
		Player();
		~Player();
};

#endif
