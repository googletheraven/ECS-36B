#include "Angle.h"
#include <iostream>

// Name: Kevali Shah
// Student ID: 920726532

Angle::Angle() {
  // Set initial angle to 30 degrees
  theta = 30;
}


int Angle::get() {
  return theta;
}

void Angle::change(int dt) {
  // Compute new angle as the sum of the current angle and dt
  int new_theta = theta + dt;

  // Clamp the new angle within the allowed range
  if (new_theta < -60) {
    theta = -60;
  } else if (new_theta > 120) {
    theta = 120;
  } else {
    theta = new_theta;
  }

  // Update the private member variable with the clamped value
  set(theta);
}

void Angle::set(int t) {
  // Update the private member variable with the given value
  theta = t;
}

void Angle::print() {
  std::cout << "angle: " << theta << std::endl;
}
