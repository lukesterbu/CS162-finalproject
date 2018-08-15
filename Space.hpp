/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: Abstract class Space declaration
******************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Character.hpp"

class Space
{
	protected:
		Space* top;
		Space* left;
		Space* right;
		Space* bottom;
		char letter;
		int events; // 1 if event hasn't happened
	public:
		Space();
		~Space();
		void setTop(Space*);
		void setLeft(Space*);
		void setRight(Space*);
		void setBottom(Space*);
		char getLetter();
		virtual void event(Character*) = 0;
};

#endif
