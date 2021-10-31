#include "timer.h"

//File for global repeat functions.

//Prompt the user for a Y/N answer, and return a 1 if yes.
int yes()
{
	char again {0};

	do {

		cout << "\n(Y/N)" << endl << endl;
		cin >> again;
		cin.ignore(100, '\n');

	}
	while(toupper(again) != 'Y' && toupper(again) != 'N');	//Check for wrong answers

	if (toupper(again) == 'Y')
		return 1;
	else
		return 0;

}
