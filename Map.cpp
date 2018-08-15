/***************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: Map class definition. Prints out the game map.
***************************************************************/

#include "Map.hpp"
#include "Space.hpp"
#include "Ocean.hpp"
#include "Desert.hpp"
#include "City.hpp"
#include "Jungle.hpp"
#include "inputValidation.hpp"
#include "Character.hpp"
#include "Player.hpp"
#include "Zombie.hpp"

#include <iostream>

using std::cout;
using std::endl;

Map::Map()
{
	days = 20;
	rows = 3;
	cols = 3;
	int startRow = 1; // sets player's start row
	int startCol = 1; // sets player's start col

	// Create the main player
	player = new Player(startRow, startCol);

	// Create the Biome Board
	spaceBoard = new Space**[rows];
	for (int row = 0; row < rows; row++)
		spaceBoard[row] = new Space*[cols];

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			// can put ifs here to make terrain different
			Space* temp = new City;
			spaceBoard[row][col] = temp;
		}
	}
	// Create the character Board
	charBoard = new Character**[rows];
	for (int row = 0; row < rows; row++)
		charBoard[row] = new Character*[cols];

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			Character* temp = new Character;
			charBoard[row][col] = temp;
		}
	}
	// Place the player on the board
	charBoard[startRow][startCol] = player;
}

Map::~Map()
{	
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			delete spaceBoard[row][col];
			delete charBoard[row][col];
		}
	}  
}

void Map::startGame()
{
	cout << "                   THE CURE" << endl << endl;
	cout << "Description: A terrible disease caused by a " << endl;
	cout << "meteorite has spread across the globe. This " << endl;
	cout << "disease has turned 30% of the human population" << endl;
	cout << "into zombies. Another 65% were immediately " << endl;
	cout << "wiped out. The remaining 5% is all that remains" << endl;
	cout << "of the human race. You have been tasked by the" << endl; 
	cout << "last remaining human civilization to find a cure." << endl;
	cout << "Without a cure the rest of the camp will turn in" << endl;
	cout << days << " days." << endl << endl;
	cout << "Directions: There are four different biomes:" << endl;
	cout << "City, Jungle, Ocean, and Desert. The Player " << endl;
	cout << "must traverse the map to find the cure while" << endl;
	cout << "either fighting or avoiding zombies. There are" << endl;
	cout << "five items that can be used throughout the " << endl;
	cout << "game: Bandages, Shields, Gun, Ammo, and the" << endl;
	cout << "Cure. You can only carry 5 items (each item" << endl;
	cout << "picked up counts as 1 of the 5). You start " << endl;
	cout << "with 100 hp, 0 shields, and do 5 damage." << endl; 
	cout << "Zombies have 25 hp and do 5 damage. The Gun" << endl;
	cout << "will allow you to do 25 damage. Bandages heal" << endl;
	cout << "15 hp and Shields add 50 to your shields." << endl << endl; 
	
	int day = 1;
	
	// checks to make sure day limit hasn't been reached
	// checks to make sure player is still alive
	while (day <= days && player->getHp() > 0)
	{
		int choice = 0;

		cout << "DAY " << day << endl << endl;
		printMap(); // prints the map
		// Inv. Mgmt or Move	
		do
		{
			cout << "Choose an option:" << endl;
			cout << "1. Inventory Management" << endl;
			cout << "2. Move" << endl;
			choice = inputValidation(2);
			if (choice == 1)
				player->openBag();
		} while (choice == 1);
		// Once out of do while loop ask user to move
		player = player->move(charBoard, rows, cols);
		triggerEvent();
		day++;
	} 
	if (player->getHp() <= 0)
		cout << "You died!" << endl;
	if (day > days)
		cout << "You ran out of time!" << endl;
	cout << "GAME OVER" << endl;
}

void Map::triggerEvent()
{
	int x = player->getMoveRow();
	int y = player->getMoveCol();

	spaceBoard[x][y]->event(player);
}

void Map::printMap()
{
	cout << "BIOME MAP" << endl;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{	
			cout << spaceBoard[row][col]->getLetter() << ' ';
		}
		cout << endl;
	}
	cout << endl;

	cout << "PLAYER MAP" << endl;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			cout << charBoard[row][col]->getLetter() << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
