/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Shield class declaration
**********************************************************************/

#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "Items.hpp"
#include "Character.hpp"

class Shield : public Items
{
	private:
	public:
		Shield();
		~Shield();
		void use(Character*);
};

#endif
