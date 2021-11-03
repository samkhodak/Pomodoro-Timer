# The TimeFlo Project: Validation and Verification
*Sam Khodak 2021*

## Introduction

This document is the validation and verification manual for the TimeFlo project.

### Purpose and Scope

The purpose of this document is to outline the testing and validation schedule and overview for 
the TimeFlo project. This document's scope includes a V&V document and testing phases for general
functionality of the product, as well as issue-solving.

### Target Audience

The target audience of this document is the stakeholders of the project and the testers of the product.

### Terms and Definitions

- Unit testing: individual units of the software system are validated and tested.
- Integration testing: units' relationships to other units are tested.
- System testing: all units in a system are tested integrated together.
- Acceptance testing: system is tested for completion and compliance to stakeholder's requirements.
- Functional/non-functional testing: testing functional requirements and non-functional requirements.
- Dynamic testing: testing a product by executing the program.
- Static testing: testing a product by reviewing software and not executing the program.


## V&amp;V Plan Description

The V&V plan will go over the high-level inspection and testing plan for the TimeFlo product.
The validation and verification of the product will be done using inspection and testing, but
not program correctness.

## Test Plan Description

The Test Plan is a formalized outline of all the testing procedures and their planned order and scope.
This will encompass all of the following sections.

### Scope Of Testing

The scope of the V&V plan is all of the advanced testing of the TimeFlo product. The areas of the product
that will be tested are mainly the separate functions of the product and how they interact with each other. 
A modular approach will be taken with testing to verify proficiency of each function of the product. 
There are no specific parts that will not be tested, although graphical/visual testing are not valued over
core functionality of the product's requirements. Functional testing and non-functional testing will be employed, as 
well as more specific tests such as dynamic testing and compliance testing, and static testing.

### Testing Schedule

The following testing schedule will be used with a deadline, but will not have specific deadlines for each
section; only a final deadline and order of tests to do.

- Unit testing
	-	Functional testing
	- Manual testing
	- Dynamic testing

- System testing
	- Functional testing
	- Dynamic testing
	- Manual testing
	- Inspection

- Acceptance testing
	- Inspection
	- Dynamic testing
	- Compliance testing

These sections must be completed in order and finished by the 7th of November.

### Release Criteria

The system must meet the minimum requirements detailed in the requirements document, each one of them. They
must be able to function correctly each time the user commands them to be executed. The non-functional requirements
are also important criteria that must be tested and met.


## Unit Testing

The purpose of the Unit Testing section is to explain the key modules of the product and their functionality,
as well as how they will be tested for proficiency. The modules of the product are the input from the user for
storing timer parameters, the base timer mechanism, and the alerts when the user's timer complets, as well
as the menu and outputs to the user.


### Strategy

The strategy of unit testing will be to mainly go through the functional modules of the product and test each
one with static and dynamic testing. The testing will be on a function-to-function basis, since the main functions 
inside the menu split up key features of the product. Each module will be statically tested first to try to catch 
logical errors in the correctness of the code. Each module will be rigorously tested dynamically after that to 
see if there are any unexpected errors that can arise from varied user input. 
The difference between such unit testing and integration is that the unit testing will test each function multiple 
times and verify input/output, whereas integration testing will verify that each module works correctly after 
other modules are run and tested (the whole system works correctly together).

### Test Cases

Main unit testing cases for each module will be a variety of input from the tester, such as incorrect characters or inputs
entered in to try to test the resilience of the program to oblivious input. A variety of inputs, correct and incorrect,
will be tested. A variety of these inputs will be tested on the proficiency of the modules that don't require input but still
work on input.

## System Testing

The systems testing section outlines the importance of testing the product as a whole and assuring a well-rounded quality of 
functionality. The test cases will be explained.

### Test Cases

Higher-level systems test cases will test a variety of input and verify that parameters and user inputs are saved and used correctly,
and that each module is called and ran correctly, producing the correct output for each correct/incorrect user input for parameters. 
The reading/writing to files will also be included in the systems testing since functions are used inside of each other.

For example, if a user enters an incorrect input for parameters, the systems test case will be to verify that this incorrect parameter
is handled and corrected before running any further modules such as the main timer or menu. Once the incorrect time parameter is corrected,
the execution of the main timer and main menu will be tested to ensure that each unit is not adversely affecting other modules' output 
because of an improperly-handled incorrect input.

## Inspection

The inspection will be a basic inspection of all the components of the software product, including some testing.
The criteria for inspection will be using the basic ideas outlined in the testing section, but will also inspect
issues that have been outlined by the tester previously. The inspections will occur after progress has been made
on the high-level functionality of the program and will rigorously review the logic of the program with static inspection
and expected outputs compared to actual outputs with dynamic testing. The inspectors will log and document issues that 
occur and review progress on previously documented issues.
