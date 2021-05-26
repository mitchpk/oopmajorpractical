all: project test

project: main.cpp Company.o Vehicle.o Package.o Destination.o
	g++ main.cpp Company.o Vehicle.o Package.o Destination.o -o project

CompanyTest: tests/Company.cpp Company.o
	g++ tests/Company.cpp Company.o -o CompanyTest

PackageTest: tests/Package.cpp Package.o Destination.o
	g++ tests/Package.cpp Package.o Destination.o -o PackageTest

test: CompanyTest PackageTest
	./CompanyTest
	./PackageTest

clean:
	rm -f project *.o *Test 
