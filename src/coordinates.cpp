#include "coordinates.h"

CoordinatePair CoordinatePair::operator+(CoordinatePair rhs) {
  CoordinatePair result;

  result.x = this->x + rhs.x;
  result.y = this->y + rhs.y;

  return result;
}
CoordinatePair CoordinatePair::operator+(double rhs) {
  CoordinatePair result;

  result.x = this->x + rhs;
  result.y = this->y + rhs;

  return result;
}

CoordinatePair CoordinatePair::operator-(CoordinatePair rhs) {
  CoordinatePair result;

  result.x = this->x - rhs.x;
  result.y = this->y - rhs.y;

  return result;
}
CoordinatePair CoordinatePair::operator-(double rhs) {
  CoordinatePair result;

  result.x = this->x - rhs;
  result.y = this->y - rhs;

  return result;
}

CoordinatePair CoordinatePair::operator*(CoordinatePair rhs) {
  CoordinatePair result;

  result.x = this->x * rhs.x;
  result.y = this->y * rhs.y;

  return result;
}
CoordinatePair CoordinatePair::operator*(double rhs) {
  CoordinatePair result;

  result.x = this->x * rhs;
  result.y = this->y * rhs;

  return result;
}

CoordinatePair CoordinatePair::operator/(CoordinatePair rhs) {
  CoordinatePair result;

  result.x = this->x / rhs.x;
  result.y = this->y / rhs.y;

  return result;
}
CoordinatePair CoordinatePair::operator/(double rhs) {
  CoordinatePair result;

  result.x = this->x / rhs;
  result.y = this->y / rhs;

  return result;
}


