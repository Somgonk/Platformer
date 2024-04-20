#include "player.h"

Player::Player(float size) {
  this->size = size;
  this->pos = {0, 0};
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
  ChangePosition(posChange);
}
void Player::ChangePosition(CoordinatePair posChange) {
  for (int i = 0; i < this->vertices.size(); i++) {
    this->vertices.at(i).x_pos += posChange.x / size;
    this->vertices.at(i).y_pos += posChange.y / size;
  }
  UpdateGeometry();
}
void Player::UpdatePosition(float deltaTime) {
  for (int i = 0; i < this->vertices.size(); i++) {
    this->vertices.at(i).x_pos -= deltaTime * (velocity.x * size);
    this->vertices.at(i).y_pos -= deltaTime * (velocity.y * size);
  }
  UpdateGeometry();
}

void Player::SetVelocity(CoordinatePair newVelocity) {
  this->velocity = newVelocity;
}
void Player::ChangeVelocity(CoordinatePair velocityChange) {
  this->velocity = this->velocity + velocityChange;
}
void Player::UpdateVelocity(float deltaTime) {
  // X velocity friction
  if (velocity.x > 0) {
    velocity.x /= 1.05;
  } else if (velocity.x < 0) {
    velocity.x /= 1.05;
  }

  

  if (abs(velocity.x) < 0.001) {
    velocity.x = 0;
  }

  // Y velocity gravity


}

void Player::UpdateGeometry() {
  this->layer->UpdateGeometry(this->vertices, this->indices);
}
