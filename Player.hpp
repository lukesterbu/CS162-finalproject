/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Player class declaration
**********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include "Items.hpp"

#include <vector>

class Player : public Character
{
	private:
		int bagSize; // max size of bag
		std::vector<Items*> bag; // holds items
	public:
		Player(int, int);
		// moveRow, moveCol, bag, shield, hp, damage params
		Player(int, int, std::vector<Items*>, int, int, int);
		~Player();
		Character* move(Character***, int, int);
		void addToBag(Items*); // add items to bag
		bool isBagFull(); // checks if bag is full
		bool openBag(); // view bag
};

#endif
