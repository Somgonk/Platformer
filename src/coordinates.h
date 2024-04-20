#ifndef COORDINATES_H_HEADER_GUARD
#define COORDINATES_H_HEADER_GUARD

class CoordinatePair {
  public: 
    float x;
    float y;

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
