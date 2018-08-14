/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: City class declaration
******************************************************************/

#ifndef CITY_HPP
#define CITY_HPP

#include "Space.hpp"

class City : public Space
{
	private:
	public:
		City();
		~City();
		void event();
};

#endif
