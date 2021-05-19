all: project test

project: main.cpp Company Vehicle Package Destination Truck
	g++ main.cpp Company.o Vehicle.o Package.o Destination.o Truck.o -o project

Company: Company.h Company.cpp
	g++ -c Company.cpp

Vehicle: Vehicle.h Vehicle.cpp
	g++ -c Vehicle.cpp

Truck: Truck.h Truck.cpp
	g++ -c Truck.cpp

Package: Package.h Package.cpp
	g++ -c Package.cpp

Destination: Destination.h Destination.cpp
	g++ -c Destination.cpp

CompanyTest: tests/Company.cpp Company.o
	g++ tests/Company.cpp Company.o -o tests/CompanyTest

test: dummy CompanyTest
	tests/dummy
	tests/CompanyTest

dummy: tests/dummy.cpp
	g++ tests/dummy.cpp -o tests/dummy

clean:
	rm -f project Company.o Vehicle.o Package.o Destination.o Truck.o tests/CompanyTest tests/dummy 
