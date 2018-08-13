/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description: Abstract Items class declaration
**********************************************************************/

#ifndef ITEMS_HPP
#define ITEMS_HPP

class Items
{
	private:
	public:
		Items();
		~Items();
		virtual void use() = 0;
};

#endif
