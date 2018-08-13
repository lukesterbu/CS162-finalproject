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
		int maxHp;
		int maxShield;
		int maxAmmo;
		int minHp;
		int minShield;
		int minAmmo;
	public:
		Items();
		~Items();
		virtual void use() = 0;
};

#endif
