#include <iostream>

#include "Airplane.h"
using namespace std;

// Airplane constructor 
Airplane::Airplane(int n) : maxContainers(n), numContainers(0) {}

int Airplane::maxLoad() const {
   return maxContainers;
}

int Airplane::currentLoad() const {
   return numContainers;
}

bool Airplane::addContainers(int n) {
   if (n <= 0) {
       throw std::invalid_argument("must be positive");
   }

   if (numContainers + n <= maxContainers) {
       numContainers += n;
       return true;
   }
   return false;
}

