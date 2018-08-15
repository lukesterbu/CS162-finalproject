/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: Ocean class declaration
******************************************************************/

#ifndef OCEAN_HPP
#define OCEAN_HPP

#include "Space.hpp"

class Ocean : public Space
{
	private:
	public:
		Ocean();
		~Ocean();
		void event(Character*);
};

#endif
