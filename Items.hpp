/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description: Abstract Items class declaration
**********************************************************************/

#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>

class Items
{
	protected:
		std::string type;
	public:
		Items();
		~Items();
		virtual void use() = 0;
		std::string getType();
};

#endif
