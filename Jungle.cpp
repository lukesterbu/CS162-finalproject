/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: Jungle class definition
******************************************************************/

class Item; // forward declaration

#include "Cure.hpp"
#include "Jungle.hpp"

#include <iostream>

using std::cout;
using std::endl;

Jungle::Jungle()
{
	letter = 'J';
	events = 1;
}

Jungle::~Jungle()
{}
// has the cure
void Jungle::event(Character* player)
{
	// if the event hasn't happened yet and the bag isn't full
	if (events == 1 && !(player->isBagFull()))
	{
		events--; // decrement so event doesn't happen
		Items* cure = new Cure;
		cout << "You found the Cure!" << endl;
		player->addToBag(cure);
	}
	else if (events == 0)
		cout << "The event already happened here!" << endl;
}
