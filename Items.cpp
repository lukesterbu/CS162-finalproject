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

Items::~Items()
{

}

string Items::getType()
{
	return type;
}
