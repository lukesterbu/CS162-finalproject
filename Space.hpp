/******************************************************************
** Author:	Luke Burris
** Date:	8/12/2018
** Description: Abstract class Space declaration
******************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
	protected:
		Space* top;
		Space* left;
		Space* right;
		Space* bottom;
		char letter;
	public:
		Space();
		~Space();
		void setTop(Space*);
		void setLeft(Space*);
		void setRight(Space*);
		void setBottom(Space*);
		char getLetter();
		virtual void event() = 0;
};

#endif
