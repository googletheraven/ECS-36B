#ifndef PILOT_H
#define PILOT_H

#include "Aircrew.h"

// Declaration of the Pilot class, derived from Aircrew
class Pilot : public Aircrew {
public:
    // Constructor: Takes the name of the pilot and initializes data members
    Pilot(std::string name_str);

    // Virtual function to get the type of aircrew member (Pilot)
    virtual const std::string type(void) const;

    // Virtual function to get the maximum number of flights a pilot can work on per week
    virtual const int maxFlights(void) const;

    // Virtual function to get the maximum number of hours a pilot can work on per week
    virtual const double maxHours(void) const;

    // Virtual function to schedule a flight for a pilot
    virtual void scheduleFlight(int i, double h) const;
};

#endif // PILOT_H