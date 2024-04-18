#ifndef LEVEL_H_HEADER_GUARD
#define LEVEL_H_HEADER_GUARD

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "layer.h"

using namespace std;

class Level {
  public:
    Level(string filename);
    void UpdateGeometry();
    void SetLayer(Layer *layer);
    bool fail();

    // Level Geometry
    vector<ColorVertex> vertices;
    vector<uint16_t> indices;

    // Gameplay
    vector<bool> CalculateCollisions(float x, float y);

  private:
    void ParseLevelFile();

    int error;
    ifstream levelFS;

    Layer *layer;

    // Level Data
    string name;
    int width;
    int height;

    float tileSize;

    float offsetX = 0;
    float offsetY = 0;

    int attempts;
    double bestTime;

    vector<vector<int>> map;
    
};


#endif
