#include "Pilot.h"
#include <iostream>

// Constructor: Initializes the Pilot object with a given name using the base class constructor
Pilot::Pilot(std::string name_str) : Aircrew(name_str) {}

// Get the type of aircrew member (Pilot)
const std::string Pilot::type(void) const {
    return "Pilot";
}

// Get the maximum number of flights a pilot can work on per week
const int Pilot::maxFlights(void) const {
    return 5;
}

// Get the maximum number of hours a pilot can work on per week
const double Pilot::maxHours(void) const {
    return 60.0;
}

// Attempt to schedule a flight for the pilot
void Pilot::scheduleFlight(int i, double h) const {
    std::cout << "Attempting to schedule for " << i << " stop(s) " << h << " hours flight..." << std::endl;

    // Check if scheduling is possible based on the maximum flights and hours
    if (flightsTaken + i <= maxFlights() && hoursWorked + h <= maxHours()) {
        std::cout << "This crew member can be scheduled" << std::endl;
        std::cout << "Done scheduling " << name() << std::endl;
    } else {
        std::cout << "This crew member cannot be scheduled" << std::endl;
    }
}