all: Project Test

Project: main.cpp Company.o Vehicle.o Package.o Destination.o Truck.o Aircraft.o Ship.o
	g++ main.cpp Company.o Vehicle.o Package.o Destination.o Truck.o Aircraft.o Ship.o -o project

CompanyTest: tests/Company.cpp Company.o Vehicle.o
	g++ tests/Company.cpp Company.o Vehicle.o -o CompanyTest

PackageTest: tests/Package.cpp Package.o Destination.o
	g++ tests/Package.cpp Package.o Destination.o -o PackageTest

Test: CompanyTest PackageTest
	./CompanyTest
	./PackageTest

clean:
	rm -f project *.o *Test 
