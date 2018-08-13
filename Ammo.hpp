/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Ammo class declaration
**********************************************************************/

#ifndef AMMO_HPP
#define AMMO_HPP

#include "Items.hpp"
#include "Character.hpp"

class Ammo : public Items
{
	private:
	public:
		Ammo();
		~Ammo();
		void use(Character*);
};

#endif
