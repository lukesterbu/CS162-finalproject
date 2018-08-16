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

#include <iostream> // i/o
#include <cstdlib> // random
#include <ctime> // time

using std::cout;
using std::endl;

Map::Map()
{
	srand(time(0)); // used for random functions
	days = 20;
	rows = 10;
	cols = 10;
	int startRow = rows - 1; // sets player's start row
	int startCol = cols / 2; // sets player's start col
	int cureRow = 0; // cure row
	int cureCol = rand() % (cols - 1); // cure col
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
			// to make terrain random
			int type = rand() % 3 + 1;
			Space* temp;			
			if (type == 1) // city
				temp = new City;
			else if (type == 2) // ocean
				temp = new Ocean;
			else if (type == 3) // desert
				temp = new Desert;
			spaceBoard[row][col] = temp;
		}
	}
	
	// make a random space have the Cure
	delete spaceBoard[cureRow][cureCol];
	spaceBoard[cureRow][cureCol] = new Jungle;
	
	// loop to link spaces
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (row >= 1) // set top
				spaceBoard[row][col]->setTop(spaceBoard[row - 1][col]);
			else
				spaceBoard[row][col]->setTop(nullptr);
			if (row < (rows - 1)) // set bottom
				spaceBoard[row][col]->setBottom(spaceBoard[row + 1][col]);
			else
				spaceBoard[row][col]->setBottom(nullptr);
			if (col >= 1) // set left
				spaceBoard[row][col]->setLeft(spaceBoard[row][col - 1]);
			else
				spaceBoard[row][col]->setLeft(nullptr);
			if (col < (cols - 1)) // set right
				spaceBoard[row][col]->setRight(spaceBoard[row][col + 1]);
			else
				spaceBoard[row][col]->setRight(nullptr);
		}
	}
	
	// Create the character Board and place some zombies
	charBoard = new Character**[rows];
	for (int row = 0; row < rows; row++)
		charBoard[row] = new Character*[cols];

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			int chance = rand() % 3 + 1;
			Character* temp; 
			if (chance == 1)
				temp = new Zombie;
			else if (chance == 2 || chance == 3)
				temp = new Character;
			else
				temp = new Character;
			charBoard[row][col] = temp;
		}
	}
	// Place the player on the board
	delete charBoard[startRow][startCol];
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
	cout << endl;
	cout << "THE CURE" << endl << endl;
	cout << "Description: A terrible disease caused by a meteorite has spread across the globe. This disease has turned 30% of the human population into zombies. Another 65% were immediately wiped out. The remaining 5% is all that remains of the human race. You have been tasked by the last remaining human civilization to find a cure. Without a cure the rest of the camp will turn in " << days << " days." << endl << endl;
	cout << "Directions: There are four different biomes: City(C), Jungle(J), Ocean(O), and Desert(D). The Player must traverse the map to find the cure while either fighting or avoiding zombies. Four items can be found throughout the game: Bandages, Shields, Gun, and the Cure. You can only carry 5 items(each item picked up counts as 1 of the 5). You start with 100 hp, 0 shields, and do 10 damage. Zombies have 25 hp and do 15 damage. The Gun will allow you to do 25 damage. Bandages heal 5 hp and Shields add 5 to your shields. Inventory Management opens your bag, Move/Attack moves if there is not a zombie in the desired space and attacks if there is, and Player details displays hp, shield, and damage. The Cure can be found on the space labeled J. Once it's in your inventory you must use it to win." << endl << endl;
	
	int day = 1;
	int choice = 0;	
	bool hasCure = false;
	// checks to make sure day limit hasn't been reached
	// checks to make sure player is still alive
	while (day <= days && player->getHp() > 0 && choice != 4
	&& !hasCure)
	{
		cout << "DAY " << day << endl << endl;
		printMap(); // prints the map
		// Inv. Mgmt or Move	
		do
		{
			cout << "Choose an option:" << endl;
			cout << "1. Inventory Management" << endl;
			cout << "2. Move/Attack" << endl;
			cout << "3. Player details" << endl;
			cout << "4. Exit Game" << endl;
			choice = inputValidation(4);
			if (choice == 1)
				hasCure = player->openBag();
			if (choice == 3)
			{
				cout << "Health: " << player->getHp() << endl;
				cout << "Shields: " << player->getShield() << endl;
				cout << "Damage: " << player->getDamage() << endl;
				cout << endl;
			}
		} while ((choice == 1 || choice == 3) && !hasCure);
		// Once out of do while loop ask user to move
		// Don't do these if user quits game
		if (choice != 4 && !hasCure)
		{
			player = player->move(charBoard, rows, cols);
			triggerEvent();
			day++;
		}
	} 
	if (player->getHp() <= 0)
		cout << "You died!" << endl;
	if (day > days)
		cout << "You ran out of time!" << endl;
	if (hasCure)
		cout << "You win!" << endl;
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
		for (int col = -1; col < cols + 1; col++)
		{	
			if (col == -1)
				cout << "| ";
			else if (col == cols)
				cout << "|";
			else
				cout << spaceBoard[row][col]->getLetter() << ' ';
		}
		cout << endl;
	}
	cout << endl;

	cout << "PLAYER MAP" << endl;
	for (int row = 0; row < rows; row++)
	{
		for (int col = -1; col < cols + 1; col++)
		{
			if (col == -1)
				cout << "| ";
			else if (col == cols)
				cout << "|";
			else
				cout << charBoard[row][col]->getLetter() << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
