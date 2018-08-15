/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: Abstract class Space definition
******************************************************************/

#include "Space.hpp"

Space::Space()
{
	top = nullptr;
	left = nullptr;
	right = nullptr;
	bottom = nullptr;
	letter = ' ';
	events = 0;
}

Space::~Space()
{

}

void Space::setTop(Space* space)
{
	top = space;
}

void Space::setLeft(Space* space)
{
	left = space;
}

void Space::setRight(Space* space)
{
	right = space;
}

void Space::setBottom(Space* space)
{
	bottom = space;
}

char Space::getLetter()
{
	return letter;
}
