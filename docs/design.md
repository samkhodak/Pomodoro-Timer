# The TimeFlo Project: Design
*Sam Khodakovskiy 2021*

## Introduction

This document will give details on the design and architecture of the TimeFlo
project. It will specify the high-level architecture of the product, as well
as the low-level detailed design of the TimeFlo product.

## Architecture

The architecture of the TimeFlo program consists of a base timer mechanism that 
will be specified by the user to fulfill a certain slice of time; this is the 
foundation of the whole implementation. 



### Startup of the program

The program will start by prompting the user to enter in a certain amount of time 
as a basis for the function of the timer, since the timer needs a time to start any
functions. After collecting two times from the user and storing them (one for the 
'workflow' phase, and one for the 'break' phase), the program will display a menu
that will run consistently throughout the program to offer the user choices on
customization of their timer.



### Menu options 
The first option in the menu will be a command to change the timer intervals of the workflow
and break times. This will allow the user to adjust their timer to their liking, any time they
want. The command will prompt the user again for the times they want for each phase and store them.
This will store the user's current specifications into memory so they can have the saved preferences
readily available that they had when they last ran the program.


The second menu option will be the main timer command. This will take the values the user entered for 
the time phases and start a workflow phase based on the input. The workflow phase will run completely 
and display the running time to the user, updating every second for a visual cue. Once the workflow
phase is complete, the program will output an alert to the user. The alert will consist of a large
visual cue to get the user's attention - this will be a text-based display, as well as a flash of the 
terminal if that can be accomplished - and an audio cue with a terminal ring to compound the visual cue.


After the workflow phase's alert, the break timer will automatically start, without the user's input.
This may be changed in the future. The break time interval will be fully run through and displayed,
then the alert will go on and the user will asked if they want to continue. If yes, the menu will display.


The last option will be to exit the program. This will thank the user and end the program, as well as
save the last parameters that the user has entered.






## Design

- Menu 
	- Menu will be implemented with a switch statement and a do-while loop, with each of the 
		menu options calling functions for each task in the switch statement. After each function 
		is called, the loop will iterate again until the user enters the exit case. Each function
		will be called from a timeflo object that saves parameters. If the user wants to exit the
		program, they simply type the last option.

- Prompting user for time phase intervals
	- A function will be called that will prompt the user for the appropriate time intervals
		for each phase of the timeflo timer. The user will enter in a number for each time phase
		and the result will be stored in the class' members for the workflow and break time interval.
	
	- This function will be reused at the beginning of the program, and each time the user wants
		to re-enter timer intervals.

	- After the time parameters have been saved to the class members, they will be entered into the 
		external data file and destroy the previously used parameters in the file. There is no need
		to append to the file.

- Main timer functionality
	- If the user selects that they want to start the timer with the parameters they have already
		entered (which will be assured by calling the interval entry function before the menu), this
		function will be called and will start the loop that counts the amount of time that has elapsed.
		This will be done twice; once for the workflow phase, and then for the break phase.
	
	- The library <chrono> will be primarily used to count time. A timer startpoint (now()) and a timer
		endpoint (now + phase length) will be declared. A while loop will be used to continue printing
		the remaining time until the endpoint of time is reached. For each while iteration, the 
		remaining time will be calculated by subtracting the current time (now()) from the endpoint. 
		This duration will then be split up into minutes and seconds by casting using the duration
		library. 

	- Once the remaining time is calculated inside the loop, the function will check if a second
		has passed by checking a separate time point and seeing if now() is greater than it. If it is,
		a second is added (to check against now() later) and the time is output.

	- Once the while is false, the function will exit. Inside each loop, getch() will be used to
		check if the user wants to stop the timer. If they press 'x', the function returns.

	- This function is multi-use and will be used for both the workflow and time phase inside 
		another function. After each call returns success (not that the user wants to stop), an
		alert will sound by using a loop that outputs '\a', the terminal bell, and a visual text
		alert will be displayed.
