#include <iostream>
#include "Airline.h"
#include "Airplane.h"
using namespace std;

Airline::Airline(int nA321, int nB777, int nB787) : nAirplanes(nA321 + nB777 + nB787) {
   airplaneList = new Airplane*[nAirplanes];
   // Initialize A321 airplanes
   for (int i = 0; i < nA321; ++i) {
       airplaneList[i] = new Airplane(10); // Capacity of A321 is 10
       cout << "Airplane " << i + 1 << " maximum load 10" << endl;
   }
   // Initialize B777 airplanes
   for (int i = nA321; i < nA321 + nB777; ++i) {
       airplaneList[i] = new Airplane(32); // Capacity of B777 is 32
       cout << "Airplane " << i + 1 << " maximum load 32" << endl;
   }
   // Initialize B787 airplanes
   for (int i = nA321 + nB777; i < nAirplanes; ++i) {
       airplaneList[i] = new Airplane(40); // Capacity of B787 is 40
       cout << "Airplane " << i + 1 << " maximum load 40" << endl;
   }
}

Airline::~Airline(void) {
   for (int i = 0; i < nAirplanes; ++i) {
       delete airplaneList[i];
       cout << "deallocating airplane " << i + 1 << endl;
   }
   delete[] airplaneList;
}

void Airline::addShipment(int size) {
   bool shipmentAssigned = false;
   for (int i = 0; i < nAirplanes; ++i) {
       if (airplaneList[i]->addContainers(size)) {
           cout << size << " containers added to airplane " << i + 1 << endl;
           shipmentAssigned = true;
           break;
       }
   }
   if (!shipmentAssigned) {
       cout << " could not fit " << size << " containers" << endl;
   }
}

void Airline::printSummary() const {
    cout << "Summary:" << endl;
   for (int i = 0; i < nAirplanes; ++i) {
       if (airplaneList[i]->currentLoad() > 0) {
           cout << "airplane " << i + 1 << " " << airplaneList[i]->currentLoad() << "/" << airplaneList[i]->maxLoad() << endl;
       }
   }
}