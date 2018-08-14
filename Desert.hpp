/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: Desert class declaration
******************************************************************/

#ifndef DESERT_HPP
#define DESERT_HPP

#include "Space.hpp"

class Desert : public Space
{
	private:
	public:
		Desert();
		~Desert();
		void event();
};

#endif
