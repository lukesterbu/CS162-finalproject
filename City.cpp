/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: City class definition
******************************************************************/

class Item;

#include "Bandage.hpp"
#include "City.hpp"

#include <iostream>

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
