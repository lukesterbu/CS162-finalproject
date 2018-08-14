/*****************************************************************************
** Author:      Luke Burris
** Date:        7/14/2018
** Description: inputValidation function definition. This function takes in a
**              string and using a stringstream object to validate the input as
**              an integer greater than 0.
******************************************************************************/

#include "inputValidation.hpp"

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

int inputValidation()
{
        std::string input = "";
        int number = 0;
	bool allDigits = true;

        do
        {
		allDigits = true;
                getline(cin, input);
		for (int i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
				allDigits = false;
		}
                stringstream toNumber(input);
                //checks to see if input is a positive int
                if(!(toNumber >> number) || number <= 0 || !allDigits)
                	cout << "Please enter a positive integer: ";
        } while(number <= 0 || !allDigits);

        cout << endl;

        return number;
}


int inputValidation(int max)
{
        std::string input = "";
        int number = 0;
	bool allDigits = true;

        do
        {
		allDigits = true;
                getline(cin, input);	
		for (int i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
				allDigits = false;
		}
                stringstream toNumber(input);
                //checks to see if input is a positive int
                if(!(toNumber >> number) || number <= 0 || number > max
		|| !allDigits)
                	cout << "Please enter a positive integer less than "
			<< max + 1 << ": ";
        } while(number <= 0 || number > max || !allDigits);

        cout << endl;

        return number;
}


int inputValidation(int min, int max)
{
        std::string input = "";
        int number = min - 1;
	bool allDigits = true;

        do
        {
		allDigits = true;
                getline(cin, input);	
		for (int i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
				allDigits = false;
		}
                stringstream toNumber(input);
                //checks to see if input is a positive int
                if(!(toNumber >> number) || number < min || number > max
		|| !allDigits)
                	cout << "Please enter an integer between " << min
			<< " and " << max << ": ";
        } while(number < min || number > max || !allDigits);

        cout << endl;

        return number;
}
