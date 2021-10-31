# The TimeFlo Project: Requirements Document
*Sam Khodakovskiy 2021*


## Introduction

This document is intended to outline the TimeFlo project for each student in CS300. The document will cover 
the purpose and scope of the document, the target audience of the timer, any terms and definitions used in
the project, and an overview of the product. It will also go over the users and stakeholders of the timer.



### Purpose and Scope

The purpose of the document is to provide an overview of the project as a reference. The 'requirements'
document can be accessed in the future to ensure that each requirement of the project is met and 
guidelines are adhered to. The scope of this project is to complete the requirements, project plan 
and schedule, and design writeup. After this, the design will be implemented and the product
will be tested to ensure efficacy.



### Target Audience

The target audience of this document is the stakeholder of the project, and possible users (including 
students and developers).



### Terms and Definitions

* Workflow - the flow of getting focused in your work that can sometimes become non-beneficial. 

* User - members of the public that will be using or testing the 
product, including developers andstakeholders.

* Stakeholder - anyone with a personal investment in the success of the product or access
to oversight of the product.

* Phase - section of the timer that the user is currently in; either workflow phase or break phase.



## Product Overview

The TimeFlo timer will be used as a study timer or a workflow timer. The TimeFlo application will
allow the user to enter the amount of time they want to work for in each work increment, and enter
the amount of time needed for each break. The timer will then run for the allotted specified amount of
workflow time, before ringing an alarm. It will then automatically start the break timer. The user will
have the ability to stop the alarm to re-enter time parameters. This application will most likely not 
have an advanced graphical user interface, as this is beyond the scope of the project and is not in 
the skillset of the developer.



## Users and Stakeholders

This section will list the users and stakeholders attached to this project.



### Professor Bart Massey

Bart Massey is the head overseer of this project and will evaluate its completed state,
as well as the quality of every phase of the project.



### Sam Khodakovskiy

Sam Khodakovskiy is the only developer and owner of this product.



## Use cases

Use cases will help readers of this document see specific examples of how the product might be used.



#### Studying timer case

The user is an end user using the product in its deployed state and decides they need a workflow 
timer for their studying. They load up the program and are greeted by a menu to start the TimeFlo timer.
The user selects the "Enter timer lengths" option and enters the timing parameters for the 
pomodoro technique used. They then decide that they want a shorter break in between study times. 
They select the same menu option and re-enter the parameters. They then start the timer and start 
studying until the timer rings an alarm and flashes the screen with an alert. The timer starts 
their break time automatically. They take a break and start the timer again. After some time, the
user stops the timer to go check on their bread in the oven. 



#### Testing case

The user is a tester, testing the program at a stage in its development. The tester turns on the
program and starts by entering in the workflow time and break time parameters. They then start the 
timer and later stop it before it rings an alarm and re-enter the timer parameters. The timer 
is started again at the beginning. 
The timer runs until it hits the alarm and then starts the break timer, then after the break 
timer runs down, the alarm once again goes off. The tester indicates that they want to start the
TimeFlo timer again, and it runs one more cycle with the same parameters.



## Functional Requirements

This section lists the specific parts of the application that are required for the finished
product, namely the usability of the timer and alerts. These are functional requirements.



### Timer functionality

- The user shall be able to enter a set time that each timer will run for in the TimeFlo program.
	- The timer should save these set times into memory so the user can re-run and have the times.
	- The timer must run for the appropriate entered times.
	- The user must be able to change these timer lengths at will.
	- The timer must be able to be stopped to re-enter timer lengths.



### Alerts functionality

- The user of the TimeFlo program must be alerted when each phase is done.
	- An alert must be dispatched after the workflow phase, then after the break phase.
	- Each alert must be seen and heard by the user. 
	- An audible sound must be played to the user.
	- A pop-up message must be shown to the user.



## Extra-functional Requirements

Extra-functional requirements are constraints on services or functions offered by the product. 
This section will outline the constraints on timing and program reliability.



### Timer accuracy
	
- The full, correct time must run before the timer is stopped or the phase is switched.
	- Time must be accurately calculated to the user's specification so they know exactly how
	much time will be spent in each flow state.


### Program reliability

- The product must be dependable to run completely.
	- The program must not have bugs that can cause it to crash, otherwise the user
	may not be broken out of their flow state; a big issue.

