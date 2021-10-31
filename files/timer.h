#include <iostream>
#include <cstring>
#include <curses.h>
#include <chrono>
#include <unistd.h>

//Sam Khodakovskiy, CS300, TimeFlo Project

//Constants
const int STR_SIZE = 200;

//Using statements
using std::cin;
using std::cout;
using std::endl;
using std::flush;

using namespace std::chrono;


//Classes

class timer
{
	public:
		timer();
		int menu();


	private:
		
		//Functions
		int minutes_timer(int num_mins, bool phase);
		int define_times();
		int main_timer();
		
		//Members
		int workflow_time;
		int break_time;


};


//Global helper functions
int yes();

/*
class pomodoro_manager
{
	public:
		pomodoro_manager();


	private:
		timer user_timer;

};
*/
