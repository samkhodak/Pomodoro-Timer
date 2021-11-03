#include <iostream>
#include <cstring>
#include <curses.h>
#include <chrono>
#include <unistd.h>
#include <fstream>

//Sam Khodakovskiy, CS300, TimeFlo Project

//Constants
const int STR_SIZE = 200;

//Using statements
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::ifstream;
using std::ofstream;

using namespace std::chrono;


//Classes

class timer
{
	public:
		timer();
		void menu();


	private:
		
		//Functions
		void read_in();
		void write_out();
		int minutes_timer(int num_mins, bool phase);
		int define_times();
		void main_timer();
		
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
