#ifndef PLAYER_H_HEADER_GUARD
#define PLAYER_H_HEADER_GUARD

#include <vector>

#include "coordinates.h"
#include "layer.h"
#include "level.h"

class Player {
  public:
    Player(Level *level);
    void SetLayer(Layer *layer);
    void SetSize(float size);

    // Position
    void SetPosition(CoordinatePair newPos);
    void UpdatePosition(float deltaTime); // Uses velocity values to update position
    // Velocity
    void SetVelocity(CoordinatePair newVelocity);
    void ChangeVelocity(CoordinatePair velocityChange);
    void UpdateVelocity(float deltaTime);

    void UpdateGeometry();
    CoordinatePair pos;
    bool onGround = true;

  private:
    CoordinatePair velocity;
    float maxVel = 5;
    float size;

        
    Layer *layer;
    Level *level;
    vector<ColorVertex> vertices;
    vector<uint16_t> indices;

    bool IsColliding(CoordinatePair playerPos);
    CoordinatePair CorrectCollision(CoordinatePair playerPos);
};

#endif
