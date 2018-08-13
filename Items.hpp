/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description: Abstract Items class declaration
**********************************************************************/

#ifndef ITEMS_HPP
#define ITEMS_HPP

class Items
{
	protected:
		int maxHp = 100;
		int maxShield = 100;
		int maxAmmo = 1000;
		int minHp = 0;
		int minShield = 0;
		int minAmmo = 0;
	public:
		Items();
		~Items();
		virtual void use() = 0;
};

#endif
