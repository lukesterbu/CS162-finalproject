/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Gun class declaration
**********************************************************************/

#ifndef GUN_HPP
#define GUN_HPP

#include "Items.hpp"
#include "Character.hpp"

class Gun : public Items
{
	private:
		int gunDmg; // gun damage
	public:
		Gun();
		~Gun();
		bool use(Character*);
};

#endif
