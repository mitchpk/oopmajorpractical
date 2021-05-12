all: game

game: main.cpp
	g++ main.cpp -o game

test: dummy

dummy: tests/dummy.cpp
	g++ tests/dummy.cpp -o dummytest

clean:
	rm -f game dummytest
