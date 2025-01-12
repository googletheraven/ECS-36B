// Aircrew.cpp

#include "Aircrew.h"
#include <iostream>
#include <iomanip>

// Aircrew Base Class Implementation
Aircrew::Aircrew(std::string name_str) : nm(name_str), flightsTaken(0), hoursWorked(0) {}

const double Aircrew::maxHours() const {
    return 60.0; // Default maximum hours per week
}

const std::string Aircrew::name() const {
    return nm;
}

void Aircrew::setFlights(int i) {
    flightsTaken = i;
}

void Aircrew::setHours(double h) {
    hoursWorked = h;
}

void Aircrew::print() const {
    std::cout << type() << ": " << name() << " has operated " << flightsTaken << " flights for a total of " << hoursWorked << " hours this week" << std::endl;
    std::cout << "Available flights: " << maxFlights() - flightsTaken << std::endl;
    std::cout << "Available hours: "  << maxHours() - hoursWorked << std::endl;
}

void Aircrew::scheduleFlight(int f, double h) const {
    // Check if the crew member can be scheduled for the flight
    double actualHours = h;
    if (type() == "TaggedAttendant") {
        actualHours /= 2.0; // Tagged Attendants register half the hours
    }
    std::cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight..." << std::endl;

    if (f > 0)
    {
        if ((flightsTaken + f + 1) <= maxFlights() && hoursWorked + actualHours <= maxHours()) {
            std::cout << "This crew member can be scheduled" << std::endl;
        }
        else 
        {
            std::cout << "This crew member should be replaced" << std::endl;
        }
    }
    else
    {
        if (flightsTaken + f <= maxFlights() && hoursWorked + actualHours <= maxHours()) {
            std::cout << "This crew member can be scheduled" << std::endl;
        } 
        else {
            std::cout << "This crew member should be replaced" << std::endl;
        }
    }
    

    std::cout << "Done scheduling " << name() << std::endl;
}

Aircrew::~Aircrew() {}

// Pilot Class Implementation
Pilot::Pilot(std::string name_str) : Aircrew(name_str) {}

const std::string Pilot::type() const {
    return "Pilot";
}

const int Pilot::maxFlights() const {
    return 5;
}

// Attendant Class Implementation
Attendant::Attendant(std::string name_str) : Aircrew(name_str) {}

const std::string Attendant::type() const {
    return "Attendant";
}

const int Attendant::maxFlights() const {
    return 8;
}

// TaggedAttendant Class Implementation
TaggedAttendant::TaggedAttendant(std::string name_str) : Aircrew(name_str) {}

const std::string TaggedAttendant::type() const {
    return "TaggedAttendant";
}

const int TaggedAttendant::maxFlights() const {
    return 8;
}

void TaggedAttendant::scheduleFlight(int f, double h) const {
    // Tagged Attendants schedule differently due to working half the hours
    double actualHours = h / 2.0;
    std::cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight..." << std::endl;

    if (f > 0)
    {
        if ((flightsTaken + f + 1) <= maxFlights() && hoursWorked + actualHours <= maxHours()) {
            std::cout << "This crew member can be scheduled" << std::endl;
        }
        else 
        {
            std::cout << "This crew member should be replaced" << std::endl;
        }
    }
    else
    {
        if (flightsTaken + f <= maxFlights() && hoursWorked + actualHours <= maxHours()) {
            std::cout << "This crew member can be scheduled" << std::endl;
        } 
        else {
            std::cout << "This crew member should be replaced" << std::endl;
        }
    }

    std::cout << "Done scheduling " << name() << std::endl;
}

// Factory method for creating aircrew objects based on the character code
Aircrew* Aircrew::makeAircrew(char ch, std::string name_str) {
    switch(ch) {
        case 'P':
            return new Pilot(name_str);
        case 'A':
            return new Attendant(name_str);
        case 'T':
            return new TaggedAttendant(name_str);
        default:
            return nullptr;
    }
}