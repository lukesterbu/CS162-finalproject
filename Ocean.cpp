/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: Ocean class definition
******************************************************************/

class Item; // forward declaration

#include "Shield.hpp"
#include "Ocean.hpp"

#include <iostream>

using std::cout;
using std::endl;

Ocean::Ocean()
{
	letter = 'O';
	events = 1;
}

Ocean::~Ocean()
{}
// player finds a shield
void Ocean::event(Character* player)
{
	// if the event hasn't happened yet and the bag isn't full
	if (events == 1 && !(player->isBagFull()))
	{
		events--; // decrement so event doesn't happen
		Items* shield = new Shield;
		cout << "You found a shield!" << endl;
		player->addToBag(shield);
	}
	else if (events == 0)
		cout << "The event already happened here!" << endl;
}
