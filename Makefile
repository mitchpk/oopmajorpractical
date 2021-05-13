all: project test

project: main.cpp Company
	g++ main.cpp Company.o -o project

Company: Company.h Company.cpp
	g++ -c Company.cpp

CompanyTest: tests/Company.cpp Company.o
	g++ tests/Company.cpp Company.o -o tests/CompanyTest

test: dummy CompanyTest
	tests/dummy
	tests/CompanyTest

dummy: tests/dummy.cpp
	g++ tests/dummy.cpp -o tests/dummy

clean:
	rm -f project tests/dummy Company.o tests/CompanyTest
