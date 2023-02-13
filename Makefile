.default: all

all: organizer

clean:
	rm -rf organizer *.o

organizer: organizer.o event.o users.o
	g++ -Wall -Werror -g -O -I/user/include/mysql -lmariadbcpp -o $@ $^

%.o: %cpp
	++ -Wall -Werror -g -O -I/user/include/mysql -lmariadbcpp -c $^

events: 