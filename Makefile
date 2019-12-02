CXX=g++
CPPFLAGS= -W -Wall -std=c++17 -g -I.
SOURCES:= random.cpp random.h
OBJECTS:= random.cpp
OUTDIR:= bin

all: main diceroll random-bytes code-usage

random.o: $(SOURCES)
	$(CXX) $(CPPFLAGS) -c $(OBJECTS)

main: $(SOURCES) main.cpp
	$(CXX) $(CPPFLAGS) -o $(OUTDIR)/$@ $(OBJECTS) main.cpp

diceroll: random.o examples/diceroll.cpp
	$(CXX) $(CPPFLAGS) -o $(OUTDIR)/diceroll $(OBJECTS) examples/diceroll.cpp

random-bytes: random.o examples/random-bytes.cpp
	$(CXX) $(CPPFLAGS) -o $(OUTDIR)/random-bytes $(OBJECTS) examples/random-bytes.cpp

code-usage: random.o examples/code-usage.cpp
	$(CXX) $(CPPFLAGS) -o $(OUTDIR)/code-usage $(OBJECTS) examples/code-usage.cpp

.PHONY: clean
clean:
	rm -f bin/* *.o *.c~ *.h~
