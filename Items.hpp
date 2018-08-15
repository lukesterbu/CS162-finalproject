/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description: Abstract Items class declaration
**********************************************************************/

#ifndef ITEMS_HPP
#define ITEMS_HPP

class Character;

#include <string>

class Items
{
	protected:
		std::string type;
	public:
		Items();
		~Items();
		virtual bool use(Character*) = 0;
		std::string getType();
};

#endif
