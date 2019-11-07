SOURCES:= main.cpp random.cpp random.h
OBJECTS:= main.cpp random.cpp
OUT:= bin/main
CFLAGS:= -W -Wall -std=c++17 -g
all: main diceroll random-bytes

main: $(SOURCES)
	g++ $(CFLAGS) -o $(OUT) $(OBJECTS)

diceroll: diceroll.cpp random.cpp random.h
	g++ $(CFLAGS) -o bin/diceroll diceroll.cpp random.cpp

random-bytes: random-bytes.cpp random.cpp random.h
	g++ $(CFLAGS) -o bin/random-bytes random-bytes.cpp random.cpp

debug: $(SOURCES)
	g++ -W -Wall -std=c++17 -g -o $(OUT) $(OBJECTS)
