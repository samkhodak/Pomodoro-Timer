#include "timer.h"

//Sam Khodakovskiy, CS300, TimeFlo Project
//Function definitions for the timer class.


//Constructor
timer::timer() : workflow_time(0), break_time(0)
{
	define_times();	//Automatically set times so menu will always be fully functional
}


//Run through both phases of timer.
int timer::main_timer()
{
	system("clear");
	
	if (minutes_timer(workflow_time, 1))	//Returns a 1, user wants to stop whole timer.
		return 1;

	if (minutes_timer(break_time, 0))	//0 arg indicates it's a break timer, 1 is for workflow.
		return 1;
	
	cout << "\n\n\nYour break has ended! Returning to main menu..." << endl;

	sleep(3);

	return 0;

}


//Run the timer for a specified amount of minutes, then ring the alarm.
int timer::minutes_timer(int num_mins, bool phase)
{
	int input_check {0}; //Used with getch() to check for user's quit.
	int row, col = 0;


	//Initiate the ncurses screen. Configure settings.
	WINDOW * win = initscr();	
	nodelay(win, TRUE);
	
	//Establish start point and end point.
	steady_clock::time_point start = steady_clock::now();	//MAY BE UNNEEDED?
	steady_clock::time_point end_point = start + minutes(num_mins);
			//char * what = "hi there " << rem_minutes << " lol";

	//Make a checker to display time.
	steady_clock::time_point checker = start;
	
	while (steady_clock::now() < end_point)	//Stops when timer is up
	{


		//Check if the user wants to stop the time
		input_check = getch();
		if (input_check == 'x')
		{
			endwin();
			return 1;	//Indicate back that the user wants to end completely.
		}

		
		//Print remaining time every second.
		if (steady_clock::now() > checker)
		{
			system("clear");
			
			//Calculate remaining time
			duration<double> time_span = duration_cast<duration<double>>(end_point - steady_clock::now());
			
			//Extract how many minutes/seconds is in the time left.
			auto rem_minutes = duration_cast<minutes>(time_span);
			auto rem_seconds = duration_cast<seconds>(time_span - rem_minutes);
		
			if (phase)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\t\t[ REMAINING WORKFLOW TIME: " 
					<< rem_minutes.count() << " minutes and " << rem_seconds.count() << " seconds]"
					<< "  [ x to end timer ]" << endl;

				refresh();
			}
			else
				cout << "hi";
			
			checker = checker + seconds(1);
		}
	
	}
	
	endwin();
	return 0;
}





//Menu for each time
int timer::menu()
{
	
	int menu_choice {0};

	do
	{
		system("clear");
		cout << "\n\nPlease choose a menu option." << endl << endl;

		cout << "\n== 1 ==== Set your timer phase lengths ====" << endl;
		cout << "\n== 2 ====== Start the TimeFlo timer =======" << endl;
		cout << "\n== 3 ======== Exit the program ============" << endl;
		
		cout << "\nMenu choice: ";
		cin >> menu_choice;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');

			cout << "\n\nMake sure you chose an integer for your menu choice and re-enter." << endl << endl;
			cout << "Menu choice: ";
			cin >> menu_choice;
		}
		cin.ignore(100,'\n');

		switch(menu_choice)
		{
			case 1:
				define_times();
				break;

			case 2: 
				main_timer();
				break;

			case 3:
				break;
		}
	


	}
	while(menu_choice != 3);
	
	return 0;
}



//Set the length of each phase of the TimeFlo timer.
int timer::define_times()
{

	int repeat_check {0};	//Will be used to check if the user wants to re-enter.

	do
	{
		cout << "\n\nHow many minutes do you want your workflow phase to be?" << endl
			<< "Enter an integer from 1 - 60." << endl << endl;

		cin >> workflow_time;

		//If workflow time is not within the correct parameters or isn't an int, loop.
		while (workflow_time < 1 || workflow_time > 60 || cin.fail())
		{
			cin.clear();						//Clear the cin.fail flag
			cin.ignore(100, '\n');	//Ignore for correct input
			system("clear");

			cout << "\n\nPlease re-enter an integer from 1 - 60 for" << endl
				<< "the amount of minutes in your workflow phase." << endl << endl;

			cin >> workflow_time;
		}
		cin.ignore(100, '\n');


		//Repeat steps for break time phase length.
		cout << "\n\nHow long should your break be? Enter an integer from 1 - 30" << endl
			<< "to indicate the number of minutes." << endl << endl;

		cin >> break_time;

		while (break_time < 1 || break_time > 30 || cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			system("clear");

			cout << "\n\nSomething went wrong. Re-enter your break length as integer from 1-30 minutes."
				<< endl << endl;

			cin >> break_time;
		}
		cin.ignore(100, '\n');
		system("clear");

		cout << "\n\nYou entered " << workflow_time << " minutes as your workflow phase length and " 
		<< break_time << " minutes as your break time." << endl;
		cout << "Does that sound correct?" << endl;
	

		repeat_check = yes();	
		if (!repeat_check)
		{
			cout << "\n\nSorry about that! Let's try again." << endl << endl;

			sleep(3);

			system("clear");
		}

		
		

	}
	while (!repeat_check);		//Yes() will return a 1 if the user enters a y. So if they enter an n
										//for incorrect, we loop again.

	
	cout << "\n\nSounds good!" << endl << endl;

	sleep(3);

	system("clear");

	return 0;	
}




