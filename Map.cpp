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
	// 17 long and 20 wide
	spaceBoard = new Space**[rows];
	for (int row = 0; row < rows; row++)
		spaceBoard[row] = new Space*[cols];

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			Space* temp = new Jungle;
			spaceBoard[row][col] = temp;
		}
	}
	
	charBoard = new Character**[rows];
	for (int row = 0; row < rows; row++)
		charBoard[row] = new Character*[cols];

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			Character* temp = new Zombie;
			charBoard[row][col] = temp;
		}
	}
	charBoard[0][0] = new Player;
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
	cout << "Cure. You start with 100 hp, 0 shields, and" << endl;
	cout << "do 5 damage. Zombies have 25 hp and do 5 " << endl;
	cout << "damage. The Gun will allow you to do 25 " << endl; 
	cout << "damage. Bandages heal 15 hp and Shields add" << endl;
	cout << "50 to your shields." << endl << endl; 
	printMap();
	userInput(); 
}

void Map::userInput()
{
	int choice = 0;
	cout << "Choose a direction to move in:" << endl;
	cout << "1. Up" << endl;
	cout << "2. Left" << endl;
	cout << "3. Right" << endl;
	cout << "4. Down" << endl;
	choice = inputValidation(4);

	
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
