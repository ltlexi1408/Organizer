.default: all

all: organizer

clean:
	rm -rf organizer *.o

blink5: organizer.o event.o
	g++ -Wall -Werror -g -O -o $@ $^

%.o: %cpp
	++ -Wall -Werror -g -O -c $^