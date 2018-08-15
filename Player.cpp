/**********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Player class declaration
**********************************************************************/

#include "Player.hpp"
#include "inputValidation.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::vector;

Player::Player(int row, int col)
{
	damage = 5;
	shield = 0;
	hp = 100;

	infected = false;
	type = "Player";
	letter = '*';

	maxHp = 100;
	maxShield = 100;
	minHp = 0;
	minShield = 0;

	moveRow = row; // used for movement
	moveCol = col; // used for movement

	bagSize = 5;
	bag.resize(0);
}

Player::Player(int row, int col, vector<Items*> oldBag)
{	
	damage = 5;
	range = 1;
	shield = 0;
	hp = 100;

	infected = false;
	type = "Player";
	letter = '*';

	maxHp = 100;
	maxShield = 100;
	maxAmmo = 1000;
	minHp = 0;
	minShield = 0;
	minAmmo = 0;

	moveRow = row; // used for movement
	moveCol = col; // used for movement

	bagSize = 5;
	bag.resize(0);
	// copies contents of old bag
	for (int i = 0; i < oldBag.size(); i++)
		addToBag(oldBag[i]);
}

Player::~Player()
{
	delete this;
}

// maybe pass board object here
Character* Player::move(Character*** board, int rows, int cols)
{
	int direction = 0;
	cout << "Choose a direction to move in:" << endl;
	cout << "1. Up" << endl;
	cout << "2. Down" << endl;
	cout << "3. Left" << endl;
	cout << "4. Right" << endl;
	direction = inputValidation(4);

	// Up
	if (direction == 1 && moveRow >= 1)	
	{
		// move
		if (board[moveRow - 1][moveCol].getLetter() != "z")
		{
			moveRow--;
			board[moveRow][moveCol] = new Player(moveRow, moveCol, bag);
			delete board[moveRow + 1][moveCol];
			board[moveRow + 1][moveCol] = new Character();
			return board[moveRow][moveCol];
		}
		// attack
		else if (board[moveRow - 1][moveCol].getLetter() == "z")
		{
			// player attacks zombie
			board[moveRow][moveCol]->attack(board[moveRow - 1][moveCol]);
			// zombie attacks player
			board[moveRow - 1][moveCol]->attack(board[moveRow][moveCol]);
			// check to see if zombie died
			// Map checks to see if player died
			if (board[moveRow - 1][moveCol].getHp() == 0)
			{
				delete board[moveRow - 1][movCol];
				board[moveRow - 1][moveCol] = new Character();
			}
			// need to make sure damage carries over
			return board[moveRow][moveCol];
		}
	}
	// Down
	else if (direction == 2 && moveRow < (rows - 1))
	{
		// move
		if (board[moveRow + 1][moveCol].getLetter() != "z")
		{	
			moveRow++;
			board[moveRow][moveCol] = new Player(moveRow, moveCol, bag);
			delete board[moveRow - 1][moveCol];
			board[moveRow - 1][moveCol] = new Character();
			return board[moveRow][moveCol];
		}
		// attack
		else if (board[moveRow + 1][moveCol].getLetter() == "z")
		{
			// player attacks zombie
			board[moveRow][moveCol]->attack(board[moveRow + 1][moveCol]);
			// zombie attacks player
			board[moveRow + 1][moveCol]->attack(board[moveRow][moveCol]);
			// check to see if zombie died
			// Map checks to see if player died
			if (board[moveRow + 1][moveCol].getHp() == 0)
			{
				delete board[moveRow + 1][movCol];
				board[moveRow + 1][moveCol] = new Character();
			}
			// need to make sure damage carries over
			return board[moveRow][moveCol];
		}
	}
	// Left
	else if (direction == 3 && moveCol >= 1)
	{	
		// move
		if (board[moveRow][moveCol - 1].getLetter() != "z")
		{
			moveCol--;
			board[moveRow][moveCol] = new Player(moveRow, moveCol, bag);
			delete board[moveRow][moveCol + 1];
			board[moveRow][moveCol + 1] = new Character();
			return board[moveRow][moveCol];
		}
		// attack
		else if (board[moveRow][moveCol - 1].getLetter() == "z")
		{
			// player attacks zombie
			board[moveRow][moveCol]->attack(board[moveRow][moveCol - 1]);
			// zombie attacks player
			board[moveRow][moveCol - 1]->attack(board[moveRow][moveCol]);
			// check to see if zombie died
			// Map checks to see if player died
			if (board[moveRow][moveCol - 1].getHp() <= 0)
			{
				delete board[moveRow][movCol - 1];
				board[moveRow][moveCol - 1] = new Character();
			}
			// need to make sure damage carries over
			return board[moveRow][moveCol];
		}
	}
	// Right
	else if (direction == 4 && moveCol < (cols - 1))
	{	
		// move
		if (board[moveRow][moveCol + 1].getLetter() != "z")
		{	
			moveCol++;
			board[moveRow][moveCol] = new Player(moveRow, moveCol, bag);
			delete board[moveRow][moveCol - 1];
			board[moveRow][moveCol - 1] = new Character();
			return board[moveRow][moveCol];
		}
		// attack
		else if (board[moveRow][moveCol + 1].getLetter() == "z")
		{
			// player attacks zombie
			board[moveRow][moveCol]->attack(board[moveRow][moveCol + 1]);
			// zombie attacks player
			board[moveRow][moveCol + 1]->attack(board[moveRow][moveCol]);
			// check to see if zombie died
			// Map checks to see if player died
			if (board[moveRow][moveCol + 1].getHp() <= 0)
			{
				delete board[moveRow][movCol + 1];
				board[moveRow][moveCol + 1] = new Character();
			}
			// need to make sure damage carries over
			return board[moveRow][moveCol];
		}
	}
	// return starting position otherwise
	else
		cout << "You can't move that direction!" << endl;
		move(board, rows, cols);
}
// adds items to the vector bag
void Player::addToBag(Items* item)
{
	if (!isBagFull())
		bag.push_back(item);	
}

// determines if the bag is full
bool Player::isBagFull()
{
	if (bag.size() < bagSize)
		return false;
	else
		cout << "Your bag is full!" << endl;
		return true;
}

// views bag so user can use an item
void Player::openBag()
{
	int choice = 0;

	cout << "Choose an item to use:" << endl;
	for (int i = 0; i < bag.size(); i++)
	{
		cout << i + 1 << ". " << bag[i]->getType() << endl;
	}
	cout << bag.size() + 1 << ". Quit" << endl;
	choice = inputValidation(bag.size() + 1);
	// if quit was not chosen	
	if (choice < bag.size() + 1)	
	{	
		// uses the element
		// returns true if used
		if (bag[choice - 1]->use(this));
		{
			// deletes the element from the vector
			bag.erase(bag.begin() + choice - 1);	
		}
	}
}
