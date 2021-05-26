#pragma once
#include "Fuel.h"
#include "Vehicle.h"

// represents a type of vehicle, the truck, which inherits functionality from
// the Vehicle class
class Ship : public Vehicle {
public:
  // constructor
  Ship(std::string name, int speed, int fuelCapacity, float fuelBurnRate,
       int price, Fuel fuel, Company *company);
  ~Ship();

  // attempt to make a trip based on currently loaded packages
  void travel() override;

  // purchases fuel and returns true if successful
  bool buyFuel(Fuel fuel) override;

  // returns "Ship"
  std::string getType() override;
};
