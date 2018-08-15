/******************************************************************
** Author:	Luke Burris
** Date: 	8/12/2018
** Description: Map class decalaration. Prints out the game map.
******************************************************************/

#ifndef MAP_HPP
#define MAP_HPP

#include "Map.hpp"
#include "Space.hpp"
#include "Character.hpp"

#include <vector>

using std::vector;

class Map
{
	private:
		int days;
		int rows;
		int cols;
		Space*** spaceBoard;
		Character*** charBoard;
		Character* player;
	public:
		Map();
		~Map();
		void startGame();
		void userInput();
		void triggerEvent();
		void printMap();
};

#endif
