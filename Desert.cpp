/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description:	Desert class definition
******************************************************************/

#include "Desert.hpp"

#include <iostream>

Desert::Desert()
{
	letter = 'D';
	events = 1;
}

Desert::~Desert()
{}
// player loses 10 health due to heat
void Desert::event(Character* player)
{
	// if the event hasn't happened yet
	if (events == 1)
	{
		events--; // decrement so event doesn't happen
		cout << "The heat is excruciating." << endl;
		cout << "You lose 10 health!" << endl;
		player->setHp(player->getHp() - 10);
	}
	else if (events == 0)
		cout << "The event already happened here!" << endl;
}
