/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Abstract Character class declaration
**********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
//might want to just use character class from project3
class Character
{
	protected:
		int hp;
		int shield;
	public:
		Character();
		~Character();
		virtual void attack() = 0;
		virtual void defend() = 0;
};

#endif
