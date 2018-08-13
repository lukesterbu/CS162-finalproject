/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Cure class declaration
**********************************************************************/

#ifndef CURE_HPP
#define CURE_HPP

#include "Items.hpp"
#include "Character.hpp"

class Cure : public Items
{
	private:
	public:
		Cure();
		~Cure();
		void use(Character*);
};

#endif
