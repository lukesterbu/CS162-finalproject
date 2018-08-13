/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Player class declaration
**********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include "Items.hpp"

class Player : public Character
{
	private:
		vector<Items*> backpack;
	public:
		Player();
		~Player();
};

#endif
