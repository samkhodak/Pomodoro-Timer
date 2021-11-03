OBJS    = globals.o main.o timer.o
SOURCE    = globals.cpp main.cpp timer.cpp
HEADER    = timer.h
OUT    = out
CC     = g++
FLAGS     = -g -c -Wall
LDLIBS     = -lncurses

all: $(OBJS)
	    $(CC) -g $(OBJS) -o $(OUT) $(LDLIBS)

globals.o: globals.cpp
	    $(CC) $(FLAGS) globals.cpp

main.o: main.cpp
	    $(CC) $(FLAGS) main.cpp

timeflo.o: timer.cpp
	    $(CC) $(FLAGS) timer.cpp


clean:
	    rm -f $(OBJS) $(OUT) *.txt

v:
			vim *.cpp *.h -p

