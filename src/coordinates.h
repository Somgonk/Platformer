#ifndef COORDINATES_H_HEADER_GUARD
#define COORDINATES_H_HEADER_GUARD

#include <iostream>
#include <string>

using namespace std;

class CoordinatePair {
  public: 
    float x;
    float y;

    void OutputCoords(); // Outputs in form of ( x: $x, y: $y )

    // CoordinatePair operations
    CoordinatePair operator+(CoordinatePair rhs);
    CoordinatePair operator+(double rhs);

    CoordinatePair operator-(CoordinatePair rhs);
    CoordinatePair operator-(double rhs);

    CoordinatePair operator*(CoordinatePair rhs);
    CoordinatePair operator*(double rhs);

    CoordinatePair operator/(CoordinatePair rhs);
    CoordinatePair operator/(double rhs);
};

#endif
