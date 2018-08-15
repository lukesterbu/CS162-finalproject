/*******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: Jungle class declaration
*******************************************************************/

#ifndef JUNGLE_HPP
#define JUNGLE_HPP

#include "Space.hpp"

class Jungle : public Space
{
	private:
	public:
		Jungle();
		~Jungle();
		void event(Character*);
};

#endif
