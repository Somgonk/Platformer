#include "player.h"

Player::Player(Level *level) {
  this->level = level;
  this->size = (*level).tileSize;
  this->pos = {0, 0};
  this->velocity = {0, 0};
  this->vertices = {
    {0 - (size / 2), 0 - (size / 2), 0xff0000ff},
    {0 + (size / 2), 0 - (size / 2), 0xff0000ff},
    {0 + (size / 2), 0 + (size / 2), 0xff0000ff},
    {0 - (size / 2), 0 + (size / 2), 0xff0000ff}
  };
  this->indices = {
    0, 1, 2,
    2, 3, 0
  };
}
void Player::SetSize(float size) {
  this->vertices = {
    {pos.x - (size / 2), pos.y - (size / 2), 0xff0000ff},
    {pos.x + (size / 2), pos.y - (size / 2), 0xff0000ff},
    {pos.x + (size / 2), pos.y + (size / 2), 0xff0000ff},
    {pos.x - (size / 2), pos.y + (size / 2), 0xff0000ff}
  };
  UpdateGeometry();
}

void Player::SetLayer(Layer *layer) {
  this->layer = layer;
  this->layer->UpdateGeometry(this->vertices, this->indices);
}

void Player::SetPosition(CoordinatePair newPos) {
  CoordinatePair oldPos = this->pos;
  this->pos = newPos;
  CoordinatePair posChange = this->pos - oldPos;
  for (int i = 0; i < this->vertices.size(); i++) {
    this->vertices.at(i).x_pos += posChange.x;
    this->vertices.at(i).y_pos += posChange.y;
  }
  UpdateGeometry();
}

bool Player::IsColliding(CoordinatePair playerPos) {
  float halfPlayer = size / 2;
  vector<CoordinatePair> corners {
    (playerPos + (CoordinatePair){halfPlayer, halfPlayer}),
    (playerPos + (CoordinatePair){halfPlayer, -halfPlayer}),
    (playerPos + (CoordinatePair){-halfPlayer, -halfPlayer}),
    (playerPos + (CoordinatePair){-halfPlayer, halfPlayer})
  };
  for (int i = 0; i < corners.size(); i++) {
    if (level->PosToData(corners.at(i)) == 1) {
      return true;
    }
  }
  return false;
}

CoordinatePair Player::CorrectCollision(CoordinatePair playerPos) {
  CoordinatePair offset = {0,0};
  float halfPlayer = size / 2;
  float tileSize = level->tileSize;

  bool groundCheck = false;

  CoordinatePair scale {0, 0};

  vector<CoordinatePair> corners {
    (playerPos + (CoordinatePair){halfPlayer, halfPlayer}),
    (playerPos + (CoordinatePair){halfPlayer, -halfPlayer}),
    (playerPos + (CoordinatePair){-halfPlayer, -halfPlayer}),
    (playerPos + (CoordinatePair){-halfPlayer, halfPlayer}),
  };
  if (level->PosToData(corners.at(0)) == 1) {
    // Top Right Collision
    CoordinatePair tileIndex = level->PosToIndex(corners.at(0));
    CoordinatePair tilePos = {tileIndex.x * tileSize - 1, (tileIndex.y + 1) * tileSize - 1};
    CoordinatePair overlap = {abs(corners.at(0).x - tilePos.x), abs(corners.at(0).y + tilePos.y)};
    if (overlap.x < overlap.y) {
      offset.x -= overlap.x; 
      velocity.x = 0;
    } else {
      offset.y -= overlap.y;
      velocity.y = 0;
    }
  }
  if (level->PosToData(corners.at(1)) == 1) {
    // Bottom Right Collision
    CoordinatePair tileIndex = level->PosToIndex(corners.at(1));
    CoordinatePair tilePos = {tileIndex.x * tileSize - 1, tileIndex.y * tileSize - 1};
    CoordinatePair overlap = {abs(corners.at(1).x - tilePos.x), abs(corners.at(1).y + tilePos.y)};
    if (overlap.x < overlap.y) {
      offset.x -= overlap.x; 
      velocity.x = 0;
    } else {
      offset.y += overlap.y;
      velocity.y = 0;
      groundCheck = true;
    }
  }
  if (level->PosToData(corners.at(2)) == 1) {
    // Bottom Left Collision
    CoordinatePair tileIndex = level->PosToIndex(corners.at(2));
    CoordinatePair tilePos = {(tileIndex.x + 1) * tileSize - 1, tileIndex.y * tileSize - 1};
    CoordinatePair overlap = {abs(corners.at(2).x - tilePos.x), abs(corners.at(2).y + tilePos.y)};
    if (overlap.x < overlap.y) {
      offset.x += overlap.x; 
      velocity.x = 0;
    } else {
      offset.y += overlap.y;
      velocity.y = 0;
      groundCheck = true;
    }
  }
  if (level->PosToData(corners.at(3)) == 1) {
    // Top Left Collision
    CoordinatePair tileIndex = level->PosToIndex(corners.at(2));
    CoordinatePair tilePos = {(tileIndex.x + 1) * tileSize - 1, (tileIndex.y + 1) * tileSize - 1};
    CoordinatePair overlap = {abs(corners.at(2).x - tilePos.x), abs(corners.at(2).y + tilePos.y)};
    if (overlap.x < overlap.y) {
      offset.x += overlap.x; 
      velocity.x = 0;
    } else {
      offset.y -= overlap.y;
      velocity.y = 0;
    }
  }
  this->onGround = groundCheck;
  return offset;
}

void Player::UpdatePosition(float deltaTime) {
  float halfPlayer = size / 2;

  CoordinatePair posChange = {velocity.x, velocity.y};
  posChange = posChange * (deltaTime * size);
  CoordinatePair newPos = pos + posChange;
  
  newPos = newPos + CorrectCollision(newPos);



  SetPosition(newPos);
  UpdateGeometry();
}

void Player::SetVelocity(CoordinatePair newVelocity) {
  this->velocity = newVelocity;
}
void Player::ChangeVelocity(CoordinatePair velocityChange) {
  this->velocity.x = this->velocity.x + velocityChange.x;
  this->velocity.y = this->velocity.y + velocityChange.y;
}
void Player::UpdateVelocity(float deltaTime) {
  
  // friction
  if (velocity.x > 0) {
    velocity.x *= 0.98;
  } else if (velocity.x < 0) {
    velocity.x *= 0.98;
  }
  if (velocity.y > 0) {
    velocity.y -= 0.1;
  } else if (velocity.y < 0) {
    velocity.y -= 0.1;
  }

  if (velocity.x > 0 && abs(velocity.x) > maxVel) {
    velocity.x = maxVel;
  }
  if (velocity.x < 0 && abs(velocity.x) > maxVel) {
    velocity.x = 0 - maxVel;
  }

  // gravity
  if (onGround == false) {
    velocity.y -= 0.05;
  }

  if (abs(velocity.x) < 0.01) {
    velocity.x = 0;
  }
  if (abs(velocity.y) < 0.01) {
    velocity.y = 0;
  }
}

void Player::UpdateGeometry() {
  this->layer->UpdateGeometry(this->vertices, this->indices);
}
