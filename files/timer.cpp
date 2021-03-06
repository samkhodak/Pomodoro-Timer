#include "timer.h"

//Sam Khodak, CS300, TimeFlo Project
//Function definitions for the timer class.


//Constructor
timer::timer() : workflow_time(0), break_time(0)
{
	read_in();
}

//WRite out parameters to an external data file for later.
void timer::write_out()
{
	ofstream out;	
	out.open("parameters.txt");

	if (out)
	{
		out << workflow_time << ' ' << break_time << ' ' << endl;
	}

	out.close();

	return;
}

//Read in previously saved parameters and store them if needed.
void timer::read_in()
{
	int workflow_param, break_param = 0;
	ifstream in;
	in.open("parameters.txt");

	if (!in)
		define_times();	//If nothing is in the file, fill the class' times.
	else
	{
		system("clear");
		in >> workflow_param >> break_param;
		cout << "\n\n\t\tYour previously saved settings were:" << endl << endl;
		cout << "\t\t[Workflow] " << workflow_param << " minutes" << endl;
		cout << "\t\t[Break] " << break_param << " minutes." << endl << endl;
		cout << "\t\tDo you want to use these settings?";

		if (yes())
		{
			workflow_time = workflow_param;
			break_time = break_param;
			cout << "\t\tYour previous times are saved!" << endl;
			return;
		}
		else				
			define_times();
	}
	return;
}


//Run through both phases of timer.
void timer::main_timer()
{
	//Run workflow timer
	if (minutes_timer(workflow_time, 1))	//Returns a 1, user wants to stop whole timer.
		return;
	system("clear");

	cout << "\n\n\n\n\n\n\n\t\tWORKFLOW PHASE COMPLETE! BREAK STARTING SOON."<< endl;

	for (int i = 0; i < 20; ++i)
	{
		cout << "\a" << flush;
		usleep(600000);
	}

	system("clear");

	cout << "\n\n\n\n\n\n\n\t\tBREAK PHASE BEGINNING IN 3.. " << flush;
	sleep(1);
	cout << "2.. " << flush;
	sleep(1);
	cout << "1.." << flush;
	sleep(1);


	//Run break timer right after
	if (minutes_timer(break_time, 0))	//0 arg indicates it's a break timer, 1 is for workflow.
		return;

	cout << "\n\n\n\n\n\n\n\t\t\tBREAK PHASE COMPLETE!"<< endl;

	for (int i = 0; i < 20; ++i)
	{
		cout << "\a" << flush;
		usleep(450000);
	}


	cout << "\n\n\n\n\n\n\n\t\t\tYour break has ended! Returning to main menu..." << endl;

	sleep(3);

	return;
}


//Run the timer for a specified amount of minutes, then ring the alarm.
int timer::minutes_timer(int num_mins, bool phase)
{
	int input_check {0}; //Used with getch() to check for user's quit.
	int center_col, half_len, adjust_col = 0;

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
			//system("clear");
			erase();	

			//Calculate remaining time
			duration<double> time_span = duration_cast<duration<double>>(end_point - steady_clock::now());

			//Extract how many minutes/seconds is in the time left.
			auto rem_minutes = duration_cast<minutes>(time_span);
			auto rem_seconds = duration_cast<seconds>(time_span - rem_minutes);

			if (phase)
			{
				half_len = 26 / 2;
				center_col = win -> _maxx / 2;
				adjust_col = center_col - half_len;
				mvprintw(13, adjust_col, "[ REMAINING WORKFLOW TIME ]");
				mvprintw(16, adjust_col + 1, "%ld minutes and %ld seconds", rem_minutes.count(), rem_seconds.count());
				mvprintw(19, adjust_col + 1, "[ Press x to stop timer ]");

				refresh();
			}
			else
			{
				half_len = 26 / 2;
				center_col = win -> _maxx / 2;
				adjust_col = center_col - half_len;
				mvprintw(13, adjust_col, "[ REMAINING BREAK TIME ]");
				mvprintw(16, adjust_col, "%ld minutes and %ld seconds", rem_minutes.count(), rem_seconds.count());
				mvprintw(19, adjust_col - 1, "[ Press x to stop timer ]");

				refresh();

			}

			checker = checker + seconds(1);
		}

	}


	endwin();
	return 0;
}





//Menu for each time
void timer::menu()
{
	int menu_choice {0};

	do
	{
		system("clear");
		cout << "\n\n\t\tPlease choose a menu option." << endl << endl;

		cout << "\n\t\t== 1 ==== Set your timer phase lengths ====" << endl;
		cout << "\n\t\t== 2 ====== Start the TimeFlo timer =======" << endl;
		cout << "\n\t\t== 3 ======== Exit the program ============" << endl;


		cout << "\n\t\tMenu choice: ";
		cin >> menu_choice;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');

			cout << "\n\n\t\tMake sure you chose an integer for your menu choice and re-enter." << endl << endl;
			cout << "\t\tMenu choice: ";
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
				cout << endl << endl << endl;
				break;
		}
	}
	while(menu_choice != 3);
	return;
}



//Set the length of each phase of the TimeFlo timer.
int timer::define_times()
{

	int repeat_check {0};	//Will be used to check if the user wants to re-enter.

	system("clear");

	do
	{
		cout << "\n\n\t\tHow many minutes do you want your workflow phase to be?" << endl
			<< "\t\tEnter an integer from 1 - 60." << endl << endl;

		display_cursor(17,10);
		cin >> workflow_time;

		//If workflow time is not within the correct parameters or isn't an int, loop.
		while (workflow_time < 1 || workflow_time > 60 || cin.fail())
		{
			cin.clear();						//Clear the cin.fail flag
			cin.ignore(100, '\n');	//Ignore for correct input
			system("clear");

			cout << "\n\n\t\tPlease re-enter an integer from 1 - 60 for" << endl
				<< "\t\tthe amount of minutes in your workflow phase." << endl << endl;

			display_cursor(17,10);
			cin >> workflow_time;
		}
		cin.ignore(100, '\n');

		system("clear");
		//Repeat steps for break time phase length.
		cout << "\n\n\t\tWorkflow time: " << workflow_time << " minutes.";
		cout << "\n\n\t\tHow long should your break be? Enter an integer from 1 - 30" << endl
			<< "\t\tto indicate the number of minutes." << endl << endl;

		display_cursor(17,10);
		cin >> break_time;

		while (break_time < 1 || break_time > 30 || cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			system("clear");

			cout << "\n\n\t\tSomething went wrong. Re-enter your break length as integer from 1-30 minutes."
				<< endl << endl;

			display_cursor(17,10);
			cin >> break_time;
		}
		cin.ignore(100, '\n');
		system("clear");

		cout << "\n\n\t\tYou entered " << workflow_time << " minutes as your workflow phase length and " 
			<< break_time << " minutes as your break time." << endl;
		cout << "\t\tDoes that sound correct?" << endl;


		repeat_check = yes();	
		if (!repeat_check)
		{
			cout << "\n\n\t\tSorry about that! Let's try again." << endl << endl;

			sleep(3);

			system("clear");
		}




	}
	while (!repeat_check);		//Yes() will return a 1 if the user enters a y. So if they enter an n
	//for incorrect, we loop again.

	//Write out final parameters.
	write_out();


	cout << "\n\n\t\tSounds good!" << endl << endl;

	sleep(3);

	system("clear");

	return 0;	
}




