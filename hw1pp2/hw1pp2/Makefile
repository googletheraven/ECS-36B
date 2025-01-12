# Makefile for ecs36b S2024
CC = g++
CFLAGS = -g -I/usr/include/jsoncpp

# rules.
EXECS = GPS_0404_s2024.o hw1p2.o hw1p2

all: $(EXECS)

GPS_0404_s2024.o: GPS_0404_s2024.cpp GPS_0404_s2024.h
	$(CC) -c $(CFLAGS) GPS_0404_s2024.cpp

hw1p2.o: hw1p2.cpp GPS_0404_s2024.h
	$(CC) -c $(CFLAGS) hw1p2.cpp

hw1p2: GPS_0404_s2024.o hw1p2.o
	$(CC) -o hw1p2 GPS_0404_s2024.o hw1p2.o

clean:
	rm -f *.o $(EXECS)