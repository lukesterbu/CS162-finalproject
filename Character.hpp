/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Character class declaration
**********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Items;

#include <string>

class Character
{
	protected:
		int damage; // damage
		int shield; 
		int hp; // hit points
		bool infected; // true if infected false otherwise
		std::string type; // used for character name
		char letter;
		int maxHp;
		int maxShield;
		int minHp;
		int minShield;
		int moveRow; // used for movement
		int moveCol; // used for movement
	public:
		Character();
		~Character();
		virtual int attack();
		virtual int defense(int);
		virtual Character* move(Character***, int, int);
		void setDamage(int); // used if gun is found
		void setShield(int);
		int getShield();
		void setHp(int);
		int getHp();
		std::string getType(); // returns type
		char getLetter();
		int getMaxHp();
		int getMaxShield();
		int getMoveRow();
		int getMoveCol();
		virtual void addToBag(Items*); // need for Player
		virtual bool isBagFull(); // need for Player
		virtual void openBag(); // need for Player
};

#endif
