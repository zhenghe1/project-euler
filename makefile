CC = g++
CFLAGS = -Wall -g -Werror -std=c++0x

test:
	$(CC) $(CFLAGS) -o test euler_test.cpp

clean:
	rm test