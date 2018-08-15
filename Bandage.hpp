/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Potion class declaration
**********************************************************************/

#ifndef BANDAGE_HPP
#define BANDAGE_HPP

#include "Items.hpp"
#include "Character.hpp"

class Bandage : public Items
{
	private:
		int bandage;
	public:
		Bandage();
		~Bandage();
		bool use(Character*);
};

#endif
