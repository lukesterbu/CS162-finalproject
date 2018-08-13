/********************************************************************
** Author:	Luke Burris
** Date:	8/13/2018
** Description:	Items class definition
********************************************************************/

#include "Items.hpp"

#include <string>

using std::string;

Items::Items()
{
	type = "Item";
}

// Never actually creating an item
Items::~Items()
{}

string Items::getType()
{
	return type;
}
