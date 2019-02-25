SOURCES = testManhunt.cpp manhunt.cpp
HEADERS = manhunt.h
OBJECTS = $(SOURCES: .o)
LIBS = -lm

CC = g++
CFLAGS = -std=c++14 -g -fPIC

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

tests: manhunt.exe

manhunt.exe: testManhunt.o manhunt.o
	$(CC) $(CFLAGS) -o $@ $^

memcheckManhunt.exe: manhunt.exe
	valgrind --leak-check=yes --track-origins=yes ./manhunt.exe

clean:
	$(RM) *.cpp~ *.h~ *.o *.exe 
