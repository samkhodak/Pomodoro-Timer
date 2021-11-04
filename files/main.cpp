#include "timer.h"

//Sam Khodak, CS300, TimeFlo Project
//Main file


int main()
{
	system("clear");

	cout << "\n\n\t\tWelcome to the TimeFlo timer! This timer allows you to be alerted when a specific" << endl;
	sleep(2);
	cout << "\t\tamount of time passes in a work phase and a break phase. With this timer, you can" << endl;
	sleep(2);
	cout << "\t\tbe brought out of your focus mode and take regular, scheduled breaks." << endl;
	sleep(4);

	timer pomodoro;
	pomodoro.menu();
	

	exit(0);
}
