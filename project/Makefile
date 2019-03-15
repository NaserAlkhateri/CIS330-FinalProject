SOURCES = testManhunt.cpp manhunt.cpp manhuntPvP.cpp testManhuntPvP.cpp
HEADERS = manhunt.h manhuntPvP.h
OBJECTS = $(SOURCES: .o)
LIBS = -lm

CC = g++
CFLAGS = -std=c++14 -g -fPIC

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

tests: manhunt.exe manhuntPvP.exe

manhunt.exe: testManhunt.o manhunt.o
	$(CC) $(CFLAGS) -o $@ $^

manhuntPvP.exe: testManhuntPvP.o manhuntPvP.origins
	$(CC) $(CFLAGS) -o $@ $^

memcheckManhunt.exe: manhunt.exe
	valgrind --leak-check=yes --track-origins=yes ./manhunt.exe

memcheckManhuntPvP.exe: manhuntPvP.exe
	valgrind --leak-check=yes --track-origins=yes ./manhuntPvP.exe

clean:
	$(RM) *.cpp~ *.h~ *.o *.exe 
