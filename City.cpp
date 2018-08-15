/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: City class definition
******************************************************************/

class Item; // forward declaration

#include "Bandage.hpp" // for new bandage
#include "Gun.hpp" // for new gun
#include "City.hpp"

#include <iostream>
#include <cstdlib> // random

using std::cout;
using std::endl;

City::City()
{
	letter = 'C';
	events = 1;
}

City::~City()
{}
// player finds a bandage
void City::event(Character* player)
{
	int chance = rand() % 10 + 1; // between 1 and 10
	
	if (num <= 8) // 80% chance of finding a bandage
	{
		// if the event hasn't happened yet and the bag isn't full
		if (events == 1 && !(player->isBagFull()))
		{
			events--; // decrement so event doesn't happen
			Items* bandage = new Bandage;
			cout << "You found a bandage!" << endl;
			player->addToBag(bandage);
		}
		else if (events == 0)
			cout << "The event already happened here!" << endl;
	}
	else // 20% chance of finding a gun
	{
		// if the event hasn't happened yet and the bag isn't full
		if (events == 1 && !(player->isBagFull()))
		{
			events--; // decrement so event doesn't happen
			Items* gun = new Gun;
			cout << "You found a Gun!" << endl;
			player->addToBag(gun);
		}
		else if (events == 0)
			cout << "The event already happened here!" << endl;
	}
}
