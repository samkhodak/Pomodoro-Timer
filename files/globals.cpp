#include "timer.h"

//File for global repeat functions.

//Prompt the user for a Y/N answer, and return a 1 if yes.
int yes()
{
	char again {0};
	do 
	{
		cout << "\n\t\t(Y/N)" << endl << endl;
		display_cursor(17,11);
		cin >> again;
		cin.ignore(100, '\n');

	}
	while(toupper(again) != 'Y' && toupper(again) != 'N');	//Check for wrong answers

	endwin();	

	if (toupper(again) == 'Y')
		return 1;
	else
		return 0;

}

//Display the cursor at a specific spot.
void display_cursor(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}
