/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Potion class declaration
**********************************************************************/

#ifndef BANDAGE_HPP
#define BANDAGE_HPP

#include "Items.hpp"

class Bandage : public Items
{
	private:
		int hp;
	public:
		Bandage();
		~Bandage();
		void move();
};

#endif
