MAIN=main.cpp

all:
	g++ $(MAIN) -o test
clean:
	rm test
