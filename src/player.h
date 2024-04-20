#ifndef PLAYER_H_HEADER_GUARD
#define PLAYER_H_HEADER_GUARD

#include <vector>

#include "coordinates.h"
#include "layer.h"

class Player {
  public:
    Player(float size);
    void SetLayer(Layer *layer);
    void SetSize(float size);

    // Position
    void SetPosition(CoordinatePair newPos);
    void ChangePosition(CoordinatePair posChange);
    void UpdatePosition(float deltaTime); // Uses velocity values to update position

    // Velocity
    void SetVelocity(CoordinatePair newVelocity);
    void ChangeVelocity(CoordinatePair velocityChange);
    void UpdateVelocity(float deltaTime);

    void UpdateGeometry();

    CoordinatePair pos;

  private:
    CoordinatePair velocity;
    float maxVel = 0.1;
    float size;
    
    Layer *layer;
    vector<ColorVertex> vertices;
    vector<uint16_t> indices;
};

#endif
